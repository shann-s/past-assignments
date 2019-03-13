#ifndef SICT_ERRORMESSAGE_H__
#define SICT_ERRORMESSAGE_H__
#include <iostream>
namespace sict{

	class ErrorMessage{

	private:
		char* message_;
	public:
		ErrorMessage();
		ErrorMessage(const char* errorMessage_);
		ErrorMessage(const ErrorMessage& em) = delete;
		ErrorMessage& operator=(const ErrorMessage& em) = delete;
		ErrorMessage& operator=(const char* errorMessage);
		virtual ~ErrorMessage(){ delete [] message_;}
		void clear();
		bool isClear() const;
		void message(const char* value);
		const char* message() const;
		friend std::ostream &operator<<(std::ostream &os, ErrorMessage &val);
	};


}
#endif

