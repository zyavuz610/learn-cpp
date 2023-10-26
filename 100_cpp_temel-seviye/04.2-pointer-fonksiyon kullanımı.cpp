#include <iostream>

using namespace std;

/*
  bu dosyada anlatılacak konular:
    fonksiyonlara dizi gönderimi
    fonksiyonlara matris gönderimi
    fonksiyonlardan dizi geri döndürme
    fonksiyonlara değişkenlerin const olarak gönderilmesi
    fonksiyonların geri dönüş değerlerinin const olması
*/

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
/*
#include <iostream>

// Bir fonksiyon tanımlayalım ve geri dönüş değerini const olarak işaretleyelim.
const int sabitTopla(int a, int b) {
    return a + b;
}

int main() {
    int sayi1 = 5;
    int sayi2 = 3;

    // Fonksiyonun dönüş değeri bir const int olduğu için aşağıdaki atama hata verecektir.
    // sayi1 = sabitTopla(sayi1, sayi2); // Hata!

    // Ancak aşağıdaki gibi bir kullanım geçerli olacaktır.
    const int sonuc = sabitTopla(sayi1, sayi2);

    std::cout << "Toplam: " << sonuc << std::endl;

    return 0;
}

*/
//--------------------------------------------------------------
/*
DİP NOT
  const pointer kullanımı
  
  const int* ptr; // ptr, sabit olan bir int değerini gösterir. ptr değişebilir ancak gösterdiği değer değişemez.

  #include <iostream>

int main() {
    int x = 10;
    int y = 20;

    // Bir int* const işaretçi tanımlayalım ve x'in adresini işaret etsin.
    const int* ptr = &x;

    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;

    // İşaretçi ile değeri okuyabiliriz.
    std::cout << "Değer ptr ile okundu: " << *ptr << std::endl;

    // Ancak işaretçi ile değeri değiştiremeyiz.
    // *ptr = 42; // Hata! Değer değiştirilemez.

    // İşaretçiyi başka bir değişkene yönlendirebiliriz.
    ptr = &y; // Geçerli, ptr şimdi y'nin adresini işaret eder.

    std::cout << "Yeni değer ptr ile okundu: " << *ptr << std::endl;

    return 0;
}


//************************************************************************************************
  int* const ptr; // ptr, değişebilen bir int değerini gösterir. ptr değişemez ancak gösterdiği değer değişebilir.

  #include <iostream>

int main() {
    int x = 10;
    int y = 20;

    // Bir const int* işaretçi tanımlayalım ve x'in adresini işaret etsin.
    int* const ptr = &x;

    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;

    // İşaretçi ile değeri okuyabiliriz ve değiştirebiliriz.
    std::cout << "Değer ptr ile okundu: " << *ptr << std::endl;
    
    *ptr = 42; // Değer değiştirilebilir, x artık 42'ye eşittir.

    std::cout << "x: " << x << std::endl;

    // İşaretçiyi başka bir adrese yönlendiremeyiz.
    // ptr = &y; // Hata! İşaretçi sabit, başka bir adresi işaret edemez.

    return 0;
}

*/
//--------------------------------------------------------------
  return 0;
}