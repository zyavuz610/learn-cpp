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
  int n=0;  // eleman sayısı
  int dizi[100];
  int temp;
  while(true){
    cout<<"Değer (çıkmak için 0): ";
    cin>>temp;
    if(temp == 0){
      break;
    }
    else{
      dizi[n] = temp;
      n++;
    }
  }
  cout<<"Eleman Sayısı: "<<n<<endl;
  cout<<"Max: " << maxBul(dizi,n);
  cout<<endl;
  return 0;
}