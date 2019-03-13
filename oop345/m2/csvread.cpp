// csvread.cpp
//read a file
//
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;


void trim(string& f){

	while (f.empty() && f[0] == ' ') // delete leading spaces
	{
		f.erase(0, 1);
	}

	while(f.empty() && f[f.size() - 1] == ' ') //delete trailing spaces
		f.erase(f.size()-1, 1);
}
void csvPrint(vector < vector<string> >& csvData){

	cout << "number of lines= " << csvData.size() << "\n";
	cout << "print using indexs" << endl;
	for (size_t row = 0; row < csvData.size(); row++){

		cout << "row = " << row << " ";
		for(size_t column = 0; column < csvData[row].size(); column++){

			cout << "'" <<csvData[row][column] << "'";
		}
		cout << "\n";
	}

	cout << "print using iterators" << endl;
	for ( auto rowIt = csvData.begin(); rowIt != csvData.end(); rowIt++){

		for(auto columnIt = rowIt->begin(); columnIt != rowIt->end(); columnIt++){

			cout << "'" <<  *columnIt << "' ";
		}
		cout << "\n";
	}

	cout << "print using range-based for loop" << endl;
	//possible final exam quesiton
	for(auto row : csvData) {

		for(auto column : row){
			cout<< "'" << column << "' ";
		}
		cout << "\n";
	}
}
void csvReader(string& filename, char delim, vector< vector<string> >& cvData)
{
	fstream is(filename, ios::in);	
	if(!is.is_open())
		throw string("Cannot open file ") + filename;
	//read a line
	string line;
	while(getline(is, line)){
		auto cr = line.find('\r');
		if (cr != string::npos){
			line.erase(cr);
		}
		//cout << "line ==>" << line << "<==\n";

		vector< string > fields;
		string field;

		size_t i = 0;

		while(i < line.size()){

			if(line[i] != delim) {
				field += line[i];
			}else{ //found delimiter
				trim(field);
				fields.push_back(move(field)); //add field to list of fields
				field.clear();
			}
			i++;

		} // end of processing line

		if(! field.empty() ) {

			trim(field);
			fields.push_back(move(field)); //add field to our list of fields
		}
		cvData.push_back( move(fields) );
		fields.clear();
	}
	is.close();
}

int main(int argc, char* argv[])
{
	try{
		if (argc != 3){
			throw string("usage: ") + argv[0] + " file.cv delimiter-char";
		}
	string filename = argv[1]; //1st arg
	char delim = argv[2][0]; //1st char of second arg

	//open file

	vector< vector<string> > csvData;

	csvReader(filename, delim, csvData);
	csvPrint(csvData);
	}catch (string& e) {

		cerr << e << "\n";
	}
}
