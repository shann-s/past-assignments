#include <iostream>
#include "Enrollment.h"
#include <iomanip>
#include <cstring>
using namespace std;
using namespace sict;
namespace sict{
	bool Enrollment::isValid()const{
		if (name_[0] != '\0' && code_[0] != '\0' && year_ >= 2015 && semester_ > 0 && semester_ < 4 && slot_ > 0 && slot_ < 6) {
			return true;
		}
		else {
			return false;
		}
	}
	//return name_ && name_[0];
	void Enrollment::setEmpty(){
		name_[0] = 0;
		code_[0] = 0;
		year_ = 0;
		semester_ = 0;
		slot_ = 0;
		enrolled_ = false;
	}

	bool Enrollment::isEnrolled() const{
		return enrolled_;
	}

	void Enrollment::display(bool nameOnly)const{
		if (isValid()){
			cout << name_;
			if (!nameOnly){
				cout << endl << code_ << ", Year: " << year_ << " semester: " << semester_ << " Slot: " << slot_ << endl;
				cout << "Status: " << (isEnrolled() ? "E" : "Not e") << "nrolled." << endl;
			}
		}
		else{
			cout << "InisValid enrollment!" << endl;
		}
	}

	void Enrollment::set(const char* name, const char* code, int year, int semester, int time, bool enrolled){
		if (name&& code&&name[0] != '\0' && code[0] != '\0' && year >= 2015 && semester > 0 && semester < 4 && time > 0 && time < 6){
			strcpy(name_, name);
			strcpy(code_, code);
			year_ = year;
			semester_ = semester;
			slot_ = time;
			enrolled_ = false;
			if (enrolled == true) {
				enrolled_ = true;
			}
		}
		else if (enrolled_ == false){
			enrolled = false;
		}
		else{
			setEmpty();

		}
	}

	bool Enrollment::hasConflict(const Enrollment &other) const {
		if (year_ == 0 && other.year_ == 0 && semester_ == 0 && other.semester_ == 0 && slot_ == 0 && other.slot_ == 0) {
			return false;
		}
		else if (year_ == other.year_ && semester_ == other.semester_ && slot_ == other.slot_){
			return true;
		}
		else{
			return false;
		}
	}
	Enrollment::Enrollment(){
		setEmpty();
	}
	Enrollment::Enrollment(const char* name, const char* code, int year, int semester, int time){
		set(name, code, year, semester, time);
			/*if (name &&code&&name[0] == '\0' && code[0] == '\0' && year == 0 && semester == 0 && time == 0){
			setEmpty();
		}
		else{
			strcpy(name_, name);
			strcpy(code_, code);
			year_ = year;
			semester_ = semester;
			slot_ = time;

		}*/
	}
}

