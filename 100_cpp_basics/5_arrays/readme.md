# 5. Diziler, Karakter Dizileri ve C++ String Sınıfı (Arrays & Strings)

Bu bölümde C++ dilinde aynı türden çok sayıda veriyi bellekte ardışık olarak tutan tek boyutlu diziler (*arrays*), dizilerin bellek organizasyonu, derin ve sığ kopyalama (*deep copy vs shallow copy*), C-tarzı karakter dizileri (*C-strings & null terminator*), `<cstring>` fonksiyonları ve modern C++ `std::string` sınıfının kapsamlı yetenekleri ele alınmaktadır.

---

## 📑 İçindekiler
1. [Tek Boyutlu Diziler ve Bellek Modeli](#1-tek-boyutlu-diziler-ve-bellek-modeli)
2. [Dizi Bildirimi ve Başlatma Yöntemleri](#2-dizi-bildirimi-ve-başlatma-yöntemleri)
3. [Dizilerin Fonksiyonlara Aktarımı ve Algoritmik İşlemler](#3-dizilerin-fonksiyonlara-aktarımı-ve-algoritmik-işlemler)
4. [Derin Kopyalama (Deep Copy) vs Sığ Kopyalama (Shallow Copy)](#4-derin-kopyalama-deep-copy-vs-sığ-kopyalama-shallow-copy)
5. [C-Tarzı Karakter Dizileri ve `<cstring>` Kütüphanesi](#5-c-tarzı-karakter-dizileri-ve-cstring-kütüphanesi)
6. [Modern C++ `std::string` Sınıfı ve Metotları](#6-modern-c-stdstring-sınıfı-ve-metotları)
7. [İki Boyutlu Dizilere Giriş](#7-iki-boyutlu-dizilere-giriş)
8. [Ekstra: Güvenli Diziler (`std::array`) ve Dinamik Diziye (`std::vector`) Bakış](#8-ekstra-güvenli-diziler-stdarray-ve-dinamik-diziye-stdvector-bakış)
9. [Pekiştirme Alıştırmaları (Çözümlü Sorular)](#9-pekiştirme-alıştırmaları-çözümlü-sorular)
10. [Öğrenciler İçin Ev Ödevleri](#10-öğrenciler-için-ev-ödevleri)

---

## 1. Tek Boyutlu Diziler ve Bellek Modeli

İlgili kaynak dosya: [1_arrays.cpp](1_arrays.cpp)

Dizi (Array), aynı veri tipindeki birden fazla elemanın bellekte **ardışık (contiguous)** olarak saklandığı statik ve doğrusal bir veri yapısıdır.

### Bellek Yerleşim Mantığı
Bir dizinin elemanına indeksle erişildiğinde derleyici adresi şu formülle hesaplar:
$$\text{Eleman Adresi} = \text{Başlangıç Adresi (Base Address)} + (\text{İndeks} \times \text{Eleman Boyutu})$$

Bu sayede dizi boyutu ne kadar büyük olursa olsun, herhangi bir indeksteki elemana $O(1)$ (sabit zamanda) anında erişilir.

```
Bellek İndeksi:       [0]         [1]         [2]         [3]         [4]
Bellek Adresi:    0x1000      0x1004      0x1008      0x100C      0x1010  (int için 4'er byte artar)
Değerler:         |  12  |    |  25  |    |  40  |    |  55  |    |  90  |
```

> [!CAUTION]
> **Sınır Denetimi Yokluğu (Out-of-Bounds Access):** C++ dilinde performans amacıyla yerel dizilerde indeks sınır kontrolü yapılmaz. Örneğin 5 elemanlı bir dizide `arr[10]` elemanına erişmeye çalışmak derleme hatası vermez; fakat başka bir program verisinin üzerine yazarak **bellek bozulmasına (memory corruption)** veya çökmeye yol açar.

---

## 2. Dizi Bildirimi ve Başlatma Yöntemleri

İlgili kaynak dosyalar: [1_arrays.cpp](1_arrays.cpp), [2_array-example.cpp](2_array-example.cpp)

```cpp
#include <iostream>
using namespace std;

int main() {
    // 1. Sadece bildirim (Bellekteki değerler çöptür / garbage)
    int arr1[5];

    // 2. Boyut belirtmeden elemanlarla başlatma (Boyut otomatik 5 olur)
    int arr2[] = {10, 20, 30, 40, 50};

    // 3. Kısmi başlatma (İlk iki eleman 1 ve 2, kalan 3 eleman otomatik 0 olur)
    int arr3[5] = {1, 2}; // {1, 2, 0, 0, 0}

    // 4. Tüm elemanları sıfırlama (Zero Initialization)
    int arr4[5] = {0};    // {0, 0, 0, 0, 0}

    // 5. Boyutun sizeof ile hesaplanması
    int elemanSayisi = sizeof(arr2) / sizeof(arr2[0]); // 20 byte / 4 byte = 5
    cout << "arr2 eleman sayısı: " << elemanSayisi << endl;

    return 0;
}
```

---

## 3. Dizilerin Fonksiyonlara Aktarımı ve Algoritmik İşlemler

İlgili kaynak dosyalar: [3_array-as-funtion-param.cpp](3_array-as-funtion-param.cpp), [4_enBuyukIndisBul.cpp](4_enBuyukIndisBul.cpp)

Diziler fonksiyonlara kopyalanarak değil, başlangıç adresi üzerinden aktarılır. Bu nedenle fonksiyon içinde dizi elemanlarında yapılan değişiklikler doğrudan `main` içerisindeki diziyi etkiler.

```cpp
#include <iostream>
using namespace std;

// Dizideki en büyük elemanın İNDİSİNİ bulan fonksiyon
int enBuyukIndisBul(const double arr[], int boyut) {
    if (boyut <= 0) return -1;

    int enbIndis = 0; // İlk elemanın indeksi en büyük kabul edilir
    for (int i = 1; i < boyut; i++) {
        if (arr[i] > arr[enbIndis]) {
            enbIndis = i; // Daha büyük bir değer bulunduğunda indeks güncellenir
        }
    }
    return enbIndis;
}

int main() {
    double notlar[] = {45.5, 78.0, 92.5, 64.0, 88.5};
    int boyut = 5;

    int enYuksekIndis = enBuyukIndisBul(notlar, boyut);
    cout << "En yüksek not: " << notlar[enYuksekIndis] 
         << " (" << enYuksekIndis << ". indekste bulundu)\n";
    return 0;
}
```

---

## 4. Derin Kopyalama (Deep Copy) vs Sığ Kopyalama (Shallow Copy)

İlgili kaynak dosya: [5_array-deep-copy.cpp](5_array-deep-copy.cpp)

- **Sığ Kopyalama (Shallow Copy):** Yalnızca dizinin başlangıç adresini (işaretçisini) kopyalar. Her iki işaretçi de bellekteki **aynı veriyi** gösterir. Birinde yapılan değişiklik diğerini de etkiler.
- **Derin Kopyalama (Deep Copy):** Bellekte bağımsız yeni bir alan tahsis edilir ve orijinal dizinin tüm elemanları tek tek yeni alana kopyalanır. Bir dizideki değişiklik diğerini etkilemez.

```cpp
#include <iostream>
using namespace std;

// Derin Kopyalama: Eleman eleman yeni diziye kopyalanır
void deepCopy(const int kaynak[], int hedef[], int boyut) {
    for (int i = 0; i < boyut; i++) {
        hedef[i] = kaynak[i];
    }
}

int main() {
    int diziA[3] = {1, 2, 3};
    int diziB[3];

    deepCopy(diziA, diziB, 3); // Derin kopyalama

    diziB[0] = 999;
    cout << "diziA[0]: " << diziA[0] << " (Değişmedi)\n"; // 1
    cout << "diziB[0]: " << diziB[0] << " (Güncellendi)\n"; // 999
    return 0;
}
```

---

## 5. C-Tarzı Karakter Dizileri ve `<cstring>` Kütüphanesi

İlgili kaynak dosya: [6_char-array-functions.cpp](6_char-array-functions.cpp)

C dilinden miras kalan karakter dizileri, son elemanı her zaman boş karakter (`'\0'` - Null Terminator) olan `char` dizileridir.

```cpp
char isim[] = "Ahmet"; // Bellekte: ['A', 'h', 'm', 'e', 't', '\0'] -> 6 byte!
```

### Temel `<cstring>` Fonksiyonları

| Fonksiyon | Görevi ve Açıklaması |
| :--- | :--- |
| `strlen(s)` | `'\0'` karakterine kadar olan karakter sayısını (uzunluğu) verir. |
| `strcpy(hedef, kaynak)` | `kaynak` metnini `hedef` dizisine kopyalar (Taşma riskine dikkat!). |
| `strcat(hedef, kaynak)` | `kaynak` metnini `hedef` metninin sonuna ekler (birleştirir). |
| `strcmp(s1, s2)` | İki metni sözlük sırasına göre karşılaştırır (Eşitse `0`, `s1 < s2` ise negatif, `s1 > s2` ise pozitif). |

```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str1[30] = "Karadeniz ";
    char str2[] = "Teknik Universitesi";

    strcat(str1, str2); // Birleştirme
    cout << "Birlesik: " << str1 << endl;
    cout << "Uzunluk : " << strlen(str1) << endl;

    if (strcmp(str1, str2) != 0) {
        cout << "Metinler birbirinden farklıdır.\n";
    }
    return 0;
}
```

---

## 6. Modern C++ `std::string` Sınıfı ve Metotları

İlgili kaynak dosya: [7_cpp-strings.cpp](7_cpp-strings.cpp)

`<string>` başlığı altındaki `std::string` sınıfı, dinamik bellek yönetimini otomatik yapan, taşma riski barındırmayan ve modern C++'ta C-tarzı dizilerin yerini alan nesne yönelimli sınıftır.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "Trabzon";
    string s2 = "KTU";

    // 1. Birleştirme (+) ve Karşılaştırma (==, <, >)
    string birlesik = s1 + " - " + s2;
    cout << "Birlesik: " << birlesik << endl;

    // 2. Boyut ve Kapasite
    cout << "Uzunluk: " << s1.length() << " veya " << s1.size() << endl;
    cout << "Bos mu?  : " << boolalpha << s1.empty() << endl;

    // 3. Alt Metin Alma (substr)
    string parca = birlesik.substr(0, 7); // 0. indeksten itibaren 7 karakter: "Trabzon"
    cout << "Alt metin: " << parca << endl;

    // 4. Arama (find)
    size_t konum = birlesik.find("KTU");
    if (konum != string::npos) {
        cout << "'KTU' " << konum << ". indekste bulundu.\n";
    }

    // 5. Değiştirme (replace) ve Silme (erase)
    birlesik.replace(konum, 3, "Bilgisayar Muh.");
    cout << "Guncel  : " << birlesik << endl;

    return 0;
}
```

---

## 7. İki Boyutlu Dizilere Giriş

İlgili kaynak dosya: [8_2d-arrays.cpp](8_2d-arrays.cpp)

İki boyutlu diziler, verileri satır ve sütunlardan oluşan bir tablo (matris) yapısında saklar:

```cpp
#include <iostream>
using namespace std;

int main() {
    // 3 satır, 4 sütundan oluşan matris bildirimi ve başlatılması
    int matris[3][4] = {
        {1, 2, 3, 4},       // 0. Satır
        {5, 6, 7, 8},       // 1. Satır
        {9, 10, 11, 12}     // 2. Satır
    };

    // Matrisi ekrana tablo halinde yazdırma
    for (int satir = 0; satir < 3; satir++) {
        for (int sutun = 0; sutun < 4; sutun++) {
            cout << matris[satir][sutun] << "\t";
        }
        cout << endl;
    }
    return 0;
}
```

---

## 8. Ekstra: Güvenli Diziler (`std::array`) ve Dinamik Diziye (`std::vector`) Bakış

### 1. `std::array` (C++11 `<array>`)
Geleneksel C dizilerinin sıfır ek maliyetli performansını korurken, `.size()` ve sınır kontrolü yapan `.at()` fonksiyonları ile güvenlik sağlar:
```cpp
#include <array>
#include <iostream>
using namespace std;

int main() {
    array<int, 4> modernDizi = {10, 20, 30, 40};
    cout << "Boyut: " << modernDizi.size() << endl;

    // modernDizi.at(10) = 5; // std::out_of_range istisnası fırlatır, belleği bozmaz!
    return 0;
}
```

### 2. `std::vector` (Dinamik Dizi - Kısa Giriş)
Boyutu çalışma anında ihtiyaca göre otomatik olarak büyüyüp küçülebilen dinamik dizidir:
```cpp
#include <vector>
vector<int> dinamik;
dinamik.push_back(100);
dinamik.push_back(200);
```

---

## 9. Pekiştirme Alıştırmaları (Çözümlü Sorular)

### Soru 1: C-String Ters Çevirme (Yerinde - In-Place)
Kullanıcıdan alınan bir `char str[]` dizisini ek bellek kullanmadan ters çeviren fonksiyonu yazınız.

**Çözüm:**
```cpp
#include <iostream>
#include <cstring>
using namespace std;

void stringTersCevir(char str[]) {
    int i = 0;
    int j = strlen(str) - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int main() {
    char metin[] = "Antigravity";
    stringTersCevir(metin);
    cout << "Ters: " << metin << endl; // ytivargitnA
    return 0;
}
```

---

### Soru 2: Çıktı Analizi (String Substr ve Find)
Aşağıdaki kodun ekran çıktısı nedir?
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string email = "ogrenci@ktu.edu.tr";
    size_t atPos = email.find('@');
    string domain = email.substr(atPos + 1);
    cout << "Domain: " << domain << endl;
    return 0;
}
```
**Çözüm:**
- `email.find('@')` karakterin indeksini bulur (7).
- `email.substr(7 + 1)` yani 8. indeksten sonrasını keser.
- Çıktı: `Domain: ktu.edu.tr`.

---

## 10. Öğrenciler İçin Ev Ödevleri

### Ödev 1: Dizi Elemanlarını Sağa Döndürme (Right Rotate by K Steps)
- **Görev:** $N$ elemanlı bir diziyi $K$ adım sağa dairesel olarak kaydıran `void rotateRight(int arr[], int n, int k)` fonksiyonunu yazınız.
- **Örnek:** `{1, 2, 3, 4, 5}` dizisi $K=2$ için döndürüldüğünde `{4, 5, 1, 2, 3}` olmalıdır.

### Ödev 2: Metin İçinde Kelime Sayacı ve Frekans Analizi
- **Görev:** Kullanıcının girdiği uzun bir paragraf metninde (`std::string`), kaç adet kelime olduğunu bulan ve en çok tekrar eden kelimeyi ekrana yazdıran programı geliştiriniz. Noktalama işaretleri (`.`, `,`, `!`) kelimelerden temizlenmelidir.

### Ödev 3: Anagram Kontrolü
- **Görev:** Kullanıcıdan alınan iki farklı kelimenin birbirinin anagramı (aynı harflerin farklı sıralanışıyla oluşan kelime, örn: "listen" ve "silent") olup olmadığını kontrol eden fonksiyonu yazınız.
