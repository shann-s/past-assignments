//factory.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "util.h"

using namespace std;

#include "i.h"
#include "o.h"
#include "t.h"

#include "machine.h"

class Factory {
	vector < Machine > machinelist;
public:
	Factory()
	{

	}

	Factory(ItemManager& im, OrderManager& om, TaskManager& tm)
	{
		//STEP 1 - load machines into the factory
		for (size_t count = 0; count < tm.size(); count++) {
			machinelist.push_back(move(Machine(tm.getTask(count))));
		}

		int line = 0;
		/*for (auto m : machinelist) {
			line++;
			cout << line << ":" << m.getTaskName() << "\n";
		}*/

		//STEP 2 - find source machine
		auto FindMachine = [&] (string n) -> Machine* {
			for (size_t i = 0; i < machinelist.size(); i++) {
				if (machinelist[i].getTaskName() == n){
					return &machinelist[i];
				}
			}
			return nullptr;
		};
		for (auto m : machinelist) {
			string pass = m.getTaskPass();
			if (not pass.empty()) FindMachine(pass)->IncInComing();

			string fail = m.getTaskFail();
			if (not fail.empty()) FindMachine(fail)->IncInComing();
		}

		int source = -1;
		for (size_t m = 0; m < machinelist.size(); m++) {
			cout << m << ":" << machinelist[m].getTaskName();
			if (machinelist[m].isSingleton())
			{
				cout << " SINGLETON";
			}
			else{
				if (machinelist[m].isSource()) {
					cout << " SOURCE";
					if (source == -1){
						source = m;
					}
					else{
						throw string("Multiple sources. Fix data and re-submit!");
					}
				}
				if (machinelist[m].isSink()) cout << " SINK";
			}
			
		}
		cout << "Source is" << source;

		//STEP 3 - load job form inputQ for the source
		for (size_t o = 0 ; o < om.getSize(); o++){
			machinelist[source].AddJob(Job(om.getOrder(o)));
		}

		for (auto m : machinelist){
			cout << m.getTaskName() << " has " << m.inputQsize() << " jobs.\n";
		}
		for (auto &m : machinelist){
			m.Classify(im);
		}
		//STEP 4 - Time loop

		while (true){
			//ARE THERE MACHINES WITH WORK TO DO?

			bool AllDone = true;
			for (auto m : machinelist){
				if (m.inputQsize()){ //found a machine with jobs
					AllDone = false;
					break;
				}
			}

			if (AllDone){
				cout << "All Done\n";
				
				break; //break out of time looop
			}

			for (auto &m : machinelist) { //machine loop
				if (m.inputQsize() == 0){
					continue; //nothing for this machine to do
				}

				Job job = m.getJob();
				cout << m.getTaskName() << " is looking for a job " << job.getCustomerName() << "/" << job.getProductName() << "\n";
				if (m.isSink()){
					cout << "Job arrived at sink --- nothing to do\n";
					cout << "Job exiting system\n";
					continue; //machine loop over for this machine
				}

				bool didSomething = false;
				//Are we an installer 
				if (m.getInstaller()){
					//do they need out services
					cout << "we are an installer\n;";

						//for each item in ther order,
						// if not installed 
						//  if the installer name is out name
						//   install the item - call Installer (i, true) )
						for (size_t i = 0; i < job.size(); i++){
							if (job.installed(i)) //already installed
								continue;	

							string itemName = job.getItem(i); //Item *pItem = nullptr;
							Item*  itemPtr = im.FindItem(itemName);
							if (m.getTaskName() == itemPtr->getItemInstallerTask()){
								job.Installed(i, true); //flag the item as being installed
								didSomething = true;
								break; //all done installing 1 item
							}
						}
				}

				if (m.getRemover()){
					//do they need out services
					cout << "we are a remover\n;";
					//for each item in ther order,
					// if not installed 
					//  if the installer name is out name
					//   install the item - call Installer (i, true) )
					for (int i = job.size() - 1 ; i >= 0; i--){
						if (not job.installed(i)) //already installed
							continue; 
							string itemName = job.getItem(i); //Item *pItem = nullptr;

						Item*  itemPtr = im.FindItem(itemName);
						if (m.getTaskName() == itemPtr->getItemRemoverTask()){
							job.Installed(i, false); //flag the item as being installed
							didSomething = true;
							break; //all done removing 1 item
						}
					}
				}

				auto MovePass = [&] {
					string pass = m.getTaskPass();
					cout << "moving job to pass machine" << pass << "\n";
					for (auto &m2 : machinelist){
						if (m2.getTaskName() == pass){
							m2.AddJob(job);
							break;
						}
					}
				};

				auto MoveFail = [&] {
					string fail = m.getTaskFail();
					cout << "moving job to fail machine" << fail << "\n";
					for (auto &m2 : machinelist){
						if (m2.getTaskName() == fail){
							m2.AddJob(job);
							break;
						}
					}

				};

				if ( not didSomething) {
					//move job to passed inputQ
					m.getTaskPass();
				}

				if ( m.getTaskFail().empty()){ // if there is only a pass task
					//move job to passed inputQ
				}

				//flip a coin (rand() &l --- test if odd)
				if (rand() & 1) {
					//pass
					//move job to pass machine inputQ
					MovePass();
					continue; //end of this machine
				}
				else{
					//fail
					//move job to failed machine inputQ
					MoveFail();
					continue; // end of this machine
				}

				exit(1); //debuging for infinite loop

			}//machine loop

		}//time loop
		cout << "Simulation Over\n";
	}
};

int main(int argc, char* argv[])
{
	try {
		if (argc != 5) {
			throw string("Usage ") + argv[0] + string(": item order task (the 3 csv files) delimiter-char");
		}

		string filenameItem = string(argv[1]); //1st arg is Item CSV filename.
		string filenameOrder = string(argv[2]); //2nd arg is Order CSV filename.
		string filenameTask = string(argv[3]); //3rd arg is Task CSV file name
		char delimiter = argv[4][0]; //4th arg, 1st char is delimiter.

		vector < vector< string > > csvItemData;
		vector < vector< string > > csvOrderData;
		vector < vector< string > > csvTaskData;

		// csvPrint(csvTaskData);

		ItemManager im(csvItemData);
		im.print();
		im.graph(filenameItem);

		OrderManager om(csvOrderData);
		om.print();
		om.graph(filenameTask);

		TaskManager tm(csvTaskData);
		tm.print();
		tm.graph(filenameTask);

		bool GoodToGo = true;
		cout << "Item integrity check\n";
		try {
			im.IntegrityCheck(tm);
		}
		catch (string& e) {
			GoodToGo = false;
			cerr << e << "\n";
		}

		cout << "Order integrity check\n";
		try {
			om.IntegrityCheck(im);
		}
		catch (string& e) {
			GoodToGo = false;
			cerr << e << "\n";
		}

		cout << "Task integrity check\n";
		try {
			tm.IntegrityCheck();
		}
		catch (string& e) {
			GoodToGo = false;
			cerr << e << "\n";
		}

		if (GoodToGo == false) {
			cerr << "**************************************\n";
			cerr << "* DATA HAS ERRORS. FIX AND RESUBMIT! *\n";
			cerr << "**************************************\n";
			exit(1);

		}

		cout << "*****************************************************\n";
		cout << "* DATA HAS PASSED INTEGRITY CHECK AND IS GOOD TO GO!*\n";
		cout << "*****************************************************\n";

		Factory factory(im, om, tm);
	}
	catch (const string& e) 
	{
		cerr << e << "\n";
	}
}