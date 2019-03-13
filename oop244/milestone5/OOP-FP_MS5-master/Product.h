#ifndef SICT__Product_H_
#define SICT__Product_H_

#include <iostream>
#include "general.h"
#include "Streamable.h"

namespace sict{

	class Product : public Streamable{

	private:

		char sku_[MAX_SKU_LEN + 1]; //Character array, MAX_SKU_LEN + 1 characters long
									//This character array holds the SKU(barcode) of the items as a string.
		char* name_;					//Character pointer. This character pointer points to a dynamic string that holds the name of the Product
		double price_;				//Holds the Price of the Product
		bool taxed_;				//This variable will be true if this Product is taxed
		int quantity_;				//Holds the on hand (current) quantity of the Product.
		int qtyNeeded_;				//Holds the needed quantity of the Product.

	public:

		~Product();
		Product();
		Product(char* sku, char* name, bool taxed, double price, int qtyNeeded);
		Product(const char* theSku, const char* theName);
		Product(const Product& t);
		Product& operator=(const Product& t);
		//virtual ~Product();
		//setters
		void sku(char* sk);
		void price(double price);
		void name(char* name);
		void taxed(bool taxed);
		void quantity(int quantity);
		void qtyNeeded(int qtyNeeded);
		//getters
		const char* sku() const;
		double price() const;
		const char* name() const;
		bool taxed() const;
		int quantity() const;
		int qtyNeeded() const;
		bool isEmpty() const;
		double cost() const;
		//member operator overload

		bool operator==(char const* val) const;
		int operator+=(int val);
		int operator-=(int val);

		//non-member operator and IO
	};

	double operator+=(double& lhs, const Product& rhs);
	std::ostream& operator<<(std::ostream& os, const Product& rhs);
	std::istream& operator>>(std::istream& is, Product& rhs);
}
#endif