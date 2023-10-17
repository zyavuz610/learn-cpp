#include <iostream>

using namespace std;

//-------------------------------------------------------------
// FONKSİYONLARIN DİZİ GERİ DÖNDÜRMESİ için kullanılacak fonk.
// rasgele sayılar üretilecek ve dizi olarak geri döndürülecek
int * SayiUret(int n) {
   //static int  r[10];   // adresi geri döndürülecek dizi static olarak tanımlanmalıdır
   static int *r = new int[n];
   // tohum setle
   srand( (unsigned)time( NULL ) );
   
   for (int i = 0; i < n; ++i) {
      r[i] = rand();
      //cout << r[i] << endl;
   }
   return r;
}
//-------------------------------------------------------------

int main () {
    //--------------------------------------------------------------
/*
    FONKSİYONLARA DİZİLERİN PARAMETRE OLARAK GÖNDERİLMESİ
      . 3 farklı gönderim şekli mevcut

      1. pointer olarak: burada fonksiyonda formal parametre olarak pointer tanımlanır
        void f(int *p) {
          ...
        }

      2. boyutu belli dizi şeklinde:
        void f(int dizi[10]) {
          ...
        }  

      3. boyutu belirsiz dizi şeklinde (pointer gibi)
        void f(int dizi[]) {
          ...
        }

//  MATRİSLER İÇİN DURUM

      1. pointer olarak: burada fonksiyonda formal parametre olarak pointer tanımlanır
        void f(int **p) {
          ...
        }

        çağırmadan önce şu yapılmalı (dinamik olarak yer ayrılmalı)
        int **a1;
        a1 = new int *[10];
        for(int i = 0; i <10; i++)
          a1[i] = new int[10];
        f(a1);

      2. boyutu belli dizi şeklinde:
        void f(int a[][10]) {
            // ...
        } 

      3. her bir satırıjn başlangıç adresini tutan pointer dizisi şeklinde
        void f(int *dizi[10]) {
          ...
        }

        çağırmadan önce şu yapılmalı (dinamik olarak yer ayrılmalı)
        int *a1[10];
        for(int i = 0; i <10; i++)
          a1[i] = new int[10];
        f(a1);
      
*/
/*
   int a[5] = {1000, 2, 3, 17, 50};
   double o;

   // dizinin fonksiyona parametre olarak verilmesi
   //o = OrtalamaBul( a, 5 ) ;
   //o = OrtalamaBul2( a, 5 ) ;
   o = OrtalamaBul3( a, 5 ) ;
 
   // output the returned value 
   cout << "Ortalama: " << o << endl;
*/
//--------------------------------------------------------------
/*
  FONKSİYONLARIN DİZİ GERİ DÖNDÜRMESİ
	. normal şartlarda bir fonksiyonun sadece 1 adet geri dönüş değeri olur.
	. ancak dizi şeklinde birden çok değer geri döndürülebilir
	. bunun için geri dönüş değeri pointer olacak şekilde fonksiyon tanımlanmalıdır
		int * f(...){
			...
		}
*/
/*
   int *p,n=20;
   p = SayiUret(n);
   
   for ( int i = 0; i < n; i++ ) {
      cout << "*(p + " << i << ") : "<< *(p + i) << endl;
   }
*/

//--------------------------------------------------------------
// fonksiyonlara değişkenlerin const olarak gönderilmesi
/*
fonksiyonlara değişkenleri const olarak göndermek için, değişkenin önüne const anahtar kelimesi eklenir. Bu, fonksiyonun, değişkenin değerini değiştirmeyeceğini garanti eder.

Örnek:


// const olmadan dene !!!
void fonksiyon(const int x) {
  // x = 5; // hata
  std::cout << "x: " << x << std::endl;
}

int main() {
  int a = 10;
  fonksiyon(a);
  return 0;
}

Çıktı:

x: 10

*/
//--------------------------------------------------------------

//--------------------------------------------------------------
  return 0;
}