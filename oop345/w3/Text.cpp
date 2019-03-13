#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Text.h"

using namespace std;

namespace w3{


	Text::~Text(){

		delete LineTable;
	};

	std::size_t Text::size(){
		return count;
	};

	Text::Text(const Text& rhs){
		count = rhs.count;
		if (count){

			LineTable = new string[count];

			//deep copy
			for (size_t i = 0; i < count; i++){
				LineTable[i] = rhs.LineTable[i];
			}
		}
	};

	Text::Text(Text&& rhs){
		//steal brains
		count = rhs.count;
		LineTable = rhs.LineTable;

		//rhs becomes zombie
		rhs.count = 0;
		rhs.LineTable = nullptr;
	};

	Text& Text::operator= (const Text rhs){

		if (this != &rhs){
			delete[] LineTable;
			count = rhs.count;


			LineTable = new string[count];
			for (size_t i = 0; i < count; i++) {
				LineTable[i] = rhs.LineTable[i];
			}
		}
		return *this;
	};

	Text& Text::operator*= (Text&& rhs){

		if (this != &rhs){
			delete[] LineTable;

			//steal brains
			//
			count = rhs.count;
				LineTable = rhs.LineTable;

			//rhs becomes zombie
			rhs.count = 0;
			rhs.LineTable = nullptr;
		}
		return *this;
	};

	Text::Text(char* filename){

		fstream is(filename, ios::in);
		if (is.is_open()) {

			string line;

			while (getline(is, line)){
				count++;
			}

			cout << "file " << filename << "' has " << count << " lines.\n";
			is.clear();
			//clear error state, getline hit END-OF-FILE leaving the file in an error state
			//
			is.seekg(0, ios_base::beg); //position file at the start

			string *LineTable = new string[count];


			//string cr
			for (size_t i = 0; i < count; i++){
				getline(is, LineTable[i]);
				/*auto cr = lineTable[i].find('\r');;
				if(cr != string::npos){
					LineTable[i].erase(cr); `
				}*/
			}
			is.close();

			print();
		}
		else {
			cerr << "Cannot open file --->" << filename << "<---\n";
			exit(1);
		}
	};

	void Text::print(){

		for (size_t i = 0; i < count; i++){
			cout << i + 1 << ": -->" << LineTable[i] << "<--\n";
		}
	};

	Text::Text(){

		LineTable = nullptr;
		count = 0;
	};
}