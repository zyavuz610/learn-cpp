#include <iostream>
using namespace  std;

int main() {
  double not1,not2;
  cout<<"Not Girişi Yapınız(?not1 not2):";
  cin >> not1 >> not2;
  double ort = (not1+not2)/2;
  cout<< "Ortalama:"<< ort <<endl;
  bool k1 = ort < 50;
  bool k2 = ort >= 50;
  if (k1) {
    cout<<"Kaldı";
  }
  if(k2) {
    cout<<"Geçti";
  }
  cout<<endl;
}

/*
eşitlik veya tersi
  ==, eşit ise
  !=, eşit değil ise
büyüklük, küçüklük
  <, <=, >, >=
*/