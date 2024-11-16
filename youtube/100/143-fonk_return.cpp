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

int toplam(int a,int b){
  int top = a+b;
  return top;
}

/*
fonk. adı: bolenSayisi
işlevi: verilen n sayısının bölen sayısını bulacak (1 ve kendi hariç)
parametre: n sayısı, int
return: bölen sayısı, int
*/
int bolenSayisi(int n){
  int bs = 0;
  for(int i=2;i<n;i++){
    if(n%i==0){
      bs++;
    }
  }
  return bs;
}

int main() {
  int n1 = 5, n2 = 10;
  int sonuc = toplam(n1,n2);
  cout<<"Sonuç:"<<sonuc<<endl;

  int n=52;
  cout<<n<<": "<<bolenSayisi(n)<<endl;

  while(true){
    cout<<"Sayi (çıkmak için -1):";
    cin>>n;
    if(n==-1) break;
    if(bolenSayisi(n)==0){
      cout<<n<<" ASAL"<<endl;
    }
    else{
      cout<<n<<" ASAL DEĞİL"<<endl;
    }
  }
}