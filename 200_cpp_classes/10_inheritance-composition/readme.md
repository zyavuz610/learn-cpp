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
10. [Kodları Derleme ve Çalıştırma Rehberi (Komut Tablosu)](#10-kodları-derleme-ve-çalıştırma-rehberi-komut-tablosu)
11. [Pekiştirme Alıştırmaları (Çözümlü Sorular)](#11-pekiştirme-alıştırmaları-çözümlü-sorular)
12. [Öğrenciler İçin Ev Ödevleri](#12-öğrenciler-için-ev-ödevleri)

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

### 7.1. Bileşim Nedir? ("Parça-Bütün" ve "HAS-A" İlişkisi)

**Bileşim (*Composition*)**, bir sınıfın başka sınıflara ait nesneleri kendi içinde **üye değişken (*member object*)** olarak barındırmasıyla karmaşık nesneler oluşturma tekniğidir. Kalıtımdaki **"IS-A" (bir türüdür)** ilişkisinden farklı olarak bileşim bir **"HAS-A" (sahiptir)** yani **Parça-Bütün (*Whole-Part*)** ilişkisidir:

- Bir Araba bir Motora sahiptir (*Car HAS-A Engine*).
- Bir Bilgisayar bir İşlemciye ve Belleğe sahiptir (*Computer HAS-A CPU and RAM*).
- Bir Etkinlik bir Tarihe ve bir Saate sahiptir (*Event HAS-A Date and Time*).

```
┌──────────────────────────────────────────────┐
│                 Event (Bütün)                │
│ ──────────────────────────────────────────── │
│  - eventName : string                        │
│  - eventDay  : Date  ──▶ [month, day, year]  │
│  - eventTime : Time  ──▶ [hr, min]           │
└──────────────────────────────────────────────┘
```

Bileşim sayesinde küçük, tek bir göreve odaklanan ve bağımsız olarak test edilebilen sınıflar (`Date`, `Time`) tasarlanır; ardından daha büyük sınıflar (`Event`) bu yapı taşlarını birleştirerek oluşturulur.

---

### 7.2. `composition.cpp` İncelemesi: `Time`, `Date` ve `Event` Mimarisi

[composition.cpp](composition.cpp) dosyasında bileşim kavramı üç sınıf üzerinden modellenmiştir:

1. **`Time` Sınıfı (Bileşen / Parça):**
   - `hr` ve `min` alanlarını `private` olarak kapsüller.
   - `Time()` (varsayılan), `Time(int, int)` (parametreli) kurucuları, `~Time()` yıkıcısı ile `setTime()`, `getTime()`, `printTime()`, `incrementHours()` ve `incrementMinutes()` metotlarına sahiptir.
   - Saat (`0 <= hours < 24`) ve dakika (`0 <= minutes < 60`) geçerlilik kontrollerini (*validation*) kendi içinde yapar.
2. **`Date` Sınıfı (Bileşen / Parça):**
   - `month`, `day` ve `year` alanlarını `private` olarak kapsüller.
   - `Date()`, `Date(int, int, int)` kurucuları, `~Date()` yıkıcısı ile `setDate()`, `getDate()` ve `printDate()` metotlarını sunar.
   - Ay (`1–12`), gün (`1–31`) ve yıl (`1900–2030`) doğrulamasını kendi içinde yürütür.
3. **`Event` Sınıfı (Kapsayıcı / Bütün):**
   - Kendi içinde `string eventName`, `Date eventDay` ve `Time eventTime` üyelerini barındırır.
   - **Kapsülleme ve Yetki Devri (*Delegation*):** `Event` sınıfı, `Date` sınıfının `month/day/year` veya `Time` sınıfının `hr/min` `private` üyelerine doğrudan erişemez. Bunun yerine işi ilgili parçanın `public` arayüzüne devreder:
     - Veri güncellerken: `eventTime.setTime(hours, minutes);` ve `eventDay.setDate(m, d, y);`
     - Ekrana yazdırırken: `eventDay.printDate();` ve `eventTime.printTime();`

```cpp
#include <iostream>
#include <string>
using namespace std;

class Time {
private:
    int hr;
    int min;

public:
    Time(int hours = 0, int minutes = 0) {
        setTime(hours, minutes);
        cout << "Time constructor called" << endl;
    }

    ~Time() {
        cout << "Time destructor called" << endl;
    }

    void setTime(int hours, int minutes) {
        hr  = (0 <= hours && hours < 24)   ? hours   : 0;
        min = (0 <= minutes && minutes < 60) ? minutes : 0;
    }

    void getTime(int& hours, int& minutes) const {
        hours = hr;
        minutes = min;
    }

    void printTime() const {
        if (hr < 10) cout << "0";
        cout << hr << ":";
        if (min < 10) cout << "0";
        cout << min;
    }
};

class Date {
private:
    int month;
    int day;
    int year;

public:
    Date(int m = 1, int d = 1, int y = 1900) {
        setDate(m, d, y);
        cout << "Date constructor called" << endl;
    }

    ~Date() {
        cout << "Date destructor called" << endl;
    }

    void setDate(int m, int d, int y) {
        month = (m >= 1 && m <= 12)      ? m : 1;
        day   = (d >= 1 && d <= 31)      ? d : 1;
        year  = (y >= 1900 && y <= 2030) ? y : 1900;
    }

    void getDate(int& m, int& d, int& y) const {
        m = month;
        d = day;
        y = year;
    }

    void printDate() const {
        if (month < 10) cout << "0";
        cout << month << "/";
        if (day < 10) cout << "0";
        cout << day << "/" << year;
    }
};

class Event {
private:
    string eventName;
    Date eventDay;   // Bileşim (Composition): Event HAS-A Date
    Time eventTime;  // Bileşim (Composition): Event HAS-A Time

public:
    // Üye başlatma listesi ile bileşen nesnelerin parametreli kurucuları çağrılır
    Event(int hours = 0, int minutes = 0, int m = 1,
          int d = 1, int y = 1900, string name = "Christmas")
        : eventName(name), eventDay(m, d, y), eventTime(hours, minutes) {
        cout << "Event constructor called" << endl;
    }

    ~Event() {
        cout << "Event destructor called" << endl;
    }

    void setEventData(int hours, int minutes, int m, int d, int y, string name) {
        eventTime.setTime(hours, minutes); // Yetki devri (Delegation)
        eventDay.setDate(m, d, y);
        eventName = name;
    }

    void printEventData() const {
        cout << eventName << " occurs ";
        eventDay.printDate();
        cout << " at ";
        eventTime.printTime();
        cout << endl;
    }
};

int main() {
    Event e(12, 44, 12, 5, 2024, "C++ Dersi");
    e.printEventData();

    // Varsayılan argümanlarla oluşturma ve sonradan güncelleme:
    Event e2;
    e2.setEventData(10, 30, 5, 19, 2026, "OOP Semineri");
    e2.printEventData();

    return 0;
}
```

---

### 7.3. Üye Başlatma Listesi (Member Initializer List) ile Bileşen Başlatma

[composition.cpp](composition.cpp) içerisindeki `Event` kurucusuna dikkat edildiğinde, bileşen nesnelere parametrelerin **üye başlatma listesi (*member initializer list*)** üzerinden aktarıldığı görülür:

```cpp
Event::Event(int hours, int minutes, int m, int d, int y, string name)
    : eventDay(m, d, y), eventTime(hours, minutes) {
    eventName = name;
    cout << "Event constructor called" << endl;
}
```

#### Neden Üye Başlatma Listesi Kullanmalıyız?
1. **Gereksiz Çift İşlemi Önler:** Eğer başlatma listesi yerine kurucu gövdesinde `eventDay.setDate(m, d, y);` yazılsaydı, derleyici önce `Date()` varsayılan kurucusunu çalıştırır, ardından `setDate()` ile değerlerin üzerine tekrar yazardı. Başlatma listesinde ise doğrudan `Date(m, d, y)` çağrılır.
2. **Parametresiz Kurucusu Olmayan Üyeler İçin Zorunludur:** Bir bileşen sınıfın varsayılan (*default*) kurucusu yoksa, o üye nesne **yalnızca** üye başlatma listesi ile başlatılabilir; aksi halde derleme hatası oluşur.
3. **Varsayılan Argümanlarla Uyumluluk:** `composition.cpp`'de `Event` kurucusunun tüm parametreleri varsayılan değere sahiptir (`hours = 0, ..., name = "Christmas"`). Dolayısıyla `Event object;` şeklinde parametresiz çağrı yapılsa bile, başlatma listesi sayesinde `Date(1, 1, 1900)` ve `Time(0, 0)` parametreli kurucuları devreye girer.

---

### 7.4. Bileşimde Kurucu ve Yıkıcıların Çalışma Sırası (Kritik Kural!)

Bileşim içeren bir nesne oluşturulduğunda ve kapsam dışına çıkıp yok edildiğinde kurucu ve yıkıcılar belirli, değişmez bir sırayla çalışır:

1. **Kurucular (Parçadan Bütüne / İçten Dışa):** Önce bileşen nesnelerin kurucuları, en son kapsayıcı (`Event`) sınıfın kurucusu çalışır. Çünkü bütün, parçaları hazır olmadan kurulamaz.
2. **Yıkıcılar (Bütünden Parçaya / Dıştan İçe):** Önce kapsayıcı (`Event`) sınıfın yıkıcısı, ardından bileşen nesnelerin yıkıcıları **oluşturulma sırasının tam tersinde** çalışır.

> [!IMPORTANT]
> **Bildirim Sırası Kuralı:** Üye nesnelerin kurucuları, **üye başlatma listesinde yazıldıkları sıraya göre değil, sınıf tanımı içerisinde bildirildikleri (*declared*) sıraya göre** çalışır!
>
> `composition.cpp`'deki `Event` sınıfında bildirim sırası `eventDay` $\rightarrow$ `eventTime` şeklindedir. Başlatma listesini `: eventTime(hours, minutes), eventDay(m, d, y)` şeklinde ters yazsanız bile önce `Date`, sonra `Time`, en son `Event` kurucusu çalışır.

Buna göre [composition.cpp](composition.cpp) içerisindeki `Event e(12, 44, 12, 5, 2024, "C++ Dersi");` satırı çalıştırıldığında konsol çıktısı tam olarak şu şekilde olur:

```text
Date constructor called
Time constructor called
Event constructor called
Event destructor called
Time destructor called
Date destructor called
```

> [!NOTE]
> **Kalıtım ve Bileşim Birlikte Kullanıldığında Sıra:** Bir türetilmiş sınıf hem başka bir sınıftan miras alıyor hem de içinde üye nesneler barındırıyorsa kurucular şu sırayla çalışır:
> 1. Temel sınıf (*Base Class*) kurucusu
> 2. Üye nesnelerin (*Member Objects*) kurucuları (bildirim sırasına göre)
> 3. Türetilmiş sınıfın (*Derived Class*) kendi kurucu gövdesi
>
> Yıkıcılar ise bu sıranın tam tersinde (**3 $\rightarrow$ 2 $\rightarrow$ 1**) çalışır.

---

### 7.5. Bileşim (Composition) vs Birleştirme (Aggregation)

Her iki kavram da **"HAS-A"** ilişkisini ifade eder; ancak aralarındaki temel fark **yaşam döngüsü sahipliğidir (*ownership*)**:

| Özellik | Bileşim (Composition) | Birleştirme (Aggregation) |
| :--- | :--- | :--- |
| **Sahiplik Türü** | **Güçlü Sahiplik (*Strong Ownership*)** | **Zayıf Sahiplik (*Weak Ownership*)** |
| **Yaşam Döngüsü** | Kapsayıcı yok olunca parçalar da yok olur | Kapsayıcı yok olsa da parçalar yaşamaya devam eder |
| **C++ Gösterimi** | Değer olarak üye nesne (`Date eventDay;`) | Dışarıdan alınan gösterici veya referans (`Ogrenci*`, `Ogrenci&`) |
| **Örnek** | `Event` $\rightarrow$ `Date`, `Time` (`composition.cpp`) | `Bolum` $\rightarrow$ `Ogrenci` (Bölüm kapansa da öğrenci nesnesi varlığını sürdürebilir) |

---

### 7.6. `composition.cpp` Kod İnceleme Notları (Dikkat Edilmesi Gereken İnce Noktalar)

[composition.cpp](composition.cpp) dosyasını incelerken eğitim açısından fark edilmesi önemli iki ince nokta bulunmaktadır:

> [!WARNING]
> **1. `getTime` ve `getDate` Metotlarındaki Atama Yönü Hatası:**
> Dosyada `getTime` ve `getDate` fonksiyonları şu şekilde yazılmıştır:
> ```cpp
> void Time::getTime(int& hours, int& minutes) {
>     hr = hours;   // HATALI YÖN: üye değişkeni dışarıdan gelen parametreyle eziyor!
>     min = minutes;
> }
> ```
> Referans parametreler aracılığıyla nesnenin değerlerini dışarıya aktarmak için atamanın yönü **`hours = hr; minutes = min;`** (ve `Date::getDate` için **`m = month; d = day; y = year;`**) şeklinde olmalıdır.
>
> **2. `Time()` ve `Time(int hours = 0, int minutes = 0)` Kurucu Çakışması:**
> `Time` sınıfında hem parametresiz `Time()` kurucusu hem de sınıf dışında varsayılan argümanlı `Time::Time(int hours = 0, int minutes = 0)` kurucusu tanımlanmıştır. Doğrudan `Time t;` şeklinde bir nesne oluşturulmak istendiğinde derleyici hangi kurucuyu çağıracağına karar veremeyerek **belirsizlik (*ambiguous overload*)** hatası üretir. Çözüm olarak ya varsayılan argümanlı tek bir kurucu (`Time(int hours = 0, int minutes = 0)`) kullanılmalı ya da `Time(int, int)` tanımındaki `= 0` ifadeleri kaldırılmalıdır.

---

## 8. Karşılaştırma: Kalıtım mı, Bileşim mi? ("Favor Composition")

Yazılım tasarımında kabul gören temel prensiplerden biri şudur: **"Favor Composition over Inheritance" (Kalıtım yerine bileşimi tercih ediniz)**.

| Kriter | Kalıtım (Inheritance) | Bileşim (Composition) |
| :--- | :--- | :--- |
| **İlişki Türü** | "IS-A" (Bir türüdür) | "HAS-A" (Sahiptir) |
| **Bağlantı Türü** | Sıkı Bağlı (Tight Coupling - Beyaz Kutu) | Gevşek Bağlı (Loose Coupling - Siyah Kutu) |
| **Esneklik** | Derleme zamanında sabittir; dinamik değişemez | Çalışma zamanında nesneler değiştirilebilir |
| **Kapsülleme** | Temel sınıfın iç yapısı alt sınıflara sızabilir (`protected`) | İç sınıfların detayları tamamen gizlidir |

### Tasarım Testi: `Event` Neden `Date` ve `Time` Sınıflarından Miras Almamalı?
- **"Event bir Tarihtir (*Event IS-A Date*)"** ifadesi mantıksal olarak **yanlıştır**; ayrıca bir etkinlik hem başlangıç hem bitiş tarihine ihtiyaç duyduğunda kalıtım tamamen yetersiz kalır.
- **"Event bir Tarihe ve bir Saate sahiptir (*Event HAS-A Date and Time*)"** ifadesi **doğrudur**. `Event` ileride `Date startDate, endDate;` şeklinde kolayca genişletilebilir ve `Date`/`Time` sınıflarının iç implementasyonu değişse bile `Event` bozulmaz.

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

## 10. Kodları Derleme ve Çalıştırma Rehberi (Komut Tablosu)

Bu dizindeki kalıtım ve bileşim programlarını terminal üzerinden derlemek ve çalıştırmak için:

```bash
# Genel Şablon:
g++ -std=c++17 -Wall dosya_adi.cpp -o app
./app         # Linux / macOS / Git Bash
.\app.exe     # Windows PowerShell / CMD
```

### Hızlı Başvuru Komut Tablosu

| Kaynak Kod Dosyası | Açıklama | Hızlı Derleme ve Çalıştırma (Bash / Linux / Mac) | Hızlı Derleme ve Çalıştırma (Windows PowerShell) |
| :--- | :--- | :--- | :--- |
| `inheritance.cpp` | Kalıtım Temelleri ("IS-A") | `g++ -std=c++17 inheritance.cpp -o app && ./app` | `g++ -std=c++17 inheritance.cpp -o app; .\app.exe` |
| `inheritance_example.cpp` | Pratik Kalıtım Uygulaması | `g++ -std=c++17 inheritance_example.cpp -o app && ./app` | `g++ -std=c++17 inheritance_example.cpp -o app; .\app.exe` |
| `one-level-inheritance.cpp` | Tek Seviyeli Miras (`Shape` -> `Rectangle`) | `g++ -std=c++17 one-level-inheritance.cpp -o app && ./app` | `g++ -std=c++17 one-level-inheritance.cpp -o app; .\app.exe` |
| `multi-level-inheritance.cpp` | Çok Seviyeli Miras Zinciri | `g++ -std=c++17 multi-level-inheritance.cpp -o app && ./app` | `g++ -std=c++17 multi-level-inheritance.cpp -o app; .\app.exe` |
| `composition.cpp` | Bileşim / Sahiplik ("HAS-A") | `g++ -std=c++17 composition.cpp -o app && ./app` | `g++ -std=c++17 composition.cpp -o app; .\app.exe` |
| `bank_account_example.cpp` | Kalıtım + Bileşim + Operatör Aşırı Yükleme (`BankAccount` / `IsYeri`) | `g++ -std=c++17 bank_account_example.cpp -o app && ./app` | `g++ -std=c++17 bank_account_example.cpp -o app; .\app.exe` |

---

## 11. Pekiştirme Alıştırmaları (Çözümlü Sorular)

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

### Soru 2: Bileşimde (Composition) Bildirim Sırası ve Kurucu/Yıkıcı Çıktısı
Aşağıdaki kod parçasının konsol çıktısını yazınız ve nedenini açıklayınız:
```cpp
#include <iostream>
using namespace std;

class Date {
public:
    Date() { cout << "Date() "; }
    ~Date() { cout << "~Date() "; }
};

class Time {
public:
    Time() { cout << "Time() "; }
    ~Time() { cout << "~Time() "; }
};

class Event {
private:
    Date eventDay;   // 1. bildirilen üye
    Time eventTime;  // 2. bildirilen üye
public:
    // Başlatma listesinde eventTime önce yazılmış!
    Event() : eventTime(), eventDay() { cout << "Event() "; }
    ~Event() { cout << "~Event() "; }
};

int main() {
    Event e;
    return 0;
}
```
**Çözüm:**
- Üye nesnelerin kurucuları **üye başlatma listesindeki sıraya göre değil**, sınıf içerisindeki **bildirim sırasına göre** çalışır.
- `Event` sınıfında önce `eventDay` (`Date`), sonra `eventTime` (`Time`) bildirildiği için önce `Date()`, sonra `Time()`, en son kapsayıcı sınıf olan `Event()` kurucusu çalışır.
- `main()` fonksiyonu biterken yıkıcılar tam tersi sırada çağrılır: `~Event()`, `~Time()`, `~Date()`.
- **Toplam Çıktı:** `Date() Time() Event() ~Event() ~Time() ~Date() `

### Soru 3: Miras Erişim Belirleyicileri — Hangi Satırlar Derleme Hatası Verir?
Aşağıdaki kodda `(1)` ile `(8)` arasında numaralandırılmış satırlardan hangilerinin geçerli olduğunu, hangilerinin derleme hatası vereceğini açıklayınız:
```cpp
class Temel {
public:
    int pub = 1;
protected:
    int prot = 2;
private:
    int priv = 3;
};

class AltPublic : public Temel {
public:
    void test() {
        pub = 10;   // (1)
        prot = 20;  // (2)
        priv = 30;  // (3)
    }
};

class AltProtected : protected Temel {
public:
    void test() {
        pub = 10;   // (4)
        prot = 20;  // (5)
    }
};

int main() {
    AltPublic a;
    a.pub = 5;      // (6)
    a.prot = 6;     // (7)

    AltProtected b;
    b.pub = 7;      // (8)
    return 0;
}
```
**Çözüm:**
- **Geçerli satırlar:** `(1)`, `(2)`, `(4)`, `(5)`, `(6)`
  - `AltPublic` sınıfında `public` miras alındığı için `pub` → `public`, `prot` → `protected` olarak kalır; ikisine de sınıf içinden erişilebilir `(1, 2)` ve `a.pub` dışarıdan (`main`) erişilebilir `(6)`.
  - `AltProtected` sınıfında `protected` miras alındığı için `pub` ve `prot` türetilmiş sınıfta `protected` olur; sınıf içinden erişilebilir `(4, 5)`.
- **Derleme hatası veren satırlar:**
  - `(3)` `priv = 30;`: `Temel` sınıfındaki `private` üyelere türetilmiş sınıftan doğrudan **asla** erişilemez.
  - `(7)` `a.prot = 6;`: `protected` üyelere sınıf dışından (`main`) erişilemez.
  - `(8)` `b.pub = 7;`: `protected` miras nedeniyle `pub` artık `AltProtected` içinde `protected` düzeyine inmiştir; bu yüzden `main()` içerisinden erişilemez.

### Soru 4: Kalıtım ve Bileşim Birlikte Kullanıldığında Kurucu ve Yıkıcı Sırası
Aşağıdaki programda `Otomobil` sınıfı hem `Arac` sınıfından miras almakta (**IS-A**) hem de bir `Motor` nesnesini üye olarak barındırmaktadır (**HAS-A**). Konsol çıktısını adım adım belirleyiniz:
```cpp
#include <iostream>
using namespace std;

class Motor {
public:
    Motor()  { cout << "Motor() "; }
    ~Motor() { cout << "~Motor() "; }
};

class Arac {
public:
    Arac()  { cout << "Arac() "; }
    ~Arac() { cout << "~Arac() "; }
};

class Otomobil : public Arac {
private:
    Motor motor; // Bileşim (HAS-A)
public:
    Otomobil()  { cout << "Otomobil() "; }
    ~Otomobil() { cout << "~Otomobil() "; }
};

int main() {
    Otomobil oto;
    return 0;
}
```
**Çözüm:**
- Bir nesne hem kalıtım hem bileşim içerdiğinde kurucular sırasıyla **1) Temel sınıf**, **2) Üye nesneler**, **3) Türetilmiş sınıf** şeklinde çalışır: `Arac()` → `Motor()` → `Otomobil()`.
- `main()` sona ererken `oto` nesnesi yok edilir ve yıkıcılar tam tersi sırada çalışır: `~Otomobil()` → `~Motor()` → `~Arac()`.
- **Toplam Çıktı:** `Arac() Motor() Otomobil() ~Otomobil() ~Motor() ~Arac() `

