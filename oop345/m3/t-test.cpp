#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include "util.h"
#include "t.h"

using namespace std;



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
		//csvPrint(csvTaskData);

		TaskManager tm(csvTaskData);
		tm.print();
		tm.graph(filename);
	}
	catch (string& e) {

		cerr << e << "\n";
	}
}