#include <iostream>
using namespace std;

int main() {

/*
bu dosyada anlatılacak konular:
  enum tanımı ve kullanımı
*/
   

   // - bazı değişkenler sadece belli değerleri alabilir             
   // - enum anahtar kelimesi ile yeni bir tip tanımlanabilir
   //enum color {red,green,blue}; // ilk değer 0 olarak alınır. red=0, green=1, blue=2
   enum color {red, green=5,blue};
   color c = red;     
   cout<<"Renk Değeri : " << c << "(" << int(c) << ")" << endl;


/* 
   // enum örnek 2
   enum gun {Pazartesi=1,Sali,Carsamba,Persembe,Cuma,Cumartesi,Pazar};
   gun g = Sali;
   cout<<g+1;
*/

   return 0;
}