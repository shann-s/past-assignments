#include <iostream>
#include <cstring>
#include "CString.h"

using namespace std;

namespace w1{


	CString::CString(char* s)
	{
		cout << "Cstring(" << s << ")\n";
		strncpy(data, s, MAX_CHAR);
		data[MAX_CHAR] = '\0';
	}
	void CString::display(std::ostream& os)
	{
		os << data;
	}

	std::ostream& operator<< (std::ostream& os, CString cs)
	{
		static int count = 0;
		cout << count << ": ";
		count++;
		cs.display(os);

		return os;
	}
}