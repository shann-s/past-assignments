#ifndef SICT_AMAPRODUCT_H__
#define SICT_AMAPRODUCT_H__
#include <iostream>
#include "Product.h"
#include "ErrorMessage.h"

namespace sict{
  class AmaProduct : public Product{

  private:
	  char fileTag_;
	  char unit_[11];
	  friend class AmaPerishable;
  protected:
	  ErrorMessage err_;
  public:
	  AmaProduct(char fT = 'N');
	  const char* unit()const;
	  void unit(const char* value);
	  std::fstream& store(std::fstream& file)const;
	  std::fstream& store(std::fstream& file, bool addNewLine)const;
	  std::fstream& load(std::fstream& file);
	  std::ostream& write(std::ostream& os, bool linear)const;
	  std::istream& read(std::istream& istr);
  };
}
#endif


