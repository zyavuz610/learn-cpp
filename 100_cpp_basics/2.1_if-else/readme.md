# 2.1. Koşul İfadeleri ve Karar Yapıları (Conditionals: if-else, switch-case)

Bu bölümde C++ programlama dilinde program akışını belirli şartlara göre yönlendiren karar yapıları (`if`, `if-else`, `else-if` merdiveni, iç içe `if`), çoklu seçim mekanizması (`switch-case`), koşul operatörü (ternary operator `?:`) ve bu yapıların altında yatan derleyici mekanizmaları ele alınmaktadır.

---

## 📑 İçindekiler
1. [Temel if ve if-else Yapısı](#1-temel-if-ve-if-else-yapısı)
2. [Çoklu Koşullar ve else-if Merdiveni](#2-çoklu-koşullar-ve-else-if-merdiveni)
3. [İç İçe Koşullar (Nested if) ve Mantıksal Operatörlerle Sadeleştirme](#3-iç-içe-koşullar-nested-if-ve-mantıksal-operatörlerle-sadeleştirme)
4. [switch-case İfadeleri ve Menü Tasarımı](#4-switch-case-ifadeleri-ve-menü-tasarımı)
5. [Koşul (Ternary) Operatörü `?:` ve Zincirleme Kullanım](#5-koşul-ternary-operatörü--ve-zincirleme-kullanım)
6. [Karşılaştırma: if-else vs switch-case (Derleyici Optimizasyonu)](#6-karşılaştırma-if-else-vs-switch-case-derleyici-optimizasyonu)
7. [Ekstra: C++17 Başlatıcılı if (if with initializer) ve Kayan Nokta Karşılaştırma Tuzağı](#7-ekstra-c17-başlatıcılı-if-if-with-initializer-ve-kayan-nokta-karşılaştırma-tuzağı)
8. [Pekiştirme Alıştırmaları (Çözümlü Sorular)](#8-pekiştirme-alıştırmaları-çözümlü-sorular)
9. [Öğrenciler İçin Ev Ödevleri](#9-öğrenciler-için-ev-ödevleri)

---

## 1. Temel if ve if-else Yapısı

İlgili kaynak dosya: [1_if-else.cpp](1_if-else.cpp)

`if` ifadesi, belirtilen mantıksal koşulun doğruluğunu (`true` / `1`) test eder. Koşul doğruysa `if` bloğu, yanlışsa (`false` / `0`) `else` bloğu yürütülür.

```cpp
#include <iostream>
#define MIDTERM_WEIGHT  0.45
#define FINAL_WEIGHT    0.55

using namespace std;

int main() {
    double vize, finalNotu;
    cout << "Vize notunu giriniz : ";
    cin >> vize;
    cout << "Final notunu giriniz: ";
    cin >> finalNotu;

    double ortalama = (vize * MIDTERM_WEIGHT) + (finalNotu * FINAL_WEIGHT);
    cout << "Dönem Sonu Ortalaması: " << ortalama << endl;

    // Tek koşullu karar
    if (ortalama < 40.0) {
        cout << "Sonuç: KALDI (Baraj 40 puandır)\n";
    } else {
        cout << "Sonuç: GEÇTİ (Tebrikler)\n";
    }

    return 0;
}
```

> [!WARNING]
> **Süslü Parantez ({}) Kullanımı ve "Dangling Else" Tuzağı:** C++ dilinde `if` veya `else` gövdesinde tek bir komut varsa süslü parantez zorunlu değildir. Ancak bu durum okunabilirliği bozar ve özellikle iç içe yapılarda `else`'in hangi `if`'e ait olduğu konusunda karışıklığa (*dangling else problem*) yol açar. İyi bir programlama alışkanlığı olarak **her zaman süslü parantez kullanılmalıdır**.

---

## 2. Çoklu Koşullar ve else-if Merdiveni

İlgili kaynak dosya: [2_if-else-if.cpp](2_if-else-if.cpp)

İkiden fazla alternatif senaryonun bulunduğu durumlarda `if - else if - else` merdiveni kullanılır. Koşullar yukarıdan aşağıya doğru sırayla değerlendirilir; ilk doğru olan blok çalıştırılır ve ardından yapının tamamından çıkılır.

```cpp
#include <iostream>
using namespace std;

int main() {
    int notDegeri;
    cout << "Notunuzu girin (0-100): ";
    cin >> notDegeri;

    if (notDegeri >= 90) {
        cout << "Harf Notu: AA (Mükemmel)\n";
    } else if (notDegeri >= 80) {
        cout << "Harf Notu: BA (Çok İyi)\n";
    } else if (notDegeri >= 70) {
        cout << "Harf Notu: BB (İyi)\n";
    } else if (notDegeri >= 60) {
        cout << "Harf Notu: CB (Orta)\n";
    } else if (notDegeri >= 50) {
        cout << "Harf Notu: CC (Geçer)\n";
    } else {
        cout << "Harf Notu: FF (Kaldı)\n";
    }

    return 0;
}
```

---

## 3. İç İçe Koşullar (Nested if) ve Mantıksal Operatörlerle Sadeleştirme

İlgili kaynak dosya: [3_nested-if.cpp](3_nested-if.cpp)

Bir koşulun doğrulanmasının ardından başka bir alt koşulun kontrol edilmesi gerektiğinde iç içe `if` yapıları kullanılır:

```cpp
#include <iostream>
using namespace std;

int main() {
    int yas;
    bool ehliyetVarMi;

    cout << "Yaşınızı giriniz: ";
    cin >> yas;
    cout << "Ehliyetiniz var mı? (1: Evet, 0: Hayır): ";
    cin >> ehliyetVarMi;

    // İç içe (Nested) if kullanımı
    if (yas >= 18) {
        if (ehliyetVarMi) {
            cout << "Araç kiralayabilirsiniz.\n";
        } else {
            cout << "Yaşınız uygun ancak ehliyetiniz olmadığı için kiralayamazsınız.\n";
        }
    } else {
        cout << "Yaşınız 18'den küçük olduğu için araç kiralayamazsınız.\n";
    }

    // Mantıksal operatör (&&) ile alternatif tek satırlı kontrol:
    if (yas >= 18 && ehliyetVarMi) {
        cout << "Hızlı kontrol: Giriş onaylandı.\n";
    }

    return 0;
}
```

---

## 4. switch-case İfadeleri ve Menü Tasarımı

İlgili kaynak dosyalar: [4_switch-case.cpp](4_switch-case.cpp), [5_nested-switch-case.cpp](5_nested-switch-case.cpp), [6_switch-case-menu.cpp](6_switch-case-menu.cpp)

`switch-case` yapısı, tek bir değişkenin eşit olduğu tam sayı veya karakter sabitlerine göre dallanma yapılmasını sağlar.

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "=== HESAP MAKİNESİ MENÜSÜ ===" << endl;
    cout << "1. Toplama" << endl;
    cout << "2. Çıkarma" << endl;
    cout << "3. Çarpma" << endl;
    cout << "4. Bölme" << endl;
    cout << "Seçiminiz (1-4): ";

    int secim;
    cin >> secim;

    double s1, s2;
    cout << "İki sayı giriniz: ";
    cin >> s1 >> s2;

    switch (secim) {
        case 1:
            cout << "Sonuç: " << s1 + s2 << endl;
            break; // switch bloğundan çıkışı sağlar
        case 2:
            cout << "Sonuç: " << s1 - s2 << endl;
            break;
        case 3:
            cout << "Sonuç: " << s1 * s2 << endl;
            break;
        case 4:
            if (s2 != 0) {
                cout << "Sonuç: " << s1 / s2 << endl;
            } else {
                cout << "Hata: Sıfıra bölme yapılamaz!" << endl;
            }
            break;
        default:
            cout << "Hata: Geçersiz menü seçimi!" << endl;
            break;
    }

    return 0;
}
```

### Kritik `switch-case` Kuralları:
1. **İzin Verilen Tipler:** Sadece tamsayı (`int`, `char`, `short`, `long`, `enum`) türleri kullanılabilir. `float`, `double` ve `string` kesinlikle **kullanılamaz**.
2. **Sabit Değer Şartı:** `case` etiketlerinin karşısında mutlaka sabit bir ifade (*constant expression*) bulunmalıdır; değişken kullanılamaz (`case x:` geçersizdir).
3. **`break` Deyiminin Önemi ve Fall-through:** `break` yazılmazsa program bir sonraki `case`'in kodlarını koşula bakmaksızın çalıştırmaya devam eder (*fall-through*).
4. **`default` Bloğu:** Hiçbir `case` eşleşmediğinde çalıştırılır (isteğe bağlıdır ancak iyi bir programlama pratiğidir).

---

## 5. Koşul (Ternary) Operatörü `?:` ve Zincirleme Kullanım

İlgili kaynak dosyalar: [7_conditional-operator.cpp](7_conditional-operator.cpp), [8_multi-conditional-operator.cpp](8_multi-conditional-operator.cpp)

Üç operand alan tek operatördür. Basit `if-else` kararlarını tek satırda ve bir ifade (*expression*) olarak yazmayı sağlar.

**Sözdizimi:** `koşul ? doğruysa_ifade : yanlışsa_ifade;`

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    double ortalama = 52.5;

    // Basit Ternary Operatörü
    string durum = (ortalama >= 50.0) ? "Geçti" : "Kaldı";
    cout << "Durum: " << durum << endl;

    // Zincirleme (Nested / Multi-conditional) Ternary Kullanımı
    string detay = (ortalama < 40.0) ? "Kaldı" 
                 : (ortalama < 60.0) ? "Şartlı Geçti" 
                 : "Başarılı";

    cout << "Detay: " << detay << endl;
    return 0;
}
```

---

## 6. Karşılaştırma: if-else vs switch-case (Derleyici Optimizasyonu)

| Kriter | `if-else` | `switch-case` |
| :--- | :--- | :--- |
| **Desteklenen Tipler** | Tüm veri tipleri (`int`, `double`, `string`, nesneler) | Yalnızca tamsayılar (`int`, `char`, `enum`) |
| **Karşılaştırma Türü** | Aralıklar (`<`, `>=`), mantıksal (`&&`, `||`) ve eşitlik | Yalnızca birebir tam eşitlik (`==`) |
| **Derleyici Optimizasyonu** | Sıralı karşılaştırma (linear search) yapar | Sıçrama Tablosu (*Jump Table*) oluşturur; $O(1)$ sürede hedefe atlar |
| **Okunabilirlik** | Karmaşık aralık ve şartlarda ideal | Çok seçenekli sabit menü ve durumlarda çok temiz |

---

## 7. Ekstra: C++17 Başlatıcılı if (if with initializer) ve Kayan Nokta Karşılaştırma Tuzağı

### 1. Başlatıcılı if Deyimi (C++17)
Değişkeni sadece `if` ve bağlı `else` blokları içinde geçerli olacak şekilde yerel tanımlamaya izin verir:
```cpp
// status değişkeni sadece bu if-else sınırları içinde yaşar
if (int status = hesapla(); status == 0) {
    cout << "İşlem başarılı\n";
} else {
    cout << "Hata kodu: " << status << endl;
}
// status değişkenine burada erişilemez (bellek temizliği ve güvenlik)
```

### 2. Kayan Noktalı Sayılarda Eşitlik (`==`) Tuzağı
IEEE 754 standardı gereği kayan noktalı sayılarda yuvarlama hataları oluşur:
```cpp
double a = 0.1 + 0.2;
if (a == 0.3) {
    cout << "Eşit\n";
} else {
    cout << "Eşit DEĞİL! (a = " << a << ")\n"; // Ekrana bu satır basılır!
}
```
**Doğru Yaklaşım (Epsilon Toleransı):**
```cpp
#include <cmath>
const double EPSILON = 1e-9;
if (std::abs(a - 0.3) < EPSILON) {
    cout << "Tolerans dahilinde eşit kabul edildi.\n";
}
```

---

## 8. Pekiştirme Alıştırmaları (Çözümlü Sorular)

### Soru 1: Artık Yıl (Leap Year) Hesabı
Girilen bir yılın artık yıl olup olmadığını belirleyen C++ kodunu yazınız. (Kural: 4'e tam bölünen yıllar artık yıldır; ancak 100'e tam bölünenlerden sadece 400'e tam bölünenler artık yıldır).

**Çözüm:**
```cpp
#include <iostream>
using namespace std;

bool isLeapYear(int yil) {
    // 400'e bölünüyorsa veya (4'e bölünüp 100'e bölünmüyorsa)
    if ((yil % 400 == 0) || (yil % 4 == 0 && yil % 100 != 0)) {
        return true;
    }
    return false;
}

int main() {
    int yil = 2024;
    cout << yil << (isLeapYear(yil) ? " bir artık yıldır." : " artık yıl değildir.") << endl;
    return 0;
}
```

---

### Soru 2: Çıktı Analizi (switch-case Fall-through)
Aşağıdaki kod parçasının konsol çıktısı ne olur?
```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 2;
    switch (x) {
        case 1: cout << "Bir ";
        case 2: cout << "Iki ";
        case 3: cout << "Uc ";
        default: cout << "Bitti";
    }
    return 0;
}
```
**Çözüm:**
- `case 2` eşleşir ve ekrana `Iki ` yazılır.
- `case 2` ve sonrasında `break` ifadesi bulunmadığı için program sonraki tüm satırları da yürütür (*fall-through*).
- Dolayısıyla çıktı: `Iki Uc Bitti` olacaktır.

---

## 9. Öğrenciler İçin Ev Ödevleri

### Ödev 1: İkinci Dereceden Denklem Kökleri ($ax^2 + bx + c = 0$)
- **Görev:** Kullanıcıdan $a$, $b$ ve $c$ katsayılarını alan programı yazınız.
- Program diskriminantı ($\Delta = b^2 - 4ac$) hesaplamalı ve:
  - $\Delta > 0$ ise iki farklı gerçek kökü,
  - $\Delta = 0$ ise çakışık tek kökü,
  - $\Delta < 0$ ise "Gerçek kök yoktur (Kökler karmaşıktır)" mesajını ekrana basmalıdır.
  - $a = 0$ durumunda bunun birinci dereceden bir denklem olduğunu belirten kontrolü ekleyiniz.

### Ödev 2: Akıllı Restoran Sipariş Sistemi (Nested switch-case)
- **Görev:** Kullanıcıya önce Ana Kategori (1. Yiyecekler, 2. İçecekler, 3. Tatlılar) sunan, ardından kullanıcının seçimine göre alt menüyü (iç içe `switch-case` ile) ekrana getirip fiyat hesaplayan bir konsol uygulaması geliştiriniz.

### Ödev 3: Basit Vergi Dilimi Hesaplayıcı
- **Görev:** Kullanıcının yıllık brüt gelirini alarak kademeli vergi dilimlerine göre (örn: ilk 100.000 TL için %15, sonraki 200.000 TL için %20, kalanı için %27) toplam ödenecek gelir vergisini ve net geliri hesaplayan programı yazınız.
