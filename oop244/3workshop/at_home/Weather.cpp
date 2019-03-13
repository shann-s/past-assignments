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
	  // set method 
	void Weather::set(const char* a, double b, double c){

		strcpy(_date, a);
		high = b;
		_low = c;

	}
	// date method (query)
	const char* Weather::date() const {
		return _date;
	}
	// low method (query)
	double Weather::low() const {
		return _low;
	}
	// display
	void Weather::display() const {
		cout.setf(ios::left);
		cout << setw(10) << setfill('_') << _date;
		cout.unsetf(ios::left);
		cout.setf(ios::fixed);
		cout.precision(1);
		cout << setw(6) << high << setfill('_');
		cout << setw(6) << _low << setfill('_');
		cout << endl;
		cout.unsetf(ios::fixed);
	}
}
