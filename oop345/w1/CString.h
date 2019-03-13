#ifndef W1_CSTRING_H__
#define W1_CSTRING_H__
#include <iostream>
#include <cstring>
#include "process.h"
namespace w1{

	const int MAX_CHAR = 3;

	class CString{
		char data[MAX_CHAR + 1]; //+1 fpr null byte
	public:
		CString(char * s);
		void display(std::ostream& os);
	};
	std::ostream& operator<<(std::ostream& os, CString cs);
}
#endif