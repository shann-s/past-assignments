#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#include "Date.h"
#include "general.h"
namespace sict{
	int Date::value()const{
		return year_ * 372 + mon_ * 31 + day_;
	}
	int Date::mdays()const{
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
		mon--;
		return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
	}

	Date::Date(){
		year_ = 0;
		mon_ = 00;
		day_ = 00;
		readErrorCode_ = NO_ERROR; //0 = No_ERROR
	}

	Date::Date(int year, int mon, int day){
		readErrorCode_ = NO_ERROR;
		year_ = year;
		mon_ = mon;
		day_ = day;

	}

	bool Date::operator==(const Date& D)const{

		if (this->value() == D.value()){
			return true;
		}
		else{
			return false;
		}

	}
	bool Date::operator!=(const Date& D)const{

		if (this->value() != D.value()){
			return true;
		}
		else{
			return false;
		}

	}
	bool Date::operator<(const Date& D)const{

		if (this->value() < D.value()){
			return true;
		}
		else{
			return false;
		}

	}
	bool Date::operator>(const Date& D)const{

		if (this->value() > D.value()){
			return true;
		}
		else{
			return false;
		}

	}
	bool Date::operator<=(const Date& D)const{

		if (this->value() <= D.value()){
			return true;
		}
		else{
			return false;
		}

	}
	bool Date::operator>=(const Date& D)const{

		if (this->value() >= D.value()){
			return true;
		}
		else{
			return false;
		}
	}

	bool Date::bad()const{
		if (readErrorCode_ != 0){
			return true;
		}
		else{
			return false;
		}
	}

	int Date::errCode()const{
		return readErrorCode_;
	}

	std::istream& Date::read(std::istream& istr){
		char t[10];
		istr >> year_ >> t[0] >> mon_ >> t[1] >> day_;
		if (istr.fail()){
			readErrorCode_ = CIN_FAILED;
			return istr;
		}

		if (istr.good()) {
				if (year_ > MAX_YEAR || year_ < MIN_YEAR){
					readErrorCode_ = YEAR_ERROR;
					return istr;
				}

				if (mon_ > 12 || mon_ < 1){
					readErrorCode_ = MON_ERROR;
					return istr;
				}

				if (day_ > 31 || day_ < 1){
					readErrorCode_ = DAY_ERROR;
					return istr;
				}
			}
		return istr;
	}

	std::ostream& Date::write(std::ostream& ostr)const{
		return ostr << year_ << '/' << setw(2) << setfill('0') << mon_ << '/' << setw(2) << setfill('0') << day_;

	}

	std::ostream& operator<<(std::ostream& os, Date const &d){
		return d.write(os);
	}
	std::istream& operator>>(std::istream& is, Date& d){
		return d.read(is);
	}
}
