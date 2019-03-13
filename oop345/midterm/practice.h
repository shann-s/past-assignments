//rule of 5

#include <iostream>

using namespace std;

namespace p{

	class Array{
		int * a;
		int n;
		int b;
		void init(const Array& s){
			if (s.n > 0) {
				a = new (std::nothrow) int[s.n];
				if (a) {
					n = s.n;
					dummy = s.dummy;
					for (int i = 0; i < n; i++)
						a[i] = s.a[i];
				}
			}
			else {
				a = nullptr;
				n = 0;
				dummy = 0;
			}
		}

	public:

		Array(int no) : n(no), dummy(0){
			if (n > 0)
				a = new (std::nothrow) int[n];
			else
				a = nullptr;
		}
		~Array(){

			delete[] a;
		}
		Array(const Array&){

			init(s);
		}
		Array(Array&& rhs){

			a = rhs.a;
			n = rhs.n;
			b = rhs.b;
			rhs.a = nullptr;
			rhs.n = 0;
			rhs.b = 0;
		}
		Array operator= (const Array& rhs){

			if (this != &rhs){
				n = rhs.n;
				b = rhs.b;
				delete[] a;
				if (rhs.a != nullptr) {
					n = s.n;
					dummy = s.dummy;
					for (int i = 0; i < n; i++)
						a[i] = s.a[i];
				}
				else{
					a = nullptr;
				}
			}
			return *this;
		}

		Array&& operator=(Array&& rhs){

			if (this != &rhs){
				a = rhs.a;
				n = rhs.n;
				b = rhs.b;
				rhs.a = nullptr;
				rhs.n = 0;
				rhs.b = 0;
			}
			return *this;
		}
	};
};