//task.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include "util.h"

using namespace std;

bool validTaskname(string& t)
{
	if (t.empty())
	{
		return false;
	}

	for( auto c : t ) {

		if (not (isalnum(c) || c == ' ' || c == '_') )
		{
			return false;
		}
	}
	return true; 
}
bool validSlotName (string& t)
{
	if (t.empty())
	{
		return false;
	}

	for(auto c: t)
	{
		if (not isdigit(c))
			return false;
	}
	return true;
}

	class Task {

		string taskName, taskSlots, taskAccept, taskFail;
	public:
		Task(vector<string> row)
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

		void Graph(fstream& os)
		{

			if (not taskFail.empty())
				os << '"' << taskName << "'" << "->" << '"' << taskFail << "'" << "[color=red];\n";
			if (not taskAccept.empty())
				os << '"' << taskName << "'" << "->" << '"' << taskAccept << "'" << "[color=green];\n";
			if (taskFail.empty() and taskAccept.empty())
				os << '"' << taskName << "'" << ";\n";
		}

		void Print()
		{
			cout << "[" << taskName << "]" << " "
				<< "[" << taskSlots << "]" << " "
				<< "[" << taskAccept << "]" << " "
				<< "[" << taskFail << "]" << "\n";
		}
	};

	class TaskManager {

		vector < Task > tasklist;
	public:
		TaskManager(vector < vector < string > > & csvData)
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
		void print()
		{
			int lineNumber = 0;
			for (auto t : tasklist)
			{

				lineNumber++;
				cout << lineNumber << ": ";
				t.Print();
			}
		}

		void graph(string& filename)
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
	};

int main(int argc, char* argv[])
{
	try{
		if (argc != 3){
			throw string("usage: ") + argv[0] + " file.cv delimiter-char";
		}
	string filename = argv[1]; //1st arg
	char delim = argv[2][0]; //1st char of second arg

	//open file

	vector< vector<string> > csvTaskData;

	csvReader(filename, delim, csvTaskData);
//	csvPrint(csvTaskData);

	TaskManager tm(csvTaskData);
	tm.print();
	tm.graph(filename);
	}catch (string& e) {

		cerr << e << "\n";
	}
}
