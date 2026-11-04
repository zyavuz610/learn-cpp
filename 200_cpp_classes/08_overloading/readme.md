# 8. Fonksiyon ve Operatör Aşırı Yükleme (Overloading & this Pointer)

Bu bölümde C++ dilinde fonksiyon aşırı yükleme (*function overloading*), mevcut dildeki operatörlerin kullanıcı tanımlı nesneler için yeniden anlamlandırılması (*operator overloading*), `this` göstericisi ve zincirleme çağrılar (*method chaining*), tekli/ikili operatörler, akış giriş/çıkış operatörleri (`<<` ve `>>`), atama ve indis operatörleri, `friend` fonksiyonlar ile operatör aşırı yükleme mimarisi ele alınmaktadır.

---

## 📑 İçindekiler
1. [Fonksiyon Aşırı Yükleme (Function Overloading) ve İmza Kuralları](#1-fonksiyon-aşırı-yükleme-function-overloading-ve-imza-kuralları)
2. [this Göstericisi ve Metot Zincirleme (Method Chaining)](#2-this-göstericisi-ve-metot-zincirleme-method-chaining)
3. [Operatör Aşırı Yüklemeye Giriş ve Temel Kurallar](#3-operatör-aşırı-yüklemeye-giriş-ve-temel-kurallar)
4. [Üye Fonksiyon (Member) vs Arkadaş Fonksiyon (Friend) ile Aşırı Yükleme](#4-üye-fonksiyon-member-vs-arkadaş-fonksiyon-friend-ile-aşırı-yükleme)
5. [İkili (Binary) ve Aritmetik Operatörlerin Aşırı Yüklenmesi (+, -, *)](#5-ikili-binary-ve-aritmetik-operatörlerin-aşırı-yüklenmesi---)
6. [İlişkisel (Relational) Operatörler (==, !=, <, >)](#6-ilişkisel-relational-operatörler---)
7. [Tekli (Unary) Operatörler ve Artırma/Azaltma (++ ve --)](#7-tekli-unary-operatörler-ve-artırmaazaltma--ve---)
8. [Akış Giriş-Çıkış Operatörleri (<< ve >>)](#8-akış-giriş-çıkış-operatörleri--ve-)
9. [Atama (=) ve İndis ([]) Operatörleri](#9-atama--ve-indis--operatörleri)
10. [Ekstra: C++20 Uzay Gemisi Operatörü (<=>) ve Functor Yapısı (operator())](#10-ekstra-c20-uzay-gemisi-operatörü--ve-functor-yapısı-operator)
11. [Kodları Derleme ve Çalıştırma Rehberi (Komut Tablosu)](#11-kodları-derleme-ve-çalıştırma-rehberi-komut-tablosu)
12. [Pekiştirme Alıştırmaları (Çözümlü Sorular)](#12-pekiştirme-alıştırmaları-çözümlü-sorular)
13. [Öğrenciler İçin Ev Ödevleri](#13-öğrenciler-için-ev-ödevleri)

---

## 1. Fonksiyon Aşırı Yükleme (Function Overloading) ve İmza Kuralları

İlgili kaynak dosyalar: [function-overloading.cpp](function-overloading.cpp), [c-polymorphizm.c](c-polymorphizm.c)

Fonksiyon aşırı yükleme (*function overloading*), aynı etki alanı (*scope*) içerisinde **aynı isme sahip**, ancak **parametre listeleri birbirinden farklı** olan birden çok fonksiyon tanımlanabilmesidir. Bu mekanizma nesne yönelimli programlamada **Statik (Derleme Zamanı / Erken Bağlama) Çok Biçimlilik (Static / Compile-Time Polymorphism)** olarak adlandırılır.

### 1.1. C vs C++: Neden Aşırı Yüklemeye İhtiyaç Duyuldu?
- **C Dilinin Kısıtı:** C dilinde her fonksiyon adı sembol tablosunda benzersiz olmalıdır. Örneğin tamsayıları toplayan `int sum(int, int)` fonksiyonu varken ondalıklı sayılar için `float sum(float, float)` tanımlanamaz (Derleyici `redefinition of 'sum'` hatası verir). Bu nedenle standart C kütüphanesinde mutlak değer için `abs()`, `fabs()`, `labs()` gibi farklı tipler için ayrı isimler uydurulmuştur (Bkz: [c-polymorphizm.c](c-polymorphizm.c)).
- **C++ Çözümü:** C++ dili, çağıran kodun türlerine bakarak hangi fonksiyonun çağrılacağına **derleme anında** karar verir. Bu sayede geliştirici tek bir anlamlı isim (`topla`, `yazdir`, `alan`) kullanarak temiz ve tutarlı bir arayüz tasarlayabilir.

### 1.2. Fonksiyon İmzası (Function Signature) ve Kurallar

Derleyicinin iki fonksiyonu birbirinden ayırt etmek için kullandığı kimlik bilgisine **fonksiyon imzası (*signature*)** denir.

#### İmzaya Dahil Olan Öğeler (Ayırt Edici Özellikler):
1. **Fonksiyonun Adı:** İsmin aynı olması şarttır.
2. **Parametre Sayısı:** Örneğin `f(int)` ile `f(int, int)` farklı imzalardır.
3. **Parametre Veri Tipleri:** Örneğin `f(int)` ile `f(double)` farklı imzalardır.
4. **Parametrelerin Sıralaması:** Örneğin `f(int, double)` ile `f(double, int)` farklı imzalardır.
5. **Referans ve Gösterici Nitelikleri:** `f(int&)` ile `f(const int&)` veya `f(int*)` ile `f(const int*)` farklı imzalardır.
6. **Üye Fonksiyonlarda `const` Niteleyicisi:** Bir sınıfın üye metodunda `void goster()` ile `void goster() const` iki ayrı fonksiyondur (nesne sabit ise `const` olan çağrılır).

#### İmzaya Kesinlikle Dahil OLMAYANLAR (Aşırı Yükleme İçin Yetersiz Durumlar):
1. **Geri Dönüş Değeri (`Return Type`):**
   ```cpp
   int hesapla(int x);
   double hesapla(int x); // DERLEME HATASI! (call cannot be resolved by return type alone)
   ```
   > [!WARNING]
   > **Neden Dönüş Tipi İmzaya Dahil Değildir?**  
   > Çünkü C++'ta bir fonksiyon `hesapla(10);` şeklinde dönüş değeri bir değişkene atanmadan (göz ardı edilerek) çağrılabilir. Bu durumda derleyici hangi fonksiyonun çalıştırılmak istendiğini asla bilemez!
2. **Parametre İsimleri:** Prototipteki `void ciz(int genislik)` ile `void ciz(int g)` tamamen aynıdır.
3. **Değer ile Aktarımda (`Pass-by-value`) `const` Niteleyicisi:**
   ```cpp
   void yazdir(int x);
   void yazdir(const int x); // DERLEME HATASI! (redefinition)
   ```
   Çünkü fonksiyon çağrılırken argüman zaten kopyalanır; çağıran taraf açısından parametrenin içeride sabit olması bir fark yaratmaz.
4. **Tür Takma Adları (`typedef` / `using`):**
   ```cpp
   typedef int Tamsayi;
   void test(int x);
   void test(Tamsayi x); // DERLEME HATASI! (Tamsayi ayrı bir tür değil, int'in takma adıdır)
   ```

---

### 1.3. Arka Planda Ne Olur? Name Mangling (İsim Bozma / Süsleme) ve `extern "C"`

C++ derleyicisi, aşırı yüklenmiş fonksiyonları derlerken ve bağlarken (*linking*) her birine sembol tablosunda benzersiz bir isim atar. Bu işleme **Name Mangling (İsim Süsleme)** denir.

Örneğin GCC/Clang derleyicisinde:
- `void print(int)` $\rightarrow$ `_Z5printi`
- `void print(double)` $\rightarrow$ `_Z5printd`
- `void print(int, double)` $\rightarrow$ `_Z5printid`

```
[Kaynak Kod: print(5)] ─────▶ [Derleyici: Mangling] ─────▶ [_Z5printi(5) Makine Kodu]
```

#### C ile C++ Kodlarını Birlikte Kullanma (`extern "C"`):
C derleyicileri *name mangling* yapmaz; sembol tablosuna fonksiyonu doğrudan `print` adıyla yazar. Bu yüzden C dilinde yazılmış bir kütüphaneyi C++ projenize dahil ettiğinizde C++ derleyicisinin süslü isim arayıp `undefined reference` hatası vermesini engellemek için `extern "C"` kullanılır:

```cpp
extern "C" {
    int sum(int a, int b); // Derleyiciye bu fonksiyonu C kurallarıyla (süslenmeden) ara der
}
```

---

### 1.4. Aşırı Yükleme Çözümleme Aşamaları (Overload Resolution) ve Belirsizlik (Ambiguity)

Derleyici bir fonksiyon çağrısıyla karşılaştığında şu 3 adımı uygular:
1. **Aday Fonksiyonlar (Candidate Functions):** Çağrılan isimle aynı ada sahip ve o kapsamda görünür olan tüm fonksiyonlar listelenir.
2. **Uygun Fonksiyonlar (Viable Functions):** Parametre sayısı uyan ve gönderilen argümanların örtük dönüşümle (*implicit conversion*) atanabildiği fonksiyonlar seçilir.
3. **En İyi Eşleşme (Best Match):** Aşağıdaki öncelik sırasına göre en uygun olan seçilir:
   - **Seviye 1 (Tam Eşleşme - Exact Match):** Tip doğrudan uyuşuyor veya lvalue/rvalue / const niteliği tam oturuyor.
   - **Seviye 2 (Yükseltme - Type Promotion):** `char`, `short`, `bool` $\rightarrow$ `int`; `float` $\rightarrow$ `double`.
   - **Seviye 3 (Standart Dönüşüm - Standard Conversion):** `int` $\rightarrow$ `double`, `double` $\rightarrow$ `int`, `derived*` $\rightarrow$ `base*`.
   - **Seviye 4 (Kullanıcı Tanımlı Dönüşüm - User-Defined Conversion):** Sınıf kurucuları (`converting constructor`) veya dönüşüm operatörleri (`operator Type()`).

#### ⚠️ Kritik Derleme Hataları: Belirsiz Çağrı (Ambiguity)
Birden fazla uygun fonksiyon aynı eşleşme seviyesinde kaldığında derleyici seçim yapamaz ve `call of overloaded '...' is ambiguous` derleme hatası verir:

1. **Varsayılan Argüman (Default Argument) ile Çakışma:**
   ```cpp
   void hesapla(int a);
   void hesapla(int a, int b = 0);

   hesapla(10); // HATA! Derleyici 1. fonksiyonu mu yoksa 2. fonksiyonun varsayılan halini mi çağıracağını bilemez!
   ```
2. **Eşit Mesafeli Tip Dönüşümü:**
   ```cpp
   void goster(long x);
   void goster(double x);

   goster(5); // HATA! 5 (int) türündedir. Hem int->long hem int->double standart dönüşümdür; öncelik farkı yoktur!
   ```
3. **Değer ile Referans Geçişi Arasındaki Belirsizlik:**
   ```cpp
   void yaz(int x);
   void yaz(int& x);

   int sayi = 20;
   yaz(sayi); // HATA! 'sayi' hem değere kopyalanabilir hem de referansa bağlanabilir.
   ```

---

### 1.5. Kapsamlı Kod Örneği: Fonksiyon Aşırı Yükleme

```cpp
#include <iostream>
#include <string>

using namespace std;

// 1. Temel tipler için aşırı yükleme
void ekranaYaz(int sayi) {
    cout << "[int] Tamsayi degeri: " << sayi << endl;
}

void ekranaYaz(double sayi) {
    cout << "[double] Ondalikli sayi degeri: " << sayi << endl;
}

void ekranaYaz(const string& metin) {
    cout << "[string] Metin verisi: " << metin << endl;
}

// 2. Parametre sayısı ile aşırı yükleme
void ekranaYaz(int sayi1, int sayi2) {
    cout << "[int, int] Iki tamsayi: " << sayi1 << " ve " << sayi2 << endl;
}

// 3. Parametre sırası ile aşırı yükleme
void personeliListele(string ad, int sicilNo) {
    cout << "Personel: " << ad << " (Sicil No: " << sicilNo << ")" << endl;
}

void personeliListele(int sicilNo, string ad) {
    cout << "Sicil No: " << sicilNo << " -> Personel: " << ad << endl;
}

// 4. const referans vs referans (Aşırı yükleme ayrımı)
void degerGuncelle(int& x) {
    x += 10;
    cout << "[int&] L-value referans uzerinden guncellendi: " << x << endl;
}

void degerGuncelle(const int& x) {
    cout << "[const int&] Salt okunur veya gecici (r-value) deger: " << x << endl;
}

int main() {
    cout << "--- 1. Tip Tabanli Asiri Yukleme ---" << endl;
    ekranaYaz(42);               // [int] cagirilir
    ekranaYaz(3.1415);           // [double] cagirilir
    ekranaYaz(string("KTU C++"));// [string] cagirilir

    cout << "\n--- 2. Parametre Sayisi ve Siralamasi ---" << endl;
    ekranaYaz(10, 20);           // [int, int] cagirilir
    personeliListele("Ahmet", 101);
    personeliListele(102, "Ayse");

    cout << "\n--- 3. Referans ve Const Referans Ayrimi ---" << endl;
    int a = 5;
    degerGuncelle(a);            // Degisken oldugu icin int& cagirilir (a = 15 olur)
    degerGuncelle(100);          // 100 gecici r-value oldugu icin const int& cagirilir

    return 0;
}
```

---

## 2. this Göstericisi ve Metot Zincirleme (Method Chaining)

İlgili kaynak dosya: [this-pointer.cpp](this-pointer.cpp)

`this`, C++ dilinde bir sınıfın **statik olmayan herhangi bir üye fonksiyonu çağrıldığında**, o an o fonksiyonu yürüten nesnenin **bellekteki adresini tutan örtük (implicit) bir göstericidir (pointer)**.

---

### 2.1. `this` Göstericisinin Felsefesi ve Bellek Mimarisi

Bir `Saat` sınıfından 100 adet nesne ürettiğimizi varsayalım:
```cpp
Saat s1, s2, s3, ..., s100;
```
Bellekte ne olur?
- Her bir nesnenin üye değişkenleri (`saat`, `dakika`, `saniye`) bellekte (Stack veya Heap) **ayrı ayrı yer tutar** (100 farklı bellek bloğu).
- Ancak üye fonksiyonların makine kodları (`yazdir()`, `setZaman()`) belleğin **Kod Bölümünde (Code / Text Segment) SADECE TEK BİR KOPYA** olarak saklanır!

Peki, `s1.yazdir()` ve `s2.yazdir()` çağrıldığında çalışan aynı makine kodu, `s1`'in mi yoksa `s2`'nin mi değişkenlerini yazdıracağını nereden bilir?

#### Gizli Parametre Mekanizması:
Derleyici, siz farkında olmadan üye fonksiyon çağrılarını ve tanımlarını dönüştürür:

```cpp
// 1. Bizim yazdigimiz cagri:
benimSaat.setZaman(14, 45, 15);

// 2. Derleyicinin arka planda urettigi gercek cagri:
Saat::setZaman(&benimSaat, 14, 45, 15);
```

Fonksiyonun arka plandaki prototipi ise şöyledir:
```cpp
// Derleyici 'this' isaretcisini ilk parametre olarak gizlice ekler:
void Saat::setZaman(Saat* const this, int saat, int dakika, int saniye) {
    this->saat = saat;
    this->dakika = dakika;
    this->saniye = saniye;
}
```

---

### 2.2. `this` Göstericisinin Türü ve Nitelikleri

1. **Sabit Bir İşaretçidir (`T* const this`):**
   `this` bir r-value ifadedir. `this` göstericisinin işaret ettiği adres fonksiyon içinde değiştirilemez:
   ```cpp
   this = &baskaNesne; // DERLEME HATASI! (l-value required as left operand of assignment)
   ```
2. **`const` Üye Fonksiyonlarda Durumu (`const T* const this`):**
   Bir üye fonksiyon `void yazdir() const` şeklinde bildirildiğinde, `this` göstericisinin tipi `const Saat* const this` haline gelir. Bu sayede o fonksiyon içinde hiçbir üye değişkenin değeri değiştirilemez:
   ```cpp
   void Saat::yazdir() const {
       // this->saat = 12; // DERLEME HATASI! const nesne alanina yazma yapilamaz
       cout << this->saat << ":" << this->dakika << endl; // Gecerli (salt okunur)
   }
   ```
3. **Neden `static` Üye Fonksiyonlarda `this` Göstericisi Yoktur?**
   `static` fonksiyonlar nesnelere değil, doğrudan sınıfın kendisine aittir (`Saat::toplamNesneSayisi()`). Fonksiyon çağrılırken ortada bir nesne örneği veya nesne adresi bulunmaz. Bu nedenle:
   - `static` fonksiyonlar içinde `this` kullanılamaz.
   - `static` fonksiyonlar sınıfın statik olmayan üye değişkenlerine doğrudan erişemez.

---

### 2.3. `this` Göstericisinin 5 Temel Kullanım Alanı

| No | Kullanım Alanı | Açıklama | Tipik Örnek Kod |
| :---: | :--- | :--- | :--- |
| **1** | **İsim Gölgelemesini Önleme** (*Name Shadowing / Hiding*) | Parametre adı ile üye değişken adı aynı olduğunda karışıklığı giderir. | `this->saat = saat;` |
| **2** | **Metot Zincirleme** (*Method Chaining / Fluent Interface*) | Fonksiyondan nesnenin kendisini (`return *this;`) referans döndürerek ardışık çağrılar sağlar. | `s.setSaat(10).setDakika(30).yazdir();` |
| **3** | **Kendine Atama Kontrolü** (*Self-Assignment Check*) | Atama operatöründe (`operator=`) nesnenin kendisine atanmasını (`a = a;`) denetler. | `if (this == &diger) return *this;` |
| **4** | **Kendini Dışarı Parametre Geçme** | Nesnenin kendisini başka bir sınıfa veya fonksiyona argüman olarak iletmesini sağlar. | `kayitSistemi.kaydet(*this);` veya `kaydet(this);` |
| **5** | **Nesne Kimliği Karşılaştırması** | İki referansın aynı bellek adresindeki nesneyi gösterip göstermediğini doğrular. | `bool ayniMi = (this == &digerNesne);` |

---

### 2.4. Metot Zincirleme (Method Chaining): Neden Referans (`Saat&`) Dönülmelidir?

Metot zincirleme yaparken dönüş tipini `Saat` (değer ile) mi yoksa `Saat&` (referans ile) mi belirlediğiniz hayati önem taşır:

```cpp
// HATALI YAKLAŞIM: Deger ile donme (Saat)
Saat setSaat(int s) {
    this->saat = s;
    return *this; // DİKKAT: Nesnenin gecici bir KOPYASI olusturulur!
}

// DOGRU YAKLASIM: Referans ile donme (Saat&)
Saat& setSaat(int s) {
    this->saat = s;
    return *this; // Asil nesnenin kendisine referans dondurulur (Kopya yok!)
}
```

> [!CAUTION]
> Eğer `Saat` (değer) dönerseniz; her zincirleme adımında yeni ve geçici bir kopya oluşturulur. Bir sonraki fonksiyon bu geçici kopya üzerinde çalışır ve zincir bittiğinde kopyalar bellekten silinir. Sonuç olarak asıl nesneniz güncellenmemiş olur! Bu yüzden zincirleme çağrılarda her zaman **referans (`Sinif&`)** döndürülmelidir.

---

### 2.5. Kapsamlı Kod Örneği: `this` Göstericisi ve Metot Zincirleme

```cpp
#include <iostream>
#include <iomanip>

using namespace std;

class Saat {
private:
    int saat;
    int dakika;
    int saniye;

public:
    // Yapici metotta baslatma ve varsayilan degerler
    Saat(int saat = 0, int dakika = 0, int saniye = 0) {
        // 1. Kullanim: Parametre ve uye degisken isimleri ayni oldugunda this-> zorunludur
        this->saat = saat;
        this->dakika = dakika;
        this->saniye = saniye;
    }

    // 2. Kullanim: *this referansi donduren zincirleme (Fluent API) metotlari
    Saat& saatAyarla(int saat) {
        this->saat = (saat >= 0 && saat < 24) ? saat : 0;
        return *this; // Mevcut nesnenin kendisini dondurur
    }

    Saat& dakikaAyarla(int dakika) {
        this->dakika = (dakika >= 0 && dakika < 60) ? dakika : 0;
        return *this;
    }

    Saat& saniyeAyarla(int saniye) {
        this->saniye = (saniye >= 0 && saniye < 60) ? saniye : 0;
        return *this;
    }

    // Nesnenin bellek adresini ekrana yazdiran metot
    void adresGoster() const {
        cout << "Bu nesnenin bellekteki adresi (this): " << this << endl;
    }

    // const uye metot: this isaretcisinin tipi 'const Saat* const this' olur
    void yazdir() const {
        cout << setfill('0') << setw(2) << this->saat << ":"
             << setw(2) << this->dakika << ":"
             << setw(2) << this->saniye << endl;
    }

    // 5. Kullanim: Nesne kimligi kontrolu
    bool ayniNesneMi(const Saat& diger) const {
        return this == &diger; // Adresler ayni ise ayni nesnedir
    }
};

int main() {
    cout << "=== 1. this Pointer ile Nesne Adresleri ===" << endl;
    Saat saat1(9, 15, 30);
    Saat saat2(12, 0, 0);

    cout << "saat1 icin: ";
    saat1.adresGoster();
    cout << "saat1 adresi (&saat1): " << &saat1 << endl;

    cout << "saat2 icin: ";
    saat2.adresGoster();
    cout << "saat2 adresi (&saat2): " << &saat2 << endl;

    cout << "\n=== 2. *this ile Metot Zincirleme (Method Chaining) ===" << endl;
    cout << "Zincirleme oncesi saat1: ";
    saat1.yazdir();

    cout << "Zincirleme ile guncellenen saat1: ";
    // Metot zincirleme cagrisi (Cascading)
    saat1.saatAyarla(21).dakikaAyarla(45).saniyeAyarla(59).yazdir();

    cout << "\n=== 3. Nesne Kimligi Karsilastirmasi ===" << endl;
    Saat& saatReferansi = saat1;
    cout << "saat1 ile saatReferansi ayni nesne mi? " 
         << (saat1.ayniNesneMi(saatReferansi) ? "EVET (Ayni Adres)" : "HAYIR") << endl;
    cout << "saat1 ile saat2 ayni nesne mi? " 
         << (saat1.ayniNesneMi(saat2) ? "EVET (Ayni Adres)" : "HAYIR (Farkli Adres)") << endl;

    return 0;
}
```

---

## 3. Operatör Aşırı Yüklemeye Giriş ve Temel Kurallar

İlgili kaynak dosya: [operator-overloading.cpp](operator-overloading.cpp)

Operatör aşırı yükleme, yerleşik operatörlerin (`+`, `-`, `==`, `<<` vb.) nesneler üzerinde doğal ve okunabilir bir şekilde çalışmasını sağlar (örn: `karmasik1 + karmasik2`).

### Temel Kurallar:
1. **Yeni operatör icat edilemez.** Yalnızca dilde zaten var olan operatörler aşırı yüklenebilir (`**` veya `<>` gibi yeni semboller üretilemez).
2. **Operatörlerin öncelik ve birleşme yönü (associativity) değiştirilemez.**
3. **Temel tiplerin davranışı değiştirilemez.** En az bir operand kullanıcı tanımlı sınıf türünden olmalıdır (`int + int` davranışı değiştirilemez).
4. **Şu Operatörler Kesinlikle Aşırı Yüklenemez:**
   - `.` (Nokta üye erişim)
   - `.*` (Üye gösterici erişim)
   - `::` (Kapsam çözünürlüğü)
   - `?:` (Koşul/Ternary operatörü)
   - `sizeof` (Boyut alma)

---

## 4. Üye Fonksiyon (Member) vs Arkadaş Fonksiyon (Friend) ile Aşırı Yükleme

İlgili kaynak dosyalar: [friend-function.cpp](friend-function.cpp), [overload-with-friend.cpp](overload-with-friend.cpp)

Bir operatör iki farklı şekilde aşırı yüklenebilir:

### 1. Üye Fonksiyon Olarak:
`A + B` ifadesi `A.operator+(B)` olarak yorumlanır. Sol taraftaki operand (`A`) mutlaka o sınıfın nesnesi olmalıdır.

### 2. Arkadaş (`friend`) Fonksiyon Olarak:
`A + B` ifadesi `operator+(A, B)` olarak bağımsız bir fonksiyon gibi çağrılır. `friend` anahtar kelimesi sayesinde fonksiyon sınıfın `private` üyelerine doğrudan erişebilir.

> [!IMPORTANT]
> **Değişme Özelliği (Commutativity) Sorunu:** `karmasik + 5.0` işlemi üye fonksiyon ile çözülebilir (`karmasik.operator+(5.0)`). Ancak `5.0 + karmasik` yazıldığında sol taraf `double` olduğu için üye metot çağrılamaz! Bu tür simetrik durumlarda **`friend` fonksiyon kullanılması zorunludur**.

---

## 5. İkili (Binary) ve Aritmetik Operatörlerin Aşırı Yüklenmesi (+, -, *)

İlgili kaynak dosya: [binary-operators.cpp](binary-operators.cpp)

Karmaşık sayı (*Complex Number*) sınıfı üzerinde `+` operatörünü inceleyelim:

```cpp
#include <iostream>
using namespace std;

class Karmasik {
private:
    double gercek, sanal;

public:
    Karmasik(double g = 0, double s = 0) : gercek(g), sanal(s) {}

    // Üye fonksiyon ile + operatörünü aşırı yükleme
    Karmasik operator+(const Karmasik& diger) const {
        return Karmasik(this->gercek + diger.gercek, this->sanal + diger.sanal);
    }

    void yazdir() const {
        cout << gercek << " + " << sanal << "i" << endl;
    }

    // friend fonksiyon prototipi (double + Karmasik için)
    friend Karmasik operator+(double sayi, const Karmasik& k);
};

// Sınıf dışı friend fonksiyon
Karmasik operator+(double sayi, const Karmasik& k) {
    return Karmasik(sayi + k.gercek, k.sanal);
}

int main() {
    Karmasik k1(2.5, 3.0), k2(1.5, 2.0);
    Karmasik k3 = k1 + k2;    // k1.operator+(k2)
    Karmasik k4 = 10.0 + k1;  // operator+(10.0, k1) - friend fonksiyon

    k3.yazdir(); // 4 + 5i
    k4.yazdir(); // 12.5 + 3i
    return 0;
}
```

---

## 6. İlişkisel (Relational) Operatörler (==, !=, <, >)

İlgili kaynak dosya: [relational-operators.cpp](relational-operators.cpp)

İlişkisel operatörler iki nesneyi karşılaştırır ve geriye her zaman `bool` (`true`/`false`) döndürür:

```cpp
class Zaman {
    int toplamSaniye;
public:
    Zaman(int s) : toplamSaniye(s) {}

    bool operator==(const Zaman& diger) const {
        return this->toplamSaniye == diger.toplamSaniye;
    }

    bool operator<(const Zaman& diger) const {
        return this->toplamSaniye < diger.toplamSaniye;
    }

    bool operator!=(const Zaman& diger) const {
        return !(*this == diger); // == üzerinden tanımlama (Best practice)
    }
};
```

---

## 7. Tekli (Unary) Operatörler ve Artırma/Azaltma (++ ve --)

İlgili kaynak dosyalar: [unary-operator.cpp](unary-operator.cpp), [increment-operator.cpp](increment-operator.cpp)

### Ön Artırma (`++x`) vs Son Artırma (`x++`) Ayrımı
C++ derleyicisi bu iki durumu birbirinden ayırmak için son artırma operatörüne kukla bir tamsayı parametresi (`int`) ekler:

```cpp
#include <iostream>
using namespace std;

class Sayac {
private:
    int deger;
public:
    Sayac(int d = 0) : deger(d) {}

    // 1. Ön Artırma (++obj): Değeri artır ve güncel nesneyi referansla dön
    Sayac& operator++() {
        ++deger;
        return *this;
    }

    // 2. Son Artırma (obj++): Eski değeri geçici nesnede sakla, artır, eskiyi kopyayla dön
    Sayac operator++(int) { // Kukla 'int' parametresi son artırmayı belirtir
        Sayac temp = *this;
        deger++;
        return temp; // Eski değer döner
    }

    int getDeger() const { return deger; }
};
```

---

## 8. Akış Giriş-Çıkış Operatörleri (<< ve >>)

İlgili kaynak dosya: [iostream-operators.cpp](iostream-operators.cpp)

`cout << nesne` veya `cin >> nesne` yazabilmek için `std::ostream&` ve `std::istream&` alan `friend` fonksiyonlar tanımlanır:

```cpp
#include <iostream>
using namespace std;

class Nokta {
private:
    int x, y;
public:
    Nokta(int x = 0, int y = 0) : x(x), y(y) {}

    // Çıkış Akışı (<<): cout << n1 << n2 zincirleme çağrısı için ostream& dönmelidir
    friend ostream& operator<<(ostream& os, const Nokta& n) {
        os << "(" << n.x << ", " << n.y << ")";
        return os;
    }

    // Giriş Akışı (>>): cin >> n
    friend istream& operator>>(istream& is, Nokta& n) {
        cout << "X ve Y giriniz: ";
        is >> n.x >> n.y;
        return is;
    }
};

int main() {
    Nokta p(10, 20);
    cout << "Nokta koordinatı: " << p << endl; // (10, 20)
    return 0;
}
```

---

## 9. Atama (=) ve İndis ([]) Operatörleri

İlgili kaynak dosyalar: [assing-operator.cpp](assing-operator.cpp), [subscript-operator.cpp](subscript-operator.cpp)

### 1. Atama Operatörü (`operator=`)
Nesneye başka bir nesne atandığında (`a = b;`) derin kopyalama yapılmasını sağlar. **Kendine atama kontrolü (`this == &diger`) hayati önem taşır:**
```cpp
class DiziYonetici {
    int* data;
    int boyut;
public:
    DiziYonetici& operator=(const DiziYonetici& diger) {
        if (this == &diger) return *this; // Kendine atama kontrolü (Self-assignment check)

        delete[] data; // 1. Eski belleği temizle
        boyut = diger.boyut;
        data = new int[boyut]; // 2. Yeni bellek tahsis et
        for (int i = 0; i < boyut; i++) data[i] = diger.data[i]; // 3. Derin kopyala

        return *this;
    }
};
```

### 2. İndis Operatörü (`operator[]`)
Nesnenin dizi gibi `nesne[i]` şeklinde kullanılmasını sağlar. Hem okuma hem yazma yapılabilmesi için referans dönmelidir:
```cpp
int& operator[](int indeks) {
    return data[indeks];
}
```

---

## 10. Ekstra: C++20 Uzay Gemisi Operatörü (<=>) ve Functor Yapısı (operator())

İlgili kaynak dosya: [function-operator.cpp](function-operator.cpp)

### 1. Functor (Fonksiyon Çağrı Operatörü `operator()`)
Bir sınıf nesnesinin fonksiyon gibi çağrılabilmesini sağlar:
```cpp
class Carpici {
    int katsayi;
public:
    Carpici(int k) : katsayi(k) {}
    int operator()(int x) const { return x * katsayi; }
};

Carpici besIleCarp(5);
cout << besIleCarp(10); // 50 yazar (Nesne fonksiyon gibi çağrıldı)
```

### 2. Üç Yönlü Karşılaştırma / Uzay Gemisi Operatörü (`<=>` - C++20)
Tek bir operatörle `<, <=, ==, !=, >=, >` operatörlerinin tamamının derleyici tarafından otomatik üretilmesini sağlar:
```cpp
#include <compare>
class Skor {
    int puan;
public:
    auto operator<=>(const Skor&) const = default; // Tüm karşılaştırmaları otomatik üretir!
};
```

---

## 11. Kodları Derleme ve Çalıştırma Rehberi (Komut Tablosu)

Bu dizindeki operatör aşırı yükleme programlarını terminal üzerinden derlemek ve çalıştırmak için:

```bash
# Genel Şablon:
g++ -std=c++17 -Wall dosya_adi.cpp -o app
./app         # Linux / macOS / Git Bash
.\app.exe     # Windows PowerShell / CMD
```

### Hızlı Başvuru Komut Tablosu

| Kaynak Kod Dosyası | Açıklama | Hızlı Derleme ve Çalıştırma (Bash / Linux / Mac) | Hızlı Derleme ve Çalıştırma (Windows PowerShell) |
| :--- | :--- | :--- | :--- |
| `function-overloading.cpp` | Fonksiyon Aşırı Yükleme Örnekleri | `g++ -std=c++17 function-overloading.cpp -o app && ./app` | `g++ -std=c++17 function-overloading.cpp -o app; .\app.exe` |
| `c-polymorphizm.c` | C Dilinde Aşırı Yükleme Sınırlılığı | `gcc c-polymorphizm.c -o app && ./app` | `gcc c-polymorphizm.c -o app; .\app.exe` |
| `this-pointer.cpp` | `this` Göstericisi ve Zincirleme | `g++ -std=c++17 this-pointer.cpp -o app && ./app` | `g++ -std=c++17 this-pointer.cpp -o app; .\app.exe` |
| `binary-operators.cpp` | İkili Operatörler (`+`, `-`, `*`) | `g++ -std=c++17 binary-operators.cpp -o app && ./app` | `g++ -std=c++17 binary-operators.cpp -o app; .\app.exe` |
| `unary-operator.cpp` | Tekli Operatörler (`-`, `!`) | `g++ -std=c++17 unary-operator.cpp -o app && ./app` | `g++ -std=c++17 unary-operator.cpp -o app; .\app.exe` |
| `increment-operator.cpp` | Ön/Son Artırma (`++`, `--`) | `g++ -std=c++17 increment-operator.cpp -o app && ./app` | `g++ -std=c++17 increment-operator.cpp -o app; .\app.exe` |
| `relational-operators.cpp` | Karşılaştırma (`==`, `<`, `>`) | `g++ -std=c++17 relational-operators.cpp -o app && ./app` | `g++ -std=c++17 relational-operators.cpp -o app; .\app.exe` |
| `iostream-operators.cpp` | Akış Giriş/Çıkış (`<<`, `>>`) | `g++ -std=c++17 iostream-operators.cpp -o app && ./app` | `g++ -std=c++17 iostream-operators.cpp -o app; .\app.exe` |
| `assing-operator.cpp` | Atama Operatörü (`=`) | `g++ -std=c++17 assing-operator.cpp -o app && ./app` | `g++ -std=c++17 assing-operator.cpp -o app; .\app.exe` |
| `subscript-operator.cpp` | İndis Operatörü (`[]`) | `g++ -std=c++17 subscript-operator.cpp -o app && ./app` | `g++ -std=c++17 subscript-operator.cpp -o app; .\app.exe` |
| `friend-function.cpp` | Arkadaş (`friend`) Fonksiyonlar | `g++ -std=c++17 friend-function.cpp -o app && ./app` | `g++ -std=c++17 friend-function.cpp -o app; .\app.exe` |
| `overload-with-friend.cpp` | `friend` ile Simetrik Aşırı Yükleme | `g++ -std=c++17 overload-with-friend.cpp -o app && ./app` | `g++ -std=c++17 overload-with-friend.cpp -o app; .\app.exe` |
| `function-operator.cpp` | Fonksiyon Çağrı Operatörü `()` | `g++ -std=c++17 function-operator.cpp -o app && ./app` | `g++ -std=c++17 function-operator.cpp -o app; .\app.exe` |

---

## 12. Pekiştirme Alıştırmaları (Çözümlü Sorular)

### Soru 1: Ön ve Son Artırma Çıktı Analizi
Aşağıdaki kodun çıktısı nedir?
```cpp
#include <iostream>
using namespace std;

class Sayi {
    int n;
public:
    Sayi(int n) : n(n) {}
    Sayi& operator++() { ++n; return *this; }
    Sayi operator++(int) { Sayi t = *this; n++; return t; }
    int val() const { return n; }
};

int main() {
    Sayi s(5);
    Sayi a = ++s;
    Sayi b = s++;
    cout << "s:" << s.val() << " a:" << a.val() << " b:" << b.val() << endl;
    return 0;
}
```
**Çözüm:**
- `++s`: `s` 6 olur, referansı `a`'ya kopyalanır (`a = 6`).
- `s++`: Eski değer (6) geçici nesnede saklanır, `s` 7 olur. `b`'ye eski değer atanır (`b = 6`).
- Çıktı: `s:7 a:6 b:6`.

---

### Soru 2: Fonksiyon Aşırı Yükleme ve Belirsizlik (Ambiguity) Analizi
Aşağıdaki C++ kodunun derleme durumunu ve olası hataları analiz ediniz:
```cpp
#include <iostream>
using namespace std;

void yaz(int x) { cout << "int: " << x << endl; }
void yaz(double x) { cout << "double: " << x << endl; }
void yaz(int x, int y = 5) { cout << "int, int: " << x << ", " << y << endl; }

int main() {
    yaz(3.14);  // (A)
    yaz('A');   // (B)
    yaz(10);    // (C)
    return 0;
}
```
**Çözüm:**
- `(A) yaz(3.14);`: Sorunsuz derlenir. `3.14` bir `double` literali olduğu için Seviye 1 (Exact Match - Tam Eşleşme) ile `yaz(double)` çağrılır. Çıktı: `double: 3.14`.
- `(B) yaz('A');`: Sorunsuz derlenir. `'A'` bir `char` türündedir. C++ kurallarına göre `char`, integral yükseltme (*integral promotion*) ile `int` türüne terfi eder (Seviye 2). Bu nedenle `yaz(int)` çağrılır. Çıktı: `int: 65`.
- `(C) yaz(10);`: **DERLEME HATASI VERİR! (Ambiguous call)**. `10` bir `int`'tir. Derleyici karşısında iki uygun fonksiyon görür: `void yaz(int)` ve ikinci parametresi varsayılan değere (`y = 5`) sahip olan `void yaz(int, int = 5)`. Her ikisi de tek bir `int` argüman ile çağrılabilir ve ikisi de tam eşleşmedir. Derleyici hangisinin kastedildiğini çözemez ve derleme hatası üretir.

---

### Soru 3: `this` Göstericisi ve Metot Zincirlemede Değer vs Referans Farkı
Aşağıdaki sınıf tasarımında `topla` fonksiyonunun dönüş tipi `Sayac&` yerine `Sayac` olsaydı `main` içindeki zincirleme işleminin sonucunda `s.deger()` ne olurdu?
```cpp
#include <iostream>
using namespace std;

class Sayac {
    int sayi;
public:
    Sayac(int s = 0) : sayi(s) {}
    
    // Dikkat: Referans (Sayac&) yerine Deger (Sayac) donuyor!
    Sayac topla(int x) {
        sayi += x;
        return *this;
    }
    int deger() const { return sayi; }
};

int main() {
    Sayac s(10);
    s.topla(5).topla(20);
    cout << "Sonuc: " << s.deger() << endl;
    return 0;
}
```
**Çözüm:**
- Konsola **Sonuc: 15** yazılır (Beklenen 35 değildir!).
- **Nedeni:** `s.topla(5)` çağrıldığında `s.sayi` değeri 15 olur. Ancak fonksiyon `Sayac` (değer ile) döndüğü için `*this` ifadesi `s` nesnesinin bellekte **isimsiz, geçici bir kopyasını** (*temporary copy*) üretir.
- Ardından gelen `.topla(20)` çağrısı `s` nesnesi üzerinde değil, bu **geçici kopya** üzerinde çalışır ve kopyanın değerini 35 yapar.
- İfade satırı bittiğinde geçici kopya bellekten tamamen silinir.
- Asıl `s` nesnesinin değeri ise ilk adımda kaldığı gibi `15` olarak kalır. Zincirleme çağrıların asıl nesneyi değiştirebilmesi için fonksiyonun mutlaka `Sayac&` (referans) döndürmesi şarttır!

---

## 13. Öğrenciler İçin Ev Ödevleri

### Ödev 1: Tam Kapsamlı Karmaşık Sayı Kütüphanesi
- **Görev:** `Karmasik` sınıfı için `+`, `-`, `*`, `/`, `==`, `!=`, `+=`, `-=`, `<<`, `>>` operatörlerinin tamamını aşırı yükleyiniz. `(a + bi) / (c + di)` bölme kuralını formüle uygun olarak kodlayınız.

### Ödev 2: Dinamik Güvenli String Sınıfı (`Stringim`)
- **Görev:** Kendi string sınıfınızı yazınız:
  - `+` ile string birleştirme,
  - `==` ile metin eşitliği,
  - `[]` ile sınır kontrollü karaktere erişim (`at()`),
  - `=` operatöründe derin kopyalama ve bellek temizliği.

### Ödev 3: Polinom Sınıfı ve Cebirsel İşlemler
- **Görev:** $P(x) = a_n x^n + \dots + a_1 x + a_0$ biçimindeki polinomları temsil eden `Polinom` sınıfı tasarlayınız. İki polinomun toplanması (`+`), çarpılması (`*`) ve $x$ değeri verilerek polinomun hesaplanması (`operator()(double x)`) işlemlerini aşırı yükleyiniz.
