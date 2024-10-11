#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

// fonksiyonlara parametre olarak dizilerin verilmesi için kullanılacak fonk. lar
double OrtalamaBul(int dizi[], int boyut) {
  int i, top = 0;       
  double ort;         
  for (i = 0; i < boyut; i++) {
      top += dizi[i];
   }
   ort = double(top) / boyut;
   return ort;
}

double OrtalamaBul2(int dizi[5], int boyut) {
  int i, top = 0;       
  double ort;         
  for (i = 0; i < boyut; i++) {
      top += dizi[i];
   }
   ort = double(top) / boyut;
   return ort;
}

// pointer bölümünde anlatılacak
double OrtalamaBul3(int *dizi, int boyut) {
  int i, top = 0;       
  double ort;         
  for (i = 0; i < boyut; i++) {
      top += *(dizi+i);
   }
   ort = double(top) / boyut;
   return ort;
}

//---------------------------------------------------------------
// matrislerin fonksiyonlara parametre olarak verilmesi
/*

#define sutunSayisi 10
void fonksiyon(int matris[][sutunSayisi], int satirSayisi) {
  // Matrisin değerini değiştirebiliriz
  for (int i = 0; i < satirSayisi; i++) {
    for (int j = 0; j < sutunSayisi; j++) {
      matris[i][j] = i * j;
    }
  }
}
*/
//---------------------------------------------------------------
/*
// 10'arlı sayıları matris şeklinde yazıyoruz
  for(int x=0;x<5;x++){
    for(int i=0;i<10;i++){
      cout<<i;
    }
    cout<<endl;
  }
*/
//---------------------------------------------------------------

int main() {

    return 0;
}