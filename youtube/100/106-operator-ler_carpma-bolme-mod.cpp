// C++ 106 - Aritmetik Operatörler 2 | Çarpma, Bölme ve Mod (Kalan Bulma) İşlemleri

#include <iostream>
using namespace std;
int main() {
  int x,y;
  x=10;   y=3;
  int z;
  z = x%y;
  cout << "Sonuç:" << z << endl;

  //----------------------------
  int n = 12547;
  int kalan = n % 10;
  cout << n
       << " sayısının birler basamağındaki rakam: "
       << kalan 
       << endl;
}

/*
= operatörü, (atama)
Aritmetik Operatörler: +,-, *, /, % (mod alma)
*/