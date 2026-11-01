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
11. [Pekiştirme Alıştırmaları (Çözümlü Sorular)](#11-pekiştirme-alıştırmaları-çözümlü-sorular)
12. [Öğrenciler İçin Ev Ödevleri](#12-öğrenciler-için-ev-ödevleri)

---

## 1. Fonksiyon Aşırı Yükleme (Function Overloading) ve İmza Kuralları

İlgili kaynak dosya: [function-overloading.cpp](function-overloading.cpp)

Aynı kapsamda (*scope*) aynı ada sahip, ancak **parametre tipleri veya parametre sayıları farklı** olan birden fazla fonksiyon tanımlanmasıdır.

### Fonksiyon İmzası Neleri İçerir?
- Fonksiyonun adı
- Parametrelerin sayısı
- Parametrelerin veri tipleri ve sıralaması

> [!WARNING]
> **Dönüş Tipi İmzaya Dahil Değildir:** Sadece dönüş tipleri (`return type`) farklı olan iki fonksiyon aşırı yüklenemez; derleyici çakışma hatası verir (`int yaz(int x)` ile `double yaz(int x)` aynı anda var olamaz).

---

## 2. this Göstericisi ve Metot Zincirleme (Method Chaining)

İlgili kaynak dosya: [this-pointer.cpp](this-pointer.cpp)

`this`, bir sınıfın üye fonksiyonu çağrıldığında, o an fonksiyonu çağıran nesnenin **bellek adresini tutan örtük (implicit) bir göstericidir**.

### Kullanım Amaçları:
1. **İsim Çakışmasını Önleme:** Parametre adı ile üye değişken adı aynı olduğunda: `this->saat = saat;`
2. **Kendini Döndürme (Method Chaining):** `*this` (nesnenin referansı) döndürülerek ardışık fonksiyon çağrıları yapılması:

```cpp
#include <iostream>
using namespace std;

class Zaman {
private:
    int s, d;
public:
    Zaman(int s = 0, int d = 0) : s(s), d(d) {}

    // Metot zincirleme için nesnenin kendi referansını (Zaman&) dönüyoruz
    Zaman& saatAyarla(int s) {
        this->s = s;
        return *this; // Mevcut nesneyi döndür
    }

    Zaman& dakikaAyarla(int d) {
        this->d = d;
        return *this;
    }

    void yazdir() const {
        cout << s << ":" << d << endl;
    }
};

int main() {
    Zaman z;
    // Zincirleme çağrı (Chaining)
    z.saatAyarla(14).dakikaAyarla(30).yazdir(); // 14:30
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

## 11. Pekiştirme Alıştırmaları (Çözümlü Sorular)

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

## 12. Öğrenciler İçin Ev Ödevleri

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
