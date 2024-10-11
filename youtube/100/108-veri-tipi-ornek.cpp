#include <iostream>
using namespace  std;

// bool, char, short int, long double
int main() {
  bool b = true;
  b = 3;
  cout << "b:" << b << endl;

  char c = 'A';
  c = c+32;
  cout << c << ":" << int(c) << endl;

  unsigned short si = 1000; // 2 byte
  si = si * 66;
  cout << "si:" << si << endl;

  long double ld = 1000.0;
  ld = ld * ld;
  cout << "ld:" << ld << endl;
  
  ld = ld * ld;
  cout << "ld:" << ld << endl;
  
  ld = ld * ld;
  cout << "ld:" << ld << endl;
  
  ld = ld * ld;
  cout << "ld:" << ld << endl;
  
  ld = ld * ld;
  ld = 1.0e+300;
  cout << "ld:" << ld << endl;

  // inf ve nan
  double posinf = 5.0 / 0.0 ; // pozitif sonsuz
  cout << posinf << '\n';  // inf

  double neginf = -5.0 / 0.0 ; // negatif sonsuz
  cout << neginf << '\n'; // -inf

  double nan1 = 0.0 / 0.0 ; // not a number (tanımsız)
  cout << nan1 << '\n'; // nan

  }