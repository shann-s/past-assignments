#include <iostream>
#include <ctype.h>
#include <fstream>
#include <cstdlib>

namespace w2{

	enum PassType { STUDENT_PASS, ADULT_PASS, PASS_COUNT };

	class Station{
		std::string name;
		unsigned passes[PASS_COUNT];

	public:
		Station();

		Station(std::fstream&);

		void set(const std::string& n, unsigned s, unsigned a);
		void update(PassType pt, int change);
		unsigned inStock(PassType pt) const;
		const std::string& getName() const;
		void update();
		void restock();
		void report();
		void save(fstream& os);
	};
}
