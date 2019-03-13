/*Weather.cpp*/
//  includes go here
#include <iostream>
#include "Weather.h"
#include <iomanip>
#include <cstring>
using namespace std;
using namespace sict;
namespace sict{
	// sict namespace
	// set
	void Weather::set(const char* a, double b, double c){

		strcpy(date, a);
		high = b;
		low = c;

	}

	// display
	void Weather::display() const{
		cout.setf(ios::left);
		cout << setw(10) << setfill('_') << date;
		cout.unsetf(ios::left);
		cout.setf(ios::fixed);
		cout.precision(1);
		cout << setw(6) << high << setfill('_');
		cout << setw(6) << low <<setfill('_');
		cout << endl;
		cout.unsetf(ios::fixed);
	}
}
