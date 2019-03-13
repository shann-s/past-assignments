#include <iostream>
#include <cstring>

using namespace std;

namespace w1{

const int MAX_CHAR = 3;
class CString{
	char data[MAX_CHAR + 1]; //+1 for \0
public:
	void Cstring( char* s)
	{
		//cout << "Cstring(" << s << ")\n";
		strncpy(data, s, MAX_CHAR);
		data[MAX_CHAR] = '\0';
	}
	void display(ostream& os)
	{
		os << data;
	}
};
ostream& operator<< (ostream& os, CString cs)
{
	static int count = 0;
	cout << count << ": ";
	count++;
	cs.display(os);

	return os;
}
} //namespace w1
void process( char * s){
	//cout << "process(" << s <<")\n";
	w1::CString cs(char * s);
	cout << cs << "\n";
}

int main(int argc, char* argv[])
{
	//cout << "argc=" << argc << "\n";
	//cout << "argv[0]=" << argv[0] << "\n";
	//for(int arg = 0; arg < argc; arg++){
	//	cout << "argv[" << arg << "] = --> " << argv[arg] << "<--\n";
	//}

	cout << "Command Line:";
	for(int arg = 0; arg < argc; arg++){
		cout << " " << argv[arg];
	}
	cout << "\n";

	if(argc == 1){
		cerr << "Insufficient number of arguments (min 10\n";
		return 1;
	}

	cout << "Maximum number of characters stored : " << w1::MAX_CHAR << "\n";

	//max number stored: 3
	
	for (int arg = 1; arg < argc; arg++){
		process ( argv[arg] );
	}

	return 0;

}

