// util.h
#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;


void trim(string& f);
void csvPrint(vector < vector<string> >& csvData);
void csvReader(string& filename, char delim, vector< vector<string> >& cvData);

bool validTaskname(string& t);
bool validSlotName(string& t);

bool validItemname(string& t);
bool validItemSequence(string& t);

bool validOrderCustomerName(string& t);

bool validOrderProductName(string& t);