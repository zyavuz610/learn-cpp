# 4. Fonksiyonlar, Göstericiler (Pointers) ve Referanslar

Bu bölümde C++ dilinde kodun modüler hale getirilmesini sağlayan fonksiyonların bildirimi ve tanımı, hazır kütüphane fonksiyonları, varsayılan parametreler, bellek adresleri ve göstericiler (*pointers*), C++ referansları (*references*), parametre aktarım yöntemleri (Call by Value, Call by Reference, Call by Address), dizilerin fonksiyonlara aktarılması ve yerel statik değişkenler (*static variables*) ayrıntılı olarak ele alınmaktadır.

---

## 📑 İçindekiler
1. [Standart Kütüphane Fonksiyonları (cmath, cstdlib, ctime)](#1-standart-kütüphane-fonksiyonları-cmath-cstdlib-ctime)
2. [Kullanıcı Tanımlı Fonksiyonlar: Prototip, Tanım ve Değer Döndürme](#2-kullanıcı-tanımlı-fonksiyonlar-prototip-tanım-ve-değer-döndürme)
3. [Varsayılan Argümanlar (Default Parameters)](#3-varsayılan-argümanlar-default-parameters)
4. [Bellek Yönetimi ve Göstericiler (Pointers)](#4-bellek-yönetimi-ve-göstericiler-pointers)
5. [C++ Referansları (References) ve Pointer ile Karşılaştırması](#5-c-referansları-references-ve-pointer-ile-karşılaştırması)
6. [Parametre Aktarım Mekanizmaları (Value vs Reference vs Pointer)](#6-parametre-aktarım-mekanizmaları-value-vs-reference-vs-pointer)
7. [Dizilerin Fonksiyonlara Aktarılması (Array Decay) ve const Korunumu](#7-dizilerin-fonksiyonlara-aktarılması-array-decay-ve-const-korunumu)
8. [Statik Yerel Değişkenler (Static Variables) ve Bellek Ömrü](#8-statik-yerel-değişkenler-static-variables-ve-bellek-ömrü)
9. [Ekstra: Fonksiyon Aşırı Yükleme (Overloading), Inline Fonksiyonlar ve Özyineleme (Recursion)](#9-ekstra-fonksiyon-aşırı-yükleme-overloading-inline-fonksiyonlar-ve-özyineleme-recursion)
10. [Pekiştirme Alıştırmaları (Çözümlü Sorular)](#10-pekiştirme-alıştırmaları-çözümlü-sorular)
11. [Öğrenciler İçin Ev Ödevleri](#11-öğrenciler-için-ev-ödevleri)

---

## 1. Standart Kütüphane Fonksiyonları (cmath, cstdlib, ctime)

İlgili kaynak dosya: [1_predefined-functions.cpp](1_predefined-functions.cpp)

C++ dilinde sık kullanılan matematiksel ve sistem seviyesindeki işlemler için standart kütüphaneler hazır fonksiyonlar sunar:

- `<cmath>`: Matematiksel fonksiyonlar
  - `sqrt(x)`: Karekök $\sqrt{x}$
  - `pow(taban, us)`: Üs alma $taban^{us}$
  - `abs(x)` / `fabs(x)`: Mutlak değer $|x|$
  - `ceil(x)`: Yukarı yuvarlama (örn: `ceil(4.2) = 5.0`)
  - `floor(x)`: Aşağı yuvarlama (örn: `floor(4.9) = 4.0`)
  - `round(x)`: En yakın tamsayıya yuvarlama
  - `sin(rad)`, `cos(rad)`, `tan(rad)`: Trigonometrik fonksiyonlar (radyan cinsinden)
- `<cstdlib>` & `<ctime>`: Rastgele sayı üretimi ve sistem fonksiyonları
  - `rand()`: `0` ile `RAND_MAX` arasında rastgele tamsayı üretir.
  - `srand(time(0))`: Rastgele sayı üretecini o anki sistem saatiyle tohumlar (*seed*).
  - `exit(0)`: Programı anında belirtilen kodla sonlandırır.

```cpp
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(static_cast<unsigned>(time(nullptr))); // Tohumlama
    int zar = (rand() % 6) + 1; // 1 ile 6 arasında rastgele zar
    cout << "Atılan Zar: " << zar << endl;
    cout << "Karekök 16: " << sqrt(16.0) << endl;
    return 0;
}
```

---

## 2. Kullanıcı Tanımlı Fonksiyonlar: Prototip, Tanım ve Değer Döndürme

İlgili kaynak dosya: [2_functions-1.cpp](2_functions-1.cpp)

C++ yukarıdan aşağıya (*top-down*) derleme yapar. Eğer bir fonksiyon `main()` fonksiyonundan sonra tanımlanacaksa, `main()` öncesinde derleyiciye **fonksiyon prototipi (declaration)** bildirilmelidir.

```cpp
#include <iostream>
using namespace std;

// 1. Fonksiyon Bildirimi / Prototipi (Function Prototype)
int topla(int a, int b);
void selamla(const string& isim);

int main() {
    selamla("Ahmet");
    int sonuc = topla(15, 25); // Fonksiyon çağrısı (Call)
    cout << "Toplam: " << sonuc << endl;
    return 0;
}

// 2. Fonksiyon Gövdesi / Tanımı (Function Definition)
int topla(int a, int b) {
    return a + b; // Geriye değer döndürme
}

void selamla(const string& isim) {
    cout << "Merhaba, " << isim << "!" << endl;
    // void fonksiyonlar geriye değer döndürmez
}
```

---

## 3. Varsayılan Argümanlar (Default Parameters)

İlgili kaynak dosya: [3_default-parameters.cpp](3_default-parameters.cpp)

Bir fonksiyon çağrılırken belirli argümanlar gönderilmediğinde varsayılan bir değer alması isteniyorsa kullanılır.

### Kurallar:
1. Varsayılan parametreler **en sağdan sola doğru (trailing parameters)** tanımlanmalıdır. Varsayılan değere sahip bir parametreden sonra varsayılanı olmayan bir parametre gelemez.
2. Prototip kullanılıyorsa varsayılan değer **yalnızca prototipte** belirtilmeli, gövde tanımında tekrar yazılmamalıdır.

```cpp
#include <iostream>
using namespace std;

// Prototip: genislik ve yukseklik varsayılan değerlere sahiptir
int alanHesapla(int uzunluk, int genislik = 10, int carpici = 1);

int main() {
    cout << alanHesapla(5) << endl;         // uzunluk=5, genislik=10, carpici=1 -> 50
    cout << alanHesapla(5, 20) << endl;     // uzunluk=5, genislik=20, carpici=1 -> 100
    cout << alanHesapla(5, 20, 2) << endl;  // uzunluk=5, genislik=20, carpici=2 -> 200
    return 0;
}

int alanHesapla(int uzunluk, int genislik, int carpici) {
    return uzunluk * genislik * carpici;
}
```

---

## 4. Bellek Yönetimi ve Göstericiler (Pointers)

İlgili kaynak dosya: [4_pointers.cpp](4_pointers.cpp)

Gösterici (Pointer), başka bir değişkenin bellekteki fiziksel adresini (`RAM` adresi) tutan özel bir değişkendir.

- **Adres Operatörü (`&`):** Bir değişkenin bellekteki adresini verir.
- **Dolaylı Yoldan Erişim / İçerik Operatörü (`*`):** Bir göstericinin işaret ettiği adresteki gerçek veriye erişir (*dereferencing*).

```cpp
#include <iostream>
using namespace std;

int main() {
    int sayi = 42;
    int* ptr = &sayi; // ptr, sayi'nin bellek adresini tutar

    cout << "sayi degeri           : " << sayi << endl;  // 42
    cout << "sayi bellek adresi (&): " << &sayi << endl; // örn: 0x61ff08
    cout << "ptr'nin tuttugu adres : " << ptr << endl;   // 0x61ff08
    cout << "ptr'nin isaret ettigi : " << *ptr << endl;  // 42 (dereference)

    // Gösterici üzerinden değeri değiştirme
    *ptr = 99;
    cout << "Guncel sayi degeri    : " << sayi << endl;  // 99 oldu!

    // Güvenli boş gösterici (Modern C++)
    int* bosGosterici = nullptr; 

    return 0;
}
```

---

## 5. C++ Referansları (References) ve Pointer ile Karşılaştırması

İlgili kaynak dosya: [5_cpp-references.cpp](5_cpp-references.cpp)

Referans (`&`), mevcut bir değişken için oluşturulmuş bir **takma isimdir (alias)**. Referans oluşturulduğunda değişkenle aynı bellek adresini paylaşır.

```cpp
int x = 10;
int& ref = x; // ref, x'in takma adıdır

ref = 20;     // x de 20 olur!
```

### Referans ile Gösterici Arasındaki Kritik Farklar

| Kriter | Referans (`Type&`) | Gösterici (`Type*`) |
| :--- | :--- | :--- |
| **Boş Değer (Null)** | `NULL` veya `nullptr` **olamaz**. Mutlaka geçerli bir nesneye bağlanmalıdır. | `nullptr` olabilir, hiçbir yeri işaret etmeyebilir. |
| **Yeniden Yönlendirme** | Tanımlandıktan sonra başka bir değişkene bağlanamaz (*immutable binding*). | İstendiğinde başka bir değişkenin adresini gösterebilir. |
| **Başlatma Zorunluluğu**| Tanımlandığı anda hemen başlatılmalıdır. | Tanımlanıp daha sonra adres atanabilir (`int* p; p = &x;`). |
| **Sözdizimi Kolaylığı** | Normal değişken gibi doğrudan kullanılır (nokta `.` veya `*` gerekmez). | İçeriğe erişim için `*` veya `->` operatörü gereklidir. |

---

## 6. Parametre Aktarım Mekanizmaları (Value vs Reference vs Pointer)

İlgili kaynak dosya: [5_cpp-references.cpp](5_cpp-references.cpp)

İki sayının değerini takas eden (*swap*) üç farklı yöntemi inceleyelim:

```cpp
#include <iostream>
using namespace std;

// 1. Değer ile Çağırma (Call by Value)
// Argümanların kopyası oluşturulur. Orijinal değişkenler DEĞİŞMEZ!
void takas_cbv(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

// 2. Referans ile Çağırma (Call by Reference) - C++ Tercihi!
// Orijinal değişkenlerin takma adları gelir. Orijinal değerler DEĞİŞİR!
void takas_cbr(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 3. Adres / Pointer ile Çağırma (Call by Address) - C-Tarzı
// Değişkenlerin bellek adresleri aktarılır. Orijinal değerler DEĞİŞİR!
void takas_cbp(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;

    takas_cbv(x, y);
    cout << "cbv sonrası: x=" << x << ", y=" << y << " (Degismedi)\n"; // 10, 20

    takas_cbr(x, y);
    cout << "cbr sonrası: x=" << x << ", y=" << y << " (Degisti)\n";   // 20, 10

    takas_cbp(&x, &y);
    cout << "cbp sonrası: x=" << x << ", y=" << y << " (Tekrar Takas)\n"; // 10, 20

    return 0;
}
```

> [!TIP]
> **Modern C++ Altın Standardı (Pass-by-const-reference):** Büyük nesneler (örneğin `std::string` veya karmaşık yapılar/sınıflar) fonksiyona parametre olarak verilirken kopyalama maliyetinden kaçınmak için referansla, fonksiyonun nesneyi kazara değiştirmesini önlemek içinse `const` ile geçirilmelidir: `void yazdir(const string& metin);`

---

## 7. Dizilerin Fonksiyonlara Aktarılması (Array Decay) ve const Korunumu

İlgili kaynak dosya: [6_functions-and-arrays.cpp](6_functions-and-arrays.cpp)

C++ dilinde bir dizi fonksiyona parametre olarak verildiğinde, dizi kopyalanmaz; dizinin ilk elemanının adresini tutan bir göstericiye indirgenir (*array decay to pointer*).

Bu nedenle:
1. `void fonk(int arr[])` ile `void fonk(int* arr)` tamamen aynı anlama gelir.
2. Fonksiyon dizinin boyutunu bilemez; **dizi boyutu her zaman ek bir parametre olarak geçirilmelidir**.
3. Fonksiyonun dizi elemanlarını değiştirmesi istenmiyorsa `const` anahtar kelimesi eklenmelidir.

```cpp
#include <iostream>
using namespace std;

// const int arr[]: Fonksiyon diziyi sadece okuyabilir, elemanları değiştiremez!
double ortalama(const int arr[], int boyut) {
    int toplam = 0;
    for (int i = 0; i < boyut; i++) {
        // arr[i] = 0; // HATA! const olduğu için derleyici izin vermez
        toplam += arr[i];
    }
    return static_cast<double>(toplam) / boyut;
}
```

---

## 8. Statik Yerel Değişkenler (Static Variables) ve Bellek Ömrü

İlgili kaynak dosya: [7_static-vars.cpp](7_static-vars.cpp)

Normalde bir fonksiyon içindeki yerel değişkenler fonksiyon çağrıldığında yığında (*stack*) oluşturulur ve fonksiyondan çıkıldığında yok edilir. 

Ancak bir değişken `static` olarak tanımlanırsa:
1. Yalnızca **bir defa**, program ilk çalıştığında başlatılır.
2. Program sonlanana kadar bellekte kalır.
3. Fonksiyondan çıkılsa bile en son aldığı değeri bir sonraki çağrıda korur.

```cpp
#include <iostream>
using namespace std;

void sayacFonksiyonu() {
    static int cagriSayisi = 0; // Sadece ilk çağrıda oluşturulur ve sıfırlanır
    cagriSayisi++;
    cout << "Bu fonksiyon " << cagriSayisi << ". kez çağrıldı.\n";
}

int main() {
    sayacFonksiyonu(); // 1. kez
    sayacFonksiyonu(); // 2. kez
    sayacFonksiyonu(); // 3. kez
    return 0;
}
```

---

## 9. Ekstra: Fonksiyon Aşırı Yükleme (Overloading), Inline Fonksiyonlar ve Özyineleme (Recursion)

### 1. Fonksiyon Aşırı Yükleme (Function Overloading)
Aynı isimde fakat **farklı parametre listesine** (parametre tipi veya parametre sayısı farklı) sahip birden çok fonksiyon tanımlanabilmesidir.
```cpp
int topla(int a, int b) { return a + b; }
double topla(double a, double b) { return a + b; }
int topla(int a, int b, int c) { return a + b + c; }
```
*(Not: Sadece dönüş tipinin farklı olması aşırı yükleme için yeterli değildir; imza parametrelerden oluşur).*

### 2. Satır İçi Fonksiyonlar (`inline`)
Küçük ve sık çağrılan fonksiyonlarda fonksiyon çağrı maliyetini (*function call overhead: stack frame hazırlama, atlama*) ortadan kaldırmak için kullanılır. Derleyici fonksiyon çağrısını silip kodun kendisini doğrudan çağrıldığı yere yapıştırır.
```cpp
inline int kareAl(int x) { return x * x; }
```

### 3. Özyinelemeli Fonksiyonlar (Recursion)
Bir fonksiyonun kendi kendini çağırmasıdır. Mutlaka bir durma koşulu (*base case*) bulunmalıdır; aksi halde yığın taşması (*stack overflow*) meydana gelir.
```cpp
long long faktoriyel(int n) {
    if (n <= 1) return 1; // Durma koşulu (Base Case)
    return n * faktoriyel(n - 1); // Özyinelemeli adım
}
```

---

## 10. Pekiştirme Alıştırmaları (Çözümlü Sorular)

### Soru 1: İşaretçi Aritmetiği ile Dizi Elemanlarına Erişim
Aşağıdaki kodun çıktısı ne olur? İşaretçi aritmetiğinin mantığını açıklayınız.
```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int* ptr = arr;

    cout << *ptr << " ";
    ptr += 2;
    cout << *ptr << " ";
    cout << *(ptr - 1) << endl;
    return 0;
}
```
**Çözüm:**
- `arr` adı dizinin ilk elemanının adresidir (`&arr[0]`). `*ptr` ifadesi `10` değerini yazar.
- `ptr += 2` işlemi işaretçiyi 2 tamsayı adımı (yani `2 * sizeof(int) = 8 byte`) ileri taşır. Artık `arr[2]` elemanını gösterir. `*ptr` ifadesi `30` yazar.
- `*(ptr - 1)` ifadesi işaretçinin konumunu kalıcı olarak değiştirmeden 1 adım gerisindeki `arr[1]` elemanını okur: `20`.
- Çıktı: `10 30 20`.

---

### Soru 2: Çıktı Analizi (Referans ile Dönüş)
Aşağıdaki fonksiyonun çalışmasını ve `main` içerisindeki atamayı yorumlayınız:
```cpp
#include <iostream>
using namespace std;

int globalDizi[] = {10, 20, 30, 40};

int& elemanGetir(int indeks) {
    return globalDizi[indeks];
}

int main() {
    elemanGetir(2) = 99; // Referans ile dönüş sayesinde sol taraf değeri (lvalue) olur
    cout << "globalDizi[2]: " << globalDizi[2] << endl;
    return 0;
}
```
**Çözüm:**
- `elemanGetir` fonksiyonu `int&` döndürdüğü için `globalDizi[2]` elemanının takma adını geriye döner.
- Bu sayede fonksiyon çağrısı bir atamanın sol tarafında (*l-value*) yer alabilir ve `globalDizi[2]` değeri 99 olarak güncellenir.
- Çıktı: `globalDizi[2]: 99`.

---

## 11. Öğrenciler İçin Ev Ödevleri

### Ödev 1: Dinamik İstatistik Hesaplayıcı (Referans Parametrelerle)
- **Görev:** Bir tamsayı dizisini parametre olarak alan ve tek bir fonksiyon çağrısında dizinin **toplamını, ortalamasını, en büyük elemanını ve en küçük elemanını** hesaplayarak `main` fonksiyonuna geri aktaran `void diziAnaliz(const int arr[], int boyut, int& toplam, double& ortalama, int& enb, int& enk)` fonksiyonunu yazınız.

### Ödev 2: Güvenli String Kırpma Fonksiyonu (Trim via Pointers)
- **Görev:** Bir C-tarzı karakter dizisini (`char* str`) parametre alarak başındaki ve sonundaki tüm boşluk karakterlerini işaretçi aritmetiği kullanarak yerinde (*in-place*, yeni bir dizi oluşturmadan) temizleyen `void trim(char* str)` fonksiyonunu kodlayınız.

### Ödev 3: Hanoi Kuleleri Bulmacası (Özyinelemeli Çözüm)
- **Görev:** $N$ adet diskin A çubuğundan C çubuğuna B çubuğu yardımcı kullanılarak taşınması adımlarını ekrana basan özyinelemeli `void hanoi(int n, char kaynak, char hedef, char yardimci)` fonksiyonunu yazınız. Program kullanıcının girdiği disk sayısına göre tüm adımları ve toplam hamle sayısını ($2^n - 1$) listelemelidir.
