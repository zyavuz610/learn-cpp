// C++ 104 - Değişkenler ve Değişken İsimlendirme Kuralları (Variables)
#include <iostream>
using namespace std;

/*
Değişkenler, 
  içeriği değiştirilebilen bellek bölgelerinin sembolik temsili
*/

int main() {
  int sayi1;
  sayi1 = 10;
  cout << "Değişken İçeriği:";
  cout << sayi1 << endl << "\n";
  sayi1 = 20;
  cout << "Değişken Yeni İçeriği:";
  cout << sayi1;
  
  cout << endl;
  
  float sayi2;
  sayi2 = 10.2;
  cout << "Değişken İçeriği:";
  cout << sayi2 << endl << "\n";
  sayi2 = -21.14;
  cout << "Değişken Yeni İçeriği:";
  cout << sayi2;
  /*Değişken İsimlendirme Kuralları
      * ingilizcedeki alfanumerik karakterler kullanılabilir. a-z,A-Z,0-9
      * _ kullanılabilir, diğer özel karakterler kullanlamaz.
      * değişken isminin ilk karakteri sayı olamaz
      * c++ için özel anlam ifade eden kelimeler (keywords) değişken ismi olamaz (int, float, if, else, return, for, while)

Örnek:
 sayi1, OK
  sayi_1, OK 
  sayı 1, HATA
  1sayi, HATA  
  A, OK
  a, OK
  _sayi1, OK
  _, OK
  __sayi, OK
  num__ber, OK
  birinci_sayi
*/
}