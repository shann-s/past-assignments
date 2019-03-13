///order.cpp
//change "item" into order
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include "util.h"

using namespace std;


class Order {

	string OrderCustomerName, OrderProductName;
	vector< string > itemList;
	public:
		Order(vector<string> row)
		{
			if (row.size() < 3) {
				throw string("need at least 3 fields, found ") + to_string(row.size());
			}



			if (validOrderCustomerName(row[0]))
			{
				OrderCustomerName = row[0];
			}
			else{

				throw string("expected customer name, found [") + row[0] + "]";
			}

			if (validOrderProductName(row[1])) {
				OrderProductName = row[1];
			}
			else {
				throw string("expected product name, found [") + row[1] + "]";
			}
			for (size_t i = 2; i < row.size(); i++){

				if (validItemname(row[i]))
				{
					itemList.push_back(row[i]);
				}
				else
				{
					throw string("expected item name, found[") + row[i] + "]";
				}
			}
	}


	void Print()
	{
		cout << "[" << OrderCustomerName << "]" << " "
			<< "[" << OrderProductName << "]" << "\n";
		for (auto e : itemList)
			cout << "[" << e << "] ";
		cout << "\n";
	}

	void Graph(fstream& os)
	{
		for (auto e : itemList)
			os << '"' << OrderCustomerName << "\n" << OrderProductName << '"'
			<< "->"
			<< '"' << e << '"'
			<< "[color=green];\n";
	}

};

class OrderManager {

	vector < Order > orderlist;
public:
	OrderManager(vector < vector < string > > & csvData)
	{
		int lineNumber = 0;
		for (auto row : csvData) {
			try {
				lineNumber++;
				orderlist.push_back(move(Order(row)));
			}
			catch (string& e) {

				cerr << "Problem with line" << lineNumber << ": " << e << "\n";
			}
		}
	}
	void print()
	{
		int lineNumber = 0;
		for (auto t : orderlist)
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
			for (auto t : orderlist) {

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

		OrderManager om(csvTaskData);
		om.print();
		om.graph(filename);
	}
	catch (string& e) {

		cerr << e << "\n";
	}
}
