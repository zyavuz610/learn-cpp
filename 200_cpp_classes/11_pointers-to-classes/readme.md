# 11. Sınıflar ve Göstericiler: Dinamik Bellek Yönetimi (Pointers to Classes & Dynamic Memory)

Bu bölüm, C++ dilinde nesnelerin dinamik olarak öbekte (*heap*) oluşturulmasını (`new` ve `delete`), nesne göstericilerini ve ok operatörünü (`->`), dinamik nesne dizilerini, sığ ve derin kopyalama (*shallow vs deep copy*) ayrımını, kopyalama kurucusunu (*copy constructor*), üç kuralını (*Rule of Three*), statik sınıf üyelerini (*static members*) ve modern akıllı işaretçilere (*smart pointers*) giriş konularını kapsamaktadır.

---

## 📑 İçindekiler
1. [Yığın (Stack) vs Öbek (Heap) Bellek Modeli](#1-yığın-stack-vs-öbek-heap-bellek-modeli)
2. [Dinamik Bellek Yönetimi: new ve delete Operatörleri](#2-dinamik-bellek-yönetimi-new-ve-delete-operatörleri)
3. [Nesne Göstericileri ve Ok Operatörü (->)](#3-nesne-göstericileri-ve-ok-operatörü--)
4. [Dinamik Nesne Dizileri (new[] ve delete[])](#4-dinamik-nesne-dizileri-new-ve-delete)
5. [Sığ Kopyalama (Shallow Copy) Tehlikesi ve Çift Serbest Bırakma (Double Free)](#5-sığ-kopyalama-shallow-copy-tehlikesi-ve-çift-serbest-bırakma-double-free)
6. [Kopyalama Kurucusu (Copy Constructor) ve Derin Kopyalama (Deep Copy)](#6-kopyalama-kurucusu-copy-constructor-ve-derin-kopyalama-deep-copy)
7. [Büyük Üç Kuralı (Rule of Three): Yıkıcı, Kopyalama Kurucusu, Atama Operatörü](#7-büyük-üç-kuralı-rule-of-three-yıkıcı-kopyalama-kurucusu-atama-operatörü)
8. [Statik Sınıf Üyeleri: Statik Değişkenler ve Statik Metotlar](#8-statik-sınıf-üyeleri-statik-değişkenler-ve-statik-metotlar)
9. [Fonksiyon Göstericileri (Function Pointers)](#9-fonksiyon-göstericileri-function-pointers)
10. [Ekstra: Akıllı İşaretçilere Giriş (std::unique_ptr ve std::shared_ptr)](#10-ekstra-akıllı-işaretçilere-giriş-stdunique_ptr-ve-stdshared_ptr)
11. [Pekiştirme Alıştırmaları (Çözümlü Sorular)](#11-pekiştirme-alıştırmaları-çözümlü-sorular)
12. [Öğrenciler İçin Ev Ödevleri](#12-öğrenciler-için-ev-ödevleri)

---

## 1. Yığın (Stack) vs Öbek (Heap) Bellek Modeli

C++ programlarında bellek temelde iki ana bölgede yönetilir:

- **Yığın (Stack):** Fonksiyon çağrıları ve yerel değişkenler burada tutulur. Bellek tahsisi ve temizliği derleyici tarafından otomatik yapılır (çok hızlıdır). Boyutu sınırlıdır.
- **Öbek (Heap / Free Store):** Programcının çalışma zamanında dinamik olarak talep ettiği bellek alanıdır. Boyutu çok büyüktür. **Bellek tahsisini (`new`) ve geri iadesini (`delete`) programcı bizzat yönetmek zorundadır**.

---

## 2. Dinamik Bellek Yönetimi: new ve delete Operatörleri

İlgili kaynak dosya: [new-delete.cpp](new-delete.cpp)

C dilindeki `malloc()` ve `free()` fonksiyonlarının yerini C++ dilinde `new` ve `delete` operatörleri alır.

### `malloc` vs `new` Arasındaki En Önemli Fark:
- `malloc()` yalnızca bayt bazında bellek ayırır; nesnenin kurucusunu (*constructor*) **çağırmaz**.
- `new` operatörü belleği ayırır **VE** nesnenin kurucusunu otomatik olarak çalıştırır.
- `delete` operatörü nesnenin yıkıcısını (*destructor*) çalıştırır **VE** belleği işletim sistemine iade eder.

```cpp
#include <iostream>
using namespace std;

class Kisi {
public:
    Kisi() { cout << "Kisi olusturuldu (Kurucu).\n"; }
    ~Kisi() { cout << "Kisi yok edildi (Yikici).\n"; }
};

int main() {
    // Heap üzerinde dinamik nesne oluşturma
    Kisi* ptr = new Kisi(); // Kurucu çalışır

    // Belleği serbest bırakma
    delete ptr;             // Yıkıcı çalışır ve bellek iade edilir
    ptr = nullptr;          // Asılı göstericiyi (Dangling Pointer) önlemek için sıfırla

    return 0;
}
```

> [!CAUTION]
> **Bellek Sızıntısı (Memory Leak):** `new` ile tahsis edilen bir bellek bloğu `delete` edilmeden işaretçisi kaybedilirse, program sonlanana kadar o bellek alanı kilitli kalır. Uzun süre çalışan sunucu yazılımlarında bellek sızıntıları sistemin çökmesine neden olur.

---

## 3. Nesne Göstericileri ve Ok Operatörü (->)

İlgili kaynak dosyalar: [pointer-to-classes.cpp](pointer-to-classes.cpp), [pointers-classes-advanced.cpp](pointers-classes-advanced.cpp), [struct_pointers.cpp](struct_pointers.cpp)

Bir nesneyi gösteren bir işaretçi (`Class* ptr`) üzerinden sınıf üyelerine erişmek için iki yol vardır:
1. `(*ptr).uye`
2. `ptr->uye` (Ok / Arrow operatörü - daha pratik ve okunabilir)

```cpp
class Kutu {
public:
    double genislik;
    void setGenislik(double g) { genislik = g; }
};

int main() {
    Kutu* kPtr = new Kutu();
    kPtr->setGenislik(15.5); // (*kPtr).setGenislik(15.5) ile aynıdır
    cout << "Genislik: " << kPtr->genislik << endl;
    delete kPtr;
    return 0;
}
```

---

## 4. Dinamik Nesne Dizileri (new[] ve delete[])

İlgili kaynak dosyalar: [dynamic-arrays.cpp](dynamic-arrays.cpp), [dynamic-array-example.cpp](dynamic-array-example.cpp)

Dizi boyutunun çalışma anında belirlendiği durumlarda `new[]` kullanılır. Serbest bırakılırken **mutlaka `delete[]`** kullanılmalıdır:

```cpp
int n = 5;
int* sayilar = new int[n]; // n elemanlı dizi

// Temizleme:
delete[] sayilar; // Köşeli parantez unutulursa yalnızca ilk eleman silinir!
```

---

## 5. Sığ Kopyalama (Shallow Copy) Tehlikesi ve Çift Serbest Bırakma (Double Free)

İlgili kaynak dosya: [shallow-deep-copy.cpp](shallow-deep-copy.cpp)

Eğer bir sınıf üye değişken olarak dinamik bir gösterici tutuyorsa (`int* ptr`), derleyicinin otomatik ürettiği varsayılan kopyalama mekanizması yalnızca işaretçinin adresini kopyalar (**Sığ Kopyalama**).

### Sonuçta Oluşan Felaket (Double Free Crash):
İki farklı nesne bellekteki **aynı adresi** gösterir. İlk nesne kapsam dışına çıktığında yıkıcısı o adresi `delete` eder. İkinci nesne yok olmaya çalıştığında zaten silinmiş olan adresi tekrar silmeye çalışır (*double free*) ve program **çöker** (*crash / segmentation fault*).

```
Nesne A: [ ptr ] ──┐
                   ▼
                 [ Heap Bellek Alanı: 0x5000 ]
                   ▲
Nesne B: [ ptr ] ──┘  (Sığ kopyalama sonucu ikisi de aynı yere bakar!)
```

---

## 6. Kopyalama Kurucusu (Copy Constructor) ve Derin Kopyalama (Deep Copy)

İlgili kaynak dosya: [copy-constructor.cpp](copy-constructor.cpp)

Bu sorunu çözmek için sınıfımıza kendi kopyalama kurucumuzu yazmalı ve **Derin Kopyalama (Deep Copy)** yapmalıyız.

```cpp
#include <iostream>
using namespace std;

class DinamikDizi {
private:
    int* veri;
    int boyut;

public:
    // Standart Kurucu
    DinamikDizi(int b) : boyut(b) {
        veri = new int[boyut];
        for (int i = 0; i < boyut; i++) veri[i] = 0;
        cout << "Kurucu: " << boyut << " elemanli dizi olusturuldu.\n";
    }

    // KOPYALAMA KURUCUSU (Copy Constructor) - Derin Kopyalama
    DinamikDizi(const DinamikDizi& diger) : boyut(diger.boyut) {
        veri = new int[boyut]; // 1. Yeni ve bagimsiz bellek tahsis et
        for (int i = 0; i < boyut; i++) {
            veri[i] = diger.veri[i]; // 2. Verileri tek tek kopyala
        }
        cout << "Kopyalama Kurucusu: Bagimsiz kopya olusturuldu.\n";
    }

    // Yıkıcı
    ~DinamikDizi() {
        delete[] veri;
        cout << "Yikici: Bellek temizlendi.\n";
    }
};

int main() {
    DinamikDizi d1(10);
    DinamikDizi d2 = d1; // Kopyalama Kurucusu calisir (Guvenli derin kopya)
    return 0;
}
```

---

## 7. Büyük Üç Kuralı (Rule of Three)

Bir sınıf dinamik bir kaynak (gösterici / bellek / dosya tanıtıcısı) yönetiyorsa, aşağıdaki **üç özel metottan birini kendisi yazmak zorundaysa, üçünü de açıkça yazmalıdır**:

1. **Yıkıcı (Destructor):** Bellek sızıntısını önlemek için `delete` eder.
2. **Kopyalama Kurucusu (Copy Constructor):** Yeni nesne kopyalanırken derin kopyalama yapar.
3. **Kopyalama Atama Operatörü (Copy Assignment Operator `=`) :** Var olan bir nesneye başka bir nesne atanırken eski belleği siler, kendine atamayı kontrol eder (`this != &other`) ve derin kopyalama yapar.

---

## 8. Statik Sınıf Üyeleri: Statik Değişkenler ve Statik Metotlar

İlgili kaynak dosya: [static-members.cpp](static-members.cpp)

- **Statik Üye Değişken:** Sınıfın tüm nesneleri tarafından **ortak paylaşılan tek bir değişkendir**. Bellekte nesnelerden bağımsız tek bir kopyası vardır. Sınıf dışında `int ClassName::var = 0;` şeklinde başlatılmalıdır.
- **Statik Üye Metot:** Bir nesne örneği oluşturulmadan doğrudan sınıf adı ile çağrılabilir (`ClassName::metot()`). İçinde `this` göstericisi bulunmaz ve yalnızca diğer statik üyelere erişebilir.

```cpp
#include <iostream>
using namespace std;

class Sayac {
public:
    static int nesneSayisi; // Statik değişken bildirimi

    Sayac() {
        nesneSayisi++;
    }

    ~Sayac() {
        nesneSayisi--;
    }

    // Statik üye fonksiyon
    static void toplamNesne() {
        cout << "Mevcut nesne sayisi: " << nesneSayisi << endl;
    }
};

// Statik üyenin sınıf dışı başlatımı
int Sayac::nesneSayisi = 0;

int main() {
    Sayac::toplamNesne(); // 0 (Nesne olmadan sinif uzerinden cagrilabilir)

    Sayac s1, s2;
    Sayac::toplamNesne(); // 2

    {
        Sayac s3;
        Sayac::toplamNesne(); // 3
    } // s3 yok oldu

    Sayac::toplamNesne(); // 2
    return 0;
}
```

---

## 9. Fonksiyon Göstericileri (Function Pointers)

İlgili kaynak dosya: [function-pointer.cpp](function-pointer.cpp)

Fonksiyonlar da bellekte kod bölümünde (*code segment*) yer alır ve bir adrese sahiptir. Bir fonksiyonun adresini tutan göstericilere fonksiyon göstericisi denir. Geri çağırma (*callback*) mekanizmalarında kullanılır:

```cpp
#include <iostream>
using namespace std;

int topla(int a, int b) { return a + b; }
int carp(int a, int b) { return a * b; }

// Fonksiyon işaretçisi parametresi alan genel işlem fonksiyonu
void hesapla(int x, int y, int (*islem)(int, int)) {
    cout << "Sonuc: " << islem(x, y) << endl;
}

int main() {
    hesapla(4, 5, topla); // 9
    hesapla(4, 5, carp);  // 20
    return 0;
}
```

---

## 10. Ekstra: Akıllı İşaretçilere Giriş (std::unique_ptr ve std::shared_ptr)

Modern C++'ta manuel `new` ve `delete` kullanımı hata riski yüksek olduğu için terk edilmiş, yerini `<memory>` kütüphanesindeki akıllı işaretçiler almıştır (RAII Prensibi):

1. **`std::unique_ptr`:** Bellek alanının tek bir sahibinin olduğunu garanti eder. Kapsam dışına çıkıldığında belleği **otomatik siler** (`delete` yazmaya gerek yoktur).
2. **`std::shared_ptr`:** Referans sayacı (*reference count*) tutar; son sahip kapsam dışına çıktığında belleği otomatik temizler.

```cpp
#include <iostream>
#include <memory>
using namespace std;

int main() {
    // Modern C++: new ve delete yok!
    unique_ptr<int> akilliPtr = make_unique<int>(100);
    cout << *akilliPtr << endl; // 100
    // Blok bittiğinde bellek otomatik temizlenir, sızıntı imkansızdır.
    return 0;
}
```

---

## 11. Pekiştirme Alıştırmaları (Çözümlü Sorular)

### Soru 1: Sığ Kopyalama Hata Tespiti
Aşağıdaki kod parçasındaki hatayı bulunuz ve çözümünü açıklayınız:
```cpp
class Veri {
public:
    int* p;
    Veri(int v) { p = new int(v); }
    ~Veri() { delete p; }
};

void test(Veri v) {
    cout << *(v.p) << endl;
}

int main() {
    Veri a(10);
    test(a);
    return 0;
}
```
**Çözüm:**
- `test(Veri v)` fonksiyonu parametreyi değerle (*by value*) aldığı için derleyicinin varsayılan kopyalama kurucusu çalışır ve sığ kopyalama yapılır. `v.p` ile `a.p` aynı adresi gösterir.
- `test` fonksiyonu bittiğinde `v` yok edilir ve `delete v.p` çalıştırılarak bellek serbest bırakılır.
- `main` bittiğinde `a` nesnesi de yok edilirken aynı adres tekrar silinmeye (`delete a.p`) çalışılır ve program *Double Free* hatasıyla çöker!
- **Çözüm:** `void test(const Veri& v)` referans kullanılmalı veya `Veri` sınıfına derin kopyalama yapan bir Kopyalama Kurucusu (*Copy Constructor*) yazılmalıdır.

---

## 12. Öğrenciler İçin Ev Ödevleri

### Ödev 1: Dinamik Matris Sınıfı ve Rule of Three
- **Görev:** İki boyutlu dinamik bellek tahsis eden (`int** matris`) bir `DinamikMatris(int satir, int sutun)` sınıfı kodlayınız.
  - Sınıfa Yıkıcı, Kopyalama Kurucusu ve Atama Operatörünü (`Rule of Three`) eksiksiz uygulayınız.
  - İki matrisi toplayan ve ekrana basan fonksiyonları ekleyiniz.

### Ödev 2: Nesne Havuzu (Object Pool & Static Counter)
- **Görev:** Bir oyun projesi için `Mermi` sınıfı tasarlayınız. Sınıf içinde toplam üretilen mermi sayısını, o an aktif olan mermi sayısını statik üyeler ile takip ediniz. Mermiler `new` ile üretilip `delete` edildikçe konsola güncel istatistikleri basınız.

### Ödev 3: Geri Çağırım (Callback) Tabanlı Filtreleme Fonksiyonu
- **Görev:** Dinamik bir tamsayı dizisini gezen ve fonksiyon göstericisi (`bool (*filtre)(int)`) alarak şartı sağlayan elemanları yeni bir dinamik diziye toplayan `filtrele()` fonksiyonunu yazınız. Fonksiyonu `ciftSayilar`, `pozitifSayilar` gibi test fonksiyonlarıyla deneyiniz.
