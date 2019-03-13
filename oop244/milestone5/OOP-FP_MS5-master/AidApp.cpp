#include <iomanip>
#include <iostream>
#include <string>
#include "AidApp.h"

using namespace std;
namespace sict{
	AidApp::AidApp(const char* filename){
		strcpy(filename_, filename);
		(*product_)->sku(nullptr);
		(*product_)->price(0);
		(*product_)->name(nullptr);
		(*product_)->taxed(nullptr);
		(*product_)->quantity(0);
		(*product_)->qtyNeeded(0);
		noOfProducts_ = 0;
		loadRecs();
	}

	void AidApp::pause()const{
		char temp;
		cout << "Press Enter to continue..." << endl;
		while (cin.get() != '\n'){
		}
	}

	int AidApp::menu(){
		int temp, t;
		cout << "Disaster Aid Supply Management Program" << endl;
		cout << "1- List products" << endl;
		cout << "2- Display product" << endl;
		cout << "3- Add non-perishable product" << endl;
		cout << "4- Add perishable product" << endl;
		cout << "5- Add to quantity of purchased products" << endl;
		cout << "0- Exit program" << endl;
		cout << "> ";
		cin >> temp;
		if (temp == 1 || temp == 2 || temp == 3 || temp == 4 || temp == 5 || temp == 0){
			cout << std::flush;
			return temp;
		}
		else{
			cout << std::flush;
			return -1;
		}
	}

	void AidApp::loadRecs(){
		int readIndex = 0;
		char c;
		datafile_.open ("data_open.txt", ios::in);
		if (datafile_.fail()){
			datafile_.clear();
			datafile_.close;
			datafile_.open("datawrite.txt", ios::out);
		}
		else{
			while (datafile_.good()){
				delete[] product_[readIndex];
				datafile_.get(c);
				if (c == 'P'){
					product_[readIndex] = new AmaPerishable;
				}
				if (c == 'N'){
					product_[readIndex] = new AmaProduct;
				}
				else{
					std::cin.ignore(256, ',');
					if (c == 'P'){
						AmaPerishable::load(datafile_);
					} 
					if (c == 'N'){
						AmaProduct::load(datafile_);
					}
					readIndex = readIndex + 1;
				}
			}
			readIndex = noOfProducts_;
			datafile_.close;
		}
	}

	void AidApp::saveRecs(){
		int i; 
		datafile_.open("datasave.txt", ios::out);
		for (i = 0; i < noOfProducts_; i++){
			datafile_ << product_[i]->sku();
			datafile_ << product_[i]->name();
			datafile_ << product_[i]->cost();
			datafile_ << product_[i]->quantity();
			datafile_ << product_[i]->qtyNeeded();
		}
		datafile_.close;
	}

	void AidApp::listProducts()const{
		int i;
		double tote;
		cout << " Row | SKU    | Product Name       | Cost  | QTY| Unit     |Need| Expiry" << endl;
		cout << "-----|--------|--------------------|-------|----|----------|----|----------" << endl;
		for (i = 0; i < noOfProducts_; i++){
			cout << setw(4) << right << i;
			cout << " | " << product_[i]->sku() << "|" << product_[i]->name() << "|" << product_[i]->cost() << "|" << product_[i]->quantity() << "|" << unit() << "|" << product_[i]->qtyNeeded() << "|" << expiry() << endl;
			tote += product_[i]->cost();
			if (i == 10){
				i = i + noOfProducts_;
			}
		}
		cout << "---------------------------------------------------------------------------" << endl;
		cout << "Total cost of support: $" << left << setprecision(2);
	}

	int AidApp::SearchProducts(const char* sku)const{
		int i;
		for (i = 0; i < noOfProducts_; i++){
			if (product_[i]->sku() == sku){
				return i;
			}
		}
		return -1;
	}

	void AidApp::addQty(const char* sku){
		int i, t;
		for (i = 0; i < noOfProducts_; i++){
			if (product_[i]->sku() == sku){
				cout << "Sku: " << product_[i]->sku() << endl;
				cout << "Name: " << product_[i]->name() << endl;
				cout << "Price: " << product_[i]->cost() << endl;
				cout << "Quantity: " << product_[i]->quantity() << endl;
				cout << "Quantity Needed: " << product_[i]->qtyNeeded() << endl;
				cout << "Please enter the number of purchased items: ";
				cin >> t;
				if (cin.fail()){
					cout << "Invalid quantity value! " << endl;
				}
				else if (t >= product_[i]->qtyNeeded() - product_[i]->quantity()){
					t += product_[i]->quantity();
					saveRecs();
					cout << "Updated!" << endl; 
				}
				else if (!t >= product_[i]->qtyNeeded() - product_[i]->quantity()){
					t -= product_[i]->qtyNeeded();
					cout << "Too many items; only" << product_[i]->qtyNeeded() << "is needed, please return the extra " << t << "items." << endl;
				}

			}
		}
		cout << "Not found!" << endl;
		cout << std::flush;
	}

	void AidApp::addProduct(bool isPerishable){
		char sk, name;
		double pric;
		bool tax;
		int qty, qtyN;
		if (isPerishable == true){
			product_[0] = new AmaPerishable;
			cout << "Sku: ";
			cin >> sk;
		}
	}
}