#include <iomanip>
#include <iostream>
#include <string>
#include "AmaPerishable.h"
using namespace std;
namespace sict{
	AmaPerishable::AmaPerishable(){

	}
	AmaPerishable::AmaPerishable(char fT){
			fileTag_ = fT;
	}
	const Date& AmaPerishable::expiry()const{
		return expiry_;
	}

	void AmaPerishable::expiry(const Date &value){
		expiry_ = value;
	}

	fstream& AmaPerishable::store(fstream& file, bool addNewLine)const{
		AmaProduct::store(file, false);
		file << ",";
		file << expiry_.year_ << "/" << expiry_.mon_ << "/" << expiry_.day_;
		if (addNewLine == true){
			file << endl;
			return file;
		}
		else{
			return file;
		}
	}

	fstream& AmaPerishable::load(fstream& file){
		AmaProduct::load(file);
		expiry_.read(file.ignore());
		return file;
	}

	ostream& AmaPerishable::write(ostream& ostr, bool linear)const{
		AmaProduct::write(ostr, linear);
		if (err_.isClear()){
			if (linear == true){
				expiry_.write(ostr);
				return ostr;
			}
			else{
				ostr << "Expiry date: ";
				expiry_.write(ostr);
				return ostr;
			}
		}
		else{
			return ostr;
		}
	}

	istream& AmaPerishable::read(istream& istr){
		AmaProduct::read(istr);
		if (err_.isClear()){
			cout << "Expiry date (YYYY/MM/DD): ";
		}
		Date temp;
		istr >> temp;
		if (istr.fail()){
			const char* msg = "Invalid Date Entry";
			err_.message(msg);
			istr.setstate(ios::failbit);
			return istr;
		}
		else if (temp.readErrorCode_ == YEAR_ERROR){
			const char* msg = "Invalid Year in Date Entry";
			err_.message(msg);
			istr.setstate(ios::failbit);
			return istr;
		}
		else if (temp.readErrorCode_ == MON_ERROR){
			const char* msg = "Invalid Month in Date Entry";
			err_.message(msg);
			istr.setstate(ios::failbit);
			return istr;
		}
		else if (temp.readErrorCode_ == DAY_ERROR){
			const char* msg = "Invalid Day in Date Entry";
			err_.message(msg);
			istr.setstate(ios::failbit);
			return istr;
		}
		else{
			expiry_ = temp;
			return istr;
		}
	}
}
