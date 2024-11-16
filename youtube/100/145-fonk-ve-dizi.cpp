/*
Temel C++ programlama (1xx)
  + kurulum, söz dizimi ve basit kurallar
  + değişkenler ve operatörler
  + kullanıcı ile etkileşim girdi, çıktı
  + koşul ifadeleri, if, else
  + döngü ifadeleri, for, while
  + diziler
  + 2D diziler ve iç içe döngüler, diğer koşul ifadeleri
  + fonksiyonlar ve modüler programlama
  pointer kavramı
  dosya işlemleri
*/
#include <iostream>
using namespace  std;

/*
  fonk. diziyi parametre olarak gönderme
    dizi adı, eleman sayısı gönderilmeli
    bir istisna, karakter dizileri (sadece dizi adı gönderilir)
    Örn;
      dizinin maks. değerini bulmak (fonk. kullanarak)
    Ödev:
      dizi elemanlarını kullanıcıdan alarak maksimum elemanı fonk. kullanarak bulun.
*/

int maxBul(int dizi[],int n){
  int max = -999999;
  for(int i=0;i<n;i++){
    if(dizi[i] > max){
      max = dizi[i];
    }
  }
  return max;
}

int main() {
  //               0 1 2 3 4 5 6 7  8
  int dizi[100] = {2,5,3,9,4,7,1,11,4};
  cout<<"Max: " << maxBul(dizi,9);
  cout<<endl;
  return 0;
}