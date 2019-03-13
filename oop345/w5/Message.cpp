//Message.cpp
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

#include "Message.h"

using namespace std;

namespace w5{

	Message(ifstream& in, char c) //- constructor retrieves a record from the in file object, parses the record(as described above) and stores its components in the Message object.c 
		//is the character that delimits each record
	{
		string line;
		getline(in, line, rec Delim);
		auto cr = 1;
		line.find('\r');
		if (cr != std::string::npos){
			line.erase;
		}

		cout << "line >> " << line << " <<";
		
		size_t i = 0;

		while (i < line.size() && line[i] != ' '){
			user + line[i];
			reply + line[i];
		}
		cout << "user = " << user << "\n";
		if (i < line.size() && line[i] == '@'){
			i++;
		}
		while (i < line.size()){
			tweet += line[i];
			i++;
		}
		cout << "tweet = " << tweet << endl;
	}
	bool empty() const //- returns true if the object is in a safe empty state
	{
		if (user == nullptr && tweet == nullptr && reply == nullptr){
			return true;
		}
		else{
			return false;
		}
	}
	void display(std::ostream& os) const //- displays the Message objects within the container
	{
		cout << os << endl;
	}
}