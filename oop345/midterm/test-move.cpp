// GB simple code to demonstrate:
//   1. copy constructor         (deep copy)
//   2. assignment operator      (deep copy)
//   3. move constructor         (no deep copy, move the pointers)
//   4. move assignment operator (no deep copy, move the pointers)
//   5. destructor

#include <iostream>
#include <string>
using namespace std;

template <typename T>
  class X {
    size_t  size;
    T*      data;
  public:
    ~X()                            // destructor
    { 
      print("dtor"); 
      if(data) delete [] data; 
    }
  
    X() 
      : size(0), data(nullptr)
    { 
      print("ctor"); 
    }
  
    X(size_t s) 
      : size(s), data(new T[size])
    {
      print("ctor"); 
    }
  
    void print() const 
    { 
       cout << "size = " << size << " elements @ " << sizeof(T) << " Bytes each = " << size * sizeof(T) * 1e-6 << " MB\n"; 
    }
  
    void print(const char* txt) const { cout << txt << " "; print(); }
  
    X(X& rhs)                       // C++ copy ctor
      : size(0), data(nullptr) // must do this or operator= might segfault deleting garbage
    {
      *this = rhs;    // use assignment op to do the copy
       print("X(X& rhs)");
    }
  
    X& operator=(const X& rhs)      // C++ assigment operator
    {
      if(this != &rhs) {
        if(data) {
          print("copy =op deleting ");
          delete [] data;    // 'if(data)' optional
        }
        size = rhs.size;
        data = new T[size];
        print("deep copy of ");
        for(size_t i = 0; i < size; i++)   // deep copy
          data[i] = rhs.data[i];
      }
      print("X& operator= (const X& rhs)");
      return *this;
    }
  
    X(X&& rhs)                      // C++11 move constructor
      : size(rhs.size), data(rhs.data) // move pointers
    {
      rhs.data = nullptr;           // zombie
      rhs.size = 0;
      print("X(X&& rhs)");
    }
  
    X&& operator=(X&& rhs)          // C++11 move assignment operator
    {
      if(this != &rhs) {
        if(data) {
          print("move =op deleting ");
          delete [] data;    // 'if(data)' optional
        }
        data = rhs.data;            // move pointers
        size = rhs.size;
        rhs.data = nullptr;         // zombie
        rhs.size = 0;
      }
      print("X&& operator= (X&& rhs)");
      return std::move(*this);
    }
   
  };

X<float> x(1 * 125 * 100000);
X<float> y(2 * 125 * 100000);

int main(int argc, char**argv)
{
  cout << "x=x\n";
  x = x;
  cout << "x=y\n";
  y = x;

  cout << "X w(x)\n";
  X<float> w(y);
  w.print("w ");
  x.print("x ");

  cout << "X z(std::move(x))\n";
  X<float> z( std::move(x) );
  z.print("z ");
  x.print("x ");

  cout << "x = std::move(z);\n";
  x = std::move(z);
  x.print("x ");
  z.print("z ");

  cout << "z = std::move(x);\n";
  z = std::move(x);
  x.print("x ");
  z.print("z ");

  cout << "x = std::move(z);\n";
  x = std::move(z);
  x.print("x ");
  z.print("z ");
  
  return 0;
}
