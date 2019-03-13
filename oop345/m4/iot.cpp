#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "util.h"

using namespace std;

#include "i.h"
#include "o.h"
#include "t.h"

int main(int argc, char* argv[])
{
	try{
		if (argc != 5){
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
		im.Print();
		im.Graph(filenameItem);

		OrderManager om(csvOrderData);
		om.Print();
		om.Graph(filenameTask);

		TaskManager tm(csvTaskData);
		tm.print();
		im.Graph(filenameTask);

		bool GoodToGo = true;
		cout << "Item integrity check\n";
		try{
			im.IntegrityCheck(im);
		}
		catch (string& e) {
			GoodToGo = false;
			cerr << e << "\n";
		}

		cout << "Order integrity check\n";
		try{
			om.IntegrityCheck(om);
		}
		catch (string& e) {
			GoodToGo = false;
			cerr << e << "\n";
		}

		cout << "Task integrity check\n";
		try{
			tm.IntegrityCheck(tm);
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

		cout << "*****************************************************";
		cout << "* DATA HAS PASSED INTEGRITY CHECK AND IS GOOD TO GO!*";
		cout << "*****************************************************";
	}
}