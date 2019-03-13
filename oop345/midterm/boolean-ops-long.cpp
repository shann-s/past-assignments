#include <iostream>
using namespace std;

template <typename T>
void bitprint(T v, int bits = 8*sizeof(T)) // sizeof(foo) returns number of bytes in foo.  * 8 to calculate bits
{
  for(int i = bits-1 ; i >= 0; i--) { // bits numbered from zero to bits-1
    // cout << (bool) (v & (1 << i));   // one line

    // T mask = 1 << i;                 // two line
    // cout << (bool) (v & mask);

    // six line
    T mask = 1;
    mask = mask << i;                   // a '1' in the bit we are interested in
    if(v & mask)                        // true if both bits are on
      cout << "1";                      // bit 'i' in v is on
    else 
      cout << "0";                      // bit 'i' in v is off
  }
}


int main(int argc, char**argv)
{
  int bits = 2;
  if(argc > 1) bits = atoi(argv[1]);

  // test bitprint
  uint8_t  ones8  = ~0; bitprint(ones8);  cout << "\n";
  ones8  = 255; cout<<"8 x 1's = ";      bitprint(ones8);    cout << "\n";
  ones8  = 37;  cout<<"37 = ";           bitprint(ones8);    cout << "\n";
  ones8  = 37;  cout<<"37 (6-bits) = ";  bitprint(ones8,6);  cout << "\n";
  ones8  = 256; cout<<"256 (8-bits) = "; bitprint(ones8);    cout << "\n";
  ones8  = 257; cout<<"257 (8-bits) = "; bitprint(ones8);    cout << "\n";

  cout << "\n";
  cout << "bits + power of 2\n";
  for (int i = 0; i < 8; i++ ) {
    ones8 = 1 << i;
    bitprint(ones8);
    cout << " <-- " << (int) ones8 << "\n";
  }
  cout << "\n";

  uint16_t ones16 = ~0; cout<<"16 x 1's = "; bitprint(ones16); cout << "\n";
  ones16 = 1024; cout<<" 1024 (16-bits) = "; bitprint(ones16); cout << "\n";
  ones16 = ~1024; cout<<"~1024 (16-bits) = "; bitprint(ones16); cout << "\n";
  uint32_t ones32 = ~0; cout<<"32 x 1's = ";  bitprint(ones32); cout << "\n";
  uint64_t ones64 = ~0; cout<<"64 x 1's = ";  bitprint(ones64); cout << "\n";
  cout << "\n";

  cout << "\nboolean OR: bit on if either bit is on.\n";
  // print first row
    cout << "|";
    for(int i = 0; i <  bits; i++) {
      cout << " ";
    }
    for(int i = 0; i < (1 << bits); i++) {
      bitprint(i, bits);
      cout << " ";
    }
    cout <<"\n";
  // print table
  for(int i = 0; i < (1 << bits); i++) {
    bitprint(i, bits);
    cout << " ";
    for(int j = 0; j < (1 << bits); j++) {
      bitprint(i|j, bits);
      cout << " ";
    }
    cout <<"\n";
  }

  cout << "\nboolean AND: bit on if both bits are on.\n";
  // print first row
    cout << "&";
    for(int i = 0; i <  bits; i++) {
      cout << " ";
    }
    for(int i = 0; i < (1 << bits); i++) {
      bitprint(i, bits);
      cout << " ";
    }
    cout <<"\n";
  // print table
  for(int i = 0; i < (1 << bits); i++) {
    bitprint(i, bits);
    cout << " ";
    for(int j = 0; j < (1 << bits); j++) {
      bitprint(i&j, bits);
      cout << " ";
    }
    cout <<"\n";
  }

  cout << "\nboolean XOR: bit on if bits are different.\n";
  // print first row
    cout << "^";
    for(int i = 0; i <  bits; i++) {
      cout << " ";
    }
    for(int i = 0; i < (1 << bits); i++) {
      bitprint(i, bits);
      cout << " ";
    }
    cout <<"\n";
  // print table
  for(int i = 0; i < (1 << bits); i++) {
    bitprint(i, bits);
    cout << " ";
    for(int j = 0; j < (1 << bits); j++) {
      bitprint(i^j, bits);
      cout << " ";
    }
    cout <<"\n";
  }
}
