#include <iostream>
#include <bitset>
using namespace std;

int main() {


   

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