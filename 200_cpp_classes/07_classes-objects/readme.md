# 7. Sınıflar ve Nesneler: Nesne Yönelimli Programlamaya Giriş (Classes & Objects)

Bu bölümde Nesne Yönelimli Programlama (Object-Oriented Programming - OOP) paradigmasının temelleri, sınıf (*class*) ve nesne (*object*) kavramları, erişim belirleyicileri ile veri gizleme (*encapsulation & data hiding*), kurucu ve yıkıcı metotlar (*constructors & destructors*), üye başlatma listeleri (*member initializer lists*), nesne dizileri, nesnelerin referansla aktarımı ve C++ projelerinde başlık (`.h`) ile kaynak (`.cpp`) dosyalarının ayrılması mimarisi ele alınmaktadır.

---

## 📑 İçindekiler
1. [Nesne Yönelimli Programlama Paradigması ve Avantajları](#1-nesne-yönelimli-programlama-paradigması-ve-avantajları)
2. [Sınıf (Class) ve Yapı (Struct) Karşılaştırması](#2-sınıf-class-ve-yapı-struct-karşılaştırması)
3. [Erişim Belirleyicileri (public, private, protected) ve Kapsülleme](#3-erişim-belirleyicileri-public-private-protected-ve-kapsülleme)
4. [Üye Fonksiyonlar: Sınıf İçi ve Dışı Tanımlama (Scope Resolution ::)](#4-üye-fonksiyonlar-sınıf-içi-ve-dışı-tanımlama-scope-resolution-)
5. [Kurucular (Constructors) ve Aşırı Yükleme](#5-kurucular-constructors-ve-aşırı-yükleme)
6. [Yıkıcılar ve Yapıcı/Yıkıcı Çağrılma Sırası (Blok İçi ve Dışı Ömür)](#6-yıkıcılar-ve-yapıcıyıkıcı-çağrılma-sırası-blok-içi-ve-dışı-ömür)
7. [Çoklu Dosya Mimarisi: Arayüz (.h) ve Gerçekleme (.cpp) Ayrımı](#7-çoklu-dosya-mimarisi-arayüz-h-ve-gerçekleme-cpp-ayrımı)
8. [Nesne Dizileri ve Fonksiyonlara Nesne Aktarımı](#8-nesne-dizileri-ve-fonksiyonlara-nesne-aktarımı)
9. [Ekstra: Üye Başlatma Listeleri, const Üye Metotlar ve explicit Anahtar Kelimesi](#9-ekstra-üye-başlatma-listeleri-const-üye-metotlar-ve-explicit-anahtar-kelimesi)
10. [Kodları Derleme ve Çalıştırma Rehberi (Komut Tablosu)](#10-kodları-derleme-ve-çalıştırma-rehberi-komut-tablosu)
11. [Pekiştirme Alıştırmaları (Çözümlü Sorular)](#11-pekiştirme-alıştırmaları-çözümlü-sorular)
12. [Öğrenciler İçin Ev Ödevleri](#12-öğrenciler-için-ev-ödevleri)

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

    // 3. Kopyalama Kurucusu (Copy Constructor)
    // Var olan bir nesnenin kopyası oluşturulurken çalışır
    Araba(const Araba& diger) {
        marka = diger.marka;
        yil = diger.yil;
        cout << "Kopyalama kurucusu calisti (Kopya nesne: " << marka << ").\n";
    }

    void bilgi() const {
        cout << "Araba: " << marka << ", Model Yili: " << yil << endl;
    }
};

int main() {
    Araba a1;                 // 1. Varsayılan kurucu
    Araba a2("Toyota", 2022); // 2. Parametreli kurucu
    Araba a3 = a2;            // 3. Kopyalama kurucusu (Copy Constructor)
    return 0;
}
```

> [!NOTE]
> **Kopyalama Kurucusunun (Copy Constructor) Ayrıntılı Yeri:** 
> Basit sınıflarda derleyicinin ürettiği varsayılan kopyalama kurucusu yeterlidir. Ancak sınıf içinde dinamik bellek (`new`) ve göstericiler kullanıldığında **Sığ Kopyalama (Shallow Copy)** felaketine yol açar. Bu nedenle Kopyalama Kurucusu, Derin Kopyalama (*Deep Copy*) ve *Rule of Three* mimarisi ders planının **Hafta 12** kısmında yer alan **[11_pointers-to-classes](../11_pointers-to-classes/readme.md)** modülündeki **[copy-constructor.cpp](../11_pointers-to-classes/copy-constructor.cpp)** dosyasında ayrıntılı olarak anlatılmıştır.

---

## 6. Yıkıcılar ve Yapıcı/Yıkıcı Çağrılma Sırası (Blok İçi ve Dışı Ömür)

İlgili kaynak dosyalar: [destructor.cpp](destructor.cpp), [cstor-dtor-order.cpp](cstor-dtor-order.cpp)

Yıkıcı (Destructor), bir nesnenin ömrü tamamlandığında (kapsam dışına çıkıldığında veya dinamik nesne için `delete` çağrıldığında) derleyici tarafından **otomatik olarak çağrılan** özel bir üye fonksiyondur.

### 6.1 Yıkıcı Metotların Temel Özellikleri
1. Sınıf adının başına tilda (`~`) getirilerek tanımlanır (`~Line()`, `~Nesne()`).
2. Geri dönüş tipi yoktur ve **hiçbir parametre alamaz**.
3. Parametre alamadığı için **aşırı yüklenemez (overload edilemez)**; bir sınıfın yalnızca **tek bir yıkıcısı** olabilir.
4. Genellikle dinamik olarak ayrılmış bellekleri (`delete[]`), açık dosyaları (`close()`) veya soket/veritabanı bağlantılarını güvenle kapatmak için kullanılır.

---

### 6.2 Blok İçerisinde ve Dışında Nesne Ömrü (Scope & Lifetime)

C++ dilinde süslü parantezler `{ ... }` bir **blok (kapsam / scope)** oluşturur. Bir nesnenin bellekte ne zaman doğup ne zaman öleceği, tanımlandığı bloğa ve saklama sınıfına (*storage duration*) bağlıdır:

| Nesne Türü | Tanımlandığı Yer | Yapıcı (Ctor) Ne Zaman Çalışır? | Yıkıcı (Dtor) Ne Zaman Çalışır? |
| :--- | :--- | :--- | :--- |
| **Global Nesne** | Tüm fonksiyonların ve blokların dışında | `main()` fonksiyonu başlamadan **ÖNCE** | `main()` bittikten sonra, program sonlanırken **EN SON** |
| **Dış Blok Yerel Nesne** | `main()` fonksiyonunun ana gövdesinde | Kod satırına ulaşıldığı anda | `main()` bloğu bittiğinde (`return 0` esnasında) |
| **İç Blok Nesnesi (Nested)** | Bir alt blok `{ ... }`, `if`, `for` içinde | İç bloğun içine girilip satıra gelindiğinde | İç bloktan çıkıldığı anda (`}` parantezinde hemen yok edilir) |
| **Fonksiyon Yerel Nesnesi** | Bir fonksiyonun gövdesinde | Fonksiyon çağrılıp satıra gelindiğinde | Fonksiyon tamamlanıp geri dönüldüğünde |
| **Statik Yerel Nesne (`static`)** | Bir fonksiyon veya blok içinde `static` | İlk defa o satıra ulaşıldığında (1 kez) | Fonksiyon bitince **YOK EDİLMEZ**; program sonlanırken yok edilir |
| **Dinamik Nesne (`new`)** | Öbek (Heap) bellekte `new` ile | `new` operatörü yürütüldüğünde | **Yalnızca `delete` çağrıldığında!** (`delete` çağrılmazsa yıkıcı hiç çalışmaz) |

---

### 6.3 LIFO Kuralı (Last In, First Out / Son Giren İlk Çıkar)

Bir blok içinde ardışık olarak birden fazla yerel nesne tanımlandığında:
- **Kurucular (Ctor):** Bildirim sırasına göre **yukarıdan aşağıya (FIFO)** çalışır.
- **Yıkıcılar (Dtor):** Kurulma sırasının tam tersiyle **aşağıdan yukarıya (LIFO / Yığın mantığı)** çalışır.

> [!IMPORTANT]
> **Neden LIFO?** İkinci oluşturulan nesne, birinci nesneye bağımlı olabilir (örneğin birinci nesnenin referansını kullanıyor olabilir). Bağımlılığın güvenle sonlandırılabilmesi için önce bağımlı olan (son nesne) yok edilmeli, en son kurucu temel nesne yok edilmelidir.

---

### 6.4 Kapsamlı Örnek Program ve Yaşam Döngüsü

İlgili kaynak dosya: [cstor-dtor-order.cpp](cstor-dtor-order.cpp)

Aşağıdaki kod parçasında global, yerel, iç blok, fonksiyon içi ve statik nesnelerin tam döngüsü gösterilmektedir:

```cpp
#include <iostream>
#include <string>
using namespace std;

class Nesne {
    string ad;
public:
    Nesne(string s) : ad(s) { cout << "[+] Kurucu : " << ad << endl; }
    ~Nesne() { cout << "[-] Yikici : " << ad << " yok edildi\n"; }
};

// 1. GLOBAL NESNE: main()'den önce doğar
Nesne g("Global");

void fonk() {
    cout << "--> fonk() basladi\n";
    Nesne fYerel("Fonk_Yerel");
    static Nesne fStatik("Fonk_Statik"); // Sadece ilk çağrıda doğar, fonk bitince ölmez!
    cout << "--> fonk() bitiyor\n";
} // fYerel burada yok edilir, fStatik yaşar

int main() {
    cout << "=== main() basladi ===\n";
    Nesne m1("Main_1");
    Nesne m2("Main_2");

    cout << "\n--- Ic Blok Basliyor ---\n";
    {
        Nesne b1("Blok_A");
        Nesne b2("Blok_B");
        // LIFO: Önce Blok_B, ardından Blok_A yok edilecek
    }
    cout << "--- Ic Blok Bitti, main devam ediyor ---\n\n";

    fonk();

    cout << "\n=== main() bitiyor ===\n";
    return 0;
}
```

### Konsol Çıktısı ve Satır Satır Analizi:

```text
[+] Kurucu : Global                         <-- 1. main() öncesi global nesne kurulur
=== main() basladi ===
[+] Kurucu : Main_1                         <-- 2. main() ilk nesnesi
[+] Kurucu : Main_2                         <-- 3. main() ikinci nesnesi

--- Ic Blok Basliyor ---
[+] Kurucu : Blok_A                         <-- 4. İç bloğa girildi
[+] Kurucu : Blok_B                         <-- 5. İç blok ikinci nesnesi
[-] Yikici : Blok_B yok edildi              <-- 6. İç blok bitti: LIFO gereği son giren B önce çıkar!
[-] Yikici : Blok_A yok edildi              <-- 7. İç blok A nesnesi yok edilir
--- Ic Blok Bitti, main devam ediyor ---

--> fonk() basladi
[+] Kurucu : Fonk_Yerel                     <-- 8. Fonksiyon yerel nesnesi
[+] Kurucu : Fonk_Statik                    <-- 9. Statik nesne ilk kez oluşturuldu
--> fonk() bitiyor
[-] Yikici : Fonk_Yerel yok edildi          <-- 10. Fonksiyon bitti, Fonk_Yerel öldü (Statik hala hayatta!)

=== main() bitiyor ===
[-] Yikici : Main_2 yok edildi              <-- 11. main() bitti: LIFO gereği son yerel nesne Main_2 öldü
[-] Yikici : Main_1 yok edildi              <-- 12. main() ilk yerel nesnesi Main_1 öldü
[-] Yikici : Fonk_Statik yok edildi         <-- 13. Program sonlanırken statik yerel nesne öldü
[-] Yikici : Global yok edildi              <-- 14. En son global nesne bellekten silindi
```

#### 💻 `cstor-dtor-order.cpp` Kodunu Terminalden Derleme ve Çalıştırma:
```bash
# 1. Derleme (C++17 standardı ve tüm uyarılar açık)
g++ -std=c++17 -Wall cstor-dtor-order.cpp -o cstor-dtor-order

# 2. Çalıştırma
./cstor-dtor-order          # Linux / macOS / Git Bash
.\cstor-dtor-order.exe      # Windows PowerShell / CMD
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

#### 💻 Çok Dosyalı `clockType` Projesini Terminalden Derleme ve Çalıştırma:
Header (`.h`) dosyaları doğrudan derleyiciye verilmez (`g++ clockType.h` yapılmaz!). Yalnızca `.cpp` kaynak dosyaları derleyiciye parametre olarak geçirilir:

```bash
# 1. clockType.cpp ve ana çalıştırıcı full-example.cpp dosyasını birlikte derleme
g++ -std=c++17 -Wall clockType.cpp full-example.cpp -o saat_programi

# 2. Çalıştırma
./saat_programi             # Linux / macOS / Git Bash
.\saat_programi.exe         # Windows PowerShell / CMD
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

## 10. Kodları Derleme ve Çalıştırma Rehberi (Komut Tablosu)

Bu dizindeki C++ kaynak kodlarını terminal üzerinden derlemek ve çalıştırmak için aşağıdaki komut kalıplarını kullanabilirsiniz:

### Tek Dosyalı Programları Derleme ve Çalıştırma
```bash
# Genel Şablon:
g++ -std=c++17 -Wall dosya_adi.cpp -o program_adi
./program_adi         # Linux / macOS / Git Bash
.\program_adi.exe     # Windows PowerShell / CMD
```

### Çok Dosyalı Projeleri Birlikte Derleme
```bash
# clockType sınıfı ve test çalıştırıcısını birlikte derleme:
g++ -std=c++17 -Wall clockType.cpp full-example.cpp -o saat_programi
./saat_programi       # Linux / macOS / Git Bash
.\saat_programi.exe   # Windows PowerShell / CMD
```

### Hızlı Başvuru Komut Tablosu

| Kaynak Kod Dosyası | Açıklama | Hızlı Derleme ve Çalıştırma (Bash / Linux / Mac) | Hızlı Derleme ve Çalıştırma (Windows PowerShell) |
| :--- | :--- | :--- | :--- |
| `classes-objects.cpp` | Temel Sınıf ve Nesne Tanımı | `g++ -std=c++17 classes-objects.cpp -o app && ./app` | `g++ -std=c++17 classes-objects.cpp -o app; .\app.exe` |
| `class-member-functions.cpp` | Sınıf İçi/Dışı Metotlar | `g++ -std=c++17 class-member-functions.cpp -o app && ./app` | `g++ -std=c++17 class-member-functions.cpp -o app; .\app.exe` |
| `constructor.cpp` | Varsayılan Kurucular | `g++ -std=c++17 constructor.cpp -o app && ./app` | `g++ -std=c++17 constructor.cpp -o app; .\app.exe` |
| `parametrized-constructor.cpp` | Parametreli Kurucular | `g++ -std=c++17 parametrized-constructor.cpp -o app && ./app` | `g++ -std=c++17 parametrized-constructor.cpp -o app; .\app.exe` |
| `destructor.cpp` | Yıkıcı Metot | `g++ -std=c++17 destructor.cpp -o app && ./app` | `g++ -std=c++17 destructor.cpp -o app; .\app.exe` |
| `cstor-dtor-order.cpp` | Ctor/Dtor Yaşam Döngüsü ve Blok Ömrü | `g++ -std=c++17 -Wall cstor-dtor-order.cpp -o app && ./app` | `g++ -std=c++17 -Wall cstor-dtor-order.cpp -o app; .\app.exe` |
| `clockType.cpp` + `full-example.cpp` | Çok Dosyalı Arayüz/Gerçekleme | `g++ -std=c++17 clockType.cpp full-example.cpp -o app && ./app` | `g++ -std=c++17 clockType.cpp full-example.cpp -o app; .\app.exe` |
| `array-of-objects.cpp` | Nesne Dizileri | `g++ -std=c++17 array-of-objects.cpp -o app && ./app` | `g++ -std=c++17 array-of-objects.cpp -o app; .\app.exe` |
| `class-reference.cpp` | Nesnelerin Referansla Aktarımı | `g++ -std=c++17 class-reference.cpp -o app && ./app` | `g++ -std=c++17 class-reference.cpp -o app; .\app.exe` |

---

## 11. Pekiştirme Alıştırmaları (Çözümlü Sorular)

### Soru 1: İç İçe Bloklar (Nested Blocks) ve LIFO Yıkım Sırası
Aşağıdaki kod parçasının konsol çıktısını satır satır yazınız ve nedenini açıklayınız:
```cpp
#include <iostream>
using namespace std;

class Takip {
    int id;
public:
    Takip(int no) : id(no) { cout << "Ctor(" << id << ") "; }
    ~Takip() { cout << "Dtor(" << id << ") "; }
};

int main() {
    cout << "Basla -> ";
    Takip t1(1);
    {
        cout << "[Blok1 ";
        Takip t2(2);
        Takip t3(3);
        cout << "Blok1] ";
    }
    cout << "[Ara] ";
    {
        cout << "[Blok2 ";
        Takip t4(4);
        cout << "Blok2] ";
    }
    cout << "Bitti -> ";
    return 0;
}
```
**Çözüm ve Adım Adım Analiz:**
1. `Basla -> ` yazılır.
2. `t1(1)` kurulur: `Ctor(1) `
3. `[Blok1 ` yazılır.
4. `t2(2)` ve ardından `t3(3)` kurulur: `Ctor(2) Ctor(3) `
5. `Blok1] ` yazılır.
6. **1. Blok Bitti:** Blok içinde tanımlanan nesneler LIFO (son giren ilk çıkar) kuralıyla yok edilir: Önce `t3`, sonra `t2`: `Dtor(3) Dtor(2) `
7. `[Ara] ` yazılır.
8. `[Blok2 ` yazılır.
9. `t4(4)` kurulur: `Ctor(4) `
10. `Blok2] ` yazılır.
11. **2. Blok Bitti:** `t4` yok edilir: `Dtor(4) `
12. `Bitti -> ` yazılır.
13. `main()` fonksiyonu sonlanır: En dıştaki `t1` yok edilir: `Dtor(1) `

**Tam Konsol Çıktısı:**
```text
Basla -> Ctor(1) [Blok1 Ctor(2) Ctor(3) Blok1] Dtor(3) Dtor(2) [Ara] [Blok2 Ctor(4) Blok2] Dtor(4) Bitti -> Dtor(1) 
```

---

### Soru 2: Statik Yerel Nesneler ve Çoklu Fonksiyon Çağrısı
Aşağıdaki program çalıştırıldığında konsola hangi metinler basılır?
```cpp
#include <iostream>
using namespace std;

class Sayac {
    string isim;
public:
    Sayac(string s) : isim(s) { cout << "+Ctor:" << isim << " "; }
    ~Sayac() { cout << "-Dtor:" << isim << " "; }
};

void islemYap(int tur) {
    cout << "\nTur(" << tur << "): ";
    Sayac normal("Normal");
    static Sayac statik("Statik");
    cout << "IslemSonu ";
}

int main() {
    cout << "mainBasladi ";
    islemYap(1);
    islemYap(2);
    cout << "\nmainBitiyor ";
    return 0;
}
```
**Çözüm ve Adım Adım Analiz:**
1. `mainBasladi ` yazılır.
2. **`islemYap(1)` Çağrısı:**
   - `\nTur(1): ` yazılır.
   - `normal` nesnesi kurulur: `+Ctor:Normal `
   - `statik` nesnesi ilk defa görüldüğü için kurulur: `+Ctor:Statik `
   - `IslemSonu ` yazılır.
   - Fonksiyon sonlanır: Yerel `normal` nesnesi yok edilir: `-Dtor:Normal `
   - **DİKKAT:** `statik` nesnesi **yok edilmez**, bellekteki durumunu ve varlığını korur.
3. **`islemYap(2)` Çağrısı:**
   - `\nTur(2): ` yazılır.
   - `normal` nesnesi tekrar kurulur: `+Ctor:Normal `
   - **DİKKAT:** `statik` nesnesi zaten ilk turda kurulmuş olduğu için kurucusu **tekrar ÇALIŞMAZ**.
   - `IslemSonu ` yazılır.
   - Fonksiyon sonlanır: Yerel `normal` nesnesi tekrar yok edilir: `-Dtor:Normal `
4. `\nmainBitiyor ` yazılır.
5. Program sonlanır: Tüm fonksiyonlar bittiği için `statik` nesnesinin yıkıcısı çalışır: `-Dtor:Statik `

**Tam Konsol Çıktısı:**
```text
mainBasladi 
Tur(1): +Ctor:Normal +Ctor:Statik IslemSonu -Dtor:Normal 
Tur(2): +Ctor:Normal IslemSonu -Dtor:Normal 
mainBitiyor -Dtor:Statik 
```

---

### Soru 3: Dinamik Bellek (new/delete) ile Blok İçi Nesnelerin Karışımı
Aşağıdaki kodun konsol çıktısını yazınız. Hangi nesnenin yıkıcısı çağrılmamıştır (bellek sızıntısı)?
```cpp
#include <iostream>
using namespace std;

class Hucre {
    char harf;
public:
    Hucre(char c) : harf(c) { cout << "Olustu(" << harf << ") "; }
    ~Hucre() { cout << "Silindi(" << harf << ") "; }
};

Hucre gA('A'); // Global

int main() {
    cout << "[M1] ";
    Hucre lB('B'); // main yerel

    {
        cout << "[B_Giris] ";
        Hucre* pC = new Hucre('C'); // Dinamik
        Hucre lD('D');              // Blok yerel

        delete pC; // Manuel silme
        cout << "[B_Cikis] ";
    }

    Hucre* pE = new Hucre('E'); // Dinamik (delete edilmiyor!)
    cout << "[M2] ";
    return 0;
}
```
**Çözüm ve Adım Adım Analiz:**
1. `gA('A')` global olduğu için `main` öncesi doğar: `Olustu(A) `
2. `[M1] ` yazılır.
3. `lB('B')` kurulur: `Olustu(B) `
4. İç bloğa girilir: `[B_Giris] `
5. `pC` dinamik olarak oluşturulur: `Olustu(C) `
6. `lD` yığın nesnesi kurulur: `Olustu(D) `
7. `delete pC;` açıkça çağrıldığı için `C` anında yok edilir: `Silindi(C) `
8. `[B_Cikis] ` yazılır.
9. İç blok parantezi kapandığında `lD` yığın nesnesi otomatik yok edilir: `Silindi(D) `
10. `pE` dinamik olarak oluşturulur: `Olustu(E) `
11. `[M2] ` yazılır ve `main()` sonlanır (`return 0`).
12. `main` yerel nesnesi `lB` yok edilir: `Silindi(B) `
13. Global `gA` yok edilir: `Silindi(A) `
14. **BELLEK SIZINTISI:** `pE` nesnesi için `delete` çağrılmadığı için `Silindi(E)` **ASLA ÇALIŞMAZ!**

**Tam Konsol Çıktısı:**
```text
Olustu(A) [M1] Olustu(B) [B_Giris] Olustu(C) Olustu(D) Silindi(C) [B_Cikis] Silindi(D) Olustu(E) [M2] Silindi(B) Silindi(A) 
```

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
