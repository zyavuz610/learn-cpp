/*
  - jenerik (yani türden bağımsız) programlama yapmak için kullanılır.
  - template kullanılmasa idi o halde her tür için fonk. ya da sınıfı aşırı yükleyecktik.
  - template anahtar kelimesi kullanılır
  - 2 türlü kullanım şekli vardır
      - typename  -> fonk. parametre ya da geri dönüş değerlerinde kullanılır
      - class     -> class tanımı içierisindeki değişkenler için kullanılır

  template <typename|class "tür_belirteci",....>
  
  ....
  - "tür belirtici" kelimesini bundan böyle tip yerine kullanabiliriz.
  - derleyici koşma ya da derleme zamanında ilgili türü yerine koyarak çalıştırılabilir kod üretir.
  - yukarıdaki tür belirteci artık tip ya da sınıf türü olabilir. 
*/
//-----------------------------------------------------------------

#include <iostream>
using namespace std;

//-----------------------------------------------------------------
// Fonksiyon için bir örnek
template <typename T> 
bool isEqual(T a,T b){
  if(a==b) return true;
  return false;
}

int main() {
    // Integer türü için test
    int num1 = 5, num2 = 5;
    cout << "Are integers ("<<num1<<","<<num2<<") equal? " << (isEqual(num1, num2) ? "Yes" : "No") << endl;

    // Double türü için test
    double d1 = 3.14, d2 = 3.14;
    cout << "Are doubles ("<<d1<<","<<d2<<") equal? " << (isEqual(d1, d2) ? "Yes" : "No") << endl;

    // String türü için test
    string str1 = "Hello", str2 = "World";
    cout << "Are strings ("<<str1<<","<<str2<<") equal? " << (isEqual(str1, str2) ? "Yes" : "No") << endl;

    // Char türü için test
    char ch1 = 'A', ch2 = 'A';
    cout << "Are chars ("<<ch1<<","<<ch2<<") equal? " << (isEqual(ch1, ch2) ? "Yes" : "No") << endl;

    return 0;
}