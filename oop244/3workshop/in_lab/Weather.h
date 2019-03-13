// compilation safegaurds

/*Weather.h*/
namespace sict{
	// sict namespace
	class Weather{
		// member variables
		char date[7];
		double high;
		double low;
	public:
		// member function
		void set(const char*, double, double);
		void display() const;
	};
}