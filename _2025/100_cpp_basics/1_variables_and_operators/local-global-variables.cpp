#include <iostream> // 'cout' ve 'endl' için gerekli kütüphane

// Fonksiyon prototipi: 'main' fonksiyonundan önce 'topla' fonksiyonunun varlığını bildirir.
int topla(int, int); 

// Global Değişken: 
// Programın herhangi bir yerinden (herhangi bir fonksiyondan) erişilebilir.
int g;

int main() {
    // Local Değişkenler:
    // Sadece tanımlandıkları 'main' fonksiyonu içinde geçerlidir.
    int a, b;
    
    // Local değişkenlere değer atanması
    a = 10;
    b = 20;

    // Global değişkene 'main' içinden erişim ve değer atama
    g = a + b;
    
    // 'topla' fonksiyonunu çağırıyoruz. 'a' ve 'b' değişkenleri argüman olarak gönderilir.
    // Fonksiyonun döndürdüğü değer (30) 'g' değişkenine atanır.
    g = topla(a, b); 
    
    // Global değişkenin (g) son değerini ekrana yazdırır.
    std::cout << g << std::endl;
    // using namespace std; satırı eklenirse yukarıdaki satır şu şekilde de yazılabilir:
    // cout << g << endl;
    // burada 'std::' kullanımı ile 'cout' ve 'endl' std (standart) isim alanından çağrılmış olur.
    // :: operatörü isim alanı (namespace) operatörüdür.

    return 0;
}

// 'topla' fonksiyonunun tanımı
int topla(int x, int y) {
    // Formal Değişkenler (Parametreler):
    // Fonksiyon çağrıldığında kendisine gönderilen değerleri (a ve b) alır.
    // Sadece 'topla' fonksiyonunun içinde geçerlidirler, local değişkenler gibi davranırlar.
    // 'x' ve 'y' bu fonksiyon için parametredir.
    return x + y;
}

/*
  3 tür değişken tanımlama çeşidi vardır
    1. lokal, yerel: sadece tanımlandığı blok içerisinde geçerlidir.
    2. formal değişkenler: fonksiyonlara parametre olarak aktarılan değişkenlerdir. tanımlandığı fonksiyon içerisinde geçerlidir.
    3. global: tüm bloklar dışında tanımlıdır. o dosya içerisinde her yerde geçerlidir. 

    global değişkenler ilk değer olarak sistem tarafından 0 lanır, lokal değişkenler ise kullanıcı tarafından ilk değer atanmalıdır.

    Genel kural: bir tanım ya da bildirim kendisinden sonraki satırlarda geçerlidir.

    DOĞRU
    int a=5,b=6,c;
    ...
    c=a+b;

    YANLIŞ
    c=a+b;
    ...
    int a=0,b=3,c;


    Argüman ve parametre kavramları karıştırılmamalıdır.
    Argüman: fonksiyon çağrıldığında fonksiyona gönderilen değerlerdir.
    Parametre: fonksiyon tanımlandığında fonksiyonun alacağı değerrlerdir (değişkenler).
    örneğin:
    int topla(int x,int y){
      // burada x,y formal değişkendir, lokal gibi işlev görür, ilk değerleri çağırıldıkları yerde verilir
      // x ve y parametredir.
      return x+y; 
    }
*/
//------------------------------------------------------------------------------------------------------------------------
/*
soru:
aynı değişken isminde hem global hem de local değişken olursa bunları nasıl ayrıt ederiz?

cevap:
local değişkenler global değişkenlerin üzerine yazar.
örneğin:

#include <iostream>
using namespace std;

int g = 10; // Global değişken

int main() {
    int g = 20; // Local değişken
    cout << "Local g: " << g << endl; // Local g kullanılır
    cout << "Global g: " << ::g << endl; // Global g kullanılır
    return 0;
}

*/
//------------------------------------------------------------------------------------------------------------------------
