# 2.2. Döngüler ve Tekrarlı Yapılar (Loops: for, while, do-while)

Bu bölümde C++ programlama dilinde belirli bir kod bloğunu tekrarlı olarak çalıştırmayı sağlayan döngü mekanizmaları (`for`, `while`, `do-while`), akış kontrol deyimleri (`break`, `continue`), iç içe döngüler (*nested loops*), sonsuz döngüler ve bekçi kontrollü döngü kalıpları (*sentinel-controlled loops*) ele alınmaktadır.

---

## 📑 İçindekiler
1. [Döngülerin Temel Yapı Taşları ve Karşılaştırma](#1-döngülerin-temel-yapı-taşları-ve-karşılaştırma)
2. [for Döngüsü ve Alternatif Kullanımları](#2-for-döngüsü-ve-alternatif-kullanımları)
3. [while Döngüsü (Ön Koşullu Döngü)](#3-while-döngüsü-ön-koşullu-döngü)
4. [do-while Döngüsü (Son Koşullu Döngü ve Girdi Doğrulama)](#4-do-while-döngüsü-son-koşullu-döngü-ve-girdi-doğrulama)
5. [Döngü Akış Kontrolü: break ve continue](#5-döngü-akış-kontrolü-break-ve-continue)
6. [İç İçe Döngüler (Nested Loops) ve Matris/Kalıp Çizimi](#6-iç-içe-döngüler-nested-loops-ve-matriskalıp-çizimi)
7. [Sonsuz Döngüler ve Bekçi Değerli Döngü (Sentinel-Controlled)](#7-sonsuz-döngüler-ve-bekçi-değerli-döngü-sentinel-controlled)
8. [Ekstra: Range-based for (C++11) ve Döngü Hataları (Off-by-One, Floating-point)](#8-ekstra-range-based-for-c11-ve-döngü-hataları-off-by-one-floating-point)
9. [Pekiştirme Alıştırmaları (Çözümlü Sorular)](#9-pekiştirme-alıştırmaları-çözümlü-sorular)
10. [Öğrenciler İçin Ev Ödevleri](#10-öğrenciler-için-ev-ödevleri)

---

## 1. Döngülerin Temel Yapı Taşları ve Karşılaştırma

Her döngü yapısı 4 temel bileşenden oluşur:
1. **Başlatma (Initialization):** Döngü sayacının veya kontrol değişkeninin başlangıç değeri.
2. **Koşul (Condition):** Döngünün devam edip etmeyeceğini belirleyen mantıksal şart.
3. **Güncelleme (Update / Step):** Her adımda sayacın artırılması, azaltılması veya değiştirilmesi.
4. **Döngü Gövdesi (Loop Body):** Koşul doğru olduğu sürece tekrarlanacak kod bloğu.

### Döngü Tiplerinin Karşılaştırma Tablosu

| Döngü Türü | Koşul Kontrol Yeri | Minimum Çalışma Sayısı | İdeal Kullanım Alanı |
| :--- | :--- | :--- | :--- |
| **`for`** | Başta (Ön koşullu) | 0 | Tekrar sayısı önceden bilinen durumlar (dizi gezme, sayaçlı işlemler) |
| **`while`** | Başta (Ön koşullu) | 0 | Tekrar sayısı belirli bir koşula bağlı olan, önceden kestirilemeyen durumlar |
| **`do-while`** | Sonda (Son koşullu) | 1 | Kod bloğunun en az 1 kez mutlaka çalışması gereken durumlar (menüler, girdi kontrolü) |

---

## 2. for Döngüsü ve Alternatif Kullanımları

İlgili kaynak dosyalar: [1_for_dongusu.cpp](1_for_dongusu.cpp), [2_for_toplam.cpp](2_for_toplam.cpp), [3_for_alternatif.cpp](3_for_alternatif.cpp)

`for` döngüsü; sayaç başlatma, koşul denetimi ve adım güncelleme işlemlerini tek bir satırda toplar.

```cpp
#include <iostream>
using namespace std;

int main() {
    // 1'den N'e kadar olan sayıların toplamı (Birikim / Accumulation Kalıbı)
    int n = 10;
    int toplam = 0;

    for (int i = 1; i <= n; i++) {
        toplam += i;
    }
    cout << "1'den " << n << "'e kadar toplam: " << toplam << endl;

    // Alternatif for kullanımları:
    // A) İki sayaç ile aynı anda çalışma
    for (int i = 0, j = 10; i < j; i++, j--) {
        cout << "i: " << i << ", j: " << j << endl;
    }

    // B) Adım aralığını farklı belirleme (örn: 2'şer artırma)
    for (int i = 0; i <= 20; i += 2) {
        // Çift sayılar...
    }

    return 0;
}
```

---

## 3. while Döngüsü (Ön Koşullu Döngü)

İlgili kaynak dosya: [4_while-toplam.cpp](4_while-toplam.cpp)

`while` döngüsü, verilen koşul `true` olduğu sürece gövdesini tekrarlar. Koşul en başta kontrol edildiği için, koşul başlangıçta yanlışsa döngü gövdesi **hiç çalışmayabilir**.

```cpp
#include <iostream>
using namespace std;

int main() {
    int sayi;
    cout << "Pozitif bir tamsayi giriniz: ";
    cin >> sayi;

    int basamakToplami = 0;
    int gecici = sayi;

    // Sayının basamakları toplamını hesaplama
    while (gecici > 0) {
        basamakToplami += (gecici % 10); // Son basamağı ekle
        gecici /= 10;                   // Son basamağı at
    }

    cout << sayi << " sayısının basamakları toplamı: " << basamakToplami << endl;
    return 0;
}
```

---

## 4. do-while Döngüsü (Son Koşullu Döngü ve Girdi Doğrulama)

İlgili kaynak dosya: [5_do-while-toplam.cpp](5_do-while-toplam.cpp)

`do-while` döngüsünde koşul ifadesi bloğun sonunda değerlendirilir. Bu nedenle koşul yanlış olsa dahi **gövde en az bir defa çalıştırılır**.

### İdeal Kullanım: Kullanıcı Girdisi Doğrulama (Input Validation)
```cpp
#include <iostream>
using namespace std;

int main() {
    int notDegeri;

    // Kullanıcı 0-100 arasında geçerli bir not girene kadar tekrar sorulur
    do {
        cout << "Lütfen 0 ile 100 arasında geçerli bir sınav notu giriniz: ";
        cin >> notDegeri;

        if (notDegeri < 0 || notDegeri > 100) {
            cout << "Geçersiz değer! Tekrar deneyiniz.\n";
        }
    } while (notDegeri < 0 || notDegeri > 100);

    cout << "Kabul edilen not: " << notDegeri << endl;
    return 0;
}
```

---

## 5. Döngü Akış Kontrolü: break ve continue

İlgili kaynak dosyalar: [6_break.cpp](6_break.cpp), [7_continue.cpp](7_continue.cpp)

- **`break`:** İçinde bulunduğu döngüyü anında sonlandırır ve döngüden sonraki ilk satıra atlar.
- **`continue`:** Mevcut döngü adımının (iterasyonunun) geri kalanını atlar ve bir sonraki adıma geçer (`for` döngüsünde güncelleme ifadesine atlar).

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "--- continue Örneği: 3'ün katlarını atla ---" << endl;
    for (int i = 1; i <= 10; i++) {
        if (i % 3 == 0) {
            continue; // 3, 6, 9 için bu adım atlanır
        }
        cout << i << " "; // 1 2 4 5 7 8 10
    }
    cout << endl;

    cout << "--- break Örneği: 7 görüldüğünde dur ---" << endl;
    for (int i = 1; i <= 10; i++) {
        if (i == 7) {
            break; // Döngü tamamen biter
        }
        cout << i << " "; // 1 2 3 4 5 6
    }
    cout << endl;

    return 0;
}
```

---

## 6. İç İçe Döngüler (Nested Loops) ve Matris/Kalıp Çizimi

İlgili kaynak dosya: [8_nested-loop.cpp](8_nested-loop.cpp)

Bir döngünün gövdesinde başka bir döngünün yer alması durumudur. Dıştaki döngünün her bir adımı için içteki döngü baştan sona tam bir tur çalışır.

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Örnek 1: Çarpım Tablosu (10x10)
    cout << "=== ÇARPIM TABLOSU ===" << endl;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            cout << setw(4) << (i * j);
        }
        cout << endl;
    }

    // Örnek 2: Yıldızlarla Dik Üçgen Çizimi
    int satir = 5;
    cout << "\n=== YILDIZ KALIBI ===" << endl;
    for (int i = 1; i <= satir; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}
```

---

## 7. Sonsuz Döngüler ve Bekçi Değerli Döngü (Sentinel-Controlled)

İlgili kaynak dosyalar: [9_sonsuz-dongu.cpp](9_sonsuz-dongu.cpp), [a_sonsuz-dongu-ornegi.cpp](a_sonsuz-dongu-ornegi.cpp)

Koşulu daima doğru olan döngülere **sonsuz döngü** denir:
- `while (true) { ... }`
- `for (;;) { ... }`

Bu tür döngülerden çıkış genellikle kullanıcının belirli bir özel değer (**bekçi / sentinel değer**, örn: çıkış için `0` veya `-1`) girmesi durumunda `break` komutu ile sağlanır.

```cpp
#include <iostream>
using namespace std;

int main() {
    int sayi;
    int toplam = 0;

    cout << "Toplanacak sayıları girin (Programı bitirmek için 0 giriniz):\n";
    while (true) {
        cout << "Sayı: ";
        cin >> sayi;

        if (sayi == 0) { // Bekçi değer (Sentinel) kontrolü
            break;       // Sonsuz döngüden çık
        }

        toplam += sayi;
        cout << "Güncel Toplam: " << toplam << endl;
    }

    cout << "Program sonlandırıldı. Nihai toplam: " << toplam << endl;
    return 0;
}
```

---

## 8. Ekstra: Range-based for (C++11) ve Döngü Hataları (Off-by-One, Floating-point)

### 1. Range-based for Döngüsü (C++11)
Bir koleksiyonun veya dizinin tüm elemanları üzerinde indeks kullanmadan doğrudan gezinmeyi sağlar:
```cpp
int sayilar[] = {10, 20, 30, 40, 50};

// Kopyalamadan salt-okunur gezinmek için const referans kullanılır
for (const auto& deger : sayilar) {
    cout << deger << " ";
}
cout << endl;
```

### 2. "Bir Eksik / Bir Fazla" Hatası (Off-by-One Error)
Döngü sınır koşullarının (`<` yerine `<=`) yanlış belirlenmesi sonucu ortaya çıkar:
```cpp
int arr[5] = {1, 2, 3, 4, 5};
// HATA: i <= 5 yazılırsa arr[5] elemanına erişilmeye çalışılır (Dizi sınır aşımı!)
for (int i = 0; i < 5; i++) { // Doğru sınır: i < 5
    cout << arr[i] << " ";
}
```

### 3. Kayan Noktalı Sayılarla Döngü Sayacı Kullanma Riski
```cpp
// TEHLİKE: IEEE 754 yuvarlama hatası nedeniyle d hiçbir zaman tam 1.0 olmayabilir!
// Bu döngü sonsuz döngüye girebilir:
for (double d = 0.0; d != 1.0; d += 0.1) {
    // ...
}
```
**Çözüm:** Döngü sayaçları her zaman tamsayı (`int`) olmalıdır!

---

## 9. Pekiştirme Alıştırmaları (Çözümlü Sorular)

### Soru 1: Asal Sayı Kontrolü
Verilen pozitif bir tamsayının asal sayı olup olmadığını en verimli şekilde kontrol eden C++ fonksiyonunu yazınız.

**Çözüm:**
```cpp
#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    // Bir sayının böleni varsa en fazla kareköküne kadar olan sayılardadır
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int test = 29;
    cout << test << (isPrime(test) ? " asaldır." : " asal değildir.") << endl;
    return 0;
}
```

---

### Soru 2: Çıktı Analizi (İç İçe Döngü Adımları)
Aşağıdaki kod parçasının konsola kaç adet `*` basacağını ve çıktısını belirleyiniz:
```cpp
#include <iostream>
using namespace std;

int main() {
    int sayac = 0;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
            sayac++;
        }
    }
    cout << "\nToplam: " << sayac << endl;
    return 0;
}
```
**Çözüm:**
- `i = 1` iken: `j` 1'den 1'e kadar (1 kez) $\rightarrow$ `*`
- `i = 2` iken: `j` 1'den 2'ye kadar (2 kez) $\rightarrow$ `**`
- `i = 3` iken: `j` 1'den 3'e kadar (3 kez) $\rightarrow$ `***`
- Toplam basılan yıldız sayısı: $1 + 2 + 3 = 6$.

---

## 10. Öğrenciler İçin Ev Ödevleri

### Ödev 1: Fibonacci Serisi ve Altın Oran Yaklaşımı
- **Görev:** Kullanıcının girdiği $N$ adım sayısı kadar Fibonacci dizisi elemanlarını ($0, 1, 1, 2, 3, 5, 8, \dots$) döngü ile ekrana yazdıran ve ardışık iki terimin oranının ($\frac{F_{n}}{F_{n-1}}$) altın orana ($\approx 1.618033$) nasıl yakınsadığını gösteren programı yazınız.

### Ödev 2: İçi Boş Elmas Deseni Çizimi (Diamond Pattern)
- **Görev:** Kullanıcıdan tek bir sayı (örn: yükseklik = 7) alarak iç içe döngülerle ekran çıktısı olarak **içi boş bir elmas** deseni oluşturan programı yazınız.

### Ödev 3: Sayı Tahmin Oyunu (Geri Bildirimli ve Skorlu)
- **Görev:** Bilgisayarın 1-100 arasında rastgele tuttuğu bir sayıyı kullanıcının tahmin ettiği bir oyun yazınız.
  - Program her tahminde "Daha BÜYÜK bir sayı giriniz" veya "Daha KÜÇÜK bir sayı giriniz" şeklinde yönlendirme yapmalıdır.
  - Kullanıcı doğru tahmin ettiğinde kaç denemede bildiğini söylemeli ve "Tekrar oynamak ister misiniz? (E/H)" sorusu ile oyunu `do-while` döngüsünde tutmalıdır.
