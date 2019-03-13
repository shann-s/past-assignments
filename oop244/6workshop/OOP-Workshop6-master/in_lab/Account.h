#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__
#include <iostream>
#include <cstring>
namespace sict{
  class Account{
    char name_[41];
    double balance_;
  public:
    Account();
    Account(double balance);
    Account(const char name[], double balance = 0.0);
    void display(bool gotoNewline = true)const;
	Account& operator+=(Account c);
	Account& operator=(Account cc);
	friend Account operator+(Account b, Account c);
	friend std::ostream& operator<<(std::ostream& os, const Account& rhs);
  };
  //std::ostream& operator<<(std::ostream& os, const Account& rhs);
 // Account& operator+(Account b, Account c);


};

#endif
