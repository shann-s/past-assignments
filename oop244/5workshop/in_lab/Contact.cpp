#include <cstring>
#include <iostream>
#include "Contact.h"
using namespace std;

namespace sict{

  void Contact::display()const{
    //display the name and go to new line
	  cout << name_ << endl;

    // loop through elements of phoneNumber_ up to _noPN and display them one by one
	  if (phoneNumber_[0].isEmpty()){

	  }
	  for (int i = 0; i < _noPN; i++){
		  phoneNumber_[i].display();
	  }

    // draw a 40 char line using '-' and go to new line
	  for (int i = 0; i < 40; i++){
		  cout << "-";
	  }
	  cout << endl;

  }

  void Contact::read(){
    cout << "Contact Name: ";
    cin.getline(name_, 41, '\n');
    cout << "Please enter " << _noPN << " phone numbers: " << endl;
    for (int i = 0; i < _noPN; i++){
      cout << i + 1 << ": ";
      phoneNumber_[i].read();
    }
  }

  bool Contact::isEmpty()const{
    return phoneNumber_ == nullptr;
  }

  void Contact::setEmpty(){
    name_[0] = 0;
    _noPN = 0;
    phoneNumber_ = nullptr;// same as phoneNumber_ = (PhoneNumber*)0;
  }
	Contact::Contact(){
		setEmpty();
	}

	Contact::Contact(const char* name, int Pnumber){
		phoneNumber_ = nullptr;
		phoneNumber_ = new PhoneNumber[Pnumber];
		
		strncpy(name_, name, 40);
		name_[40] = '\0';
		_noPN = Pnumber;
	}

	Contact::~Contact(){
		delete [] phoneNumber_;
		phoneNumber_ = nullptr;

	}
}
