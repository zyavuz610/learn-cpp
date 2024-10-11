#include <iostream>
using namespace  std;
/*
Koşullu İfadeler, if

Kullanımı: if

if (...koşul...) {
  koşul doğru olnuca çalışacak kodlar
}

*/
int main() {
  double not1,not2;
  cout<<"Not Girişi Yapınız(?not1 not2):";
  cin >> not1 >> not2;
  double ort = (not1+not2)/2;
  cout<< "Ortalama:"<< ort <<endl;
  if (ort < 50) {
    cout<<"Kaldı";
  }
  if(ort >= 50) {
    cout<<"Geçti";
  }
  cout<<endl;
}