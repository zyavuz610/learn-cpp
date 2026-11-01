# 7. Sınıflar ve Nesneler: Nesne Yönelimli Programlamaya Giriş (Classes & Objects)

Bu bölümde Nesne Yönelimli Programlama (Object-Oriented Programming - OOP) paradigmasının temelleri, sınıf (*class*) ve nesne (*object*) kavramları, erişim belirleyicileri ile veri gizleme (*encapsulation & data hiding*), kurucu ve yıkıcı metotlar (*constructors & destructors*), üye başlatma listeleri (*member initializer lists*), nesne dizileri, nesnelerin referansla aktarımı ve C++ projelerinde başlık (`.h`) ile kaynak (`.cpp`) dosyalarının ayrılması mimarisi ele alınmaktadır.

---

## 📑 İçindekiler
1. [Nesne Yönelimli Programlama Paradigması ve Avantajları](#1-nesne-yönelimli-programlama-paradigması-ve-avantajları)
2. [Sınıf (Class) ve Yapı (Struct) Karşılaştırması](#2-sınıf-class-ve-yapı-struct-karşılaştırması)
3. [Erişim Belirleyicileri (public, private, protected) ve Kapsülleme](#3-erişim-belirleyicileri-public-private-protected-ve-kapsülleme)
4. [Üye Fonksiyonlar: Sınıf İçi ve Dışı Tanımlama (Scope Resolution ::)](#4-üye-fonksiyonlar-sınıf-içi-ve-dışı-tanımlama-scope-resolution-)
5. [Kurucular (Constructors) ve Aşırı Yükleme](#5-kurucular-constructors-ve-aşırı-yükleme)
6. [Yıkıcılar (Destructors) ve Bellek Temizliği](#6-yıkıcılar-destructors-ve-bellek-temizliği)
7. [Çoklu Dosya Mimarisi: Arayüz (.h) ve Gerçekleme (.cpp) Ayrımı](#7-çoklu-dosya-mimarisi-arayüz-h-ve-gerçekleme-cpp-ayrımı)
8. [Nesne Dizileri ve Fonksiyonlara Nesne Aktarımı](#8-nesne-dizileri-ve-fonksiyonlara-nesne-aktarımı)
9. [Ekstra: Üye Başlatma Listeleri, const Üye Metotlar ve explicit Anahtar Kelimesi](#9-ekstra-üye-başlatma-listeleri-const-üye-metotlar-ve-explicit-anahtar-kelimesi)
10. [Pekiştirme Alıştırmaları (Çözümlü Sorular)](#10-pekiştirme-alıştırmaları-çözümlü-sorular)
11. [Öğrenciler İçin Ev Ödevleri](#11-öğrenciler-için-ev-ödevleri)

---

## 1. Nesne Yönelimli Programlama Paradigması ve Avantajları

İlgili kaynak dosya: [classes-objects.cpp](classes-objects.cpp)

Geleneksel yordamsal (*procedural*) programlamada (örneğin C dilinde) veriler değişkenlerde tutulur, bu verileri işleyen fonksiyonlar ise veriden ayrı bulunur. Proje büyüdükçe bu yaklaşım kod yönetimini zorlaştırır.

**Nesne Yönelimli Programlama (OOP)**, yazılımı gerçek dünyadaki nesnelere benzeyen birimlerle modeller. Her nesne hem **durumu/özellikleri (veriyi - attributes/fields)** hem de **davranışlarını (fonksiyonları - methods)** tek bir çatı altında birleştirir.

### OOP'nin 4 Temel Direği:
1. **Kapsülleme (Encapsulation):** Verilerin ve bu veriyi işleyen metotların sınıfta paketlenmesi; veriye kontrolsüz doğrudan erişimin engellenmesi.
2. **Soyutlama (Abstraction):** Kullanıcıya yalnızca gerekli arayüzün sunulması, karmaşık iç detayların gizlenmesi.
3. **Kalıtım (Inheritance):** Mevcut bir sınıftan ortak özelliklerin yeni sınıflara aktarılması; kodun yeniden kullanılabilirliği.
4. **Çok Biçimlilik (Polymorphism):** Aynı isimdeki eylemin farklı nesneler tarafından farklı şekillerde icra edilebilmesi.

---

## 2. Sınıf (Class) ve Yapı (Struct) Karşılaştırması

İlgili kaynak dosya: [classes-objects.cpp](classes-objects.cpp)

C++ dilinde `class` ve `struct` teknik olarak neredeyse aynı yeteneklere sahiptir. Aralarındaki tek temel fark **varsayılan erişim düzeyidir**:

| Kriter | `class` | `struct` |
| :--- | :--- | :--- |
| **Varsayılan Üye Erişimi** | `private` (Gizli) | `public` (Açık) |
| **Varsayılan Miras Erişimi** | `private` | `public` |
| **Tasarım Alışkanlığı** | Kapsülleme ve davranış (metotlar) içeren nesnelerde | Yalnızca veri tutan basit paketlerde (DTO / POD) |

```cpp
class Kutu {
    double hacim; // Varsayılan olarak PRIVATE'tır
};

struct Nokta {
    int x, y;     // Varsayılan olarak PUBLIC'tir
};
```

---

## 3. Erişim Belirleyicileri (public, private, protected) ve Kapsülleme

İlgili kaynak dosyalar: [public-modifiers.cpp](public-modifiers.cpp), [private-modifiers.cpp](private-modifiers.cpp), [protected-modifiers.cpp](protected-modifiers.cpp), [imp-hiding.cpp](imp-hiding.cpp)

Erişim belirleyicileri sınıf üyelerinin nereden erişilebileceğini kontrol eder:

- **`public`:** Sınıf içinden ve sınıfın dışındaki her yerden (örneğin `main` içinden) doğrudan erişilebilir.
- **`private`:** Yalnızca sınıfın kendi üye fonksiyonları tarafından erişilebilir. Dış dünyadan doğrudan erişilemez (Veri Gizleme).
- **`protected`:** Sınıf içinden ve bu sınıftan **türetilen alt sınıflardan (inheritance)** erişilebilir; dış dünyadan erişilemez.

```cpp
#include <iostream>
#include <string>
using namespace std;

class BankaHesabi {
private:
    // Veri Gizleme: Bakiye dışarıdan rastgele değiştirilemez!
    double bakiye;
    string hesapNo;

public:
    // Kurucu metot
    BankaHesabi(string no, double ilkBakiye) {
        hesapNo = no;
        bakiye = (ilkBakiye >= 0) ? ilkBakiye : 0;
    }

    // Setter (Mutator): Kontrollü değişiklik
    void paraYatir(double miktar) {
        if (miktar > 0) {
            bakiye += miktar;
            cout << miktar << " TL yatirildi.\n";
        }
    }

    // Getter (Accessor): Kontrollü okuma
    double getBakiye() const {
        return bakiye;
    }
};

int main() {
    BankaHesabi hesap("TR123456", 1000.0);
    // hesap.bakiye = 500000; // DERLEME HATASI! private üyeye doğrudan erişilemez.
    hesap.paraYatir(500.0);
    cout << "Guncel Bakiye: " << hesap.getBakiye() << " TL\n";
    return 0;
}
```

---

## 4. Üye Fonksiyonlar: Sınıf İçi ve Dışı Tanımlama (Scope Resolution ::)

İlgili kaynak dosya: [class-member-functions.cpp](class-member-functions.cpp)

Üye fonksiyonlar sınıf bildiriminin içinde yazılabileceği gibi, prototipi sınıf içinde bırakılıp gövdesi sınıfın dışında **kapsam çözünürlüğü operatörü (`::`)** ile tanımlanabilir:

```cpp
#include <iostream>
using namespace std;

class Dikdortgen {
private:
    int en, boy;

public:
    void setBoyutlar(int, int); // Sadece prototip bildirimi
    int alan();                 // Prototip
};

// Sınıf dışı fonksiyon tanımı (ClassName::FunctionName)
void Dikdortgen::setBoyutlar(int e, int b) {
    en = e;
    boy = b;
}

int Dikdortgen::alan() {
    return en * boy;
}
```

---

## 5. Kurucular (Constructors) ve Aşırı Yükleme

İlgili kaynak dosyalar: [constructor.cpp](constructor.cpp), [parametrized-constructor.cpp](parametrized-constructor.cpp)

Kurucu (Constructor), sınıftan bir nesne üretildiği anda derleyici tarafından **otomatik olarak çağrılan** özel bir üye fonksiyondur.

### Kurucu Özellikleri:
1. Sınıf ile **tamamen aynı ada** sahiptir.
2. Geri dönüş tipi **yoktur** (`void` bile yazılmaz).
3. `public` alanda tanımlanmalıdır.
4. Aşırı yüklenebilir (*overload* edilebilir: parametresiz varsayılan kurucu, parametreli kurucu).

```cpp
#include <iostream>
using namespace std;

class Araba {
private:
    string marka;
    int yil;

public:
    // 1. Varsayılan Kurucu (Default Constructor)
    Araba() {
        marka = "Bilinmiyor";
        yil = 2000;
        cout << "Varsayilan kurucu calisti.\n";
    }

    // 2. Parametreli Kurucu (Parameterized Constructor)
    Araba(string m, int y) {
        marka = m;
        yil = y;
        cout << marka << " (" << yil << ") nesnesi olusturuldu.\n";
    }

    void bilgi() const {
        cout << "Araba: " << marka << ", Model Yili: " << yil << endl;
    }
};

int main() {
    Araba a1;                 // Varsayılan kurucu
    Araba a2("Toyota", 2022); // Parametreli kurucu
    return 0;
}
```

---

## 6. Yıkıcılar (Destructors) ve Bellek Temizliği

İlgili kaynak dosya: [destructor.cpp](destructor.cpp)

Yıkıcı (Destructor), bir nesnenin ömrü bittiğinde (nesne bulunduğu kapsamdan/bloktan çıktığında veya `delete` edildiğinde) otomatik olarak çağrılan özel fonksiyondur.

- Sınıf adının başına tilda (`~`) getirilerek tanımlanır (`~Araba()`).
- Parametre alamaz ve aşırı yüklenemez; bir sınıfın **tek bir yıkıcısı** olabilir.
- **Yok Edilme Sırası (LIFO - Last In, First Out):** En son oluşturulan nesnenin yıkıcısı ilk olarak çalışır.

```cpp
#include <iostream>
using namespace std;

class KaynakYonetici {
public:
    int id;
    KaynakYonetici(int n) : id(n) {
        cout << "Nesne " << id << " olusturuldu.\n";
    }
    ~KaynakYonetici() {
        cout << "Nesne " << id << " yok edildi (Yikici calisti).\n";
    }
};

int main() {
    cout << "main basladi...\n";
    {
        KaynakYonetici k1(1);
        KaynakYonetici k2(2);
    } // Blok bitti: k2 ve k1 ters sirayla yok edilir
    cout << "main bitti...\n";
    return 0;
}
```

---

## 7. Çoklu Dosya Mimarisi: Arayüz (.h) ve Gerçekleme (.cpp) Ayrımı

İlgili kaynak dosyalar: [clockType.h](clockType.h), [clockType.cpp](clockType.cpp), [full-example.cpp](full-example.cpp), [full-example2.cpp](full-example2.cpp)

Büyük C++ projelerinde kodun temizliği ve derleme hızının artması için sınıflar iki dosyaya ayrılır:

1. **Başlık Dosyası (`.h` / Header):** Sınıf bildirimi, üye değişkenler ve metot prototipleri yer alır (Arayüz / Interface). Çoklu dahil etmeyi önlemek için `#ifndef / #define / #endif` (*include guards*) kullanılır.
2. **Kaynak Dosyası (`.cpp` / Implementation):** Metotların gövdeleri ve iş mantığı `ClassName::` ile burada kodlanır.

### Örnek: `clockType` Mimarisi

**`clockType.h`:**
```cpp
#ifndef CLOCKTYPE_H
#define CLOCKTYPE_H

class clockType {
public:
    clockType(int = 0, int = 0, int = 0); // Varsayılan argümanlı kurucu
    void setTime(int, int, int);
    void printTime() const;
    void incrementSeconds();

private:
    int hr, min, sec;
};

#endif
```

**`clockType.cpp`:**
```cpp
#include "clockType.h"
#include <iostream>
#include <iomanip>
using namespace std;

clockType::clockType(int h, int m, int s) {
    setTime(h, m, s);
}

void clockType::setTime(int h, int m, int s) {
    hr = (h >= 0 && h < 24) ? h : 0;
    min = (m >= 0 && m < 60) ? m : 0;
    sec = (s >= 0 && s < 60) ? s : 0;
}

void clockType::printTime() const {
    cout << setfill('0') << setw(2) << hr << ":"
         << setw(2) << min << ":"
         << setw(2) << sec << endl;
}
```

---

## 8. Nesne Dizileri ve Fonksiyonlara Nesne Aktarımı

İlgili kaynak dosyalar: [array-of-objects.cpp](array-of-objects.cpp), [class-reference.cpp](class-reference.cpp)

### 1. Nesne Dizileri
Bir sınıftan dizi oluşturulduğunda her bir eleman için otomatik olarak varsayılan kurucu (*default constructor*) çalıştırılır:
```cpp
clockType saatler[3] = {
    clockType(8, 30, 0),
    clockType(12, 0, 0),
    clockType(17, 45, 0)
};
```

### 2. Fonksiyonlara Nesne Aktarımı (`const ClassName&`)
Nesneleri fonksiyona değerle (*by value*) geçirmek nesnenin tüm verilerinin kopyalanmasına yol açar (kopyalama maliyeti). 
Bunun yerine nesneler **`const &` (sabit referans)** ile aktarılmalıdır:
```cpp
// Verimli ve güvenli: Kopyalama yapmaz, nesneyi değiştiremez
bool ayniMi(const clockType& s1, const clockType& s2) {
    // ...
}
```

---

## 9. Ekstra: Üye Başlatma Listeleri, const Üye Metotlar ve explicit Anahtar Kelimesi

### 1. Üye Başlatma Listesi (Member Initializer List)
Kurucu gövdesinde atama yapmak yerine değişkenleri doğrudan oluşturulma anında başlatır. `const` veya referans üyeler için **kullanılması zorunludur**:
```cpp
class Nokta {
private:
    const int x; // const üye
    int y;
public:
    // Üye başlatma listesi syntax'ı:
    Nokta(int a, int b) : x(a), y(b) {
        // Gövde boş kalabilir
    }
};
```

### 2. `const` Üye Metotlar
Metot bildiriminin sonuna eklenen `const`, bu metodun sınıfın üye değişkenlerini **asla değiştirmeyeceğini** garanti eder:
```cpp
void yazdir() const; // Üye değişkenlerde değişiklik yapamaz
```

### 3. `explicit` Kurucular
Tek parametreli kurucuların sebep olduğu istenmeyen örtük (*implicit*) tip dönüşümlerini engeller:
```cpp
class Canta {
public:
    explicit Canta(int kapasite);
};

// Canta c = 50; // HATA! explicit olduğu için örtük int -> Canta dönüşümüne izin verilmez.
Canta c(50);     // Doğru ve açık çağrı
```

---

## 10. Pekiştirme Alıştırmaları (Çözümlü Sorular)

### Soru 1: Kurucu ve Yıkıcı Çalışma Sırası Analizi
Aşağıdaki kod parçasının konsol çıktısını sırasıyla yazınız:
```cpp
#include <iostream>
using namespace std;

class Test {
    string ad;
public:
    Test(string s) : ad(s) { cout << ad << " Dogdu\n"; }
    ~Test() { cout << ad << " Oldu\n"; }
};

Test tGlobal("Global");

void func() {
    Test tLocal("Fonksiyon");
}

int main() {
    cout << "main baslangici\n";
    Test tMain("Main");
    func();
    cout << "main sonu\n";
    return 0;
}
```
**Çözüm:**
1. Global nesneler `main`'den önce oluşturulur: `Global Dogdu`
2. `main` başlar: `main baslangici`
3. `main` içindeki yerel nesne: `Main Dogdu`
4. `func()` çağrılır: `Fonksiyon Dogdu`
5. `func()` biter ve yerel nesnesi yok edilir: `Fonksiyon Oldu`
6. `main` sonu: `main sonu`
7. `main` kapsamı biter, yerel nesne yok edilir: `Main Oldu`
8. Program sonlanır, global nesne yok edilir: `Global Oldu`

---

## 11. Öğrenciler İçin Ev Ödevleri

### Ödev 1: Rasyonel Sayı Sınıfı (`Kesir` / `RationalNumber`)
- **Görev:** Pay ve payda (`int pay, payda`) tutan bir `Kesir` sınıfı geliştiriniz.
  - Paydanın 0 girilmesi durumunda hata fırlatan veya paydayı 1 yapan kurucu yazınız.
  - İki kesri toplayan, çıkaran, çarpan ve bölen metotları kodlayınız.
  - Kesri en sade haline getiren (`sadelestir()`) private yardımcı metodunu ekleyiniz (EBOB algoritması ile).

### Ödev 2: Dinamik Dizi Sınıfı Tasarımı (`OzelVektor`)
- **Görev:** `int* veri`, `int kapasite` ve `int boyut` üyelerine sahip bir sınıf tasarlayınız.
  - Kurucuda dinamik bellek tahsis ediniz (`new int[kapasite]`).
  - Yıkıcıda ayrılan belleği mutlaka temizleyiniz (`delete[] veri`).
  - `elemanEkle(int x)` metodu ile dizi dolduğunda kapasiteyi 2 katına çıkaran dinamik büyütme mantığını kurunuz.

### Ödev 3: Banka Sistemi (Header ve Implementation Ayrımı)
- **Görev:** `Musteri` ve `BankaHesabi` sınıflarını `.h` ve `.cpp` dosyalarına bölerek tasarlayınız. Birden fazla müşterinin hesap açabildiği, para transferi yapabildiği ve hesap hareketlerini listeleyebildiği bir menü uygulaması geliştiriniz.
