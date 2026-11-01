# 12. Sanal Fonksiyonlar ve Çok Biçimlilik (Virtual Functions & Polymorphism)

Bu bölümde Nesne Yönelimli Programlamanın en ileri düzeyi olan Çok Biçimlilik (*Polymorphism*), erken bağlama (*early/static binding*) ile geç bağlama (*late/dynamic binding*) arasındaki farklar, sanal fonksiyonlar (*virtual functions*), saf sanal fonksiyonlar (*pure virtual functions*), soyut sınıflar (*abstract classes*), arayüzler (*interfaces*), sanal yıkıcıların (*virtual destructors*) önemi ve derleyicinin arka plandaki VTable/VPtr mekanizması ayrıntılı olarak ele alınmaktadır.

---

## 📑 İçindekiler
1. [Çok Biçimlilik (Polymorphism) Nedir?](#1-çok-biçimlilik-polymorphism-nedir)
2. [Erken Bağlama (Static Binding) vs Geç Bağlama (Dynamic Binding)](#2-erken-bağlama-static-binding-vs-geç-bağlama-dynamic-binding)
3. [Sanal Fonksiyonlar (virtual) ve Temel Kurallar](#3-sanal-fonksiyonlar-virtual-ve-temel-kurallar)
4. [Saf Sanal Fonksiyonlar (= 0) ve Soyut Sınıflar (Abstract Classes)](#4-saf-sanal-fonksiyonlar--0-ve-soyut-sınıflar-abstract-classes)
5. [C++'ta Arayüz (Interface) Tasarımı](#5-cta-arayüz-interface-tasarımı)
6. [Heterojen Koleksiyonlar (Base Class Pointer ile Nesne Yönetimi)](#6-heterojen-koleksiyonlar-base-class-pointer-ile-nesne-yönetimi)
7. [Sanal Yıkıcılar (Virtual Destructors) ve Bellek Güvenliği](#7-sanal-yıkıcılar-virtual-destructors-ve-bellek-güvenliği)
8. [Ekstra: VTable ve VPtr Mekanizması, C++11 override ve final Belirteçleri](#8-ekstra-vtable-ve-vptr-mekanizması-c11-override-ve-final-belirteçleri)
9. [Pekiştirme Alıştırmaları (Çözümlü Sorular)](#9-pekiştirme-alıştırmaları-çözümlü-sorular)
10. [Öğrenciler İçin Ev Ödevleri](#10-öğrenciler-için-ev-ödevleri)

---

## 1. Çok Biçimlilik (Polymorphism) Nedir?

İlgili kaynak dosya: [polymorphizm.cpp](polymorphizm.cpp)

Çok Biçimlilik (Polymorphism - Yunanca *poly*: çok, *morph*: biçim), farklı sınıflara ait nesnelerin aynı arayüz çağrısına kendi türlerine özgü farklı davranışlarla yanıt verebilmesidir.

### İki Tür Çok Biçimlilik:
1. **Derleme Zamanı Çok Biçimliliği (Compile-time / Static):** Fonksiyon aşırı yükleme (*function overloading*) ve şablonlar (*templates*).
2. **Çalışma Zamanı Çok Biçimliliği (Run-time / Dynamic):** Kalıtım ve sanal fonksiyonlar (*virtual functions*) ile gerçekleştirilen dinamik yöntem.

---

## 2. Erken Bağlama (Static Binding) vs Geç Bağlama (Dynamic Binding)

İlgili kaynak dosyalar: [virtual-functions.cpp](virtual-functions.cpp), [virtual-example.cpp](virtual-example.cpp)

Bir fonksiyon çağrısı ile o fonksiyonun bellekteki gerçek kod bloğunun eşleştirilmesine **bağlama (binding)** denir.

- **Erken Bağlama (Early / Static Binding):** Hangi fonksiyonun çağrılacağı derleme zamanında göstericinin tipine bakılarak kesinleşir. C++'ta varsayılan yöntemdir (hızlıdır).
- **Geç Bağlama (Late / Dynamic Binding):** Hangi fonksiyonun çağrılacağı çalışma zamanında (`runtime`) göstericinin o an işaret ettiği gerçek nesnenin tipine bakılarak belirlenir. `virtual` anahtar kelimesi ile etkinleştirilir.

```cpp
#include <iostream>
using namespace std;

class Hayvan {
public:
    void sesNormal() { cout << "Hayvan sesi...\n"; }
    virtual void sesSanal() { cout << "Hayvan sesi...\n"; } // Sanal fonksiyon
};

class Kopek : public Hayvan {
public:
    void sesNormal() { cout << "Hav hav!\n"; }
    void sesSanal() override { cout << "Hav hav!\n"; }
};

int main() {
    Hayvan* h = new Kopek();

    h->sesNormal(); // Statik Bağlama: Hayvan::sesNormal() çağrılır! (Hayvan sesi...)
    h->sesSanal();  // Dinamik Bağlama: Kopek::sesSanal() çağrılır! (Hav hav!)

    delete h;
    return 0;
}
```

---

## 3. Sanal Fonksiyonlar (virtual) ve Temel Kurallar

İlgili kaynak dosya: [virtual-functions.cpp](virtual-functions.cpp)

`virtual` anahtar kelimesi bir metodun temel sınıfta (*base class*) dinamik olarak ezilebileceğini (*override*) bildirir.

### Kurallar:
1. `virtual` bildirimi temel sınıfta yapılır; türetilmiş sınıfta tekrar yazılması zorunlu değildir ancak okunabilirlik ve `override` denetimi için yazılması tavsiye edilir.
2. Fonksiyon prototipleri (parametre sayısı ve türleri) temel ve türetilmiş sınıfta **birebir aynı olmalıdır**.
3. Çalışma zamanı polimorfizmi yalnızca **işaretçiler (`Base*`) veya referanslar (`Base&`)** üzerinden yapılan çağrılarda devreye girer. Değer kopyalamasında (*object slicing*) çalışmaz.
4. Statik fonksiyonlar ve kurucular (*constructors*) `virtual` **olamaz**. Ancak yıkıcılar (*destructors*) `virtual` **olabilir ve olmalıdır**.

---

## 4. Saf Sanal Fonksiyonlar (= 0) ve Soyut Sınıflar (Abstract Classes)

İlgili kaynak dosya: [pure-virtual-functions.cpp](pure-virtual-functions.cpp)

Bir temel sınıfta gövdesi (implementasyonu) bulunmayan ve alt sınıflar tarafından mutlaka ezilmesi (*override*) zorunlu kılınan fonksiyonlara **Saf Sanal Fonksiyon (Pure Virtual Function)** denir:
`virtual void ciz() = 0;`

### Soyut Sınıf (Abstract Class)
Bünyesinde **en az bir adet saf sanal fonksiyon** barındıran sınıflara Soyut Sınıf denir.
- Soyut sınıflardan doğrudan **nesne üretilemez** (`Sekil s; // DERLEME HATASI`).
- Ancak soyut sınıf türünden **işaretçi (`Sekil*`) veya referans (`Sekil&`)** oluşturulabilir.
- Alt sınıf saf sanal fonksiyonu ezmezse, kendisi de soyut sınıf haline gelir ve ondan da nesne üretilemez.

```cpp
#include <iostream>
using namespace std;

// Soyut Sınıf (Abstract Class)
class Sekil {
public:
    virtual double alan() const = 0; // Saf Sanal Fonksiyon (Pure Virtual)
    virtual void ciz() const = 0;    // Saf Sanal Fonksiyon
    virtual ~Sekil() {}             // Sanal Yıkıcı
};

class Daire : public Sekil {
    double yaricap;
public:
    Daire(double r) : yaricap(r) {}
    double alan() const override { return 3.14159 * yaricap * yaricap; }
    void ciz() const override { cout << "O (Daire cizildi)\n"; }
};

class Dikdortgen : public Sekil {
    double en, boy;
public:
    Dikdortgen(double e, double b) : en(e), boy(b) {}
    double alan() const override { return en * boy; }
    void ciz() const override { cout << "[] (Dikdortgen cizildi)\n"; }
};
```

---

## 5. C++'ta Arayüz (Interface) Tasarımı

C++ dilinde Java veya C#'taki gibi ayrı bir `interface` anahtar kelimesi yoktur. Tüm metotları saf sanal (`= 0`) olan ve hiçbir üye değişken barındırmayan soyut sınıflar C++'ta **Arayüz (Interface)** olarak adlandırılır.

```cpp
class IYazdirilabilir {
public:
    virtual void yazdir() const = 0;
    virtual ~IYazdirilabilir() = default;
};
```

---

## 6. Heterojen Koleksiyonlar (Base Class Pointer ile Nesne Yönetimi)

İlgili kaynak dosya: [polymorphizm.cpp](polymorphizm.cpp)

Polimorfizmin en yaygın kullanım senaryosu, farklı türetilmiş sınıf nesnelerini tek bir temel sınıf işaretçi dizisinde toplamak ve tek döngüde çalıştırmaktır:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Heterojen Koleksiyon: Base class göstericileri tutan dizi
    Sekil* sekiller[2];
    sekiller[0] = new Daire(5.0);
    sekiller[1] = new Dikdortgen(4.0, 6.0);

    for (int i = 0; i < 2; i++) {
        sekiller[i]->ciz();
        cout << "Alan: " << sekiller[i]->alan() << endl;
        delete sekiller[i]; // Sanal yıkıcı sayesinde güvenli silme
    }

    return 0;
}
```

---

## 7. Sanal Yıkıcılar (Virtual Destructors) ve Bellek Güvenliği

İlgili kaynak dosya: [virtual-functions.cpp](virtual-functions.cpp)

Bir temel sınıf işaretçisi ile türetilmiş bir nesne silindiğinde (`delete basePtr;`), eğer temel sınıfın yıkıcısı `virtual` değilse yalnızca temel sınıfın yıkıcısı çalışır; türetilmiş sınıfın yıkıcısı **çağrılmaz**. Bu durum ciddi bellek sızıntılarına yol açar.

> [!CAUTION]
> **Altın Kural:** Bir sınıfta en az bir adet `virtual` fonksiyon varsa, o sınıfın yıkıcısı **kesinlikle `virtual` olmalıdır**:
> `virtual ~Base() {}`

---

## 8. Ekstra: VTable ve VPtr Mekanizması, C++11 override ve final Belirteçleri

### 1. VTable (Virtual Table) ve VPtr (Virtual Pointer) Arka Planı
Derleyici sanal fonksiyon barındıran her sınıf için bellekte o sınıfa ait sanal fonksiyon adreslerini tutan bir tablo (**VTable**) oluşturur. Sınıftan üretilen her nesneye ise gizli bir işaretçi (**VPtr**) eklenir. `ptr->func()` çağrıldığında işlemci `VPtr` üzerinden `VTable` tablosuna gider ve doğru fonksiyon adresine atlar ($O(1)$ çalışma zamanı maliyeti).

### 2. C++11 `override` Belirteci
Yazım hatalarını derleme anında yakalar:
```cpp
class Base {
    virtual void yaz(int x);
};

class Derived : public Base {
    // void yaz(double x) override; // HATA! Taban sınıfta double alan sanal metot yok.
    void yaz(int x) override;       // Doğru ve güvenli
};
```

### 3. C++11 `final` Belirteci
Bir sınıfın artık miras alınmasını veya bir metodun artık alt sınıflarda ezilmesini engeller:
```cpp
class SonSinif final : public Base {}; // Artık SonSinif'tan miras alınamaz
```

---

## 9. Pekiştirme Alıştırmaları (Çözümlü Sorular)

### Soru 1: Nesne Dilimleme (Object Slicing) Analizi
Aşağıdaki kod parçasının konsol çıktısı ne olur? Neden?
```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void goster() { cout << "Base\n"; }
};

class Derived : public Base {
public:
    void goster() override { cout << "Derived\n"; }
};

void fDeger(Base b) { b.goster(); }
void fReferans(Base& b) { b.goster(); }

int main() {
    Derived d;
    fDeger(d);
    fReferans(d);
    return 0;
}
```
**Çözüm:**
- `fDeger(d)` çağrısında nesne değerle (*by value*) aktarılır. Bu sırada `d` nesnesinin `Derived`'a ait kısımları atılır ve sadece `Base` kısmı kopyalanır (**Object Slicing**). Bu nedenle sanal mekanizma çalışmaz ve `Base` yazar.
- `fReferans(d)` çağrısında referans kullanıldığı için nesnenin orijinal kimliği korunur ve dinamik bağlama devreye girerek `Derived` yazar.
- Çıktı:
  ```text
  Base
  Derived
  ```

---

## 10. Öğrenciler İçin Ev Ödevleri

### Ödev 1: Geometrik Şekil Çizim Motoru (Soyut Sınıf & Heterojen Dizi)
- **Görev:** Saf sanal metotlara sahip `Sekil` soyut sınıfı (`alan()`, `cevre()`, `ciz()`) tasarlayınız.
  - `Daire`, `Ucgen`, `Dikdortgen` sınıflarını türetiniz.
  - Bir `vector<Sekil*>` listesinde rastgele boyutlarda 10 adet şekil oluşturup tek bir döngüde tüm şekillerin alan ve çevrelerini toplayıp ekrana çizdiren programı yazınız.

### Ödev 2: RPG Oyun Karakterleri (Rol Yapma Oyunu)
- **Görev:** `Karakter` soyut temel sınıfı (`ad`, `can`, `saldiriGucu`) tasarlayınız:
  - Saf sanal `saldir(Karakter& hedef)` ve `ozelYetenek()` metotlarını tanımlayınız.
  - `Savasci` (kalkan darbesi), `Buyucu` (ateş topu), `Okcu` (kritik vuruş) alt sınıflarını türetiniz.
  - Farklı sınıflardaki iki karakterin sırayla birbirine saldırdığı ve canı sıfıra inenin elendiği bir düello simülatörü kodlayınız.

### Ödev 3: Bankacılık Bildirim Sistemi (Interface Mimarisi)
- **Görev:** `IBildirimGonderici` adında saf sanal `gonder(string alici, string mesaj)` fonksiyonu olan bir arayüz yazınız.
  - Bu arayüzü uygulayan `SMSBildirim`, `EpostaBildirim` ve `PushNotification` sınıflarını geliştiriniz.
  - Bir `BankaHesabi` nesnesinde para transferi yapıldığında seçilen bildirim kanalı üzerinden dinamik olarak bilgilendirme mesajı gönderilmesini sağlayınız.
