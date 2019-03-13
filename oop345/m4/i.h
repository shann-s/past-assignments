#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

class Item {

	string itemName, itemInstallTask, ItemRemoverTask, itemSequence, itemDescription;
public:
	Item(vector<string> row);
	void Print();
	void Graph(fstream& os);
	std::string& getItemName() { return itemName; }
	std::string& getItemInstallerTask() { return iteminstallerTask; }
	std::string getItemRemoverTask() { return itemRemoverTask; }
};

class ItemManager {

	vector < Item > itemlist;
public:
	ItemManager(vector < vector < string > > & csvData);
	void print();
	void graph(string& filename);
	void IntegrityCheck(TaskManager& tm);
	Item* FindItem(std::string& name);
};