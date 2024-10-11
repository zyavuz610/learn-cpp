#include <iostream>
using namespace std;
/*
Önceki Derslerde:
  cin, cout
  değişkenler, operatörler (aritmetik,karşılaştırma)
  koşullu ifadeler (if, else if, else)
  döngüler-giriş

C++ 114 - Döngüler 1 | for Döngüsü

Örnek:
  1-100 arası sayılarda işlem yap (ekrana yaz)
  50 kere kodu çalıştır
  dosya sonuna kadar kelimelere oku
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
  cout << "For Döngüsü\n";
  int sayac;
  for(sayac=1;sayac<=100;sayac = sayac+1){
    cout<<sayac <<", ";
  }

  int i;
  int n=50;
  for (i=0;i<n;i++){
    cout<< n-i <<". Merhaba Dünya" <<endl;
  }

  /*
    tek sayılar, çift sayılar ekrana
  */
}