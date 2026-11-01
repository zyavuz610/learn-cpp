# 3. Giriş-Çıkış Akışları, Formatlama ve Dosya İşlemleri (I/O & File Streams)

Bu bölüm, C++ dilinde konsol girdi ve çıktı akışlarının derinlemesine yönetimini (`cin` ve `cout` fonksiyonları/metotları), `<iomanip>` kütüphanesi ile profesyonel çıktı formatlamayı ve `<fstream>` kütüphanesi aracılığıyla metin ve ikili dosya okuma/yazma (File I/O) ile rastgele erişimli dosya yönetimini (*Random Access Files*) kapsamaktadır.

---

## 📑 İçindekiler
1. [Standart Giriş Akışı (cin) ve Akış Manipülasyon Metotları](#1-standart-giriş-akışı-cin-ve-akış-manipülasyon-metotları)
2. [Girdi Hata Yönetimi ve Tampon Temizliği (cin.clear ve cin.ignore)](#2-girdi-hata-yönetimi-ve-tampon-temizliği-cinclear-ve-cinignore)
3. [Biçimlendirilmiş Çıktı Yönetimi (cout ve iomanip)](#3-biçimlendirilmiş-çıktı-yönetimi-cout-ve-iomanip)
4. [Dosya İşlemlerine Giriş (ifstream, ofstream, fstream)](#4-dosya-işlemlerine-giriş-ifstream-ofstream-fstream)
5. [Dosya Açma Modları (ios::app, ios::binary, ios::ate vb.)](#5-dosya-açma-modları-iosapp-iosbinary-iosate-vb)
6. [Rastgele Erişimli Dosyalar (seekg, seekp, tellg, tellp)](#6-rastgele-erişimli-dosyalar-seekg-seekp-tellg-tellp)
7. [Örnek Uygulama: Öğrenci Not Dosyası Analizi](#7-örnek-uygulama-öğrenci-not-dosyası-analizi)
8. [Ekstra: stringstream (Hafıza İçi Akışlar) ve İkili (Binary) Dosya I/O](#8-ekstra-stringstream-hafıza-içi-akışlar-ve-ikili-binary-dosya-io)
9. [Pekiştirme Alıştırmaları (Çözümlü Sorular)](#9-pekiştirme-alıştırmaları-çözümlü-sorular)
10. [Öğrenciler İçin Ev Ödevleri](#10-öğrenciler-için-ev-ödevleri)

---

## 1. Standart Giriş Akışı (cin) ve Akış Manipülasyon Metotları

İlgili kaynak dosyalar: [1_cin-intro.cpp](1_cin-intro.cpp), [2_cin-multiple-input.cpp](2_cin-multiple-input.cpp), [4_cin-putback.cpp](4_cin-putback.cpp), [5_cin-peek.cpp](5_cin-peek.cpp), [6_cin-get.cpp](6_cin-get.cpp)

`std::cin`, klavyeden veri almak için kullanılan giriş akış (*input stream*) nesnesidir.

### Temel Giriş Metotları:
- `cin >> degisken;`: Beyaz boşlukları (*whitespace*: boşluk, tab, yeni satır) atlar ve istenen tipte veriyi çeker (*extraction operator*).
- `cin.get(ch)` veya `ch = cin.get()`: Boşluk ve yeni satır (`\n`) dahil olmak üzere akıştaki sıradaki **tek bir karakteri** okur.
- `getline(cin, metin)`: Satır sonuna (`\n`) kadar olan tüm cümleyi boşluklarıyla birlikte okur.
- `cin.peek()`: Akıştaki sıradaki karakteri akıştan **tüketmeden (çekmeden)** önizler/inceler.
- `cin.putback(ch)`: Okunmuş olan bir karakteri tekrar akış tamponunun başına geri bırakır.

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Bir karakter giriniz: ";
    char ch = cin.peek(); // Sıradaki karaktere sadece bakıyoruz, akıştan silinmiyor

    if (isdigit(ch)) {
        int sayi;
        cin >> sayi;
        cout << "Bir sayi okundu: " << sayi << endl;
    } else {
        string kelime;
        cin >> kelime;
        cout << "Bir metin okundu: " << kelime << endl;
    }
    return 0;
}
```

---

## 2. Girdi Hata Yönetimi ve Tampon Temizliği (cin.clear ve cin.ignore)

İlgili kaynak dosyalar: [3_cin-ignore.cpp](3_cin-ignore.cpp), [7_cin-clear.cpp](7_cin-clear.cpp)

### 1. `cin >>` Sonrası `getline()` Tuzağı
Kullanıcı `cin >> sayi;` ile sayı girdikten sonra Enter'a bastığında, sayı okunur fakat Enter tuşunun oluşturduğu `\n` karakteri girdi tamponunda (*buffer*) kalır. Hemen ardından çağrılan `getline()`, tamponda bekleyen bu `\n` karakterini okuyarak boş geçer.
**Çözüm:** Tamponu temizlemek için `cin.ignore()` kullanılır:
```cpp
cin >> sayi;
cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Tamponu satır sonuna kadar temizle
getline(cin, isim);
```

### 2. Girdi Hata Durumu (cin.clear ve failbit)
Kullanıcıdan tamsayı beklenirken harf girilirse `cin` nesnesinin hata bayrağı (`failbit`) aktifleşir ve sonraki tüm okumalar kilitlenir.
```cpp
#include <iostream>
#include <limits>
using namespace std;

int main() {
    int sayi;
    while (true) {
        cout << "Pozitif bir tamsayi giriniz: ";
        if (cin >> sayi) {
            break; // Girdi başarıyla okundu
        } else {
            cout << "Hatalı girdi! Sayı girmelisiniz.\n";
            cin.clear(); // 1. Hata bayrağını sıfırla
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 2. Hatalı girdiyi tampondan temizle
        }
    }
    cout << "Girilen sayı: " << sayi << endl;
    return 0;
}
```

---

## 3. Biçimlendirilmiş Çıktı Yönetimi (cout ve iomanip)

İlgili kaynak dosyalar: [8_cout-setprecision.cpp](8_cout-setprecision.cpp), [9_cout-unsetf.cpp](9_cout-unsetf.cpp), [a_cout-showpoint.cpp](a_cout-showpoint.cpp), [b_cout-setw.cpp](b_cout-setw.cpp), [c_cout-left-right.cpp](c_cout-left-right.cpp), [d_cout-fill.cpp](d_cout-fill.cpp)

Verilerin profesyonel ve düzenli bir tablo halinde ekrana yazdırılması için `<iomanip>` manipülatörleri kullanılır:

| Manipülatör / Fonksiyon | Görevi ve Açıklaması |
| :--- | :--- |
| `setw(n)` | Çıktı alanının genişliğini $n$ karakter olarak ayarlar (yalnızca takip eden ilk veri için geçerlidir). |
| `setprecision(n)` | Ondalıklı sayılarda gösterilecek basamak sayısını belirler. |
| `fixed` | `setprecision` ile birlikte kullanıldığında virgülden sonraki basamak sayısını sabitler. |
| `scientific` | Sayıları bilimsel üslü gösterimde ($1.23e+02$) yazar. |
| `left` / `right` | Metin veya sayıları alan içerisinde sola veya sağa yaslar. |
| `setfill(ch)` | `setw` ile belirlenen boşluk alanlarını belirtilen karakterle doldurur (örn: `0` veya `*`). |
| `showpoint` | Ondalık kısmı sıfır olsa dahi ondalık noktasını ve sıfırları zorla gösterir. |

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << left << setw(15) << "Urun Adi" 
         << right << setw(10) << "Adet" 
         << setw(12) << "Birim Fiyat" << endl;
    cout << string(37, '-') << endl;

    cout << left << setw(15) << "Defter" 
         << right << setw(10) << 5 
         << setw(12) << fixed << setprecision(2) << 45.50 << " TL" << endl;

    cout << left << setw(15) << "Kursun Kalem" 
         << right << setw(10) << 12 
         << setw(12) << fixed << setprecision(2) << 8.25 << " TL" << endl;

    return 0;
}
```

---

## 4. Dosya İşlemlerine Giriş (ifstream, ofstream, fstream)

İlgili kaynak dosyalar: [e_file-open.cpp](e_file-open.cpp), [f_file-read.cpp](f_file-read.cpp)

C++ dilinde dosya işlemleri `<fstream>` başlık dosyası altındaki sınıflarla yapılır:
- `std::ifstream`: Dosyadan okuma yapmak için (*input file stream*).
- `std::ofstream`: Dosyaya yazma yapmak için (*output file stream*).
- `std::fstream`: Hem okuma hem yazma yapabilen akış.

```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // 1. Dosyaya Yazma (ofstream)
    ofstream dosyaYaz("veriler.txt");
    if (!dosyaYaz.is_open()) {
        cerr << "Dosya oluşturulamadı!\n";
        return 1;
    }
    dosyaYaz << "KTÜ Bilgisayar Mühendisliği\n";
    dosyaYaz << "Nesne Yönelimli Programlama\n";
    dosyaYaz << 2026 << endl;
    dosyaYaz.close(); // Dosyayı kapat

    // 2. Dosyadan Okuma (ifstream)
    ifstream dosyaOku("veriler.txt");
    if (!dosyaOku.is_open()) {
        cerr << "Dosya okuma için açılamadı!\n";
        return 1;
    }

    string satir;
    cout << "--- Dosya İçeriği ---\n";
    while (getline(dosyaOku, satir)) {
        cout << satir << endl;
    }
    dosyaOku.close();

    return 0;
}
```

---

## 5. Dosya Açma Modları (ios::app, ios::binary, ios::ate vb.)

İlgili kaynak dosya: [g_ostream-modes.cpp](g_ostream-modes.cpp)

Dosyalar açılırken ikinci parametre olarak açılış modları belirtilebilir:

| Açılış Modu | Anlamı ve Davranışı |
| :--- | :--- |
| `ios::in` | Dosyayı salt okunur olarak açar (`ifstream` varsayılanı). |
| `ios::out` | Dosyayı yazmak için açar; mevcut içeriği tamamen siler (`ofstream` varsayılanı). |
| `ios::app` | Ekleme modu (*append*). Mevcut içeriği silmez, her yeni yazılanı dosyanın sonuna ekler. |
| `ios::trunc` | Dosya zaten varsa içeriğini kırpar/sıfırlar (*truncate*). |
| `ios::binary` | Dosyayı metin olarak değil, ikili (*raw binary*) veri olarak açar. |
| `ios::ate` | Dosyayı açar açmaz imleci dosya sonuna (*at the end*) konumlandırır. |

*Örnek Kullanım (Üzerine yazmadan ekleme yapma):*
```cpp
ofstream logDosyasi("log.txt", ios::out | ios::app);
logDosyasi << "Sistem baslatildi: " << __DATE__ << endl;
```

---

## 6. Rastgele Erişimli Dosyalar (seekg, seekp, tellg, tellp)

İlgili kaynak dosya: [h_random-access-files.cpp](h_random-access-files.cpp)

Büyük dosyalarda sırayla satır satır okumak yerine dosyanın istenen baytına doğrudan atlamak mümkündür:

- **Konumlandırıcılar (Seek):**
  - `seekg(offset, yon)`: Okuma imlecini taşır (*seek get*).
  - `seekp(offset, yon)`: Yazma imlecini taşır (*seek put*).
- **Yön Bayrakları:**
  - `ios::beg`: Dosya başlangıcına göre.
  - `ios::cur`: Mevcut imleç konumuna göre.
  - `ios::end`: Dosya sonuna göre (genellikle negatif ofset ile geriye doğru).
- **Konum Öğrenme (Tell):**
  - `tellg()`: Okuma imlecinin o anki bayt konumunu döndürür.
  - `tellp()`: Yazma imlecinin o anki bayt konumunu döndürür.

```cpp
#include <iostream>
#include <fstream>
using namespace std;

// Dosya boyutunu hızlıca bayt cinsinden öğrenme
long long dosyaBoyutuBul(const string& dosyaAdi) {
    ifstream dosya(dosyaAdi, ios::binary | ios::ate);
    if (!dosya) return -1;
    return dosya.tellg(); // İmleç sonda olduğu için konumu doğrudan boyuttur
}
```

---

## 7. Örnek Uygulama: Öğrenci Not Dosyası Analizi

İlgili kaynak örnekler: [samples/grades.cpp](samples/grades.cpp), [samples/grades2.cpp](samples/grades2.cpp), [samples/grades3.cpp](samples/grades3.cpp), [samples/grades_input.txt](samples/grades_input.txt)

Bir metin dosyasında `Ad Soyad Vize Final` şeklinde tutulan verileri okuyup ağırlıklı ortalamayı hesaplayan ve harf notuyla birlikte formatlı bir rapor dosyasına yazdıran endüstriyel kalıp:

```cpp
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    ifstream giris("grades_input.txt");
    ofstream cikis("grades_report.txt");

    if (!giris || !cikis) {
        cerr << "Dosya okuma/yazma hatası!\n";
        return 1;
    }

    cikis << left << setw(20) << "Ogrenci Adi" 
          << right << setw(8) << "Vize" 
          << setw(8) << "Final" 
          << setw(10) << "Ortalama" 
          << setw(8) << "Sonuc" << endl;
    cikis << string(54, '=') << endl;

    string ad, soyad;
    double vize, finalNotu;

    while (giris >> ad >> soyad >> vize >> finalNotu) {
        double ortalama = (vize * 0.4) + (finalNotu * 0.6);
        string sonuc = (ortalama >= 50.0) ? "GECTI" : "KALDI";

        cikis << left << setw(20) << (ad + " " + soyad)
              << right << setw(8) << vize
              << setw(8) << finalNotu
              << setw(10) << fixed << setprecision(2) << ortalama
              << setw(8) << sonuc << endl;
    }

    cout << "Rapor başarıyla 'grades_report.txt' dosyasına yazıldı.\n";
    return 0;
}
```

---

## 8. Ekstra: stringstream (Hafıza İçi Akışlar) ve İkili (Binary) Dosya I/O

### 1. `std::stringstream` ile Metin Parçalama (`<sstream>`)
Konsol veya dosyadan okunan bir satırdaki farklı tiplerdeki verileri bellek içinde ayrıştırmak için kullanılır:
```cpp
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

int main() {
    string veri = "Ahmet 101 88.5";
    stringstream ss(veri);

    string isim;
    int no;
    double notu;
    ss >> isim >> no >> notu; // Otomatik tip dönüşümü

    cout << isim << " (No: " << no << ") -> Not: " << notu << endl;
    return 0;
}
```

### 2. İkili (Binary) Dosya Okuma/Yazma
Metin dosyalarında sayılar karakter dizisi olarak saklanırken, ikili dosyalarda doğrudan bellekteki ham bayt haliyle yazılır (`write` ve `read`):
```cpp
struct Kayit {
    int id;
    double bakiye;
};

// Yazma:
Kayit k1 = {105, 1250.75};
ofstream out("veri.bin", ios::binary);
out.write(reinterpret_cast<const char*>(&k1), sizeof(Kayit));
out.close();

// Okuma:
Kayit k2;
ifstream in("veri.bin", ios::binary);
in.read(reinterpret_cast<char*>(&k2), sizeof(Kayit));
in.close();
```

---

## 9. Pekiştirme Alıştırmaları (Çözümlü Sorular)

### Soru 1: Dosyadaki Kelime, Karakter ve Satır Sayısını Bulan Program (wc Fonksiyonu)
Verilen bir metin dosyasını açıp içindeki toplam satır, kelime ve karakter sayısını hesaplayan fonksiyonu yazınız.

**Çözüm:**
```cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void dosyaIstatistik(const string& dosyaAdi) {
    ifstream dosya(dosyaAdi);
    if (!dosya) {
        cerr << "Dosya bulunamadı!\n";
        return;
    }

    int satirSayisi = 0;
    int kelimeSayisi = 0;
    int karakterSayisi = 0;
    string satir, kelime;

    while (getline(dosya, satir)) {
        satirSayisi++;
        karakterSayisi += satir.length() + 1; // +1 yeni satır karakteri için

        stringstream ss(satir);
        while (ss >> kelime) {
            kelimeSayisi++;
        }
    }

    cout << "Satır Sayısı   : " << satirSayisi << endl;
    cout << "Kelime Sayısı  : " << kelimeSayisi << endl;
    cout << "Karakter Sayısı: " << karakterSayisi << endl;
}
```

---

### Soru 2: Çıktı Analizi (Manipülatör Etkisi)
Aşağıdaki kod parçasının ekrana ne basacağını belirleyiniz:
```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << setfill('#') << setw(8) << 42 << endl;
    cout << setw(8) << 42 << endl;
    cout << 42 << endl;
    return 0;
}
```
**Çözüm:**
- `setfill('#')` kalıcı bir ayardır; değiştirilene kadar yürürlükte kalır.
- `setw(8)` geçici bir ayardır; sadece kendisinden sonraki ilk veri basımında geçerlidir.
- 1. Satır: `######42`
- 2. Satır: `######42` (setw yeniden uygulandı, dolgu hala `#`)
- 3. Satır: `42` (`setw` bitti, varsayılan genişlikte yazıldı).

---

## 10. Öğrenciler İçin Ev Ödevleri

### Ödev 1: CSV Dosyası Ayrıştırıcı ve Filtreleyici
- **Görev:** `ogrenciler.csv` dosyasında virgülle ayrılmış veriler bulunmaktadır (`No,Ad,Soyad,Bolum,GNO`). Dosyadaki satırları okuyan, GNO'su (Genel Not Ortalaması) 3.00 ve üzerinde olan öğrencileri filtreleyerek `onur_listesi.txt` dosyasına düzgün hizalanmış bir tablo halinde yazdıran programı kodlayınız.

### Ödev 2: Güvenli Şifreli Not Defteri
- **Görev:** Kullanıcının girdiği metinleri basit bir XOR şifreleme algoritması (örn: kullanıcıdan alınan tek baytlık bir şifre anahtarı ile her karakteri `ch ^ key` yaparak) ikili bir dosyaya kaydeden; istendiğinde aynı anahtarla dosyayı okuyup deşifre eden bir konsol not defteri uygulaması yazınız.

### Ödev 3: Banka Hesap Yönetim Sistemi (Rastgele Erişimli Dosya)
- **Görev:** `Hesap` yapısına (`int hesapNo`, `char ad[30]`, `double bakiye`) sahip verileri ikili bir dosyada saklayınız. Kullanıcı hesap numarasını girdiğinde, dosyayı baştan sona taramadan doğrudan hesap numarasına denk gelen bayt konumuna `seekg` / `seekp` ile atlayarak bakiye sorgulayan ve para yatırma/çekme işlemi yapan programı yazınız.
