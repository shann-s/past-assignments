//item.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include "util.h"

using namespace std;


class Item {

	string itemName, itemInstallTask, ItemRemoverTask, itemSequence, itemDescription;
public:
	Item(vector<string> row)
	{
		switch (row.size()) {
		case 5:
			itemDescription = row[4];
		case 4:
			if (validItemSequence(row[3]))
				itemSequence = row[3];
			else
				throw string("expected sequence, found [") + row[3] + "]";
			//case 3
			if (validTaskname(row[2]))
				ItemRemoverTask = row[2];
			else
				throw string("expected fail task name, found [") + row[2] + "]";
			//case 2
			if (validTaskname(row[1]))
				itemInstallTask = row[1];
			else
				throw string("expected fail task name, found [") + row[1] + "]";
			//case 1
			if (validItemname(row[0]))
				itemName = row[0];
			else
				throw string("expected fail task name, found [") + row[0] + "]";
			break;
		default:
			throw string("expected 4 or 5 fields, found - ") + to_string(row.size());
		}
	}


	void Print()
	{
		cout << "[" << itemName << "]" << " "
			<< "[" << itemInstallTask << "]" << " "
			<< "[" << ItemRemoverTask << "]" << " "
			<< "[" << itemSequence << "]"
			<< "[" << itemDescription << "]" << "\n";
	}

	void Graph(fstream& os)
	{
		os << '"' << "Item\n" << itemName << '"'
			<< "->"
			<< '"' << "Installer\n" << itemInstallTask << '"'
			<< "[color=green];\n";
		os << '"' << "Item\n" << itemName << '"' \
			<< "->" << '"' << "Item\n" << ItemRemoverTask << '"' \
			<< "[color=red];\n";
	}

};

class ItemManager {

	vector < Item > itemlist;
public:
	ItemManager(vector < vector < string > > & csvData)
	{
		int lineNumber = 0;
		for (auto row : csvData) {
			try {
				lineNumber++;
				itemlist.push_back(move(Item(row)));
			}
			catch (string& e) {

				cerr << "Problem with line" << lineNumber << ": " << e << "\n";
			}
		}
	}
	void print()
	{
		int lineNumber = 0;
		for (auto t : itemlist)
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
			for (auto t : itemlist) {

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
	try {
		if (argc != 3) {
			throw string("usage: ") + argv[0] + " file.cv delimiter-char";
		}
		string filename = argv[1]; //1st arg
		char delim = argv[2][0]; //1st char of second arg

								 //open file

		vector< vector<string> > csvTaskData;

		csvReader(filename, delim, csvTaskData);
		//	csvPrint(csvTaskData);

		ItemManager im(csvTaskData);
		im.print();
		im.graph(filename);
	}
	catch (string& e) {

		cerr << e << "\n";
	}
}
