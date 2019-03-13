#include <iostream>
#include <cstring>
#include "process.h"
#include "CString.h"

using namespace std;

	void process(char * s){
		cout << "process(" << s <<")\n";
		w1::CString cs(char * s);
		cout << cs << "\n";
	}