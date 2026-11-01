# 0. C++'a Giriş, Geliştirme Ortamı ve Temel Algoritmalar

Bu bölüm, C++ programlama diline ilk adımı atacak öğrenciler için temel geliştirme ortamının hazırlanmasını, C++ dilinin sözdizimi ve çalışma mantığını, C ile C++ arasındaki felsefi ve teknik farkları ve programlamanın belkemiğini oluşturan en temel dizi algoritmalarını kapsamaktadır.

---

## 📑 İçindekiler
1. [Geliştirme Ortamı ve Temel Terminal Komutları](#1-geliştirme-ortamı-ve-temel-terminal-komutları)
2. [İlk C++ Programı ve C vs C++ Karşılaştırması](#2-ilk-c-programı-ve-c-vs-c-karşılaştırması)
3. [C++ Sözdizimi (Syntax) ve Dil Kuralları](#3-c-sözdizimi-syntax-ve-dil-kuralları)
4. [Temel Programlama ve Dizi Algoritmaları](#4-temel-programlama-ve-dizi-algoritmaları)
5. [Ekstra: C++ Derleme Süreci ve Derleyici Bayrakları](#5-ekstra-c-derleme-süreci-ve-derleyici-bayrakları)
6. [Pekiştirme Alıştırmaları (Çözümlü Sorular)](#6-pekiştirme-alıştırmaları-çözümlü-sorular)
7. [Öğrenciler İçin Ev Ödevleri](#7-öğrenciler-için-ev-ödevleri)

---

## 1. Geliştirme Ortamı ve Temel Terminal Komutları

C++ kodları metin dosyaları olarak yazılır (`.cpp`) ve doğrudan işlemci tarafından çalıştırılamaz. Bir **derleyici (compiler)** yardımıyla makine koduna (çalıştırılabilir ikili dosya - binary/executable) dönüştürülmelidir.

İlgili kaynak dosya: [0_linux-cammands.txt](0_linux-cammands.txt)

### Önerilen Geliştirme Ortamları
- **Yerel Ortam (Local):** 
  - **Windows:** VS Code + [w64devkit / MinGW-w64](https://www.mingw-w64.org/downloads/) (GCC/G++ derleyicisi).
  - **Linux / macOS:** GCC (`g++`) veya LLVM/Clang (`clang++`).
- **Bulut Tabanlı Ortam (Online):** [Replit.com](https://replit.com) (Kurulum gerektirmeden tarayıcı üzerinden hızlı deneme ve öğrenme olanağı sunar).

### Temel Terminal (Linux / Bash / PowerShell) Komutları

| Komut | Açıklama | Örnek Kullanım |
| :--- | :--- | :--- |
| `pwd` | Bulunulan dizinin tam yolunu gösterir (*print working directory*) | `pwd` |
| `ls` / `dir` | Bulunulan dizindeki dosya ve klasörleri listeler (`-la` gizli dosyalar dahil) | `ls -la` |
| `cd` | Dizin değiştirir | `cd 100_cpp_basics` veya `cd ..` (üst dizin) |
| `mkdir` | Yeni bir dizin (klasör) oluşturur | `mkdir proje1` |
| `touch` | Yeni boş bir dosya oluşturur veya dosya tarihini günceller | `touch main.cpp` |
| `rm` | Dosya siler (`-r` alt klasörleri de siler) | `rm dosya.txt` / `rm -rf eski_dizin` |
| `cp` | Dosya veya dizin kopyalar | `cp kaynak.cpp hedef.cpp` |
| `mv` | Dosyayı taşır veya yeniden adlandırır | `mv eski_ad.cpp yeni_ad.cpp` |
| `cat` / `type` | Dosyanın içeriğini terminale yazdırır | `cat main.cpp` |

### C++ Kodunu Komut Satırından Derleme ve Çalıştırma

C++ kodlarını derlemek için `g++` derleyicisi kullanılır:

```bash
# 1. Kaynak kodu derleme (-o parametresi çıktı dosyasının adını belirler)
g++ -o program main.cpp

# 2. Derlenmiş programı çalıştırma
./program          # Linux / macOS / Git Bash
.\program.exe      # Windows PowerShell / CMD

# 3. Derleme ve başarılı olursa doğrudan çalıştırma (tek komut)
g++ -o program main.cpp && ./program
```

---

## 2. İlk C++ Programı ve C vs C++ Karşılaştırması

İlgili kaynak dosya: [1_hello-world.cpp](1_hello-world.cpp)

İlk C++ programımızın yapısını ve temel yapı taşlarını inceleyelim:

```cpp
// Giriş-çıkış (input-output) akış kütüphanesini dahil ediyoruz
#include <iostream>

// Standart isim alanını (namespace) kodumuza dahil ediyoruz
using namespace std;

// İşletim sisteminin programı başlattığı ana fonksiyon
int main() {
    // cout (character output) ile konsola metin yazdırılır
    // << operatörü 'stream insertion' (akışa ekleme) operatörüdür
    cout << "Merhaba Dünya! KTÜ Bilgisayar Mühendisliği\n";

    // 0 değeri işletim sistemine programın başarıyla tamamlandığını bildirir
    return 0;
}
```

### Kodun Anatomisi
1. `#include <iostream>`: C++ Standart Kütüphanesinden giriş/çıkış akışlarını (`cout`, `cin`, `cerr`) sağlayan başlık dosyasını (*header*) önişlemci (*preprocessor*) aracılığıyla koda dahil eder.
2. `using namespace std;`: Standart kütüphanedeki tüm öğeler `std` isim alanı (*namespace*) içerisindedir. Bu satır sayesinde `std::cout` yazmak yerine doğrudan `cout` yazabiliriz.
3. `int main()`: C ve C++ programlarının giriş kapısıdır. İşletim sistemi programı buradan yürütmeye başlar. `int` dönüş tipi, fonksiyonun işletim sistemine bir tamsayı hata kodu bildireceğini belirtir.
4. `return 0;`: Programın hatasız ve başarılı bir şekilde sonlandığını temsil eden çıkış kodudur (exit status code).

---

### C ile C++ Arasındaki Temel ve Felsefi Farklar

| Özellik | C Dili | C++ Dili |
| :--- | :--- | :--- |
| **Geliştirici & Yıl** | Dennis Ritchie (1973, AT&T Bell Labs) | Bjarne Stroustrup (1979, Bell Labs - "C with Objects") |
| **Programlama Paradigması** | Yordamsal (Procedural) | Çok Paradigmali (Multi-paradigm: OOP, Prosedürel, Generic) |
| **Odak Noktası** | Fonksiyonlar ve adımlar (Function-driven) | Veri ve Nesneler (Data/Object-driven) |
| **Nesne Yönelim (OOP)** | Yok (Kalıtım, polimorfizm, kapsülleme desteklenmez) | Tam destek (Sınıflar, miras, çok biçimlilik, soyutlama) |
| **Giriş / Çıkış** | Fonksiyon tabanlı: `printf()`, `scanf()` (`<stdio.h>`) | Akış ve nesne tabanlı: `std::cout`, `std::cin` (`<iostream>`) |
| **Dinamik Bellek** | `malloc()`, `calloc()`, `free()` | `new` ve `delete` operatörleri (nesne constructor/destructor çağrılır) |
| **Operator Overloading** | Desteklemez | Destekler (örn: `+` operatörü sayılar için toplama, string için birleştirme yapar) |
| **Struct Yetenekleri** | Yalnızca veri tutar, fonksiyon barındıramaz | Fonksiyon, erişim belirteci (public/private) ve kurucu barındırabilir |
| **İsim Alanı (Namespace)** | Yok (Global isim çakışmaları riski yüksektir) | Var (`namespace` ile isim çakışmaları önlenir) |
| **Referans Değişkeni** | Yok (Sadece pointer aritmetiği var) | Var (`int &ref = x;` referanslar desteklenir) |
| **Hata Yönetimi** | Dönüş kodları ile manuel kontrol | İstisna Durum Yönetimi (Exception Handling: `try-catch-throw`) |
| **Anahtar Kelime Sayısı** | ~32 anahtar kelime | ~52+ anahtar kelime (C++20 ile daha da artmıştır) |

---

## 3. C++ Sözdizimi (Syntax) ve Dil Kuralları

İlgili kaynak dosya: [2_cpp-syntax.cpp](2_cpp-syntax.cpp), Şablon: [template.cpp](template.cpp)

C++ dilinde kod yazarken uyulması gereken temel kurallar şunlardır:

### 1. İfade Sonlandırma (Statements and Semicolons)
C++ dilinde her komut/ifade (*statement*) noktalı virgül (`;`) ile sonlandırılmalıdır.
```cpp
int x = 10;
x = x + 5;
cout << x << endl;
```

### 2. Blok Yapısı (`{ ... }`)
Mantıksal olarak bir arada bulunması gereken ifadeler kıvrık parantezler (`{ }`) içerisine alınır. Bloklar değişkenlerin etki alanını (*scope*) da sınırlar.
```cpp
{
    int yerelSayi = 50;
    cout << yerelSayi << endl;
} // yerelSayi burada bellekten temizlenir
```

### 3. Yorum Satırları (Comments)
Yorum satırları derleyici tarafından tamamen yok sayılır ve ikili dosya boyutunu etkilemez.
```cpp
// Tek satırlık yorum

/* 
   Çok satırlı
   blok yorum 
*/
```

### 4. Tanımlayıcılar (Identifiers) ve İsimlendirme Kuralları
Değişkenler, fonksiyonlar ve sınıflara verilen isimlerdir.
- Harfler (`a-z`, `A-Z`) veya alt çizgi (`_`) ile başlamalıdır.
- Rakamla **başlayamaz**, ancak ilk karakterden sonra rakam içerebilir (`sayi1` geçerli, `1sayi` geçersiz).
- Özel karakterler içeremez (`@`, `$`, `%`, `-`, boşluk vb. yasaktır).
- C++ **büyük/küçük harfe duyarlıdır** (*case-sensitive*). `toplam`, `Toplam` ve `TOPLAM` üç farklı değişkendir.
- C++'ın rezerve edilmiş anahtar kelimeleri (*keywords*: `int`, `double`, `class`, `return`, `if` vb.) isim olarak kullanılamaz.

### 5. Beyaz Boşluklar (Whitespace)
C++ serbest biçimli (*free-form*) bir dildir. Boşluklar, tab karakterleri ve satır sonları derleyici için önemsizdir. Kodun okunabilirliği (*clean code*) için standart girintileme (*indentation*) yapılmalıdır.

---

## 4. Temel Programlama ve Dizi Algoritmaları

İlgili kaynak dosya: [3_algorithms.cpp](3_algorithms.cpp)

Her bilgisayar mühendisi ve yazılımcının refleks gibi bilmesi gereken en temel 9 algoritma kalıbı aşağıda özetlenmiştir:

```cpp
#include <iostream>
using namespace std;

// 1. Dizi Elemanlarını Yazdırma
void diziYazdir(const int dizi[], int boyut) {
    cout << "[ ";
    for (int i = 0; i < boyut; i++) {
        cout << dizi[i] << (i == boyut - 1 ? "" : ", ");
    }
    cout << " ]\n";
}

// 2. Toplam Bulma (Sum / Accumulation)
int toplamBul(const int dizi[], int boyut) {
    int toplam = 0; // Toplama etkisiz eleman 0
    for (int i = 0; i < boyut; i++) toplam += dizi[i];
    return toplam;
}

// 3. Çarpım Bulma (Product)
long long carpimBul(const int dizi[], int boyut) {
    long long carpim = 1; // Çarpma etkisiz eleman 1
    for (int i = 0; i < boyut; i++) carpim *= dizi[i];
    return carpim;
}

// 4. Ortalama Bulma (Average) - Tip dönüşümüne dikkat!
double ortalamaBul(const int dizi[], int boyut) {
    if (boyut == 0) return 0.0;
    // Tamsayı bölmesi veri kaybına sebep olacağından static_cast<double> şarttır
    return static_cast<double>(toplamBul(dizi, boyut)) / boyut;
}

// 5. En Büyük Elemanı Bulma (Maximum)
int enBuyukBul(const int dizi[], int boyut) {
    int enb = dizi[0];
    for (int i = 1; i < boyut; i++) {
        if (dizi[i] > enb) enb = dizi[i];
    }
    return enb;
}

// 6. En Küçük Elemanı Bulma (Minimum)
int enKucukBul(const int dizi[], int boyut) {
    int enk = dizi[0];
    for (int i = 1; i < boyut; i++) {
        if (dizi[i] < enk) enk = dizi[i];
    }
    return enk;
}

// 7. Belirli Bir Elemanın Frekansını Bulma (Count Occurrences)
int elemanSay(const int dizi[], int boyut, int aranan) {
    int adet = 0;
    for (int i = 0; i < boyut; i++) {
        if (dizi[i] == aranan) adet++;
    }
    return adet;
}

// 8. Koşullu Sayma (Örn: Çift Sayıların Adedi)
int ciftSayilariSay(const int dizi[], int boyut) {
    int adet = 0;
    for (int i = 0; i < boyut; i++) {
        if (dizi[i] % 2 == 0) adet++;
    }
    return adet;
}

// 9. Doğrusal Arama (Linear Search)
int dogrusalArama(const int dizi[], int boyut, int aranan) {
    for (int i = 0; i < boyut; i++) {
        if (dizi[i] == aranan) return i; // Bulundu, indeks dön
    }
    return -1; // Bulunamadı
}
```

---

## 5. Ekstra: C++ Derleme Süreci ve Derleyici Bayrakları

C++ kodunuzun çalıştırılabilir hale gelmesi 4 ana aşamadan geçer:

```
[Kaynak Kod .cpp] 
       │
       ▼ (1. Preprocessing - Önişleme: #include, #define işlenir)
[.ii / Preprocessed File]
       │
       ▼ (2. Compilation - Derleme: C++ kodu Assembly koduna çevrilir)
[.s / Assembly Code]
       │
       ▼ (3. Assembly - Çevirme: Assembly kodu Makine Koduna çevrilir)
[.o / .obj Object File]
       │
       ▼ (4. Linking - Bağlama: Kütüphaneler ve nesne dosyaları birleştirilir)
[Executable Binary (.exe / a.out)]
```

### Önemli G++ Derleyici Parametreleri (Compiler Flags)
Öğrencilerin temiz kod yazması ve derleyicinin sunduğu tüm uyarıları görmesi için aşağıdaki bayraklarla derleme yapması tavsiye edilir:

```bash
g++ -std=c++17 -Wall -Wextra -O2 main.cpp -o program
```
- `-std=c++17`: C++17 modern standartlarını etkinleştirir.
- `-Wall -Wextra`: Olası tüm mantıksal hatalar ve eksiklikler için derleyici uyarılarını gösterir.
- `-O2`: Kodun çalışma hızını optimize eder.

### `\n` ile `std::endl` Arasındaki Kritik Fark
- `cout << "\n";`: Yalnızca yeni satıra geçer. Çıktı tamponunu (*buffer*) boşaltmaya zorlamaz, bu nedenle performans açısından çok daha hızlıdır.
- `cout << endl;`: Yeni satıra geçer **VE** tamponu hemen boşaltır (`flush`). Yoğun döngülerde `endl` kullanmak programı ciddi ölçüde yavaşlatır.

---

## 6. Pekiştirme Alıştırmaları (Çözümlü Sorular)

### Soru 1: Çıktı Analizi
Aşağıdaki C++ kodunun konsol çıktısı ne olur? Nedenini açıklayınız.
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 7, b = 2;
    double c = a / b;
    double d = static_cast<double>(a) / b;
    cout << "c: " << c << ", d: " << d << endl;
    return 0;
}
```
**Çözüm:**
- `c: 3, d: 3.5` çıktısı üretilir.
- `a / b` ifadesinde her iki terim de `int` olduğu için derleyici tamsayı bölmesi (*integer division*) yapar ve kesirli kısmı atarak `3` sonucunu üretir. Bu `3` değeri daha sonra `double` türündeki `c` değişkenine `3.0` olarak atanır.
- `d` hesabında ise `static_cast<double>(a)` ile `a` değeri `7.0`'a dönüştürülür. Bir `double` ile bir `int` bölündüğünde C++ otomatik olarak sonucu `double` hesaplar ve `3.5` elde edilir.

---

### Soru 2: Dizi Elemanlarını Tersine Çevirme (In-place Reversal)
Verilen bir tamsayı dizisinin elemanlarını ek bir dizi kullanmadan, aynı dizi üzerinde tersine çeviren (`reverseArray`) fonksiyonu yazınız.

**Çözüm:**
```cpp
#include <iostream>
using namespace std;

void diziTersCevir(int arr[], int boyut) {
    int bas = 0;
    int son = boyut - 1;
    while (bas < son) {
        // İki elemanın takas edilmesi (Swap)
        int temp = arr[bas];
        arr[bas] = arr[son];
        arr[son] = temp;
        bas++;
        son--;
    }
}

int main() {
    int sayilar[] = {1, 2, 3, 4, 5};
    int n = 5;
    diziTersCevir(sayilar, n);
    for (int i = 0; i < n; i++) cout << sayilar[i] << " ";
    // Çıktı: 5 4 3 2 1
    return 0;
}
```

---

## 7. Öğrenciler İçin Ev Ödevleri

### Ödev 1: İkinci En Büyük Elemanı Bulma (Second Maximum)
- **Görev:** Kullanıcının girdiği $N$ elemanlı bir dizideki **en büyük ikinci** elemanı tek bir döngü içerisinde ($O(N)$ zaman karmaşıklığında) bulan fonksiyonu yazınız.
- **Kısıt:** Dizi sıralanmayacaktır (`std::sort` yasaktır). Dizideki tüm elemanların aynı olma ihtimali kontrol edilmelidir.

### Ödev 2: Polindrom Dizi Kontrolü
- **Görev:** Bir dizinin baştan ve sondan okunuşlarının aynı olup olmadığını (polindrom) kontrol eden `bool isPalindrome(const int arr[], int size)` fonksiyonunu yazınız.
- **Örnek:** `{1, 2, 3, 2, 1}` $\rightarrow$ `true`, `{1, 2, 3, 4, 5}` $\rightarrow$ `false`.

### Ödev 3: Mini İstatistik Raporu Programı
- **Görev:** Kullanıcıdan önce kaç adet sayı gireceğini alan ($N \le 100$), ardından bu sayıları okuyan bir program yazınız. Program aşağıdaki istatistikleri düzenli bir tablo halinde ekrana basmalıdır:
  1. Girilen sayıların toplamı ve aritmetik ortalaması
  2. En büyük ve en küçük değer ile bunların ilk görüldüğü indeksler
  3. Ortalamanın üstünde kalan elemanların adedi ve listesi
  4. Dizideki pozitif, negatif ve sıfır değerlerin sayıları
