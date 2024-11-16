/*
Temel C++ programlama (1xx)
  + kurulum, söz dizimi ve basit kurallar
  + değişkenler ve operatörler
  + kullanıcı ile etkileşim girdi, çıktı
  + koşul ifadeleri, if, else
  + döngü ifadeleri, for, while
  + diziler
  + 2D diziler ve iç içe döngüler, diğer koşul ifadeleri
  - fonksiyonlar ve modüler programlama
  pointer kavramı
  dosya işlemleri
*/
#include <iostream>
using namespace  std;

void yaz(int n){
  cout<<"Sonuç:"<<n<<endl;
}

void toplam_yaz(int n1,int n2){
  int toplam;
  toplam = n1+n2;
  cout <<n1<<"+"<<n2<<" = " 
       <<toplam<<endl;
}

void yyYaz(int year){
  // year = 1701
  int yy=0;
  if (year%100 == 0){
    yy = year/100;
  }
  else{
    yy = year/100 +1;
  }
  cout<<year<<" => "<<yy<<endl;
}

int main() {
  yaz(5);
  yaz(50);
  yaz(45);
  toplam_yaz(3,6);
  toplam_yaz(30,61);
  yyYaz(1701);
  yyYaz(1800);
}