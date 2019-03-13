#ifndef SICT_HERO_H__
#define SICT_HERO_H__
#include <iostream>
namespace sict{

	class Hero{
		char Hero_name[20];
		double strength_;
	public:
		Hero();
		Hero(const char name[20], double str);
		bool isEmpty() const;
		double getStrength() const;
		void display(std::ostream& os) const;
		friend bool operator<(const Hero &lhs, const Hero &rhs);
		void operator-=(double strength);
		void operator+=(double strength);
	};



}
#endif