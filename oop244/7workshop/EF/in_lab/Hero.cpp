#include <iostream>
#include <cstring>
using namespace std;
#include "Hero.h"
namespace sict{

	Hero::Hero(){
		Hero_name[0] = '\0';
		strength_ = 110;
	}

	Hero::Hero(const char name[20], double str){
		if (name[0] == '\0' && str == 110){
			Hero_name[0] = '\0';
			strength_ = 110;
		}
		else {
			strcpy(Hero_name, name);
			strength_ = str;
		}
	}

	bool Hero::isEmpty() const{
		
		if (Hero_name[0] == '\0' && strength_ == 110){
			return true;
		}
		else{
			return false;
		}
	}

	double Hero::getStrength() const{
		
		if (Hero_name[0] != '\0' && strength_ != 110){
			return strength_;
		}
		else{
			return 0.0;
		}
	}

	void Hero::display(std::ostream& os) const{
		
		if (Hero_name[0] == '\0' && strength_ == 110){
		}
		else {
			os << Hero_name << " - " << strength_ << endl;
		}
	}

	bool operator<(const Hero &lhs, const Hero &rhs){

		if (lhs.strength_ < rhs.strength_){
			return rhs.strength_;
		}
		else {
			return 0;
		}
	}

	void Hero::operator-=(double strength){
		if (strength > strength_){
			strength_ = 0.0;
		}
		else {
			strength_ -= strength;
		}
	}

	void Hero::operator+=(double strength){
		strength_ += strength;
	}

}
