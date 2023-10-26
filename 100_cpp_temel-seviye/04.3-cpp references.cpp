#include <iostream>
using namespace std;
/*
   bu dosyada
*/

void takas_cbr(int &a,int &b){
  int temp;
  temp = a;
  a = b;
  b = temp;
}

void takas_cbv(int a,int b){
  int temp;
  temp = a;
  a = b;
  b = temp;
}

void takas_cbp(int *a,int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
int main () {
/*
	. referance aslında bir değişken için takma isimdir
	. zaten var olan değişkenlere ayrıca takma isim vermek için kullanılır
	. bir reference bir değişken ile başlatımlandığında o değeri temsil için artık hem değişkeni hem de reference ini kullanabiliriz
	
	Reference ile Pointer Karşılaştırması
	. 3 açıdan birbirinden farklıdır
		1. NULL olabilen reference olamaz, mutlaka bir değişkenin reference olması gerekir, pointer böyle değildir
		2. bir reference bir değişken ile başlatımlandığında değiştirilemez, pointer böyle değildir
		3. reference ilk yaratıldığında mutlaka bir değişkenle başlatımlanmalıdır, pointer lar böyle değildir.
*/
   int    i;
   double d;
 
   int &r = i;
   double &s = d;
   
   i = 5;
   cout << "i : " << i << endl;
   // r= 6;  // i değişkeni değişiyor
   cout << "i reference : " << r  << endl;
 
   d = 11.7;
   cout << "d : " << d << endl;
   cout << "d reference : " << s  << endl;

//-------------------------------------------------------------------
// Call by Reference, daha önce bu örnek verilmişti

//    fonksiyon çağrılırken call by value gibi çağrılırken
//    ancak fonksiyona değişkenlerin referansları kopyalanırlar
//    dolayısıyla içerikler etkilenir, çünkü değerler kopyalanmıyor, referans kopyalanıyor
/*
    int a=5,b=6;
    cout<<"Takastan Önce (a,b)=("<<a<<","<<b<<")"<<endl;
    takas_cbr(a,b);     // call by reference
    takas_cbv(a,b);     // call by value
    takas_cbp(&a,&b);     // call by pointer
    cout<<"Takastan Sonra (a,b)=("<<a<<","<<b<<")"<<endl;
    // fonksiyon çağrıldığında değerler nasıl geçiyor? şekil ile anlatalım
*/
//-----------------------------------------------------------------------
// fonksiyonlara geri dönüş değeri olarak referans ayarlanabilir
// bu durumda fonksiyonun geri dönüş değeri referans olmalıdır
/*
örnek:
int & f(...){
  ...
}

int main(){
  int a=5;
  int &b = f(a);
  ...
}
*/

//-----------------------------------------------------------------------
   return 0;
}
