# 6. Çok Boyutlu Diziler, Numaralandırmalar (Enum) ve Yapılar (Struct)

Bu bölüm, matris matematiği ve çok boyutlu veri tablolarını modellemek için kullanılan iki ve üç boyutlu dizileri, kodun okunabilirliğini artıran ve tip güvenliği sağlayan numaralandırma tiplerini (`enum` ve modern `enum class`), farklı veri türlerini tek bir çatı altında birleştiren yapıları (`struct`), yapı dizilerini ve yapı kompozisyonunu (*struct composition*) kapsamaktadır.

---

## 📑 İçindekiler
1. [İki Boyutlu Diziler (Matrisler) ve Bellek Modeli](#1-iki-boyutlu-diziler-matrisler-ve-bellek-modeli)
2. [Matris İşlemleri (Toplama, Transpoz ve Çarpma)](#2-matris-işlemleri-toplama-transpoz-ve-çarpma)
3. [Çok Boyutlu Dizilerin Fonksiyonlara Aktarımı](#3-çok-boyutlu-dizilerin-fonksiyonlara-aktarımı)
4. [Karakter Dizisi Matrisleri vs `std::string` Dizileri](#4-karakter-dizisi-matrisleri-vs-stdstring-dizileri)
5. [Üç ve Daha Çok Boyutlu Diziler](#5-üç-ve-daha-çok-boyutlu-diziler)
6. [Numaralandırma Tipleri (enum ve modern enum class)](#6-numaralandırma-tipleri-enum-ve-modern-enum-class)
7. [Kullanıcı Tanımlı Yapılar (struct): Tanım ve Üye Erişimi](#7-kullanıcı-tanımlı-yapılar-struct-tanım-ve-üye-erişimi)
8. [Yapı Dizileri (Array of Structs)](#8-yapı-dizileri-array-of-structs)
9. [Yapı Bileşimi / Kompozisyonu (Nested Structs)](#9-yapı-bileşimi--kompozisyonu-nested-structs)
10. [Ekstra: struct vs class, Ok Operatörü (`->`) ve Bellek Hizalaması (Padding)](#10-ekstra-struct-vs-class-ok-operatörü---ve-bellek-hizalaması-padding)
11. [Kodları Derleme ve Çalıştırma Rehberi (Komut Tablosu)](#11-kodları-derleme-ve-çalıştırma-rehberi-komut-tablosu)
12. [Pekiştirme Alıştırmaları (Çözümlü Sorular)](#12-pekiştirme-alıştırmaları-çözümlü-sorular)
13. [Öğrenciler İçin Ev Ödevleri](#13-öğrenciler-için-ev-ödevleri)

---

## 1. İki Boyutlu Diziler (Matrisler) ve Bellek Modeli

İlgili kaynak dosyalar: [1_2D-array-def.cpp](1_2D-array-def.cpp), [2_2D-array-init.cpp](2_2D-array-init.cpp)

İki boyutlu bir dizi satır (*row*) ve sütun (*column*) indeksleri ile tanımlanır:
`veri_tipi diziAdi[SATIR_SAYISI][SUTUN_SAYISI];`

### Satır Öncelikli Bellek Yerleşimi (Row-Major Order)
C ve C++ dilinde matrisler bellekte satır satır ardışık olarak tutulur. `matris[i][j]` elemanının fiziksel bellek adresi derleyici tarafından şu şekilde hesaplanır:
$$\text{Adres}(matris[i][j]) = \text{Base} + (i \times \text{SUTUN\_SAYISI} + j) \times \text{sizeof(Tip)}$$

```cpp
#include <iostream>
using namespace std;

int main() {
    // 2 satır, 3 sütunluk matris başlatma
    int matris[2][3] = {
        {10, 20, 30}, // 0. Satır
        {40, 50, 60}  // 1. Satır
    };

    cout << "matris[1][2] = " << matris[1][2] << endl; // 60
    return 0;
}
```

---

## 2. Matris İşlemleri (Toplama, Transpoz ve Çarpma)

İlgili kaynak dosyalar: [3_matrix-process.cpp](3_matrix-process.cpp), [4_matrix-process2.cpp](4_matrix-process2.cpp)

### 1. Matris Transpozu ($A^T$)
Bir matrisin satırları ile sütunlarının yer değiştirmesidir ($T[j][i] = A[i][j]$).

### 2. Matris Çarpımı ($C = A \times B$)
$M \times K$ boyutundaki bir $A$ matrisi ile $K \times N$ boyutundaki bir $B$ matrisinin çarpılabilmesi için **$A$'nın sütun sayısı ile $B$'nin satır sayısı eşit olmalıdır**. Sonuç matrisi $M \times N$ boyutunda olur:
$$C_{i,j} = \sum_{k=0}^{K-1} A_{i,k} \cdot B_{k,j}$$

```cpp
#include <iostream>
using namespace std;

const int M = 2, K = 3, N = 2;

void matrisCarp(const int A[M][K], const int B[K][N], int C[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < K; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
```

---

## 3. Çok Boyutlu Dizilerin Fonksiyonlara Aktarımı

İlgili kaynak dosya: [5_functions-2D-arrays.cpp](5_functions-2D-arrays.cpp)

İki boyutlu bir dizi fonksiyona parametre olarak verilirken **sütun boyutu mutlaka sabit olarak belirtilmelidir**. Satır boyutu boş bırakılabilir:
`void yazdir(const int mat[][SUTUN_SAYISI], int satirSayisi)`

> [!IMPORTANT]
> **Neden Sütun Boyutu Zorunludur?** Derleyicinin $i$. satırdan bir sonraki satıra geçebilmesi için bir satırın bellekte kaç bayt yer tuttuğunu bilmesi gerekir (`i * SUTUN_SAYISI`). Sütun boyutu verilmezse derleyici bellek ofsetini hesaplayamaz ve derleme hatası verir.

```cpp
#include <iostream>
using namespace std;

const int SUTUN = 3;

void matrisYazdir(const int mat[][SUTUN], int satir) {
    for (int i = 0; i < satir; i++) {
        for (int j = 0; j < SUTUN; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}
```

---

## 4. Karakter Dizisi Matrisleri vs `std::string` Dizileri

İlgili kaynak dosya: [6_arrays-of-strings.cpp](6_arrays-of-strings.cpp)

Metin listelerini saklamak için iki yaklaşım mevcuttur:

1. **2D `char` Dizisi (C-Tarzı):** Sabit uzunluklu karakter dizileri tablosu (`char sehirler[3][20]`). Her kelime için en fazla 19 karakter ayrılır; bellek israfına veya taşmaya açıktır.
2. **`std::string` Dizisi (Modern C++):** Her elemanı bağımsız dinamik uzunluğa sahip modern nesne dizisi:
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string iller[] = {"Trabzon", "Rize", "Artvin", "Giresun"};
    int n = sizeof(iller) / sizeof(iller[0]);

    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". İl: " << iller[i] << " (Uzunluk: " << iller[i].length() << ")\n";
    }
    return 0;
}
```

---

## 5. Üç ve Daha Çok Boyutlu Diziler

İlgili kaynak dosya: [7_multi-dim-array.cpp](7_multi-dim-array.cpp)

Üç boyutlu diziler, katmanlardan oluşan veri küplerini temsil eder (`dizi[katman][satir][sutun]`):
- **Kullanım Alanları:** RGB renkli görüntüler (`resim[yukseklik][genislik][3]`), 3B oyun haritaları, medikal görüntüleme (MR kesitleri).

```cpp
#include <iostream>
using namespace std;

int main() {
    // 2 katman, her katmanda 3 satır, 4 sütun
    int kup[2][3][4] = {0};
    kup[1][2][3] = 99; // 1. katman, 2. satır, 3. sütun
    cout << "Değer: " << kup[1][2][3] << endl;
    return 0;
}
```

---

## 6. Numaralandırma Tipleri (enum ve modern enum class)

İlgili kaynak dosyalar: [8_enum.cpp](8_enum.cpp), [9_enum-loop.cpp](9_enum-loop.cpp), [a_enum-functions.cpp](a_enum-functions.cpp)

Numaralandırma (`enum`), ilişkili tamsayı sabitlerine anlamlı isimler vererek sihirli sayıların (*magic numbers*) kullanımını önleyen kullanıcı tanımlı bir veri tipidir.

### 1. Klasik C-Tarzı `enum`
```cpp
enum Gun { Pazartesi = 1, Sali, Carsamba, Persembe, Cuma, Cumartesi, Pazar };
Gun bugun = Cuma; // Değeri: 5
```

### 2. Modern Kapsamlı Numaralandırma (`enum class` - C++11)
Klasik `enum`'lar isim çakışmasına açıktır ve örtük olarak `int`'e dönüşür. `enum class` ise tip güvenlidir:
```cpp
#include <iostream>
using namespace std;

enum class TrafikIsigi { Kirmizi, Sari, Yesil };
enum class Renk { Kirmizi, Mavi, Yesil }; // İsim çakışması yaşanmaz!

int main() {
    TrafikIsigi durum = TrafikIsigi::Kirmizi;

    // if (durum == 0) // HATA! Doğrudan tamsayı ile karşılaştırılamaz (Tür güvenliği)
    if (durum == TrafikIsigi::Kirmizi) {
        cout << "Lütfen durunuz!\n";
    }
    return 0;
}
```

---

## 7. Kullanıcı Tanımlı Yapılar (struct): Tanım ve Üye Erişimi

İlgili kaynak dosya: [b_structs.cpp](b_structs.cpp)

`struct`, mantıksal olarak birbiriyle ilişkili ancak **farklı veri tiplerindeki** değişkenleri tek bir çatı altında toplayan kullanıcı tanımlı bir veri yapısıdır.

```cpp
#include <iostream>
#include <string>
using namespace std;

struct Ogrenci {
    int id;
    string ad;
    double gno; // Genel Not Ortalaması
};

int main() {
    // Yapı değişkeni oluşturma ve başlatma
    Ogrenci ogr1 = {101, "Ali Yilmaz", 3.45};

    // Nokta (.) operatörü ile üyelere erişim
    cout << "Öğrenci No: " << ogr1.id << endl;
    cout << "Adı       : " << ogr1.ad << endl;
    cout << "GNO       : " << ogr1.gno << endl;

    ogr1.gno = 3.60; // Değer güncelleme
    return 0;
}
```

---

## 8. Yapı Dizileri (Array of Structs)

İlgili kaynak dosya: [c_struct-array.cpp](c_struct-array.cpp)

Birden çok kaydın bir tablo halinde bellekte tutulmasını sağlar (veri tabanı tablolarının C++ karşılığı):

```cpp
#include <iostream>
#include <string>
using namespace std;

struct Kitap {
    int id;
    string baslik;
    double fiyat;
};

int main() {
    Kitap kütüphane[3] = {
        {1, "C++ Programlama", 120.0},
        {2, "Veri Yapıları", 150.0},
        {3, "Algoritmalar", 180.0}
    };

    cout << "--- Kütüphane Listesi ---\n";
    for (int i = 0; i < 3; i++) {
        cout << kütüphane[i].id << " - " 
             << kütüphane[i].baslik << " : " 
             << kütüphane[i].fiyat << " TL\n";
    }
    return 0;
}
```

---

## 9. Yapı Bileşimi / Kompozisyonu (Nested Structs)

İlgili kaynak dosya: [d_struct-composition.cpp](d_struct-composition.cpp)

Bir yapının bir veya daha fazla üyesinin başka bir yapı türünden olması durumudur ("has-a" / sahiplik ilişkisi):

```cpp
#include <iostream>
#include <string>
using namespace std;

struct Adres {
    string sehir;
    string ilce;
    int postaKodu;
};

struct Calisan {
    string isim;
    double maas;
    Adres ikamet; // Yapı içinde yapı (Kompozisyon)
};

int main() {
    Calisan c1;
    c1.isim = "Zeynep Kaya";
    c1.maas = 45000.0;
    c1.ikamet.sehir = "Trabzon";
    c1.ikamet.ilce = "Ortahisar";
    c1.ikamet.postaKodu = 61000;

    cout << c1.isim << ", " << c1.ikamet.ilce << "/" << c1.ikamet.sehir << " adresinde ikamet etmektedir.\n";
    return 0;
}
```

---

## 10. Ekstra: struct vs class, Ok Operatörü (`->`) ve Bellek Hizalaması (Padding)

### 1. `struct` vs `class` Farkı
C++ dilinde `struct` ile `class` arasında tek bir fark vardır:
- `struct` içinde tanımlanan üyeler varsayılan olarak **`public`** (herkese açık) durumdadır.
- `class` içinde tanımlanan üyeler varsayılan olarak **`private`** (yalnızca sınıfa özel) durumdadır.

### 2. Ok Operatörü (`->`) ile Erişim
Bir yapıya işaretçi (pointer) üzerinden erişilirken `(*ptr).uye` yazmak yerine pratik olarak `ptr->uye` kullanılır:
```cpp
Ogrenci ogr = {200, "Ayse", 3.80};
Ogrenci* ptr = &ogr;

cout << ptr->ad << endl; // (*ptr).ad ile tamamen aynıdır
```

### 3. Bellek Hizalaması ve Dolgu (Memory Alignment & Padding)
Derleyici işlemcinin verilere en hızlı şekilde erişebilmesi için yapı üyeleri arasına görünmeyen boş baytlar (*padding*) ekler:
```cpp
struct Ornek {
    char a;    // 1 byte (+ 3 byte dolgu/padding)
    int b;     // 4 byte
    char c;    // 1 byte (+ 3 byte dolgu/padding)
}; // sizeof(Ornek) = 12 byte olur! (1 + 4 + 1 = 6 byte DEĞİLDİR)
```

---

## 11. Kodları Derleme ve Çalıştırma Rehberi (Komut Tablosu)

Bu dizindeki çok boyutlu diziler, matrisler, `enum` ve `struct` programlarını terminal üzerinden derlemek ve çalıştırmak için:

```bash
# Genel Şablon:
g++ -std=c++17 -Wall dosya_adi.cpp -o app
./app         # Linux / macOS / Git Bash
.\app.exe     # Windows PowerShell / CMD
```

### Hızlı Başvuru Komut Tablosu

| Kaynak Kod Dosyası | Açıklama | Hızlı Derleme ve Çalıştırma (Bash / Linux / Mac) | Hızlı Derleme ve Çalıştırma (Windows PowerShell) |
| :--- | :--- | :--- | :--- |
| `1_2D-array-def.cpp` | İki Boyutlu Dizi Tanımı | `g++ -std=c++17 1_2D-array-def.cpp -o app && ./app` | `g++ -std=c++17 1_2D-array-def.cpp -o app; .\app.exe` |
| `2_2D-array-init.cpp` | 2D Dizi Başlatma Biçimleri | `g++ -std=c++17 2_2D-array-init.cpp -o app && ./app` | `g++ -std=c++17 2_2D-array-init.cpp -o app; .\app.exe` |
| `3_matrix-process.cpp` | Matris Transpozu ve Toplamı | `g++ -std=c++17 3_matrix-process.cpp -o app && ./app` | `g++ -std=c++17 3_matrix-process.cpp -o app; .\app.exe` |
| `4_matrix-process2.cpp` | Matris Çarpımı | `g++ -std=c++17 4_matrix-process2.cpp -o app && ./app` | `g++ -std=c++17 4_matrix-process2.cpp -o app; .\app.exe` |
| `5_functions-2D-arrays.cpp` | 2D Dizileri Fonksiyona Aktarma | `g++ -std=c++17 5_functions-2D-arrays.cpp -o app && ./app` | `g++ -std=c++17 5_functions-2D-arrays.cpp -o app; .\app.exe` |
| `6_arrays-of-strings.cpp` | Metin Dizileri (2D char vs string) | `g++ -std=c++17 6_arrays-of-strings.cpp -o app && ./app` | `g++ -std=c++17 6_arrays-of-strings.cpp -o app; .\app.exe` |
| `7_multi-dim-array.cpp` | Üç Boyutlu Dizi (Veri Küpü) | `g++ -std=c++17 7_multi-dim-array.cpp -o app && ./app` | `g++ -std=c++17 7_multi-dim-array.cpp -o app; .\app.exe` |
| `8_enum.cpp` | Numaralandırma (`enum`) Temelleri | `g++ -std=c++17 8_enum.cpp -o app && ./app` | `g++ -std=c++17 8_enum.cpp -o app; .\app.exe` |
| `b_structs.cpp` | Yapılar (`struct`) ve Üye Erişimi | `g++ -std=c++17 b_structs.cpp -o app && ./app` | `g++ -std=c++17 b_structs.cpp -o app; .\app.exe` |
| `c_struct-array.cpp` | Yapı Dizileri (Array of Structs) | `g++ -std=c++17 c_struct-array.cpp -o app && ./app` | `g++ -std=c++17 c_struct-array.cpp -o app; .\app.exe` |
| `d_struct-composition.cpp` | Yapı Kompozisyonu (Nested Structs) | `g++ -std=c++17 d_struct-composition.cpp -o app && ./app` | `g++ -std=c++17 d_struct-composition.cpp -o app; .\app.exe` |

---

## 12. Pekiştirme Alıştırmaları (Çözümlü Sorular)

### Soru 1: Bir Matrisin Simetrik Olup Olmadığını Kontrol Etme
Kare bir matrisin ($N \times N$) devriğine (transpozuna) eşit olup olmadığını ($A[i][j] == A[j][i]$) kontrol eden fonksiyonu yazınız.

**Çözüm:**
```cpp
#include <iostream>
using namespace std;

const int N = 3;

bool isSymmetric(const int mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) { // Sadece köşegenin üstünü kontrol etmek yeterlidir
            if (mat[i][j] != mat[j][i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int matris[N][N] = {
        {1, 7, 3},
        {7, 4, -5},
        {3, -5, 6}
    };

    cout << "Matris simetrik mi? " << boolalpha << isSymmetric(matris) << endl; // true
    return 0;
}
```

---

### Soru 2: Çıktı Analizi (Yapı Kopyalama)
Aşağıdaki kod parçasının çıktısı nedir?
```cpp
#include <iostream>
using namespace std;

struct Nokta {
    int x, y;
};

int main() {
    Nokta p1 = {10, 20};
    Nokta p2 = p1; // Varsayılan üye üye kopyalama (Memberwise copy)
    p2.x = 99;

    cout << "p1.x: " << p1.x << ", p2.x: " << p2.x << endl;
    return 0;
}
```
**Çözüm:**
- `p2 = p1` ataması yapıldığında C++ otomatik olarak tüm alanları kopyalar (değer kopyası).
- `p2.x`'in değiştirilmesi `p1.x`'i etkilemez.
- Çıktı: `p1.x: 10, p2.x: 99`.

---

## 12. Öğrenciler İçin Ev Ödevleri

### Ödev 1: Matris Determinantı ve Ters Matris Hesaplayıcı
- **Görev:** Kullanıcının girdiği $3 \times 3$'lük bir matrisin determinantını (Sarrus kuralı veya kofaktör açılımı ile) hesaplayan, determinant sıfırdan farklıysa matrisin tersini ($A^{-1}$) bulup formatlı olarak ekrana yazdıran programı kodlayınız.

### Ödev 2: Öğrenci Otomasyon Sistemi (`struct` ve Dosya Bütünleşmesi)
- **Görev:** `Ogrenci` yapısı (`int no`, `string adSoyad`, `double vize`, `double finalNot`, `char harfNotu`) tanımlayınız.
  - Kullanıcıya menü sunarak: Yeni öğrenci ekleme (en fazla 100 öğrenci), öğrencileri GNO'ya göre büyükten küçüğe sıralama (`sort`), sınıf ortalamasını hesaplama ve verileri `ogrenciler.dat` dosyasına kaydedip geri yükleme yeteneklerini kodlayınız.

### Ödev 3: Tic-Tac-Toe (XOX) Oyunu
- **Görev:** İki kişilik oynanabilen $3 \times 3$'lük matris tabanlı bir XOX oyunu geliştiriniz:
  - Oyun her hamlede tahtanın güncel durumunu ekrana basmalıdır.
  - Yatay, dikey veya çaprazda 3 aynı sembolü (`X` veya `O`) ilk yan yana getiren oyuncunun kazandığını tespit etmeli, hamle kalmadığında ise "Berabere" bittiğini bildirmelidir.
