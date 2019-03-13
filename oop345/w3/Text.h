#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

namespace w3{

	class Text{
		std::string* LineTable;
		std::size_t count;
	public:

		std::size_t size();
		~Text();
		Text(const Text& rhs);
		Text(Text&& rhs);
		Text& operator= (const Text rhs);
		Text& operator*= (Text&& rhs);
		Text(char* filename);
		void print();
		Text();
	};
}