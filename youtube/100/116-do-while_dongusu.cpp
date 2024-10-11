#include <iostream>
using namespace std;
/*
Önceki Derslerde:
  cin, cout
  değişkenler, operatörler (aritmetik,karşılaştırma)
  koşullu ifadeler (if, else if, else)
  döngüler-giriş

C++ 116 - Döngüler 3 | do-while döngüsü

Örnek:
  1-100 arası sayılarda işlem yap (ekrana yaz)
  50 kere kodu çalıştır
  dosya sonuna kadar kelimeleri oku
  dizinin tüm elemanlarında işlem yap(arama)

Döngünün Bileşenleri
  1. başlangıç
  2. bitiş (devam etme şartı)
  3. artış
  4. gövde (tekrar edilecek kodlar)

C++ Döngüleri
  for,   while,   do-while
*/

int main() {
  cout << "Do-While Döngüsü\n";
  int sayac;
  /*
  for(sayac=1;sayac<=100;sayac = sayac+1){
    cout<<sayac <<", ";
  }*/
  /*
  sayac = 1;
  while (sayac<=100){
    cout<<sayac <<", ";
    sayac = sayac+1;
  }*/

  sayac = 1;
  do{
    cout<<sayac <<", ";
    sayac = sayac+1;
  }while(sayac<=100);
  cout<<endl;

  
  int i;
  int n=50;
  /*
  for (i=0;i<n;i++){
    cout<< n-i <<". Merhaba Dünya" <<endl;
  }*/
  /*
  i=0;
  while(i<n){
    cout<< i+1 <<". Merhaba Dünya" <<endl;
    i++;
  }*/

  i=0;
  do{
    cout<< i+1 <<". Merhaba Dünya" <<endl;
    i++;
  }while(i<n);

  string pstr;
  cout<<"Do-While Döngüsü Örneği:\n";
  do{
    cout<<"parola:";
    cin>>pstr;
  }while(pstr != "abc");
  cout<<"iyi günler"<<endl;

  /*
    tek sayılar, çift sayılar ekrana
  */
}