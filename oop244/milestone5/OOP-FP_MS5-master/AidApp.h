#ifndef SICT__AidApp_H_
#define SICT__AidApp_H_
#include <iostream>
#include "Product.h"
#include "AmaProduct.h"
#include "AmaPerishable.h"
#include <fstream>

namespace sict{
	class AidApp : public AmaPerishable{
	private:
		//variables

		char filename_[256];
		Product* product_[MAX_NO_RECS];
		std::fstream datafile_;
		int noOfProducts_;

		//constructor
		AidApp(const char* filename);

		//functions
		void pause()const;
		int menu();
		void loadRecs();
		void saveRecs();
		void listProducts()const;
		int SearchProducts(const char* sku)const;
		void addQty(const char* sku);
		void addProduct(bool isPerishable);
		int run();
	public:

	};
}

#endif