### Soru 5: Parametresiz Kurucusu Olmayan Bileşen ile Bileşim (Hata Bulma ve Düzeltme)
Aşağıdaki kod neden derleme hatası verir? Hatayı düzeltiniz:
```cpp
#include <iostream>
#include <string>
using namespace std;

class Adres {
private:
    string sehir;
public:
    // Varsayılan (parametresiz) kurucu tanımlı değil!
    Adres(string s) : sehir(s) {}
    string getSehir() const { return sehir; }
};

class Musteri {
private:
    string ad;
    Adres adres; // Bileşim (Composition)
public:
    Musteri(string a, string s) { // DERLEME HATASI!
        ad = a;
        adres = Adres(s);
    }

    void yazdir() const {
        cout << ad << " - " << adres.getSehir() << endl;
    }
};
```
**Çözüm:**
- **Hatanın Nedeni:** `Adres` sınıfında parametreli bir kurucu (`Adres(string s)`) yazıldığı için derleyici otomatik olarak parametresiz `Adres()` kurucusunu üretmez. `Musteri` kurucusu gövdesine girmeden önce `adres` üyesini varsayılan kurucu ile oluşturmaya çalışır; `Adres()` bulunamadığı için derleme hatası (*no matching function for call to `Adres::Adres()`*) oluşur.
- **Doğru Çözüm (Üye Başlatma Listesi Kullanımı):**
  ```cpp
  Musteri(string a, string s) : ad(a), adres(s) {}
  ```
  Üye başlatma listesi kullanıldığında `adres` doğrudan `Adres(s)` ile tek adımda başlatılır; hem derleme hatası giderilir hem de gereksiz geçici nesne oluşturma maliyeti ortadan kalkar.

---

## 12. Öğrenciler İçin Ev Ödevleri

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
