#include <iostream>
#include <ctype.h>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "Stations.h"

using namespace std;

namespace w2{

	Stations::~Stations(){
		std::fstream os(filename, ios::out | ios::trunc); //opens file zaps it
		if (os.is_open()) {


			for (int s = 0; s < stationCount; s++){
				stationTable[s].save(os);
				os.close();
			}
		}
		delete[] stationTable;
	}

	Stations::Stations(char* f)
		: filename(f){
		fstream is(filename);
		if (!is.is_open()){
			cerr << "Cannot find data file -->" << filename << "<--\n";
			exit(1);
		}

		string line;
		getline(is, line, ';');
		cout << "line-'" << line << "'\n"; //returns line until the smicolon

		stationCount = 0;
		//size_t is a size type that cen be int depending on the machine bit
		for (size_t index = 0; index < line.size(); index++){
			if (isdigit(line[index])) {
				stationCount = 10 * stationCount + (line[index] - '0');
			}
			else {
				cerr << "non-digit character " << line[index] << " in station count field\n";
				cerr << line << "\n";
				exit(2);
			}
		}

		cout << "stationCount = " << stationCount << "\n";

		//skip '\n'
		getline(is, line);
		if (line.size() != 0){ //extra char after ';'
			cerr << "extra character after ';' on station count line in data file\n";
			cerr << line << "<n";
			exit(3);
		}
		Station* Table = new Station[stationCount];
		for (int s = 0; s < stationCount; s++){
			stationTable[s] = Station(is);
		}
	}

	void Stations::update(){
		cout << "Passes Sold :\n";
		cout << "-------------\n";
		for (int s = 0; s < stationCount; s++){
			stationTable[s].update();
		}
	}
	void Stations::restock(){
		cout << "Passes Added:\n";
		cout << "-------------\n";

		for (int s = 0; s < stationCount; s++){
			stationTable[s].restock();
		}
		//print 
	}
	void Stations::report(){
		cout << "Passes in Stock : Student Adult\n";
		cout << "-------------------------------\n";
		for (int s = 0; s < stationCount; s++){
			stationTable[s].report();
		}
	}

}