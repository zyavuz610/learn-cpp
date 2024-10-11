#include <iostream>
using namespace std;
/*
Program: girdi -> işlem -> çıktı

çıktı: cout << ...
girdi: cin >> ...

tek değişken için girdi
çok değişken için girdi
arada boşluk olması
satırın tamamının okunması

*/
int main() {
  int i;
  string name;
  /*
  cout << "Bir sayı giriniz:";
  cin >> i;
  cout << "Girilen Değer:" << i << endl;*/

  cout << "Adınızı Giriniz:";
  //cin >> name;
  getline(cin,name);
  cout << "Merhaba " << name << endl;
  
  /*
  char c;
  cout << "Sayı ve İsim Giriniz:";
  cin >> i >> c >> name;
  cout << "Girilen değerler:" << endl
       << i << endl
       << c << endl
       << name <<endl;
*/
}