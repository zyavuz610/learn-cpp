// C++ 105 - Aritmetik Operatörler 1 | Toplama ve Çıkarma

#include <iostream>
using namespace std;
/*
Aritmetik Operatörler
  + 
  -
  *
  /
  %
*/
int main() { 
  int a,b,c;
  a = 5;
  b = 6;
  c = a + b; /* c = 11  */
  cout << "Toplam:" << c << endl;

  // ilk değer ataması 
  float f1=5.5,f2=2.3,f3=0.0;
  /*
  float f1 = 5.5;
  float f2 = 2.3;
  float f3 = 0.0;
  */
  f3 = f1 - f2;
  cout << "Fark: " << f3 << "\n";
}