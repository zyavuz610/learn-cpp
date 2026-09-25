#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

int main() {
//  Çok Boyutlu Dizi
/*
    . Birden çok boyutlu dizler C++ tarafından desteklenmektedir
    . 2 boyutlu dizi - matris olarak adlandırılabilir
    . 2 den daha yüksek boyutlu diziler tanımlamak da mümkündür, genel ismi tensor olarak adlandırılır
      int matris1[20][20];   // veri yapılarında daha ayrıntılı görülecek
      int tensor[10][20][30];
      unsigned char rgb[3][512][512];   // 512x512 boyutlu renkli bir resim için kullanılabilir
*/

  int a[3][4] = {       // matrislere İLK DEĞER atama
   {0, 1, 2, 3} ,   //  satir 1 (index 0) 
   {4, 5, 6, 7} ,   //  satir 2 (index 1) 
   {8, 9, 10, 11}   //  satir 3 (index 2) 
  };
  int b[3][4] = {  
   {10, 11, 22, 43} ,   //  satir 1 (index 0) 
   {43, 51, 46, 47} ,   //  satir 2 (index 1) 
   {85, 98, 10, 71}     //  satir 3 (index 2) 
  };
  int c[3][4]={0};

  // matris toplamı
  for(int i=0;i<3;i++){
    for(int j=0;j<4;j++){
      c[i][j] = a[i][j] + b[i][j];  
      cout<<setw(4)<<c[i][j]; 
    }
    cout<<endl;
  }

  // matris çarpımı kodlayın (boyutlar uygun olmalı, kontrol edin)
  // transpozu kodlayın (kare matris için)
  // çıkarma kodlayın
  // matisin izini (trace) bulun (köşegen üzerindeki elemanların toplamı) (kare matris için)
  // matrisin alt ve üst üçgen bölgelerini ekrana yazın (kare matris için)

  return 0;
}
