#include <iomanip>
#include <iostream>
#include <string>
#include <cstring>
#include "AmaProduct.h"
#include "general.h"
using namespace std;
namespace sict{

	AmaProduct::AmaProduct(char fT){
		if (fT == '\0'){
			fileTag_ = 'N';
		}
		fileTag_ = fT;
	}

	const char* AmaProduct::unit()const{
		return unit_;
	}

	void AmaProduct::unit(const char* value){
		strcpy(unit_, value);
	}

	fstream& AmaProduct::store(fstream& file, bool addNewLine)const{
		file << fileTag_ << "," << sku() << "," << name() << ","
			<< price() << "," << taxed() << "," << quantity() << "," << unit_ << "," << qtyNeeded();
		if (addNewLine == true){
			file << endl;
			return file;
		}
		else{
			return file;
		}
	}

	fstream& AmaProduct::store(fstream& file)const{
		file << fileTag_ << "," << sku() << "," << name() << ","
			<< price() << "," << taxed() << "," << quantity() << "," << unit_ << "," << qtyNeeded() << endl;
		return file;
	}

	fstream& AmaProduct::load(fstream& file){
		double pric;
		int q, qN;
		string nam, sk, uni;
		char t[10];
		bool tax;

		getline(file, sk, ',');
		getline(file, nam, ',');
		
		file >> pric >> t[0] >> tax >> t[1] >> q >> t[2];

		getline(file, uni, ',');

		file >> qN;

		taxed(tax);
		char * cstr = new char[sk.length() + 1];
		strcpy(cstr, sk.c_str());

		sku(cstr);
		price(pric);
		quantity(q);

		char * num = new char[nam.length() + 1];
		strcpy(num, nam.c_str());

		name(num);
		qtyNeeded(qN);

		char * un = new char[uni.length() + 1];
		strcpy(un, uni.c_str());

		unit(un);

		return file;
	}

	ostream& AmaProduct::write(ostream& os, bool linear) const{
		if (!err_.isClear()){
			os << err_.message();
			return os;
		}
		else{
			if (linear == true){
				os.fill(' ');
				os << left << setw(MAX_SKU_LEN) << sku() << "|" << left << setw(20) << name() << "|" << right << setw(7) << fixed << setprecision(2) << cost() << "|" <<
					right << setw(4) << quantity() << "|" << left << setw(10) << unit_ << "|" << right << setw(4) << qtyNeeded() << "|";
				return os;
			}if (linear == false){
				os << "Sku: " << sku() << endl;
				os << "Name: " << name() << endl;
				os << "Price: " << price() << endl;
				if (!taxed()){
					os << "Price after tax: N/A" << endl;
					os << "Quantity On Hand: " << quantity() << " " << unit_ << endl;
					os << "Quantity Needed: " << qtyNeeded() << endl;
					return os;
				}
				else {
					os << "Price after tax: " << cost() << endl;
					os << "Quantity On Hand: " << quantity() << " "<< unit_ <<  endl;
					os << "Quantity Needed: " << qtyNeeded();
					return os;
				}
			}
		}
		return os;
	}

	istream& AmaProduct::read(istream& istr){

		char sk[MAX_SKU_LEN + 1], nam[10], uni[11], tax[1];
		double pric;
		int qt, qtyNeed;
		cout << "Sku: ";
		istr >> sk;
		sku(sk);
		cout << "Name: ";
		istr >> nam;
		name(nam);
		cout << "Unit: ";
		istr >> uni;
		unit(uni);
		if (istr.fail()){
			istr.setstate(ios::failbit);
			return istr;
		}
		else{ 
			cout << "Taxed? (y/n): ";
			istr >> tax[0];
			if (tax[0] == 'y' || tax[0] == 'Y' || tax[0] == 'n' || tax[0] == 'N'){
				if (tax[0] == 'y' || tax[0] == 'Y'){
					taxed(true);
				}if (tax[0] == 'n' || tax[0] == 'N'){
					taxed(false);
				}
				cout << "Price: ";
				istr >> pric;
				price(pric);
				if (istr.fail()){
					const char* msg = "Invalid Price Entry";
					err_.message(msg);
					istr.setstate(ios::failbit);
					return istr;
				}
				else {
					cout << "Quantity On hand: ";
					istr >> qt;
					quantity(qt);
					if (istr.fail()){
						const char* msg = "Invalid Quantity Entry";
						err_.message(msg);
						istr.setstate(ios::failbit);
						return istr;
					}
					else{
						cout << "Quantity Needed: ";
						istr >> qtyNeed;
						qtyNeeded(qtyNeed);
						if (istr.fail()){
							const char* msg = "Invalid Quantity Needed Entry";
							err_.message(msg);
							istr.setstate(ios::failbit);
							return istr;
						}
						else{
							/*sku(sk);
							price(pric);
							name(nam);
							quantity(qt);
							qtyNeeded(qtyNeed);
							if (tax[0] == 'y' || tax[0] == 'Y'){
								taxed(true);
							}if (tax[0] == 'n' || tax[0] == 'N'){
								taxed(false);
							}*/
							err_.clear();
							return istr;
						}
					}
				}
			}
			else{
				const char* msg = "Only (Y)es or (N)o are acceptable";
				err_.message(msg);
				istr.setstate(ios::failbit);
				return istr;
			}
		}
	}
}
