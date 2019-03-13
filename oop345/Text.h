//rule of 5
//

#pragma once //only if year is greater than 2000
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

namespace w3{

	class Text{
		string* LineTable;
		size_t count;
		public:

			void print(){
				for(size_t i = 0; i < count; i++){
					cout << i+1 << ": -->" << lineTable[i] << "<--\n";
				}
			}
			size_t size() {return count; }


			Text()
				: count(0), lineTable(nullptr)
			{}

			Text(char* filename)
				: count(0), lineTable(nullptr)
			{
				fstream is(filename, ios::in);
				if(is.is_open()) { 

					string line;

					while( getline( is, line) ){
						count++;
					}

					cout << "file " << filename << "' has" << count << "lines.\n";
					is.clear();
				       	//clear error state, getline hit END-OF-FILE leaving the file in an error state
					//
					is.seekg( 0, ios_base::beg); //position file at the start

					lineTable = new string [count];
					

					//string cr
					for(size_t = 0; i < count; i++){
						getline( is, lineTable[i] );
						//auto cr = lineTable[i].find('\r');;
						//if(cr != string::npos){
						//lineTable[i].erase( cr );`
						//}
					}
					is.close();

					print();
				} else {
					cerr << "Cannot open file --->" << filename << "<---\n";
					exit(1);
				}
			}

			~Text()
			{
			delete [] lineTable;
			}

			Text( const Text& rhs)
				: count(0), lineTable(nullptr)
			{

				count = rhs.count;
				if(count){
					lineTable = new string [ ount ];
					
					//deep copy
					for( size_t i = 0; i < count; i++){
						lineTable[i] = rhs.lineTable[i];
					}
				}
			}

			Text& operator= (const Text rhs)
			{
				if(this != &rhs){
					delete [] lineTable;
					count = rhs.count;

					lineTable = new string [count];

					for(size_t i = 0; i < count; i++) {
						lineTable[i] = rhs.lineTable[i];
					}
				}
				return *this;
			}

			Text(Text&& rhs)
				: count(0), lineTable(nullptr)
			{
				
				//steal brains
				count = rhs.count;
				lineTable = rhs.lineTable;

				//rhs becomes zombie
				rhs.count = 0;
				rhs.lineTable = nullptr;
			}

			Text& operator= (Text&& rhs){
				
				if(this != &rhs){
					delete [] lineTable;

				//steal brains
				//
				count = rhs.count
				lineTable = rhs.lineTable;

				//rhs becomes zombie
				rhs.count = 0;
				rhs.lineTable = nullptr;
				}
				return move(*this);
			}
	};
}//namespace w3
