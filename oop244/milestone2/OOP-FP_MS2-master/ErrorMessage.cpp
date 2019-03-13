#include "ErrorMessage.h"
#include <cstring>
#include <iostream>
namespace sict{

	ErrorMessage::ErrorMessage(){
		message_ = nullptr;
	}

	ErrorMessage::ErrorMessage(const char* errorMessage_){
		message_ = nullptr;
		message(errorMessage_);
	}

	const char* ErrorMessage::message()const{
		return message_;
	}

	void ErrorMessage::message(const char* value){
		delete[] message_;
		int len = 0;
		len = strlen(value);
		message_ = new char[len + 1];
		strcpy(message_, value);
	}

	ErrorMessage& ErrorMessage::operator=(const char* errorMessage){
		delete[] message_;
		int len = 0;
		len = strlen(errorMessage);
		message_ = new char[len + 1];
		strcpy(message_, errorMessage);
		return *this;
	}

	void ErrorMessage::clear(){
		delete[] message_;
		message_ = nullptr;
	}

	bool ErrorMessage::isClear() const{

		if (message_ == nullptr){
			return true;
		}
		else{
			return false;
		}
	}

	std::ostream &operator<<(std::ostream &os, ErrorMessage &val){
		if (val.isClear()){
			return os;
		}
		else {
			return os << val.message_;
		}
	}

	//ErrorMessage::~ErrorMessage() {
	//		delete[] message_;
	//}

}
