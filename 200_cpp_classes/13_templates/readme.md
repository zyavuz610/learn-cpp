# 13. Şablonlar ve Jenerik Programlama (Templates & Generic Programming)

Bu bölüm, veri tiplerinden bağımsız genel amaçlı algoritmalar ve sınıflar tasarlamayı sağlayan Jenerik Programlama (*Generic Programming*), fonksiyon şablonları (*function templates*), sınıf şablonları (*class templates*), şablon örneklendirmesi (*template instantiation*), şablon özelleştirmesi (*template specialization*), tip dışı şablon parametreleri (*non-type template parameters*), komut satırı argümanları (`argc`, `argv`) ve satır içi fonksiyonlar (*inline functions*) konularını kapsamaktadır.

---

## 📑 İçindekiler
1. [Jenerik Programlama ve Şablon (Template) Mantığı](#1-jenerik-programlama-ve-şablon-template-mantığı)
2. [Fonksiyon Şablonları (Function Templates)](#2-fonksiyon-şablonları-function-templates)
3. [Çoklu Tür Parametreli Şablonlar](#3-çoklu-tür-parametreli-şablonlar)
4. [Sınıf Şablonları (Class Templates)](#4-sınıf-şablonları-class-templates)
5. [Örnek Uygulama: Jenerik Matris Sınıfı](#5-örnek-uygulama-jenerik-matris-sınıfı)
6. [Şablon Derleme Modeli (Neden Header Dosyalarında Yazılır?)](#6-şablon-derleme-modeli-neden-header-dosyalarında-yazılır)
7. [Satır İçi Fonksiyonlar (inline) ve ODR Kuralı](#7-satır-içi-fonksiyonlar-inline-ve-odr-kuralı)
8. [Komut Satırı Parametreleri (argc ve argv)](#8-komut-satırı-parametreleri-argc-ve-argv)
9. [Ekstra: Tip Dışı Şablon Parametreleri (Non-type Parameters) ve Şablon Özelleştirmesi](#9-ekstra-tip-dışı-şablon-parametreleri-non-type-parameters-ve-şablon-özelleştirmesi)
10. [Kodları Derleme ve Çalıştırma Rehberi (Komut Tablosu)](#10-kodları-derleme-ve-çalıştırma-rehberi-komut-tablosu)
11. [Pekiştirme Alıştırmaları (Çözümlü Sorular)](#11-pekiştirme-alıştırmaları-çözümlü-sorular)
12. [Öğrenciler İçin Ev Ödevleri](#12-öğrenciler-için-ev-ödevleri)

---

## 1. Jenerik Programlama ve Şablon (Template) Mantığı

İlgili kaynak dosya: [templates.cpp](templates.cpp)

Jenerik Programlama, kodun belirli bir veri tipine (`int`, `double`, `string`) bağlı kalmadan, tipin kendisinin bir parametre olarak verildiği soyut algoritmalar ve yapılar yazma yaklaşımıdır.

Şablonlar olmasaydı:
İki değeri karşılaştıran bir fonksiyon için `int`, `double`, `float`, `char`, `long` türlerinin her biri için ayrı ayrı onlarca aşırı yüklenmiş fonksiyon yazmak zorunda kalırdık.

**Şablon Çözümü:**
Derleyiciye bir kalıp (şablon) veririz. Derleyici programın akışında hangi tiple çağrıldığını görür ve o tipe özel fonksiyonu makine kodunda **otomatik olarak kendisi üretir (Template Instantiation)**.

---

## 2. Fonksiyon Şablonları (Function Templates)

İlgili kaynak dosya: [templates.cpp](templates.cpp)

**Sözdizimi:**
`template <typename T>` veya `template <class T>`
*(C++ standartlarında `typename` ve `class` bu bağlamda tamamen eşanlamlıdır; modern C++'ta `typename` tercih edilir).*

```cpp
#include <iostream>
#include <string>
using namespace std;

// Jenerik En Büyük Elemanı Bulma Şablonu
template <typename T>
T enBuyuk(T a, T b) {
    return (a > b) ? a : b;
}

// Jenerik Takas (Swap) Fonksiyonu
template <typename T>
void takas(T& a, T& b) {
    T gecici = a;
    a = b;
    b = gecici;
}

int main() {
    // 1. Örtük Tip Çıkarsaması (Implicit Type Deduction)
    cout << "Büyük (int)   : " << enBuyuk(10, 25) << endl;     // T = int
    cout << "Büyük (double): " << enBuyuk(3.14, 2.71) << endl; // T = double
    cout << "Büyük (string): " << enBuyuk(string("Trabzon"), string("Ankara")) << endl;

    // 2. Açık Tip Belirtimi (Explicit Type Specification)
    cout << "Açıkça int    : " << enBuyuk<int>(15, 20.8) << endl;

    int x = 5, y = 9;
    takas(x, y);
    cout << "Takas sonrası: x=" << x << ", y=" << y << endl; // x=9, y=5

    return 0;
}
```

---

## 3. Çoklu Tür Parametreli Şablonlar

İlgili kaynak dosya: [templates.cpp](templates.cpp)

Bir fonksiyon veya sınıf birden fazla farklı tür parametresi alabilir:

```cpp
#include <iostream>
using namespace std;

template <typename T1, typename T2>
void ikiliYazdir(T1 anahtar, T2 deger) {
    cout << "[" << anahtar << "] => " << deger << endl;
}

int main() {
    ikiliYazdir("OgrenciNo", 202601); // T1 = const char*, T2 = int
    ikiliYazdir(1, 98.5);              // T1 = int, T2 = double
    return 0;
}
```

---

## 4. Sınıf Şablonları (Class Templates)

İlgili kaynak dosya: [templates.cpp](templates.cpp)

Veri yapıları (koleksiyonlar, yığınlar, kuyruklar, matrisler) genellikle sınıf şablonu olarak tasarlanır.

```cpp
#include <iostream>
using namespace std;

// Jenerik Çift Değer Tutucu (Pair) Sınıf Şablonu
template <typename T>
class Cift {
private:
    T birinci, ikinci;

public:
    Cift(T a, T b) : birinci(a), ikinci(b) {}

    T getBirinci() const { return birinci; }
    T getIkinci() const { return ikinci; }

    T maksimum() const {
        return (birinci > ikinci) ? birinci : ikinci;
    }
};

int main() {
    // Sınıf şablonlarında tür parantez içinde belirtilir: Cift<int>
    Cift<int> sayiCifti(45, 90);
    cout << "Maksimum sayi: " << sayiCifti.maksimum() << endl; // 90

    Cift<double> kesirliCift(3.14, 2.71);
    cout << "Maksimum kesir: " << kesirliCift.maksimum() << endl; // 3.14

    return 0;
}
```

---

## 5. Örnek Uygulama: Jenerik Matris Sınıfı

İlgili kaynak dosya: [matrix-templates.cpp](matrix-templates.cpp)

Herhangi bir türdeki (`int`, `float`, `double`) verilerle matematiksel matris işlemleri yapabilen jenerik sınıf:

```cpp
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Matris {
private:
    int satir, sutun;
    vector<vector<T>> veri;

public:
    Matris(int r, int c, T baslangic = T()) : satir(r), sutun(c), veri(r, vector<T>(c, baslangic)) {}

    void set(int r, int c, T val) { veri[r][c] = val; }
    T get(int r, int c) const { return veri[r][c]; }

    void yazdir() const {
        for (int i = 0; i < satir; i++) {
            for (int j = 0; j < sutun; j++) {
                cout << veri[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

int main() {
    Matris<int> tamsayiMatrisi(2, 2, 0);
    tamsayiMatrisi.set(0, 0, 10);
    tamsayiMatrisi.set(1, 1, 20);
    tamsayiMatrisi.yazdir();

    Matris<double> ondalikMatris(2, 2, 1.5);
    ondalikMatris.yazdir();

    return 0;
}
```

---

## 6. Şablon Derleme Modeli (Neden Header Dosyalarında Yazılır?)

Normal sınıflarda metot prototipleri `.h` dosyasına, gövdeleri `.cpp` dosyasına yazılır. **Ancak şablonlarda bu yapılamaz!**

> [!IMPORTANT]
> **Şablon Gövdeleri Mutlaka Header (`.h` / `.hpp`) Dosyasında Bulunmalıdır:**
> Şablonlar derleyicinin kod üretebilmesi için birer reçetedir. Derleyici `enBuyuk<int>` çağrısını gördüğü anda şablonun tam gövdesini görmek zorundadır. Eğer şablon gövdesi `.cpp` dosyasına ayrılırsa, bağlayıcı (*linker*) aşamasında **"undefined reference to ..."** hatası meydana gelir.

---

## 7. Satır İçi Fonksiyonlar (inline) ve ODR Kuralı

İlgili kaynak dosya: [inline-function.cpp](inline-function.cpp)

- **`inline`:** Fonksiyon çağrı yükünü (*call overhead*) ortadan kaldırmak için derleyiciye fonksiyon kodunu çağrıldığı yere doğrudan gömme tavsiyesi verir.
- **Tek Tanım Kuralı (One Definition Rule - ODR):** Normal bir fonksiyon header içine gövdesiyle yazılırsa ve birden fazla `.cpp` tarafından dahil edilirse "multiple definition" hatası oluşur. Ancak `inline` veya şablon fonksiyonlar ODR kuralından muaftır; derleyici aynı kopyaları tekilleştirir.

---

## 8. Komut Satırı Parametreleri (argc ve argv)

İlgili kaynak dosya: [command-line-params.cpp](command-line-params.cpp)

Konsoldan çalıştırılan bir programa parametre aktarmak için `main` fonksiyonunun iki parametreli biçimi kullanılır:
`int main(int argc, char* argv[])`

- **`argc` (Argument Count):** Komut satırından girilen argümanların toplam sayısıdır (programın kendi adı her zaman ilk argümandır: `argc >= 1`).
- **`argv` (Argument Vector):** Girilen argümanları dizi olarak tutan karakter dizileri dizisidir (`char*` dizisi). `argv[0]` programın dosya adıdır.

```cpp
#include <iostream>
#include <fstream>
using namespace std;

// Programın komut satırından aldığı dosya adını okuyup ekrana basması
int main(int argc, char* argv[]) {
    cout << "Toplam Argüman Sayısı: " << argc << endl;

    if (argc < 2) {
        cout << "Kullanım: " << argv[0] << " <okunacak_dosya_adi>\n";
        return 1;
    }

    cout << "Açılacak dosya: " << argv[1] << endl;
    ifstream dosya(argv[1]);
    if (!dosya) {
        cerr << "Hata: Dosya bulunamadı!\n";
        return 1;
    }

    string satir;
    while (getline(dosya, satir)) {
        cout << satir << endl;
    }
    dosya.close();

    return 0;
}
```

---

## 9. Ekstra: Tip Dışı Şablon Parametreleri (Non-type Parameters) ve Şablon Özelleştirmesi

### 1. Tip Dışı Şablon Parametreleri (Non-type Template Parameters)
Şablon parametresi olarak bir veri tipi yerine doğrudan sabit bir değer (örneğin tamsayı boyut) geçirilmesidir (Tıpkı `std::array<int, 5>` yapısında olduğu gibi):
```cpp
#include <iostream>
using namespace std;

// T: Tip parametresi, BOYUT: Tip dışı (Non-type) tamsayı parametresi
template <typename T, int BOYUT>
class SabitDizi {
private:
    T dizi[BOYUT];
public:
    int getBoyut() const { return BOYUT; }
    T& operator[](int i) { return dizi[i]; }
};

int main() {
    SabitDizi<int, 10> d1; // 10 elemanlı int dizisi
    SabitDizi<double, 50> d2; // 50 elemanlı double dizisi
    cout << "d1 boyutu: " << d1.getBoyut() << endl; // 10
    return 0;
}
```

### 2. Şablon Özelleştirmesi (Template Specialization)
Belirli bir özel tip için şablonun genel mantığı yerine farklı bir özel algoritma çalıştırmak istendiğinde kullanılır:
```cpp
template <typename T>
class Gosterici {
public:
    void yaz(T val) { cout << "Genel tip: " << val << endl; }
};

// char* tipi için tam özelleştirme (Full Specialization)
template <>
class Gosterici<char*> {
public:
    void yaz(char* val) { cout << "ÖZEL Karakter Dizisi: " << val << endl; }
};
```

---

## 10. Kodları Derleme ve Çalıştırma Rehberi (Komut Tablosu)

Bu dizindeki şablon ve komut satırı programlarını terminal üzerinden derlemek ve çalıştırmak için:

```bash
# Standart Şablon Programlarını Derleme:
g++ -std=c++17 -Wall dosya_adi.cpp -o app
./app         # Linux / macOS / Git Bash
.\app.exe     # Windows PowerShell / CMD

# Komut Satırı Argümanı (argc/argv) Alan Programları Çalıştırma:
g++ -std=c++17 -Wall command-line-params.cpp -o cmd_app
./cmd_app girdi.txt           # Linux / macOS / Git Bash
.\cmd_app.exe girdi.txt       # Windows PowerShell / CMD
```

### Hızlı Başvuru Komut Tablosu

| Kaynak Kod Dosyası | Açıklama | Hızlı Derleme ve Çalıştırma (Bash / Linux / Mac) | Hızlı Derleme ve Çalıştırma (Windows PowerShell) |
| :--- | :--- | :--- | :--- |
| `templates.cpp` | Fonksiyon ve Sınıf Şablonları | `g++ -std=c++17 templates.cpp -o app && ./app` | `g++ -std=c++17 templates.cpp -o app; .\app.exe` |
| `matrix-templates.cpp` | Jenerik Matris Sınıf Şablonu | `g++ -std=c++17 matrix-templates.cpp -o app && ./app` | `g++ -std=c++17 matrix-templates.cpp -o app; .\app.exe` |
| `inline-function.cpp` | Satır İçi (`inline`) Fonksiyonlar | `g++ -std=c++17 inline-function.cpp -o app && ./app` | `g++ -std=c++17 inline-function.cpp -o app; .\app.exe` |
| `command-line-params.cpp` | Komut Satırı Parametreleri (`argc`, `argv`) | `g++ -std=c++17 command-line-params.cpp -o app && ./app` | `g++ -std=c++17 command-line-params.cpp -o app; .\app.exe` |

---

## 11. Pekiştirme Alıştırmaları (Çözümlü Sorular)

### Soru 1: Jenerik Dizi Arama Şablonu
Herhangi bir türdeki dizide aranan elemanın indeksini bulan doğrusal arama (`linearSearch`) şablon fonksiyonunu yazınız.

**Çözüm:**
```cpp
#include <iostream>
#include <string>
using namespace std;

template <typename T>
int dogrusalArama(const T arr[], int boyut, const T& aranan) {
    for (int i = 0; i < boyut; i++) {
        if (arr[i] == aranan) { // T türü == operatörünü desteklemelidir
            return i;
        }
    }
    return -1; // Bulunamadı
}

int main() {
    int sayilar[] = {10, 20, 30, 40};
    cout << "20'nin indeksi: " << dogrusalArama(sayilar, 4, 20) << endl; // 1

    string kelimeler[] = {"elma", "armut", "cilek"};
    cout << "cilek indeksi : " << dogrusalArama(kelimeler, 3, string("cilek")) << endl; // 2
    return 0;
}
```

---

## 11. Öğrenciler İçin Ev Ödevleri

### Ödev 1: Jenerik Yığın (Stack) Veri Yapısı Şablonu
- **Görev:** Dinamik bellek tahsis eden jenerik `Yigin<T>` (Stack) sınıf şablonu geliştiriniz.
  - `push(T eleman)`: Yığının tepesine eleman ekler (kapasite dolarsa dinamik 2 katına çıkar).
  - `pop()`: Yığının tepesindeki elemanı çeker ve siler (boşsa istisna fırlatır).
  - `top()`: Tepedeki elemanı silmeden görüntüler.
  - `isEmpty()`: Yığının boş olup olmadığını bildirir.
  - Sınıfı `int`, `string` ve kendi yazdığınız bir `Ogrenci` sınıfı ile test ediniz.

### Ödev 2: Jenerik Sıralama Algoritması (Bubble Sort & Selection Sort)
- **Görev:** Herhangi bir türdeki diziyi küçükten büyüğe sıralayan jenerik `sirala(T arr[], int boyut)` şablon fonksiyonunu yazınız. Fonksiyonu hem sayılar hem de metin dizileri (`std::string`) üzerinde test ediniz.

### Ödev 3: Komut Satırından Dosya Şifreleme / Kopyalama Aracı
- **Görev:** Komut satırından `program <kaynak_dosya> <hedef_dosya> <anahtar>` parametrelerini alan, `argc` ve `argv` denetimlerini eksiksiz yapan ve kaynak dosyayı okuyup belirtilen anahtarla XOR şifrelemesi yaparak hedef dosyaya yazan konsol yardımcı aracını kodlayınız.
