#include <iostream>
#include <ctype.h>
#include <fstream>
#include "Station.h"

namespace w2{

	class Stations{

		char* filename;
		int stationCount;
		Station* stationTable;
	public:
		~Stations();

		Stations(char* f);

		void update();
		void restock();
		void report();
	};
}