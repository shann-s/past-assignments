//Notifications.cpp
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include "Notifications.h"
using namespace std;

namespace w5{

	Notifications::Notifications() //- default constructor - empty
	{
		messageCount = 0;
		messageTable = nullptr;

	}
	Notifications(const Notifications& rhs) //- copy constructor
	{
		if (rhs.messageCount != 0){
			messageTable = new message[MAX_MESSAGE];
			messageCount = rhs.messageCount;
			for (size_t i = 0; i < messageCount; i++){
				messageTable[i] = rhs.messageTable[i];
			}
		}
	}
		Notifications& operator=(const Notifications&) //-copy assignment operator
		{
			if (this != &rhs) {
				if (messageCount == 0 && rhs.messageCount == 0){
					//if we are zombie and rhs is a zombie
				}
				else
					//we are zombie rhs has brains
				if (messageCount == 0 && rhs.messageCount != 0){
					messageTable = new Message[MAX_MESSAGE];
					messageCount = rhs.messageCount;
					for (size_t i = 0; i < messageCount; i++){
						messageTable[i] = rhs.messageTable[i]
							;
					}

				else
				if (messageCount != 0 && rhs.messageCount == 0){
					//we have brains rhs is zombie
					delete[] messageTable;
					messageTable = nullptr;
					messageCount = 0;
				}
				else if(messageCount != 0 && rhs.messageCount != 0){

					}
				}
			}
		}
		Notifications(Notifications&& rhs)
			: messageCount(rhs.messageCount), messageTable(rhs.messageTable) {}//- move constructor
		Notifications&& operator=(Notifications&&) //-move assignment operator
		{
			if (this != &rhs){
				delete[] messageTable;
				messageCount = rhs.messageCount;
				messageTable = rhs.messageTable;
				rhs.messageCount = 0; 
				rhs.messageTable = nullptr;
			}
			return std::move(*this);
		}
		~Notifications()//- destructor
		{
			delete[] messageTable;

		}
		void operator+=(const Message& msg) //- adds msg to the set
		{
			if (messageCount == 0){
				messageTable = new Message[MAX_MESSAGE];
			}if (messageCount < MAX_MESSAGE){
				messageTable[messageCount] = msg;
				messageCount++;
			}
		}
		void display(std::ostream& os) const //- inserts the Message objects to the os output stream
		{
			for (size_t = 0; i < messageCount; i++){
				messageTable[i].display(os);
				os << "\n";
			}
		}
};