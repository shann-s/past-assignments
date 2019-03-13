//Week 3/ workshop 2

//stations.hi
#include <iostream>
#include <ctype.h>
#include <fstream>

using namespace std;

namespace w2{

	enum PassType {STUDENT_PASS, ADULT_PASS, PASS_COUNT};


	class Station {
		string name;
		unsigned passes[PASS_COUNT];
		
		public:
			Station()
			{
				
			}

			Station(fstream& is)
			{
				string line;
				getline(is, line);
				cout << "line -->" << line << "<--\n";

				string n;
				size_t index = 0;
				for( ; index < line.size(); index++) {
					if( line[index] != ';'){
						n += line[index];
					}else{
						index++; //skip ';'
						break;
					}
				}
				if(index == line.size()){
					cerr << "';' missing on station line " << line << "'\n";
					exit(4);
				}
				cout << "name= " << n << "\n";
				cout << "student pass count =" << s << "\n";
				//do another one for adult replacing 's' with 'a'
				unsigned s = 0;
				for( ; index < line.size(); index++){
					if( line[index] == ''){
						break;
					} if( isdigit(line[index]) ){
						s = 10 * s + (line[index] - '0');
					}else{
						cerr << "non-digit chracter in student pass count field\n";
						exit(5);
					}
				}
				//do another one for adult
				cout << "student pass count =" << s << "\n";
				set(n, s, a);
			}

			void set(const std::string& n, unsigned s, unsigned a)
			{
				name = n;
				passes[STUDENT_PASS] = s;
				passes[ADULT_PASS] = a;
				// - sets the instance var to the values recieved in its parameters
			}

			void update(PassType pt, int change)
			{
				pass[pt] += change;
				//- updates the number of passes - sold if negative, added if positive
			}

			unsigned inStock(Passtype pt)
			{
				//returns the number of passes of the requested type
				return passes[pt];
			}

			const std::string& getName() const
			{
				//returns a reference to a string object holding the name of the station
				return name;
			}

			void update(){
				
				int s, a;
				cout << getName() << "\n";
				cout << " Student Passes sold: "; cin >> s;
				cout << " Adult Passes sold : " cin >> a;

				update(STUDENT_PASS, -s);
				update(ADULT_PASS, -a);
			}

			void restock() {
				//same as update but
				//update(STUDENT_PASS, s);
				//update(ADULT_PASS, a);
				//
			}

			void report()
			{
				cout << getName() << ", "
				     << inStock(STUDENT_PASS) << ", "
				     << inStock(ADULT_PASS) 
				     << "\n";
			}

			void save(fstream& os)
			{
				os << name << ':' << inStock.
			}
	};

	class Stations{

		char* filename;
		int stationCount;
		Station* stationTable;
		public:
		~Stations()
		{
			fstream os(filename, ios::out| ios::trunc); //opens file zaps it
			if(os.is_open() ) {

			
				for(int s = 0; s< stationCount; s++){
					stationTable[s].save(os);
					os.close();
				}
			}
			delete [] stationTable;
		}


		Stations(char* f)
		 : filename(f)
		{
			fstream is(filename);
			if( ! is.is_open() ){
				cerr << "Cannot find data file -->" << filename << "<--\n";
				exit(1);
			}

			string line;
			getline(is, line, ';');
			cout << "line-'" << line << "'\n"; //returns line until the smicolon
			
			stationCount = 0;
			//size_t is a size type that cen be int depending on the machine bit
			for( size_t index = 0; index < line.size(); index++){
				if( isdigit(line[index]) ) {
					stationCount = 10 * stationCount + (line[index] - '0');
				}else {
					cerr << "non-digit character " << line[index] << " in station count field\n";
					cerr << line << "\n";
					exit(2);
				}
			}

			cout << "stationCount = " << stationCount << "\n";
			
			//skip '\n'
			getline(is,line);
			if(line.size() != 0){ //extra char after ';'
				cerr << "extra character after ';' on station count line in data file\n";
				cerr << line << "<n";
				exit(3);
			}
			station Table = new Station [stationCount];
			for(int s = 0; s < stationCount; s++){
				stationTable[s] = Station(is);
			}
		}

		void update()
		{
			//print
		}
		void restock()
		{
			cout << "Passes Added:\n";
			cout << "-------------\n";

			for(int s=0; s < stationCount; s++){
				stationTable.restock();
			}
			//print 
		}
		void report()
		{
			cout << "Passes in Stock : Student Adult\n";
			cout << "-------------------------------\n";
			for(int s = 0; s < stationCount; s++){
				stationTable[s].report();
			}
		}

	}; //class stations
}//namespace w2
