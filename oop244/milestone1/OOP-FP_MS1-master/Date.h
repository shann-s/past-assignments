#ifndef SICT_DATE_H__
#define SICT_DATE_H__
#include <iostream>
#define NO_ERROR 0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR 3
#define DAY_ERROR 4
namespace sict{



  class Date{
  private:
    int value()const;
	void errCode(int errorCode);
  public:
	  int year_;
	  int mon_;
	  int day_;
	  int readErrorCode_;
	  Date();
	  Date(int year_, int mon_, int day);
	  bool operator==(const Date& D)const;
	  bool operator!=(const Date& D)const;
	  bool operator<(const Date& D)const;
	  bool operator>(const Date& D)const;
	  bool operator<=(const Date& D)const;
	  bool operator>=(const Date& D)const;
	  bool bad()const;
	  int errCode()const;
	  int mdays()const;
	  std::istream& read(std::istream& istr);
	  std::ostream& write(std::ostream& ostr)const;
  };
	std::ostream& operator<<(std::ostream& os, Date const &d);
	std::istream& operator>>(std::istream& is, Date &d);

}
#endif