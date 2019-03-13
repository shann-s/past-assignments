// compilation safegaurds

/*Weather.h*/

namespace sict {
	class Weather{
		// member variables
		char _date[7];
		double high;
		double _low;
	public:
		// member function
		void set(const char*, double, double);
		void display() const;
		const char* date() const;
		double low() const;
	};
}

