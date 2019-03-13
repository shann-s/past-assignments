#include <iostream>
#include <cstring>

#include "process.h"
#include "CString.h"

using namespace std;

int main(int argc, char* argv[])
{
	//cout << "argc=" << argc << "\n";
	//cout << "argv[0]=" << argv[0] << "\n";
	//for(int arg = 0; arg < argc; arg++){
	//	cout << "argv[" << arg << "] = --> " << argv[arg] << "<--\n";
	//}

	cout << "Command Line:";
	for (int arg = 0; arg < argc; arg++){
		cout << " " << argv[arg];
	}
	cout << "\n";

	if (argc == 1){
		cerr << "Insufficient number of arguments (min 1)\n";
		return 1;
	}

	cout << "Maximum number of characters stored : " << w1::MAX_CHAR << "\n";

	//max number stored: 3

	for (int arg = 1; arg < argc; arg++){
		process(argv[arg]);
	}

	return 0;

}