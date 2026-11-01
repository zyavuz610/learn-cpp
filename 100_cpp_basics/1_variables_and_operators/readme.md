# 1. Değişkenler, Veri Tipleri ve Operatörler

Bu bölümde C++ programlama dilinin temel yapı taşları olan ilkel veri tipleri, değişken tanımlama ve başlatma mekanizmaları, değişkenlerin kapsamı (scope) ve ömrü (lifetime), sabitler ve değişmezler (literals), operatörler ve C++ tip dönüştürme (type casting) yöntemleri ayrıntılı olarak ele alınmaktadır.

---

## 📑 İçindekiler
1. [İlkel Veri Tipleri ve Bellek Boyutları](#1-ilkel-veri-tipleri-ve-bellek-boyutları)
2. [Değişken Tanımlama, Başlatma ve İsimlendirme Kuralları](#2-değişken-tanımlama-başlatma-ve-isimlendirme-kuralları)
3. [Yerel ve Global Değişkenler (Scope ve Kapsam Çözünürlüğü)](#3-yerel-ve-global-değişkenler-scope-ve-kapsam-çözünürlüğü)
4. [Sabitler (const, #define) ve Değişmezler (Literals)](#4-sabitler-const-define-ve-değişmezler-literals)
5. [C++ Operatörleri ve Öncelik Sıralaması](#5-c-operatörleri-ve-öncelik-sıralaması)
6. [Tip Dönüşümleri (Type Conversion & Casting)](#6-tip-dönüşümleri-type-conversion--casting)
7. [İleri Düzey C++ Cast Operatörleri (const_cast ve reinterpret_cast)](#7-ileri-düzey-c-cast-operatörleri-const_cast-ve-reinterpret_cast)
8. [Ekstra: auto, constexpr ve Birörnek Başlatma (Uniform Initialization)](#8-ekstra-auto-constexpr-ve-birörnek-başlatma-uniform-initialization)
9. [Pekiştirme Alıştırmaları (Çözümlü Sorular)](#9-pekiştirme-alıştırmaları-çözümlü-sorular)
10. [Öğrenciler İçin Ev Ödevleri](#10-öğrenciler-için-ev-ödevleri)

---

## 1. İlkel Veri Tipleri ve Bellek Boyutları

İlgili kaynak dosya: [1_data-types.cpp](1_data-types.cpp)

C++ statik tipli (*statically-typed*) bir dildir. Bir değişken tanımlanırken türü mutlaka belirtilmelidir ve derleme zamanında bilinir.

| Veri Tipi | Boyut (Tipik) | Değer Aralığı / Açıklama |
| :--- | :--- | :--- |
| `bool` | 1 byte | `true` (1) veya `false` (0) |
| `char` | 1 byte | Tek bir karakter veya ASCII değeri (-128 ile 127) |
| `unsigned char` | 1 byte | 0 ile 255 arası tamsayı / karakter |
| `short int` | 2 byte | -32,768 ile 32,767 |
| `unsigned short` | 2 byte | 0 ile 65,535 |
| `int` | 4 byte | Yaklaşık -2.14 milyar ile +2.14 milyar arası |
| `unsigned int` | 4 byte | 0 ile 4.29 milyar arası |
| `long long` | 8 byte | -9 kentilyon ile +9 kentilyon arası |
| `float` | 4 byte | Tek duyarlıklı kayan noktalı sayı (~7 basamak hassasiyet) |
| `double` | 8 byte | Çift duyarlıklı kayan noktalı sayı (~15-17 basamak hassasiyet) |
| `long double` | 8/12/16 byte | Yüksek duyarlıklı kayan noktalı sayı |

```cpp
#include <iostream>
#include <bitset>
using namespace std;

int main() {
    bool aktif = true;
    char harf = 'A'; // ASCII 65
    int sayi = -500;
    double pi = 3.1415926535;

    cout << "bool boyut : " << sizeof(aktif) << " byte | ikili: " << bitset<8>(aktif) << endl;
    cout << "char boyut : " << sizeof(harf)  << " byte | ASCII: " << int(harf) << endl;
    cout << "int boyut  : " << sizeof(sayi)  << " byte" << endl;
    cout << "double     : " << sizeof(pi)    << " byte" << endl;
    return 0;
}
```

> [!WARNING]
> **Tamsayı Taşması (Integer Overflow):** İşaretli tamsayıların sınırları aşıldığında tanımsız davranış (*undefined behavior*) meydana gelir. İşaretsiz tamsayılarda ise modülo aritmetiği uygulanarak değer sıfıra döner (`unsigned short s = 65535; s++; // s = 0 olur`).

---

## 2. Değişken Tanımlama, Başlatma ve İsimlendirme Kuralları

İlgili kaynak dosya: [2_variable-definition.cpp](2_variable-definition.cpp)

Değişken, bellekte veri depolamak için ayrılan isimlendirilmiş bir alandır.

### Değişken Başlatma Yöntemleri
```cpp
int a;          // Bildirim (Declaration): Değeri çöp (garbage) değerdir!
a = 10;         // Atama (Assignment)

int b = 20;     // Kopyalama ile başlatma (Copy initialization)
int c(30);      // Doğrudan başlatma (Direct initialization)
int d{40};      // Birörnek liste başlatma (Uniform/List initialization - C++11)
```

### Değişken İsimlendirme Kuralları ve Standartları
- İsimler harf (`a-z`, `A-Z`) veya `_` ile başlamalıdır. Rakamla başlayamaz.
- Özel semboller (`$`, `@`, `!`, `-`, boşluk vb.) içeremez.
- C++ anahtar kelimeleri (`int`, `for`, `return`, `class`) değişken adı olamaz.
- **Standart İsimlendirme Biçimleri:**
  - `camelCase`: İlk kelime küçük, sonrakiler büyük harfle başlar (`ogrenciNotu`, `toplamFiyat`). C++'ta değişkenler için yaygındır.
  - `snake_case`: Kelimeler alt çizgi ile ayrılır (`ogrenci_notu`, `toplam_fiyat`). Standart kütüphane tarzıdır.
  - `PascalCase`: Her kelimenin ilk harfi büyüktür (`OgrenciNotu`). Genellikle sınıf isimlerinde tercih edilir.

---

## 3. Yerel ve Global Değişkenler (Scope ve Kapsam Çözünürlüğü)

İlgili kaynak dosya: [3_local-global-variables.cpp](3_local-global-variables.cpp)

Değişkenlerin geçerli oldukları kod bloğuna **etki alanı (scope)**, bellekte kaldıkları süreye ise **ömür (lifetime)** denir.

```cpp
#include <iostream>
using namespace std;

// GLOBAL DEĞİŞKEN: Programın her yerinden erişilebilir. 
// Başlatılmazsa derleyici tarafından otomatik olarak 0 yapılır.
int sayi = 100;

void fonksiyon() {
    // YEREL DEĞİŞKEN: Sadece bu fonksiyon içinde geçerlidir.
    int sayi = 50;
    cout << "Fonksiyondaki yerel sayi: " << sayi << endl; // 50 yazar
    
    // Global değişkene erişmek için Kapsam Çözünürlüğü Operatörü (::) kullanılır
    cout << "Global sayiya erisim (::sayi): " << ::sayi << endl; // 100 yazar
}

int main() {
    int sayi = 20; // main() fonksiyonuna ait yerel değişken (globali gölgeler - shadow)
    cout << "main yerel sayi: " << sayi << endl;   // 20
    cout << "Global sayi     : " << ::sayi << endl; // 100
    fonksiyon();
    return 0;
}
```

---

## 4. Sabitler (const, #define) ve Değişmezler (Literals)

İlgili kaynak dosya: [4_constants-litterals.cpp](4_constants-litterals.cpp)

Değeri programın çalışması boyunca değiştirilemeyen yapılara sabit denir.

### `#define` vs `const` Karşılaştırması

```cpp
#define PI_MAKRO 3.14159   // Önişlemci yönergesi (Tip kontrolü yok, metin kopyalama yapar)
const double PI_CONST = 3.14159; // C++ tür güvenli sabit (Bellekte yer tutar, scope kurallarına uyar)
```

> [!TIP]
> Modern C++'ta `#define` ile sabit tanımlamak yerine her zaman `const` veya `constexpr` anahtar kelimesi tercih edilmelidir. `const` değişkenler tip kontrolünden geçer ve hata ayıklama (debugging) esnasında incelenebilir.

### Değişmez Değerler (Literals) ve Kaçış Karakterleri (Escape Characters)
- **Tamsayı Literalleri:** `42` (onluk), `052` (sekizlik/octal), `0x2A` (onaltılık/hex), `0b00101010` (ikili/binary - C++14).
- **Sonekler (Suffixes):** `42U` (unsigned), `42L` (long), `3.14f` (float), `3.14` (double).
- **Kaçış Karakterleri:**
  - `\n`: Yeni satır (newline)
  - `\t`: Yatay sekme (tab)
  - `\\`: Ters eğik çizgi karakteri
  - `\"`: Çift tırnak karakteri
  - `\0`: Boş karakter (Null character - string sonlandırıcı)

---

## 5. C++ Operatörleri ve Öncelik Sıralaması

İlgili kaynak dosya: [5_operators.cpp](5_operators.cpp)

### 1. Aritmetik Operatörler
`+`, `-`, `*`, `/`, `%` (Mod alma - sadece tamsayılarda çalışır).
```cpp
int x = 17 % 5; // Sonuç: 2
```

### 2. Artırma ve Azaltma Operatörleri (Ön Ek vs Son Ek)
```cpp
int a = 5;
int b = ++a; // Ön artırma (Pre-increment): a önce 6 olur, sonra b'ye atanır (b=6, a=6)

int x = 5;
int y = x++; // Son artırma (Post-increment): x'in mevcut değeri y'ye atanır (y=5), sonra x 6 olur
```

### 3. İlişkisel ve Mantıksal Operatörler
- İlişkisel: `==`, `!=`, `<`, `>`, `<=`, `>=` (Sonuç `bool` türünde `true` veya `false` döner).
- Mantıksal: `&&` (VE), `||` (VEYA), `!` (DEĞİL).
- **Kısa Devre Değerlendirmesi (Short-circuit Evaluation):** `(false && func())` durumunda `func()` hiç çalıştırılmaz; çünkü ilk koşul `false` olduğunda sonucun `false` olacağı kesindir. Benzer şekilde `(true || func())` durumunda da ikinci ifade değerlendirilmez.

### 4. Bitsel Operatörler (Bitwise Operators)
Sayıların ikili (binary) bitleri üzerinde doğrudan işlem yapar:
- `&` (Bitwise AND): Her iki bit 1 ise sonuç 1.
- `|` (Bitwise OR): En az bir bit 1 ise sonuç 1.
- `^` (Bitwise XOR): Bitler farklı ise 1, aynı ise 0.
- `~` (Bitwise NOT): Bitleri ters çevirir (1 $\rightarrow$ 0, 0 $\rightarrow$ 1).
- `<<` (Sola Kaydırma): Sayıyı 2 ile çarpmakla eşdeğerdir (`a << 1`).
- `>>` (Sağa Kaydırma): Sayıyı 2'ye bölmekle eşdeğerdir (`a >> 1`).

---

## 6. Tip Dönüşümleri (Type Conversion & Casting)

İlgili kaynak dosya: [6_type-convertion.cpp](6_type-convertion.cpp)

### Örtük Dönüşüm (Implicit Conversion / Type Promotion)
Derleyici tarafından veri kaybı olmayacak şekilde küçük veri tipinin büyük tipe otomatik yükseltilmesidir.
```cpp
int sayi = 10;
double sonuc = sayi + 5.5; // sayi otomatik olarak double yapılır (10.0 + 5.5 = 15.5)
```

### Belirgin Dönüşüm (Explicit Casting)
Programcının tür dönüşümünü açıkça talep etmesidir.

1. **C-Tipi Dönüşüm (C-Style Cast):** `(yeni_tur)deger` (Örn: `int x = (int)3.99;`). Güvenli değildir, çünkü derleyici denetimi zayıftır.
2. **C++ `static_cast`:** Derleme zamanında tür uyumluluğunu denetleyen güvenli C++ standardıdır:
```cpp
double pi = 3.14159;
int tamKisim = static_cast<int>(pi); // Güvenli ve okunabilir
```

---

## 7. İleri Düzey C++ Cast Operatörleri (const_cast ve reinterpret_cast)

İlgili kaynak dosyalar: [7_const_cast.cpp](7_const_cast.cpp), [8_reinterpret-cast.cpp](8_reinterpret-cast.cpp)

C++ dilinde farklı amaçlar için özelleşmiş 4 adet casting operatörü bulunur:

| Cast Operatörü | Ne İşe Yarar? | Güvenlik Düzeyi |
| :--- | :--- | :--- |
| `static_cast` | Uyumlu temel tipler veya miras ilişkisi olan sınıflar arası dönüşüm | Yüksek (Derleme zamanı denetimi) |
| `dynamic_cast` | Polimorfik sınıflarda çalışma zamanında güvenli aşağı doğru dönüşüm | Çok Yüksek (Çalışma zamanı denetimi) |
| `const_cast` | Bir işaretçi veya referansın `const` veya `volatile` niteliğini kaldırma | Dikkat gerektirir (Riskli) |
| `reinterpret_cast` | Birbirinden tamamen bağımsız tipler veya işaretçiler arasında bit düzeyinde yeniden yorumlama | Çok Düşük (Oldukça tehlikeli) |

### `const_cast` Kullanımı ve Tehlikeleri
```cpp
#include <iostream>
using namespace std;

void eskiKutuphaneFonksiyonu(int* p) {
    *p = 500;
}

int main() {
    int sayi = 100;
    const int* constPtr = &sayi;

    // const niteliğini kaldırarak int* türüne dönüştürüyoruz
    int* modifiablePtr = const_cast<int*>(constPtr);
    *modifiablePtr = 250; // sayi artık 250 oldu

    cout << "Guncel sayi: " << sayi << endl;
    return 0;
}
```
> [!CAUTION]
> Eğer `sayi` en baştan `const int sayi = 100;` şeklinde salt okunur sabit olarak tanımlanmış olsaydı, `const_cast` ile içeriğini değiştirmeye çalışmak işletim sistemi düzeyinde bellek ihlaline (*segmentation fault*) veya tanımsız davranışa (*undefined behavior*) yol açardı!

### `reinterpret_cast` Kullanımı (Bit Düzeyinde Dönüşüm)
```cpp
#include <iostream>
using namespace std;

int main() {
    int sayi = 65; // Bellekte 4 byte yer tutar (ASCII 65 = 'A')
    // int adresini char işaretçisine dönüştürüp ilk byte'ı okuyoruz
    char* baytGosterici = reinterpret_cast<char*>(&sayi);

    cout << "Ilk baytin karakter karsiligi: " << *baytGosterici << endl; // 'A' yazar
    return 0;
}
```

---

## 8. Ekstra: auto, constexpr ve Birörnek Başlatma (Uniform Initialization)

### 1. `auto` Tür Belirteci (C++11)
Derleyicinin sağ taraftaki ifadenin tipine bakarak değişkenin türünü otomatik olarak belirlemesini sağlar.
```cpp
auto x = 5;         // int
auto y = 3.14;      // double
auto z = "KTU";     // const char*
```

### 2. `constexpr` (Compile-time Constants)
Değerin derleme anında hesaplanabileceğini garanti eder. Performans optimizasyonu ve dizi boyutları belirlemede kullanılır.
```cpp
constexpr int DIZI_BOYUTU = 10 * 5; // Derleme anında 50 olarak sabitlenir
int dizi[DIZI_BOYUTU];             // Geçerli ve standartlara uygundur
```

### 3. Birörnek Başlatma ve Daraltma Engeli (Narrowing Prevention)
C++11 süslü parantez `{}` ile başlatmada veri kaybı (daraltıcı dönüşüm) tespit edilirse derleme hatası verir:
```cpp
int x = 3.14;   // C-tarzı: Derlenir, x = 3 olur (uyarı verebilir)
// int y{3.14}; // HATA! double'dan int'e daraltıcı dönüşüme izin verilmez
```

---

## 9. Pekiştirme Alıştırmaları (Çözümlü Sorular)

### Soru 1: Bitsel Operatör ile Tek/Çift Sayı ve 2'nin Kuvveti Kontrolü
Mod operatörü (`%`) kullanmadan, bir sayının tek mi çift mi olduğunu ve bir sayının 2'nin üssü olup olmadığını bitsel operatörlerle kontrol eden fonksiyonları yazınız.

**Çözüm:**
```cpp
#include <iostream>
using namespace std;

// Sayının son biti 1 ise sayı tektir, 0 ise çifttir.
bool isOdd(int n) {
    return (n & 1) == 1;
}

// 2'nin kuvveti olan sayıların ikili açılımında tek bir '1' bulunur (örn: 8 = 1000).
// 8 - 1 = 7 (0111) olur. 1000 & 0111 = 0000 sonucunu verir.
bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    return (n & (n - 1)) == 0;
}

int main() {
    cout << "7 tek mi? " << boolalpha << isOdd(7) << endl;         // true
    cout << "16 ikinin ussu mu? " << isPowerOfTwo(16) << endl;     // true
    cout << "18 ikinin ussu mu? " << isPowerOfTwo(18) << endl;     // false
    return 0;
}
```

---

### Soru 2: Çıktı Analizi (İşlem Önceliği ve Artırma)
Aşağıdaki kod parçası çalıştırıldığında çıktılar ne olur?
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int b = 20;
    int c = a++ + ++b;
    cout << "a: " << a << ", b: " << b << ", c: " << c << endl;
    return 0;
}
```
**Çözüm:**
- `++b`: Ön artırma işlemi önce gerçekleşir, `b` değeri 21 olur.
- `a++`: Son artırma olduğu için işlemde `a`'nın o anki değeri olan 10 kullanılır, işlem bittikten sonra `a` değeri 11'e yükselir.
- `c = 10 + 21 = 31`.
- Çıktı: `a: 11, b: 21, c: 31`.

---

## 10. Öğrenciler İçin Ev Ödevleri

### Ödev 1: İki Değişkenin Değerini Takas Etme (Swap Without Temp)
- **Görev:** İki tamsayı değişkenin değerlerini üçüncü bir geçici (`temp`) değişken **kullanmadan** takas eden iki farklı yöntem kodlayınız:
  1. Yöntem: Aritmetik operatörler (`+` ve `-`) ile.
  2. Yöntem: Bitsel XOR (`^`) operatörü ile.
- **Düşünme Sorusu:** Aritmetik yöntemde tamsayı taşması (*overflow*) riski var mıdır? Bitsel yöntemde neden yoktur?

### Ödev 2: RGB Renk Kodunu 32-bit Tamsayıya Paketleme
- **Görev:** Kullanıcıdan 0-255 arasında Kırmızı (Red), Yeşil (Green) ve Mavi (Blue) değerlerini alıp, bunları bitsel kaydırma (`<<`) ve VEYA (`|`) operatörleri ile tek bir `unsigned int` (veya `uint32_t`) içerisinde birleştiren programı yazınız. Ardından paketlenen tamsayıdan renk bileşenlerini tekrar çözen kodu ekleyiniz.

### Ödev 3: Güvenli Tip Dönüşümü ve Veri Doğrulama
- **Görev:** Kullanıcıdan `double` türünde bir sıcaklık değeri alan (örn: `-273.15` ile `1000.0` arası), bu değeri `int`, `char` ve `bool` türlerine dönüştüren bir test kodu yazınız. Her dönüşümde ne kadar veri kaybı (hassasiyet kaybı veya taşma) yaşandığını ekranda raporlayınız.
