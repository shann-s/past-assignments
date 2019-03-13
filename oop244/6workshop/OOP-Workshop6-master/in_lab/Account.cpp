#include <iomanip>
#include <cstring>
#include "Account.h"
using namespace std;
namespace sict{
  Account::Account(){
    name_[0] = 0;
    balance_ = 0;
  }

  Account::Account(double balance){
    name_[0] = 0;
    balance_ = balance;
  }

  Account::Account(const char name[], double balance){
    strncpy(name_, name, 40);
    name_[40] = 0;
    balance_ = balance;
  }


  void Account::display(bool gotoNewline)const{
    cout << (name_[0] ? name_: "No Name") << ": $" << setprecision(2) << fixed << balance_;
    if (gotoNewline) cout << endl;
  }

  Account& Account::operator+=(Account c){
	  balance_ += c.balance_;
	  return *this;
  }

  Account& Account::operator=(Account cc){
	  strcpy(name_, cc.name_);
	  if (cc.balance_ > 1){
		  balance_ = cc.balance_;
	  }
	  return *this;
  }

  Account operator+(Account b, Account c){
	  Account n;
	  n.name_[0] = 0;
	  n.balance_ += b.balance_;
	  n.balance_ += c.balance_;
	  return n;
  }

  std::ostream& operator<<(std::ostream& os, const Account& rhs){
	  return os << (rhs.name_[0] ? rhs.name_ : "No Name") << ": $" << setprecision(2) << fixed << rhs.balance_;
  }
}
