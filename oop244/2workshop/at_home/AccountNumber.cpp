// OOP244 Workshop 2: Compound types and privacy
// File	???????
// Version 1.0
// Date	???????????
// Author	?????????
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		Reason
// 
///////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
using namespace std;
#include "AccountNumber.h"

namespace sict {
	// member functions' (methods') definition go here

	void AccountNumber::name(const char name[]) {
		strcpy(_name, name);
	}
	void AccountNumber::accountNumber(int bankCode, int branchCode, int accountNumber) {

		if (bankCode >= MIN_BANKCODE && bankCode <= MAX_BANKCODE && branchCode >= MIN_BRANCHCODE && branchCode <= MAX_BRANCHCODE && accountNumber >= MIN_ACCNO && accountNumber <= MAX_ACCNO) {
			_validAccNumber = true;
			_bankCode = bankCode;
			_branchCode = branchCode;
			_accountNumber = accountNumber;
		}
		else {
			_validAccNumber = false;
		}

	}

	bool AccountNumber::isValid() const {

		return  _validAccNumber;
	}

	void AccountNumber::display() const {
		if (isValid() == true) {
			cout << "Name: " << _name << ", Account number: " << _bankCode << "-"
				<< _branchCode << "-" << _accountNumber << endl;

		}if (isValid() == false) {
			cout << _name << " does not have a valid account number." << endl;
		}

	}

	void AccountNumber::displayName() const {

		cout << "Name: " << _name << endl;

	}

	void AccountNumber::displayNumber() const {

		cout << "Account number: " << _bankCode << "-"
			<< _branchCode << "-" << _accountNumber << endl;

	}

	void AccountNumber::display(bool display_number) const{
		if (isValid() == false) {
			cout << _name << " does not have a valid account number." << endl;
		}
		if (isValid() == true) {
			if (display_number == false) {
				displayNumber();
			}
		}

	}
	void AccountNumber::display(bool display_number, bool display_name) const{
		
		if (isValid() == false) {
			cout << _name << " does not have a valid account number." << endl;
		}
		if (isValid() == true) {
			if (display_number == true && display_name == false){
				displayName();
			}
			else if (display_number == true && display_name == true) {

			}
		}
	}
}
