#include <iostream>
#include <cstring>     // memcpy
using namespace std;

template <class T>
class X {
  size_t s;
  T*     b;
public:
  void print(string label) const
  {
    cout << (void*) this << " " << label << ": " << (void*) b << "  " << (s? " has brains": " is a zombie") << "\n";
  }
  X()
    : s(0), b(nullptr)  // It's a 'zombie'
  {}

  X(size_t size)
    : s(size), b(nullptr)
  {
    if(s) {
      b = new T[s];  // It now has brains
    }
  }


  X(const X& rhs)
    : s(rhs.s), b(nullptr)
  {
    if(s) {
      b = new T[s];
      memcpy(b, rhs.b, sizeof(T) * s); // deep copy
    }
    print("copy ctor this");
    rhs.print("rhs");
  }

  X& operator= (const X& rhs)
  {
    if(this != &rhs) {
      delete [] b;
      b = nullptr;

      s = rhs.s;
      if(s) {
        b = new T[s];
        memcpy(b, rhs.b, sizeof(T) * s); // deep copy
      }
      print("copy assignment op this");
      rhs.print("rhs");
    }

    return *this;
  }

  X(X&& rhs)
    : s(rhs.s), b(rhs.b)   // steal brains
  {
    // turn rhs into a 'zombie'
    rhs.s = 0;
    rhs.b = nullptr;
    print("move ctor this");
    rhs.print("rhs");
  }

  X&& operator= (X&& rhs)
  {
    if(this != &rhs) {
      delete [] b;
      b = nullptr;

      s = rhs.s;  // steal 'brains'
      b = rhs.b;

      // turn rhs into a 'zombie'
      rhs.s = 0;
      rhs.b = nullptr;
      print("move assignment op this");
      rhs.print("rhs");
    }

    return move(*this);
  }

};

 int main(int argc, char*argv[])
 {
   X<double> zombie;
   zombie.print("zombie");
   X<double> brains( 3ll*1000000000l/sizeof(double) );
   brains.print("brains");

   X<double> xZombie(zombie);
   xZombie.print("xZombie");
   X<double> xBrains(brains);
   xBrains.print("xBrains");

   X<double> x1, x2;
   x1.print("x1");
   x2.print("x2");

   x1 = zombie;
   x1.print("x1");
   x2 = brains;
   x2.print("x2");

   x1 = x2;
   x1.print("x1");

   X<double> x3 = move(x2);   // move ctor
   x3.print("x3");
   x2.print("x2");
  
   // give the brains back to x2
   x2 = move(x3);   // move operator=
   x3.print("x3");
   x2.print("x2");

   X<double>* p = new X<double>;
   *p = move(x2);
   p->print("*p");
   x2.print("x2");
   delete p;

   return 0;
 }
