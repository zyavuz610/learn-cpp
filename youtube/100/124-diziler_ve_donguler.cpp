/*
Temel C++ programlama (1xx)
      + kurulum, söz dizimi ve basit kurallar
      + değişkenler ve operatörler
      + kullanıcı ile etkileşim girdi, çıktı
      + koşul ifadeleri, if, else
      + döngü ifadeleri, for, while
      - diziler
      2D diziler ve iç içe döngüler, koşul ifadeleri
      fonksiyonlar ve modüler programlama
      pointer kavramı
      dosya işlemleri
*/
#include <iostream>
using namespace std;
int main() {
  //          0 1 2 3 4, indis (index)
  int a[5] = {1,2,3,4,5};  // 5 elemanlı tam sayı dizisi
  int a2=5;    // tek bir değişken
  cout<<"ilk eleman:"<<a[0]<<endl; // dizi elemanlarına erişim
  cout<<"son eleman:"<<a[4]<<endl; // dizi elemanlarına erişim
  a[0] = 10;  // dizi elemanlarını güncelle
  a[2] = 20;
  cout<<"Dizi Elemanları: "
      << a[0] <<", "
      << a[1] <<", "
      << a[2] <<", "
      << a[3] <<", "
      << a[4] <<endl;
  float f[5] = {1.0,2.0,3.5}; // ilk değer verilmeyen indislere 0 değeri atanır
  string s[3] = {"zafer","yavuz","ktü"};
  int b[] = {1,2,3,4,5,6}; // 6 değer verildiği için 6 elemanlı dizi tanımlanmış olur
}