#ifndef SICT_AMAPERISHABLE_H__
#define SICT_AMAPERISHABLE_H__
#include <iostream>
#include "AmaProduct.h"
#include "Date.h"
namespace sict{
  class AmaPerishable: public AmaProduct{
  private:
	  Date expiry_;
  public:
	  AmaPerishable();
	  AmaPerishable(char fT = 'P');
	  const Date& expiry()const;
	  void expiry(const Date &value);
	  std::fstream& store(std::fstream& file, bool addNewLine = true)const;
	  std::fstream& load(std::fstream& file);
	  std::ostream& write(std::ostream& ostr, bool linear)const;
	  std::istream& read(std::istream& istr);

  };
}
#endif
