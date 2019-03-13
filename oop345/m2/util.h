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
