#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>

class Order {

	string OrderCustomerName, OrderProductName;
	vector< string > itemList;
public:
	Order(vector<string> row);
	void Print();
	void Graph(fstream& os);
};

class OrderManager {

	vector < Order > orderlist;
public:
	OrderManager(vector < vector < string > > & csvData);
	void print();
	void graph(string& filename);
};