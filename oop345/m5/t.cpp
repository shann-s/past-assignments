#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include "util.h"
#include "t.h"

using namespace std;

	Task::Task(vector<string> row)
		: taskSlots("1")
	{
		switch (row.size()){

		case 4:
			if (validTaskname(row[3]))
				taskFail = row[3];
			else
				throw string("expected fail task name, found [") + row[3] + "]";
		case 3:
			if (validTaskname(row[2]))
				taskAccept = row[2];
			else
				throw string("expected fail task name, found [") + row[2] + "]";

		case 2:
			if (validSlotName(row[1]))
				taskSlots = row[1];
			else
				throw string("expected fail task name, found [") + row[1] + "]";
		case 1:
			if (validTaskname(row[0]))
				taskName = row[0];
			else
				throw string("expected fail task name, found [") + row[0] + "]";
			break;
		default:
			throw string("expected 1,2,3 or 4 fields, found - ") + to_string(row.size());
		}
	}

	void Task::Graph(fstream& os)
	{
		if (not taskFail.empty())
			os << '"' << taskName << "'" << "->" << '"' << taskFail << "'" << "[color=red];\n";
		if (not taskAccept.empty())
			os << '"' << taskName << "'" << "->" << '"' << taskAccept << "'" << "[color=green];\n";
		if (taskFail.empty() and taskAccept.empty())
			os << '"' << taskName << "'" << ";\n";
	}

	void Task::Print()
	{
		cout << "[" << taskName << "]" << " "
			<< "[" << taskSlots << "]" << " "
			<< "[" << taskAccept << "]" << " "
			<< "[" << taskFail << "]" << "\n";
	}

	TaskManager::TaskManager(vector < vector < string > > & csvData)
	{
		int lineNumber = 0;
		for (auto row : csvData) {
			try{
				lineNumber++;
				tasklist.push_back(move(Task(row)));
			}
			catch (string& e){

				cerr << "Problem with line" << lineNumber << ": " << e << "\n";
			}
		}
	}
	void TaskManager::print()
	{
		int lineNumber = 0;
		for (auto t : tasklist)
		{

			lineNumber++;
			cout << lineNumber << ": ";
			t.Print();
		}
	}
	void TaskManager::graph(string& filename)
	{
		fstream os(filename + ".gv", ios::out);
		if (os.is_open())
		{

			os << "digraph taskgraph { \n";
			for (auto t : tasklist) {

				t.Graph(os);
			}
			os << "}\n";
			os.close();

			string cmd;
#ifdef __MSVC
			cmd = "C:\\Program Files(x86)\\Graphviz2.38\\bin\\dot.exe"
#else
			cmd = "dot";
#endif
			cmd += string(" -Tpng ") + filename + ".gv > " + filename + ".gv.png";
			cout << "running " << cmd << "\n";
			system(cmd.c_str());
		}
	}

	Task* TaskManager::FindTask(string name){
		for (size_t t = 0; t < tasklist.size(); t++){
			if (tasklist[t].getTaskName() == name)
			return &tasklist[t];
		}
		return nullptr; //not found
	}

	void TaskManager::IntegrityCheck()
	{
		for (auto t : tasklist) {
			if (not t.getTaskPass().empty() && FindTask(t.getTaskPass()) == nullptr) {
				throw std::string("Task '") + t.getTaskName() + "' references Pass task '" + t.getTaskPass() + "' but it does not exist!";
			}
			if (not t.getTaskFail().empty() && FindTask(t.getTaskFail()) == nullptr) {
				throw string("Task '") + t.getTaskName() + "' refernces Fail task '" + t.getTaskFail() + "' but it does not exist!";
			}
		}
	}