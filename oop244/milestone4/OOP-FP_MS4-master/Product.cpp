#include <iomanip>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#include "Product.h"
#include "general.h"
#include "Streamable.h"
using namespace std;
namespace sict{
	
	Product::Product(){
		sku_[0] = '\0';
		name_ = '\0';
		price_ = 0;			
		taxed_ = true;				
		quantity_ = 0;
		qtyNeeded_ = 0;
	}

	Product::Product(char* sku, char* name, bool taxed, double price, int qtyNeeded){
		quantity_ = 0;

		taxed_ = taxed;

		strcpy(sku_, sku);

		price_ = price;
		qtyNeeded_ = qtyNeeded;

		name_ = new char[strlen(name) + 1];
		strcpy(name_, name);
	}

	Product::Product(const char* theSku, const char* theName){
		name_ = new char[strlen(theName) + 1];
		strcpy(name_, theName);
		strcpy(sku_, theSku);
		price_ = 0;
		taxed_ = true;
		quantity_ = 0;
		qtyNeeded_ = 0;
	}

	Product::Product(const Product& t){
		strcpy(sku_, t.sku_);
		name(t.name_);
		price_ = t.price_;
		taxed_ = t.taxed_;
		quantity_ = t.quantity_;
		qtyNeeded_ = t.qtyNeeded_;
	}

	Product& Product::operator=(const Product& t){
		strcpy(sku_, t.sku_);
		name(t.name_);
		price_ = t.price_;
		taxed_ = t.taxed_;
		quantity_ = t.quantity_;
		qtyNeeded_ = t.qtyNeeded_;
		return *this;
	}


	//setters

	void Product::sku(char* sk){
		strcpy(sku_, sk);
	}
	void Product::price(double price){
		price_ = price;
	}
	void Product::name(char* name){
		name_ = new char[strlen(name) + 1];
		strcpy(name_, name);
	}
	void Product::taxed(bool taxed){
		taxed_ = taxed;
	}
	void Product::quantity(int quantity){
		quantity_ = quantity;
	}
	void Product::qtyNeeded(int qtyNeeded){
		qtyNeeded_ = qtyNeeded;
	}

	//getters

	const char* Product::sku() const{
		return sku_;
	}
	double Product::price() const{
		return price_;
	}
	const char* Product::name() const{
		return name_;
	}
	bool Product::taxed() const{
		return taxed_;
	}
	int Product::quantity() const{
		return quantity_;
	}
	int Product::qtyNeeded() const{
		return qtyNeeded_;
	}
	bool Product::isEmpty() const{
		if (sku_[0] == '\0' &&
		name_ == '\0' &&
		price_ == 0	&&		
		quantity_ == 0 &&
		qtyNeeded_ == 0){
			return true;
		}
		else {
			return false;
		}
	}
	double Product::cost() const{
		if (taxed_ == false){
			return price_;
		}
		else {
			return price_ * TAX;
		}
	}

	bool Product::operator==(const char* val){
		if (strcmp(sku_, val) == 0){
			return true;
		}
		else {
			return false;
		}
	}

	int Product::operator+=(int val){
		quantity_ = quantity_ + val;
		return quantity_; 
	}

	int Product::operator-=(int val){
		quantity_ = quantity_ - val;
		return quantity_;
	}

	double operator+=(double& lhs, const Product& rhs){
		double t = rhs.cost() * rhs.quantity();
		return lhs = lhs + t;
	}

	std::ostream& operator<<(std::ostream& os, Product& rhs){
		rhs.write(os, 1);
		return os;
	}

	std::istream& operator>>(std::istream& is, Product& rhs){
		rhs.read(is);
		return is;
	}

	/*Product::~Product(){
		delete [] name_;
		name_ = nullptr;
	}*/
}
