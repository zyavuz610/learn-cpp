/*
Koşul Operatörü
  ? :
  deger = (_koşul_) ? doğru ise : yanlış ise;
*/

#include <iostream>
using namespace  std;

int main() {
  int sinav1 = 45;
  int sinav2 = 35;
  float ag1 = 0.40; // %40
  float ag2 = 0.60; // %60
  float ort = ag1*sinav1 + ag2*sinav2;
  string sonuc;
  sonuc = (ort >= 50) ? "Geçti" : "Kaldı";
  /*
  if(ort >= 50){
    sonuc="Geçti";
  }
  else{
    sonuc="Kaldı";
  }
  */
  cout<<sonuc<<endl;
}