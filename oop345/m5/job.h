//job.h
#pragma once
#include "o.h"

class Job : public Order{
	vector < bool > install;
public:
	Job(){

	}

	Job(Order *o) : Order(*o) {
		install.resize( size() ); //allocate space
		for (size_t i = 0; i < size(); i++){
			install[i] = false; //initiate to false (not installed).
		}
	}

	bool installed(size_t i) { return install[i]; }
	void Installed(size_t i, bool value) { install[i] = value; }
};