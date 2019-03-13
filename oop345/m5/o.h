#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

#include "i.h"

class Order {

	string OrderCustomerName, OrderProductName;
	vector< string > itemList;
public:
	Order(vector<string> row);
	Order() {};
	void Print();
	void Graph(fstream& os);
	std::string& getCustomerName() { return OrderCustomerName; }
	std::string& getProductName() { return OrderProductName; }
	size_t size() { return itemList.size(); }
	const string getItem(size_t i) { return itemList[i]; }
};

class OrderManager {

	vector < Order > orderlist;
public:
	OrderManager(vector < vector < string > > & csvData);
	void print();
	void graph(string& filename);
	void IntegrityCheck(ItemManager& im);

	size_t getSize() { return orderlist.size(); }
	Order* getOrder(size_t o) { return &orderlist[o]; }
};