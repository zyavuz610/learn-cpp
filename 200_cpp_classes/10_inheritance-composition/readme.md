# 10. Kalıtım (Miras) ve Bileşim (Inheritance & Composition)

Bu bölüm, Nesne Yönelimli Programlamanın en güçlü mekanizmalarından biri olan kalıtım (*inheritance / "IS-A" ilişkisi*), temel sınıf (*base class*) ve türetilmiş sınıf (*derived class*), tek ve çok seviyeli kalıtım, miras erişim belirleyicileri, kurucu/yıkıcıların çağrılma sırası, çoklu kalıtım ve elmas problemi (*diamond problem*) ile nesnelerin birbirini içermesi anlamına gelen bileşim (*composition / "HAS-A" ilişkisi*) konularını kapsamaktadır.

---

## 📑 İçindekiler
1. [Kalıtım (Miras) Nedir ve Neden İhtiyaç Duyulur?](#1-kalıtım-miras-nedir-ve-neden-ihtiyaç-duyulur)
2. [Temel ve Türetilmiş Sınıf Tanımı ("IS-A" İlişkisi)](#2-temel-ve-türetilmiş-sınıf-tanımı-is-a-ilişkisi)
3. [Miras Erişim Belirleyicileri (public, protected, private Miras)](#3-miras-erişim-belirleyicileri-public-protected-private-miras)
4. [Tek Seviyeli ve Çok Seviyeli Kalıtım (Single & Multi-level)](#4-tek-seviyeli-ve-çok-seviyeli-kalıtım-single--multi-level)
5. [Kalıtımda Kurucu ve Yıkıcıların Çalışma Sırası](#5-kalıtımda-kurucu-ve-yıkıcıların-çalışma-sırası)
6. [Temel Sınıf Kurucusuna Parametre Aktarımı](#6-temel-sınıf-kurucusuna-parametre-aktarımı)
7. [Bileşim (Composition / "HAS-A" İlişkisi)](#7-bileşim-composition--has-a-ilişkisi)
8. [Karşılaştırma: Kalıtım mı, Bileşim mi? ("Favor Composition")](#8-karşılaştırma-kalıtım-mı-bileşim-mi-favor-composition)
9. [Ekstra: Çoklu Kalıtım (Multiple Inheritance) ve Elmas Problemi (Virtual Inheritance)](#9-ekstra-çoklu-kalıtım-multiple-inheritance-ve-elmas-problemi-virtual-inheritance)
10. [Pekiştirme Alıştırmaları (Çözümlü Sorular)](#10-pekiştirme-alıştırmaları-çözümlü-sorular)
11. [Öğrenciler İçin Ev Ödevleri](#11-öğrenciler-için-ev-ödevleri)

---

## 1. Kalıtım (Miras) Nedir ve Neden İhtiyaç Duyulur?

İlgili kaynak dosya: [inheritance.cpp](inheritance.cpp)

Kalıtım, mevcut bir sınıfın (*Base Class / Parent*) özellik ve davranışlarının yeni bir sınıfa (*Derived Class / Child*) aktarılmasını sağlar.

### Avantajları:
- **Kodun Yeniden Kullanılabilirliği (Reusability):** Ortak alanlar (ad, soyad, TC kimlik vb.) her sınıfta tekrar yazılmaz; bir üst sınıfta bir kez tanımlanır.
- **Bakım Kolaylığı (Maintainability):** Ortak bir davranışta değişiklik yapılacağı zaman yalnızca temel sınıfı güncellemek yeterlidir; türetilmiş tüm sınıflar otomatik olarak güncellenir.
- **Hiyerarşik Modelleme:** Gerçek dünyadaki sınıflandırmalar yazılıma doğrudan aktarılabilir.

---

## 2. Temel ve Türetilmiş Sınıf Tanımı ("IS-A" İlişkisi)

İlgili kaynak dosyalar: [inheritance.cpp](inheritance.cpp), [inheritance_example.cpp](inheritance_example.cpp)

Kalıtım bir **"IS-A" (bir türüdür)** ilişkisidir:
- Köpek bir Memelidir (*Dog IS-A Mammal*).
- Öğrenci bir Kişidir (*Student IS-A Person*).

```cpp
#include <iostream>
#include <string>
using namespace std;

// Temel Sınıf (Base Class)
class Kisi {
protected:
    string ad;
    int yas;

public:
    Kisi(string a = "", int y = 0) : ad(a), yas(y) {}

    void bilgileriYazdir() const {
        cout << "Ad: " << ad << ", Yas: " << yas << endl;
    }
};

// Türetilmiş Sınıf (Derived Class) - Kisi sınıfından miras alıyor
class Ogrenci : public Kisi {
private:
    int ogrenciNo;

public:
    // Temel sınıfın kurucusunu çağırıyoruz
    Ogrenci(string a, int y, int no) : Kisi(a, y), ogrenciNo(no) {}

    void ogrenciKarti() const {
        bilgileriYazdir(); // Temel sınıfın metoduna erişim
        cout << "Ogrenci No: " << ogrenciNo << endl;
    }
};

int main() {
    Ogrenci ogr("Ali Yilmaz", 21, 2024001);
    ogr.ogrenciKarti();
    return 0;
}
```

---

## 3. Miras Erişim Belirleyicileri (public, protected, private Miras)

Kalıtım yapılırken kullanılan erişim belirteci (`class B : public A`), temel sınıf üyelerinin türetilmiş sınıfta hangi erişim düzeyine dönüşeceğini belirler:

| Temel Sınıftaki Üye | `public` Miras Alındığında | `protected` Miras Alındığında | `private` Miras Alındığında |
| :--- | :--- | :--- | :--- |
| **`public`** | `public` kalır | `protected` olur | `private` olur |
| **`protected`** | `protected` kalır | `protected` olur | `private` olur |
| **`private`** | Türetilmiş sınıftan **erişilemez** | Türetilmiş sınıftan **erişilemez** | Türetilmiş sınıftan **erişilemez** |

> [!TIP]
> OOP tasarımlarının %95'inde **`public` miras** kullanılır. Bu, "IS-A" ilişkisinin dış dünyaya karşı bozulmadan korunmasını sağlar.

---

## 4. Tek Seviyeli ve Çok Seviyeli Kalıtım (Single & Multi-level)

İlgili kaynak dosyalar: [one-level-inheritance.cpp](one-level-inheritance.cpp), [multi-level-inheritance.cpp](multi-level-inheritance.cpp)

### 1. Tek Seviyeli Kalıtım (Single Inheritance)
Bir sınıfın doğrudan tek bir üst sınıftan türemesidir: `Sekil` $\rightarrow$ `Dikdortgen`.

### 2. Çok Seviyeli Kalıtım (Multi-level Inheritance)
Kalıtım hiyerarşisinin zincirleme olarak devam etmesidir: `Canli` $\rightarrow$ `Hayvan` $\rightarrow$ `Kopek`.

```cpp
#include <iostream>
using namespace std;

class Sekil {
protected:
    int genislik, yukseklik;
public:
    void setBoyut(int g, int y) { genislik = g; yukseklik = y; }
};

// 1. Seviye Türeme
class Dikdortgen : public Sekil {
public:
    int alan() const { return genislik * yukseklik; }
};

// 2. Seviye Türeme (Dikdortgen'den türeyen Kare)
class Kare : public Dikdortgen {
public:
    void setKenar(int kenar) {
        setBoyut(kenar, kenar);
    }
};

int main() {
    Kare k;
    k.setKenar(6);
    cout << "Kare Alani: " << k.alan() << endl; // 36
    return 0;
}
```

---

## 5. Kalıtımda Kurucu ve Yıkıcıların Çalışma Sırası

Kalıtım hiyerarşisinde bir nesne oluşturulduğunda ve yok edildiğinde kurucu ve yıkıcıların çağrılma sırası şöyledir:

1. **Kurucu Sırası (Yukarıdan Aşağıya):** Önce en tepedeki temel sınıfın (*Base*) kurucusu, ardından türetilmiş sınıfın (*Derived*) kurucusu çalışır.
2. **Yıkıcı Sırası (Aşağıdan Yukarıya):** Önce türetilmiş sınıfın (*Derived*) yıkıcısı, ardından temel sınıfın (*Base*) yıkıcısı çalışır.

```cpp
#include <iostream>
using namespace std;

class A {
public:
    A() { cout << "A Kurucusu\n"; }
    ~A() { cout << "A Yikicisi\n"; }
};

class B : public A {
public:
    B() { cout << "B Kurucusu\n"; }
    ~B() { cout << "B Yikicisi\n"; }
};

int main() {
    B nesne;
    // Çıktı:
    // A Kurucusu
    // B Kurucusu
    // B Yikicisi
    // A Yikicisi
    return 0;
}
```

---

## 6. Temel Sınıf Kurucusuna Parametre Aktarımı

Türetilmiş sınıf kurucusu, temel sınıfın parametreli kurucusunu çağırmak için **üye başlatma listesini (initializer list)** kullanmak zorundadır:

```cpp
class Arac {
    string plaka;
public:
    Arac(string p) : plaka(p) {}
};

class Kamyon : public Arac {
    double yukKapasitesi;
public:
    // Arac(p) çağrısı ile temel sınıfa plaka aktarılır
    Kamyon(string p, double k) : Arac(p), yukKapasitesi(k) {}
};
```

---

## 7. Bileşim (Composition / "HAS-A" İlişkisi)

İlgili kaynak dosya: [composition.cpp](composition.cpp)

Bileşim (Composition), bir sınıfın başka bir sınıfın nesnesini kendi içinde bir üye değişken olarak barındırmasıdır. Bu bir **"HAS-A" (sahiptir)** ilişkisidir:
- Bir Araba bir Motora sahiptir (*Car HAS-A Engine*).
- Bir Etkinlik bir Tarih ve Saate sahiptir (*Event HAS-A Date and Time*).

```cpp
#include <iostream>
#include <string>
using namespace std;

class Tarih {
public:
    int gun, ay, yil;
    Tarih(int g = 1, int a = 1, int y = 2026) : gun(g), ay(a), yil(y) {}
    void yazdir() const { cout << gun << "/" << ay << "/" << yil; }
};

class Etkinlik {
private:
    string etkinlikAdi;
    Tarih etkinlikGunu; // Bileşim (Composition): Etkinlik bir Tarih'e sahiptir!

public:
    Etkinlik(string ad, int g, int a, int y) 
        : etkinlikAdi(ad), etkinlikGunu(g, a, y) {}

    void rapor() const {
        cout << "Etkinlik: " << etkinlikAdi << " - Tarih: ";
        etkinlikGunu.yazdir();
        cout << endl;
    }
};

int main() {
    Etkinlik e("OOP Ara Sınavı", 15, 11, 2026);
    e.rapor();
    return 0;
}
```

---

## 8. Karşılaştırma: Kalıtım mı, Bileşim mi? ("Favor Composition")

Yazılım tasarımında kabul gören temel prensiplerden biri şudur: **"Favor Composition over Inheritance" (Kalıtım yerine bileşimi tercih ediniz)**.

| Kriter | Kalıtım (Inheritance) | Bileşim (Composition) |
| :--- | :--- | :--- |
| **İlişki Türü** | "IS-A" (Bir türüdür) | "HAS-A" (Sahiptir) |
| **Bağlantı Türü** | Sıkı Bağlı (Tight Coupling - Beyaz Kutu) | Gevşek Bağlı (Loose Coupling - Siyah Kutu) |
| **Esneklik** | Derleme zamanında sabittir; dinamik değişemez | Çalışma zamanında nesneler değiştirilebilir |
| **Kapsülleme** | Temel sınıfın iç yapısı alt sınıflara sızabilir (`protected`) | İç sınıfların detayları tamamen gizlidir |

---

## 9. Ekstra: Çoklu Kalıtım (Multiple Inheritance) ve Elmas Problemi (Virtual Inheritance)

C++ dilinde bir sınıf birden fazla temel sınıftan aynı anda miras alabilir:
`class Yarasa : public Memeli, public UcanHayvan`

### Elmas Problemi (Diamond Problem)
Aynı büyük-ata sınıftan türeyen iki ara sınıftan yeni bir sınıf türetildiğinde, en alttaki sınıf ata sınıfın değişkenlerini iki kez kopyalayarak kafa karışıklığına ve belirsizliğe (*ambiguity*) yol açar:

```
        [ A ]
       /     \
     [ B ]   [ C ]
       \     /
        [ D ]  --> A'nın iki kopyasına sahip olur!
```

**Çözüm: `virtual` Kalıtım (Sanal Temel Sınıf):**
```cpp
class A { public: int x; };
class B : virtual public A {}; // virtual kalıtım
class C : virtual public A {}; // virtual kalıtım
class D : public B, public C {}; // D artık tek bir A kopyasına sahiptir
```

---

## 10. Pekiştirme Alıştırmaları (Çözümlü Sorular)

### Soru 1: Kurucu Çağrı Zinciri İncelemesi
Aşağıdaki kod parçasının konsol çıktısını adım adım açıklayınız:
```cpp
#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "1 "; }
    Base(int x) { cout << "2 "; }
};

class Derived : public Base {
public:
    Derived() { cout << "3 "; }
    Derived(int x) : Base(x) { cout << "4 "; }
};

int main() {
    Derived d1;
    Derived d2(10);
    return 0;
}
```
**Çözüm:**
- `Derived d1;`: `Derived`'ın parametresiz kurucusu çağrılır. Başlatma listesinde açıkça `Base(...)` belirtilmediği için derleyici otomatik olarak `Base()` (parametresiz) çağırır: `1 3 ` basılır.
- `Derived d2(10);`: `Derived(10)` kurucusu başlatma listesinde `Base(x)` çağırdığı için `Base(10)` çalışır: `2 4 ` basılır.
- Toplam Çıktı: `1 3 2 4 `.

---

## 11. Öğrenciler İçin Ev Ödevleri

### Ödev 1: Üniversite Personel ve Öğrenci Hiyerarşisi
- **Görev:** En tepede `Kisi` sınıfı (`ad`, `soyad`, `tcNo`, `dogumYili`) tanımlayınız.
  - `Kisi`'den türeyen `Ogrenci` (`ogrenciNo`, `bolum`, `gno`) ve `Akademisyen` (`unvan`, `sicilNo`, `maas`) sınıflarını yazınız.
  - `Akademisyen`'den türeyen `IdariGorevli` sınıfı ile çok seviyeli kalıtım kurunuz.
  - Tüm sınıfların kurucularında zincirleme temel sınıf çağrılarını eksiksiz yapınız.

### Ödev 2: Bilgisayar Sistemi Modellemesi (Bileşim - Composition)
- **Görev:** `Islemci` (çekirdek sayısı, GHz), `Bellek` (RAM boyutu, MHz), `Depolama` (SSD kapasitesi) sınıfları tanımlayınız.
  - Bu üç sınıfın nesnelerini üye olarak barındıran bir `Bilgisayar` sınıfı oluşturunuz.
  - Bilgisayar nesnesi oluşturulduğunda tüm bileşenlerin kurucularının sırayla çalışmasını sağlayınız ve `sistemOzeti()` fonksiyonu ile tüm donanım özelliklerini ekrana basınız.

### Ödev 3: Amfibik Araç Tasarımı (Çoklu Kalıtım)
- **Görev:** `KaraAraci` (`tekerlekSayisi`, `surusModu()`) ve `DenizAraci` (`pervaneTipi`, `yuzmeModu()`) sınıflarını tasarlayınız.
  - Her iki sınıftan çoklu miras alan `AmfibiArac` sınıfını kodlayınız ve hem karada hem denizde gidiş yeteneklerini test ediniz.
