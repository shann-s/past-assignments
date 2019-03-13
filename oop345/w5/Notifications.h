//Notifications.h
#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
#include "Message.h"
namespace w5{

	class Notifications{
		size_t messageCount;
		Message* messageTable;
		int MAX_MESSAGE = 10;
	public:

		Notifications(); //- default constructor - empty
		Notifications(const Notifications& rhs); //- copy constructor
		Notifications& operator=(const Notifications&); //-copy assignment operator
		Notifications(Notifications&&); //- move constructor
		Notifications&& operator=(Notifications&&); //-move assignment operator
		~Notifications(); //- destructor
		void operator+=(const Message& msg); //- adds msg to the set
		void display(std::ostream& os) const;//- inserts the Message objects to the os output stream

	};

};