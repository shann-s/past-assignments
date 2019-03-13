#include <iostream>
#include <ctype.h>
#include <fstream>
#include <cstdlib>
#include "Station.h"

using namespace std;

namespace w2{

	Station::Station(){
		name = '\0';
		passes[STUDENT_PASS] = 0;
		passes[ADULT_PASS] = 0;
	}

	Station::Station(std::fstream& is){
		string line;
		getline(is, line);
		cout << "line -->" << line << "<--\n";

		string n;
		size_t index = 0;
		for (; index < line.size(); index++) {
			if ( line[index] != ';'){
				n += line[index];
			}
			else{
				index++; //skip ';'
				break;
			}
		}
		if ( index == line.size()){
			cerr << "';' missing on station line " << line << "'\n";
			exit(4);
		}
		cout << "name= " << n << "\n";
		//do another one for adult replacing 's' with 'a'
		unsigned s = 0;
		cout << "student pass count =" << s << "\n";
		for (; index < line.size(); index++){
			if (line[index] == '\0'){
				break;
			} if (isdigit(line[index])){
				s = 10 * s + (line[index] - '0');
			}
			else{
				cerr << "non-digit chracter in student pass count field\n";
				exit(5);
			}
		}
		//do another one for adult
		unsigned a = 0;
		cout << "adult pass count =" << a << "\n";
		for (; index < line.size(); index++){
			if (line[index] == '\0'){
				break;
			} if (isdigit(line[index])){
				a = 10 * a + (line[index] - '0');
			}
			else{
				cerr << "non-digit chracter in student pass count field\n";
				exit(5);
			}
		}
		set(n, s, a);
	}

	void Station::set(const std::string& n, unsigned s, unsigned a){
		name = n;
		passes[STUDENT_PASS] = s;
		passes[ADULT_PASS] = a;
		// - sets the instance var to the values recieved in its parameters
	}

	void Station::update(PassType pt, int change){
		passes[pt] += change;
		//- updates the number of passes - sold if negative, added if positive
	}

	unsigned Station::inStock(Passtype pt) const{
		//returns the number of passes of the requested type
		return passes[pt];
	}
	const std::string& Station::getName() const{
		//returns a reference to a string object holding the name of the station
		return name;
	}

	void Station::update(){
		int s, a;
		cout << getName() << "\n";
		cout << " Student Passes sold: "; cin >> s;
		cout << " Adult Passes sold : "; cin >> a;

		update(STUDENT_PASS, -s);
		update(ADULT_PASS, -a);
	}
	void Station::restock(){
		int s, a;
		cout << getName() << "\n";
		cout << " Student Passes sold: "; cin >> s;
		cout << " Adult Passes sold : "; cin >> a;

		update(STUDENT_PASS, s);
		update(ADULT_PASS, a);
	}
	void Station::report(){
		cout << getName() << ", "
			<< inStock(STUDENT_PASS) << ", "
			<< inStock(ADULT_PASS)
			<< "\n";
	}
	void Station::save(std::fstream& os){
		os << name << ':' << inStock;
	}
}
