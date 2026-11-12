# Linux Komutları, C++ Derleme Süreçleri ve Makefile Kılavuzu

Bu belge, KTÜ Bilgisayar Mühendisliği öğrencileri ve yazılım geliştiriciler için Linux işletim sisteminde temel terminal komutlarını, `gcc`, `g++` ve `clang++` derleyicileri ile C/C++ programlarının derlenmesini, derleyici bayraklarını (*compiler flags*), derleme aşamalarını ve `Makefile` ile otomatik derleme mimarisini ayrıntılı ve uygulamalı örneklerle açıklamaktadır.

---

## 📑 İçindekiler
1. [Linux Dosya Sistemi Hiyerarşisi (FHS)](#1-linux-dosya-sistemi-hiyerarşisi-fhs)
2. [Temel Linux Terminal Komutları](#2-temel-linux-terminal-komutları)
   - [2.1. Donanım ve Sistem Bilgisi](#21-donanım-ve-sistem-bilgisi)
   - [2.2. Dizin Gezintisi (Navigation)](#22-dizin-gezintisi-navigation)
   - [2.3. Dosya ve Dizin Yönetimi](#23-dosya-ve-dizin-yönetimi)
   - [2.4. Dosya İçeriği İnceleme ve Metin İşleme](#24-dosya-içeriği-inceleme-ve-metin-işleme)
   - [2.5. Dosya ve Metin Arama (grep & find)](#25-dosya-ve-metin-arama-grep--find)
   - [2.6. Giriş/Çıkış Yönlendirmeleri ve Boru Hattı (Redirection & Pipes)](#26-girişçıkış-yönlendirmeleri-ve-boru-hattı-redirection--pipes)
   - [2.7. Kullanıcı, Grup ve Dosya İzinleri (chmod & chown)](#27-kullanıcı-grup-ve-dosya-izinleri-chmod--chown)
   - [2.8. Dosya Sıkıştırma ve Arşivleme (tar & gzip)](#28-dosya-sıkıştırma-ve-arşivleme-tar--gzip)
   - [2.9. Ağ ve Güvenli Dosya Transferi (scp & rsync)](#29-ağ-ve-güvenli-dosya-transferi-scp--rsync)
   - [2.10. Paket Yöneticileri (apt, dnf, yum)](#210-paket-yöneticileri-apt-dnf-yum)
3. [Linux'ta C ve C++ Programlarını Derleme ve Çalıştırma](#3-linuxta-c-ve-c-programlarını-derleme-ve-çalıştırma)
   - [3.1. Kurulu Derleyiciler: GCC, G++ ve Clang++](#31-kurulu-derleyiciler-gcc-g-ve-clang)
   - [3.2. İlk Programı Derleme ve Çalıştırma](#32-ilk-programı-derleme-ve-çalıştırma)
   - [3.3. Çok Dosyalı (Multi-file) Projeleri Derleme](#33-çok-dosyalı-multi-file-projeleri-derleme)
4. [C++ Derleyici Bayrakları (Compiler Flags Rehberi)](#4-c-derleyici-bayrakları-compiler-flags-rehberi)
   - [4.1. C++ Dil Standartları](#41-c-dil-standartları)
   - [4.2. Uyarı ve Kod Kalitesi Bayrakları (-Wall, -Wextra)](#42-uyarı-ve-kod-kalitesi-bayrakları--wall--wextra)
   - [4.3. Optimizasyon Seviyeleri (-O0, -O2, -O3)](#43-optimizasyon-seviyeleri--o0--o2--o3)
   - [4.4. Hata Ayıklama Sembolleri (-g / GDB)](#44-hata-ayıklama-sembolleri--g--gdb)
   - [4.5. Bellek ve Çalışma Zamanı Denetleyicileri (Sanitizers)](#45-bellek-ve-çalışma-zamanı-denetleyicileri-sanitizers)
   - [4.6. Kütüphane ve Başlık Yolları (-I, -L, -l)](#46-kütüphane-ve-başlık-yolları--i--l--l)
5. [C++ Derleme Sürecinin 4 Temel Aşaması](#5-c-derleme-sürecinin-4-temel-aşaması)
6. [Otomatik Proje Yönetimi: Make ve Makefile Mimarisi](#6-otomatik-proje-yönetimi-make-ve-makefile-mimarisi)
   - [6.1. Make Nedir ve Neden Kullanılır?](#61-make-nedir-ve-neden-kullanılır)
   - [6.2. Makefile Temel Sözdizimi ve Tab Kuralı](#62-makefile-temel-sözdizimi-ve-tab-kuralı)
   - [6.3. Değişkenler ve Otomatik Değişkenler ($@, $<, $^)](#63-değişkenler-ve-otomatik-değişkenler---)
   - [6.4. Sahte Hedefler (.PHONY)](#64-sahte-hedefler-phony)
   - [6.5. Basit Makefile Örneği](#65-basit-makefile-örneği)
   - [6.6. Profesyonel Modüler C++ Makefile Şablonu (G++ / Clang++ Seçimli)](#66-profesyonel-modüler-c-makefile-şablonu-g--clang-seçimli)
7. [Terminalde Üretkenlik: Kısayollar ve Süreç Yönetimi](#7-terminalde-üretkenlik-kısayollar-ve-süreç-yönetimi)

---

## 1. Linux Dosya Sistemi Hiyerarşisi (FHS)

Windows'taki sürücü harfleri (`C:\`, `D:\`) yerine Linux tek bir kök dizinle (`/`) başlar ve tüm depolama birimleri bu ağaca bağlanır (*mount*):

| Dizin | Açıklama |
| :--- | :--- |
| `/` | **Kök Dizin (Root):** Tüm dosya sisteminin başladığı tepe noktasıdır. |
| `/home/<kullanıcı>` | **Kullanıcı Ev Dizini:** Kişisel dosyaların, kodların ve projelerin tutulduğu alan (`~` ile gösterilir). |
| `/bin` ve `/usr/bin` | **Çalıştırılabilir Programlar:** `ls`, `g++`, `make`, `cat` gibi tüm sistem ve kullanıcı komutları. |
| `/etc` | **Sistem Yapılandırma Dosyaları:** Sistem ve servislerin ayar metin dosyaları. |
| `/tmp` | **Geçici Dosyalar:** Yeniden başlatmada temizlenen geçici çalışma alanı. |
| `/var` | **Değişken Veriler:** Log dosyaları (`/var/log`), veritabanları, paket önbellekleri. |
| `/dev` | **Cihaz Dosyaları:** Sabit diskler, terminaller, klavye vb. donanım düğümleri (`/dev/sda`, `/dev/null`). |
| `/proc` ve `/sys` | **Sanal Dosya Sistemleri:** Çekirdeğin (*kernel*) anlık durumunu ve donanım bilgilerini sunan sanal arayüz. |

---

## 2. Temel Linux Terminal Komutları

### 2.1. Donanım ve Sistem Bilgisi

Sistemin donanım kaynaklarını, işlemci çekirdeklerini ve bellek durumunu analiz etmek için kullanılır:

```bash
# Çekirdek ve işletim sistemi mimarisi hakkında genel bilgi alma
uname -a

# İşlemci (CPU) modelini, çekirdek sayısını ve frekansını listeleme
cat /proc/cpuinfo

# Bellek (RAM ve Swap) kullanımını insan tarafından okunabilir (GB/MB) formatta görme
free -h

# Disk bölümleri, boş/dolu alan oranları
df -h

# Bulunulan dizinin kapladığı disk alanını hesaplama (summary)
du -sh .

# Tüm donanım konfigürasyonunu detaylı listeleme (root yetkisi gerektirebilir)
sudo lshw -short

# USB cihazlarını hiyerarşik ağaç yapısında listeleme
lsusb -tv

# PCI veri yoluna bağlı donanımları (Ekran kartı, ağ kartı) listeleme
lspci
```

---

### 2.2. Dizin Gezintisi (Navigation)

```bash
# Bulunulan dizinin tam yolunu (Absolute Path) ekrana basar
pwd
# Çıktı örneği: /home/ogrenci/cpp_projeleri

# Belirtilen dizine geçiş yapma
cd 100_cpp_basics

# Bir üst dizine çıkma (Parent Directory)
cd ..

# İki üst dizine çıkma
cd ../..

# Doğrudan kullanıcının ev dizinine (~ veya /home/kullanici) gitme
cd
# veya
cd ~

# Bir önceki çalışılan dizine geri dönme (Toggle)
cd -
```

---

### 2.3. Dosya ve Dizin Yönetimi

```bash
# Bulunulan dizindeki dosya ve klasörleri listeleme
ls

# Detaylı liste (İzinler, sahip, boyut, değiştirilme tarihi)
ls -l

# Gizli dosyalar (. ile başlayanlar) dahil tüm dosyaları listeleme
ls -la

# Dosyaları boyutlarına göre büyükten küçüğe sıralayarak listeleme
ls -lhS

# Yeni bir dizin oluşturma
mkdir proje1

# İç içe dizinleri tek seferde oluşturma (-p: parents)
mkdir -p proje/src/include

# Yeni boş dosya oluşturma veya mevcut dosyanın erişim tarihini güncelleme
touch main.cpp

# Dosya kopyalama: cp <kaynak> <hedef>
cp main.cpp main_yedek.cpp

# Dizin kopyalama (-r: recursive, alt klasörleriyle birlikte)
cp -r src/ src_yedek/

# Dosya veya dizin taşıma ya da yeniden adlandırma (Rename)
mv main_yedek.cpp main_v2.cpp
mv main_v2.cpp ../yedekler/

# Dosya silme
rm test.o

# Birden çok dosyayı uzantısına göre silme (Joker karakter: *)
rm *.o *.exe

# Dizini içindekilerle birlikte soru sormadan zorla silme (-r: recursive, -f: force)
rm -rf eski_proje/

# Sembolik Bağlantı (Soft Link / Kısayol) oluşturma: ln -s <hedef> <link_adi>
ln -s /usr/bin/g++-12 ./my_compiler

# Dosyayı güvenli bir şekilde sıfırlarla ezerek kalıcı silme (Kurtarılamaz)
shred -u hassas_veri.txt
```

> [!CAUTION]
> `rm -rf` komutu geri dönüşüm kutusuna taşımaz, doğrudan siler. Yanlışlıkla `rm -rf /` veya `rm -rf *` çalıştırmamak için komutları dikkatli yazınız!

---

### 2.4. Dosya İçeriği İnceleme ve Metin İşleme

```bash
# Dosya içeriğinin tamamını terminale basma
cat main.cpp

# Dosya satır numaralarıyla birlikte görüntüleme
cat -n main.cpp

# Büyük dosyaları sayfa sayfa okuma (Çıkış için 'q' tuşuna basılır)
less main.cpp
# (more komutu da benzerdir ancak less yukarı/aşağı kaydırmayı destekler)

# Dosyanın ilk 10 satırını görüntüleme
head main.cpp
head -n 25 main.cpp  # İlk 25 satır

# Dosyanın son 10 satırını görüntüleme
tail main.cpp

# Log dosyalarını canlı izleme (-f: follow, yeni satır geldikçe anlık yazar)
tail -f derleme.log

# Dosyadaki satır, kelime ve bayt sayısını hesaplama (word count)
wc main.cpp
wc -l main.cpp  # Yalnızca satır sayısı

# İki dosya arasındaki farkları satır satır karşılaştırma
diff dosya1.cpp dosya2.cpp
# Yan yana (Side-by-side) karşılaştırma
diff -y dosya1.cpp dosya2.cpp

# Metin dosyasının belirli bir sütununu ayırma (Delimiter tabanlı kesme)
cut -d':' -f1 /etc/passwd  # Sistemdeki kullanıcı adlarını listeler

# Dosya içeriğini alfabetik sıralama
sort isimler.txt

# Birbirini tekrar eden ardışık satırları tekilleştirme (sort ile borulanır)
sort isimler.txt | uniq
```

---

### 2.5. Dosya ve Metin Arama (grep & find)

C++ projelerinde belirli bir fonksiyonu, sınıfı veya dosyayı ararken en çok kullanılan iki komuttur:

```bash
# 1. GREP: Dosya içinde metin deseni arama
# "cout" geçen satırları main.cpp içinde bul
grep "cout" main.cpp

# Büyük/küçük harf duyarsız arama (-i: ignore-case)
grep -i "class" main.cpp

# Alt dizinler dahil tüm dosyalarda satır numarasıyla arama (-r: recursive, -n: line number)
grep -rn "virtual void" src/

# Yalnızca eşleşen satırların sayısını öğrenme (-c: count)
grep -c "include" main.cpp

# 2. FIND: Dosya sistemi üzerinde isim, tip veya boyuta göre arama
# Bulunulan dizinde sonu .cpp ile biten tüm dosyaları listele
find . -name "*.cpp"

# Büyük/küçük harf duyarsız dosya adı arama (-iname)
find . -iname "readme.md"

# Yalnızca dizinleri arama (-type d) veya dosyaları arama (-type f)
find . -type f -name "*.h"

# 10 MB'tan büyük dosyaları bulma
find . -type f -size +10M

# Bulunan dosyalar üzerinde toplu işlem yapma (Örn: Tüm .o dosyalarını sil)
find . -name "*.o" -exec rm -f {} +
```

---

### 2.6. Giriş/Çıkış Yönlendirmeleri ve Boru Hattı (Redirection & Pipes)

Linux'ta her sürecin standart 3 veri kanalı vardır:
- `0`: Standart Girdi (`stdin`)
- `1`: Standart Çıktı (`stdout`)
- `2`: Standart Hata (`stderr`)

```bash
# Standart çıktıyı (stdout) bir dosyaya yazma (Dosya varsa üzerine yazar / Overwrite)
./program > cikti.txt

# Standart çıktıyı dosyanın sonuna ekleme (Append)
./program >> cikti.txt

# Standart hata akışını (stderr) ayrı bir dosyaya yönlendirme
./program 2> hatalar.log

# Hem normal çıktıyı hem hata çıktısını aynı dosyaya yönlendirme
./program &> hersey.log

# Çıktıyı çöpe atma (Hiçbir yere yazma ve terminali kirletme)
./program > /dev/null 2>&1

# Dosyadan girdi alma (stdin yönlendirme)
./hesaplayici < sayilar.txt

# BORU HATTI (Pipe - |): Bir komutun çıktısını diğer komuta girdi yapma
# Derleyici uyarıları arasında sadece "warning" geçenleri sayfalara bölerek incele:
g++ -Wall main.cpp 2>&1 | grep "warning" | less

# TEE Komutu: Çıktıyı hem terminale basar hem de dosyaya kaydeder:
g++ main.cpp 2>&1 | tee derleme_raporu.txt
```

---

### 2.7. Kullanıcı, Grup ve Dosya İzinleri (chmod & chown)

Linux'ta dosya izinleri 3 gruba ayrılır: **Owner (Sahip - u)**, **Group (Grup - g)**, **Others (Diğerleri - o)**.  
İzinler: `r` (Read = 4), `w` (Write = 2), `x` (Execute = 1).

```
-rwxr-xr--  1  ogrenci  muhendislik  16384  Kas 12 10:00  app
 │──┬──┬──
 │  │  │  └── Diğerleri: Yalnızca okuma (r = 4)
 │  │  └───── Grup: Okuma ve Çalıştırma (r + x = 4 + 1 = 5)
 │  └──────── Sahip: Okuma, Yazma, Çalıştırma (r + w + x = 4 + 2 + 1 = 7)
 └─────────── Dosya tipi (-: normal dosya, d: dizin)
```

```bash
# Bir script veya ikili dosyaya çalıştırma yetkisi verme
chmod +x build.sh
# veya
chmod 755 app

# Dosyayı yalnızca sahibinin okuyup yazabileceği hale getirme (600)
chmod 600 id_rsa

# Dosyanın sahibini değiştirme (Root gerektirir)
sudo chown ahmet main.cpp

# Dosyanın hem sahibini hem grubunu değiştirme
sudo chown ahmet:ogrenciler main.cpp

# Geçici olarak root (yönetici) haklarıyla komut çalıştırma
sudo apt update

# Şu anki kullanıcı kimliği ve dahil olduğu gruplar
id

# Sistemde şu an oturum açmış kullanıcılar
who
w
```

---

### 2.8. Dosya Sıkıştırma ve Arşivleme (tar & gzip)

```bash
# 1. TAR İle Arşivleme (Sıkıştırmasız paketleme)
tar -cf proje.tar src/ include/ main.cpp

# 2. TAR + GZIP (En yaygın .tar.gz sıkıştırma formatı)
# -c: create, -z: gzip, -v: verbose (listele), -f: file
tar -czvf proje_kaynak.tar.gz src/ Makefile

# .tar.gz arşivini bulunulan dizine açma
# -x: extract
tar -xzvf proje_kaynak.tar.gz

# Arşivi belirli bir hedef dizine açma (-C)
tar -xzvf proje_kaynak.tar.gz -C /opt/proje/

# Tek bir dosyayı gzip ile sıkıştırma (dosya.txt.gz olur)
gzip dosya.txt

# Sıkıştırılmış .gz dosyasını açma
gunzip dosya.txt.gz

# Standart .zip arşivleme ve açma
zip -r proje.zip src/
unzip proje.zip
```

---

### 2.9. Ağ ve Güvenli Dosya Transferi (scp & rsync)

```bash
# SSH ile uzak Linux sunucusuna bağlanma
ssh ogrenci@lab.ktu.edu.tr -p 22

# SCP ile yerel bilgisayardan uzak sunucuya dosya kopyalama
scp main.cpp ogrenci@lab.ktu.edu.tr:/home/ogrenci/odev/

# Uzak sunucudaki bir dosyayı yerel bilgisayara indirme
scp ogrenci@lab.ktu.edu.tr:/home/ogrenci/proje.tar.gz ./

# RSYNC: Akıllı senkronizasyon (Yalnızca değişen dosyaları aktarır, yarım kalırsa devam eder)
# -a: archive, -v: verbose, -z: compress
rsync -avz ./src/ ogrenci@lab.ktu.edu.tr:/home/ogrenci/proje/src/

# İnternetten dosya indirme (wget)
wget https://github.com/catchorg/Catch2/releases/download/v3.4.0/catch_amalgamated.hpp

# REST API veya Web sayfasına HTTP isteği atma (curl)
curl -s https://api.ipify.org
```

---

### 2.10. Paket Yöneticileri (apt, dnf, yum)

Linux dağıtımınıza göre geliştirme araçlarını (`build-essential`, `g++`, `clang`, `gdb`, `make`, `valgrind`, `cmake`) yüklemek için:

```bash
# Ubuntu / Debian / Linux Mint (APT)
sudo apt update
sudo apt install build-essential gdb valgrind cmake clang

# Fedora / Red Hat / Rocky Linux (DNF / YUM)
sudo dnf groupinstall "Development Tools"
sudo dnf install gcc-c++ clang gdb valgrind cmake

# Arch Linux / Manjaro (Pacman)
sudo pacman -S base-devel clang gdb valgrind cmake
```

---

## 3. Linux'ta C ve C++ Programlarını Derleme ve Çalıştırma

### 3.1. Kurulu Derleyiciler: GCC, G++ ve Clang++

Linux sisteminde genellikle iki ana derleyici ailesi kullanılır:
1. **GNU Compiler Collection (GCC):**
   - `gcc`: C kaynak kodlarını derler.
   - `g++`: C++ kaynak kodlarını derler ve standart C++ kütüphanelerini (`libstdc++`) otomatik olarak bağlar.
2. **LLVM / Clang Ailesi:**
   - `clang`: C kaynak kodlarını derler.
   - `clang++`: C++ kodlarını derler. Derleme hızı ve son derece anlaşılır hata/uyarı mesajları ile ünlüdür.

Her iki derleyicinin de komut satırı seçenekleri %98 oranında birebir aynıdır.

```bash
# Kurulu derleyici sürümlerini kontrol etme:
g++ --version
clang++ --version
gcc --version
```

---

### 3.2. İlk Programı Derleme ve Çalıştırma

Basit bir C++ kaynak dosyamız (`hello.cpp`) olduğunu varsayalım:

```cpp
#include <iostream>

int main() {
    std::cout << "Merhaba KTÜ C++!" << std::endl;
    return 0;
}
```

#### Adım Adım Derleme ve Çalıştırma:

```bash
# 1. Varsayılan adla derleme (a.out üretir):
g++ hello.cpp
./a.out

# 2. Çıktı dosyasının adını belirleyerek derleme (-o parametresi):
g++ hello.cpp -o hello_app

# 3. Clang++ ile aynı işlemi yapma:
clang++ hello.cpp -o hello_app

# 4. Derlenmiş programı çalıştırma:
# Linux'ta güvenlik gereği bulunulan dizin doğrudan PATH'te yer almaz, başına './' eklenmelidir!
./hello_app

# 5. Derleme ve başarılı olursa doğrudan çalıştırma (tek satırda bağlama):
g++ -std=c++17 -Wall hello.cpp -o hello_app && ./hello_app
```

---

### 3.3. Çok Dosyalı (Multi-file) Projeleri Derleme

Gerçek projelerde sınıflar ve fonksiyonlar başlıklara (`.h`) ve gövdelere (`.cpp`) bölünür:
- `math_utils.h` : Fonksiyon prototipleri
- `math_utils.cpp` : Fonksiyon gövdeleri
- `main.cpp` : `main()` fonksiyonu

#### Yöntem 1: Tek Satırda Birlikte Derleme
```bash
g++ -std=c++17 -Wall main.cpp math_utils.cpp -o my_project
./my_project
```
*(Dezavantaj: Bir dosyada 1 satır değişse bile tüm dosyalar sıfırdan derlenir).*

#### Yöntem 2: Nesne Dosyaları (.o) ile İki Aşamalı Derleme (Profesyonel Yaklaşım)
```bash
# 1. Aşama: Her kaynak dosyayı bağımsız nesne koduna (.o) derle (-c parametresi):
g++ -std=c++17 -Wall -c math_utils.cpp -o math_utils.o
g++ -std=c++17 -Wall -c main.cpp -o main.o

# 2. Aşama: Nesne dosyalarını bağlayarak çalıştırılabilir dosyayı üret (Linking):
g++ main.o math_utils.o -o my_project

# 3. Çalıştır:
./my_project
```
*(Avantaj: Sadece `main.cpp` değiştiğinde `math_utils.cpp` tekrar derlenmez, yalnızca `main.o` yeniden oluşturulur ve bağlanır).*

---

## 4. C++ Derleyici Bayrakları (Compiler Flags Rehberi)

Derleyiciye kodun nasıl çevrileceğini, hangi standartların kullanılacağını ve ne tür kontroller yapılacağını söyleyen parametrelerdir.

### 4.1. C++ Dil Standartları

Derleyicinin hangi C++ standardına göre sözdizimini yorumlayacağını belirler:

| Bayrak | Standart | Önemli Yenilikler |
| :--- | :--- | :--- |
| `-std=c++11` | C++11 | `auto`, `nullptr`, lambda fonksiyonları, r-value referansları, `constexpr` |
| `-std=c++14` | C++14 | Generic lambdalar, gevşetilmiş `constexpr`, ikili (binary) literaller |
| `-std=c++17` | C++17 | Structured binding, `std::optional`, `std::filesystem`, `if-init` |
| `-std=c++20` | C++20 | Concepts, Coroutines, Ranges, Spaceship operatörü (`<=>`), Modules |
| `-std=c++23` | C++23 | `std::print`, `std::expected`, multidimensional subscript (`mdspan`) |

```bash
g++ -std=c++17 main.cpp -o app
clang++ -std=c++20 main.cpp -o app
```

---

### 4.2. Uyarı ve Kod Kalitesi Bayrakları (-Wall, -Wextra)

Öğrencilerin ve profesyonel mühendislerin **her zaman** kullanması tavsiye edilen altın bayrak kombinasyonudur:

| Bayrak | Görevi |
| :--- | :--- |
| `-Wall` | En sık karşılaşılan tüm mantık ve sözdizimi uyarılarını açar (Kullanılmayan değişkenler, başlatılmamış bellek, hatalı tip dönüşümleri). |
| `-Wextra` | `-Wall` kapsamına girmeyen ekstra uyarıları açar (İşaretsiz/işaretli karşılaştırmaları, eksik switch case'leri). |
| `-Wpedantic` | ISO C++ standartlarına sıkı sıkıya uyulmasını şart koşar; derleyiciye özgü resmi olmayan eklentileri uyarır. |
| `-Wconversion` | Olası veri kaybına yol açabilecek örtük tip dönüşümlerinde (`double -> int`, `int -> char`) uyarır. |
| `-Wshadow` | Bir yerel değişken üst kapsamdaki bir değişkeni gölgelediğinde (*shadowing*) uyarır. |
| `-Werror` | **Tüm uyarıları derleme hatasına dönüştürür.** Kodunuzda 1 tane bile uyarı varsa derleme iptal edilir. Temiz kod yazma disiplini kazandırır. |

```bash
# Önerilen geliştirme bayrakları:
g++ -std=c++17 -Wall -Wextra -Wpedantic -Wshadow main.cpp -o app
```

---

### 4.3. Optimizasyon Seviyeleri (-O0, -O2, -O3)

Derleyicinin makine kodunu hız veya dosya boyutu açısından nasıl optimize edeceğini belirler:

| Bayrak | Açıklama | Kullanım Senaryosu |
| :--- | :--- | :--- |
| `-O0` | **Optimizasyon Yok:** Kod aynen yazıldığı gibi çevrilir. En hızlı derleme süresini sağlar. | Geliştirme ve Hata Ayıklama (Debug) aşaması. |
| `-O1` | **Temel Optimizasyon:** Kodu yavaşlatmadan temel basitleştirmeleri yapar. | Genel testler. |
| `-O2` | **Standart Üretim (Release) Optimizasyonu:** Kod boyutu ve hız arasında mükemmel denge kurar. Döngüleri ve fonksiyon çağrılarını optimize eder. | **Endüstri standardı**, sunucu ve son kullanıcı sürümleri. |
| `-O3` | **Agresif Optimizasyon:** Vektörizasyon (SIMD), fonksiyon içi genişletme (*inline*), döngü açma (*loop unrolling*) uygular. | Bilimsel hesaplamalar, grafik ve oyun motorları. |
| `-Os` | **Boyut Optimizasyonu:** İkili dosya boyutunu en aza indirmeye odaklanır. | Gömülü sistemler (Microcontroller, IoT). |

```bash
# Hızlı çalışan nihai release derlemesi:
g++ -std=c++17 -O2 -Wall main.cpp -o app_release
```

---

### 4.4. Hata Ayıklama Sembolleri (-g / GDB)

Bir program çöktüğünde (*Segmentation fault*) veya beklenmedik sonuç ürettiğinde, GDB (*GNU Debugger*) ile kaynak kodun hangi satırında hata olduğunu görebilmek için derleme aşamasına `-g` eklenmelidir:

```bash
# Hata ayıklama sembolleriyle derle:
g++ -std=c++17 -g -O0 main.cpp -o app_debug

# GDB ile hata ayıklamayı başlat:
gdb ./app_debug
```

*(GDB içinde: `run` başlatır, `break main` durma noktası koyar, `next` satır atlar, `print degisken` değer gösterir, `backtrace` çökme anındaki çağrı yığınını döker).*

---

### 4.5. Bellek ve Çalışma Zamanı Denetleyicileri (Sanitizers)

Modern GCC ve Clang derleyicileri, Valgrind kullanmaya gerek kalmadan kodun içine doğrudan bellek kontrol mekanizmaları gömebilir:

#### 1. AddressSanitizer (`-fsanitize=address` - ASan)
Dizi sınır aşımı (*Buffer Overflow*), bellek sızıntısı (*Memory Leak*), silinen belleği kullanma (*Use-After-Free*) gibi hataları anında yakalar ve satır numarasıyla terminale basar:

```bash
g++ -std=c++17 -fsanitize=address -g main.cpp -o app_sanitized
./app_sanitized
```

#### 2. UndefinedBehaviorSanitizer (`-fsanitize=undefined` - UBSan)
İşaretli tamsayı taşması (*Integer Overflow*), sıfıra bölme veya geçersiz gösterici dönüşümlerini tespit eder:

```bash
g++ -std=c++17 -fsanitize=undefined -g main.cpp -o app_ubsan
```

---

### 4.6. Kütüphane ve Başlık Yolları (-I, -L, -l)

Harici kütüphaneleri projeye dahil ederken:

```bash
# -I<dizin>: Başlık (.h / .hpp) dosyalarının aranacağı dizini ekler
g++ -I./include main.cpp -o app

# -L<dizin>: Derlenmiş kütüphane dosyalarının (.so / .a) aranacağı dizini ekler
# -l<ad>: Kütüphaneyi programa bağlar (libpthread.so için -lpthread)
g++ -I./include -L./lib main.cpp -lmatematik -lpthread -o app
```

---

## 5. C++ Derleme Sürecinin 4 Temel Aşaması

`g++ main.cpp -o program` yazdığımızda arka planda 4 farklı aşama işletilir. Bu aşamaları ayrı ayrı gözlemleyebiliriz:

```
[1. main.cpp] 
      │
      ▼  (Önişlemci - Preprocessor: #include, #define, #ifdef çözümlenir)
[2. main.ii]  ───▶  g++ -E main.cpp -o main.ii
      │
      ▼  (Derleyici - Compiler: C++ sözdizimi denetlenir, Assembly üretilir)
[3. main.s]   ───▶  g++ -S main.ii -o main.s
      │
      ▼  (Çevirici - Assembler: Assembly komutları ikili makine koduna çevrilir)
[4. main.o]   ───▶  g++ -c main.s -o main.o
      │
      ▼  (Bağlayıcı - Linker: Kütüphaneler ve nesne dosyaları birbirine bağlanır)
[5. program]  ───▶  g++ main.o -o program
```

1. **Önişleme (Preprocessing):** `#include <iostream>` satırı dosyanın içine kopyalanır, makrolar yerine konur, yorum satırları silinir (`main.ii`).
2. **Derleme (Compilation):** Yüksek seviyeli C++ kodu işlemcinin anlayacağı Assembly talimatlarına (`mov`, `add`, `call`) çevrilir (`main.s`).
3. **Çevirme (Assembly):** Assembly kodu ikili makine kodundan oluşan nesne dosyasına (`.o`) dönüştürülür (`main.o`).
4. **Bağlama (Linking):** Fonksiyon adresleri çözülür, C++ standart kütüphanesi (`libstdc++`) bağlanır ve işletim sisteminin çalıştırabileceği nihai ELF ikilisi (`program`) elde edilir.

---

## 6. Otomatik Proje Yönetimi: Make ve Makefile Mimarisi

### 6.1. Make Nedir ve Neden Kullanılır?

Onlarca veya yüzlerce `.cpp` dosyasından oluşan bir projede her seferinde uzun terminal komutları yazmak imkansızdır.  
**GNU Make**, bir projedeki dosyaların bağımlılıklarını inceler ve **yalnızca değiştirilmiş olan kaynak dosyaları yeniden derler (Incremental Build)**. Böylece 10 dakikalık bir derleme süresi 2 saniyeye inebilir.

---

### 6.2. Makefile Temel Sözdizimi ve Tab Kuralı

Bir `Makefile` kuralı 3 parçadan oluşur:

```makefile
hedef: bağımlılıklar
	çalıştırılacak_komut
```

> [!WARNING]
> **TAB Karakteri Kuralı:**  
> Komut satırının başında **MUTLAKA gerçek bir TAB karakteri** olmalıdır! Boşluk (space) kullanırsanız Make derleyicisi `*** missing separator. Stop.` hatası verir.

---

### 6.3. Değişkenler ve Otomatik Değişkenler

Makefile içinde tekrarı önlemek için değişkenler tanımlanır:
- `CXX` : Kullanılacak C++ derleyicisi (`g++` veya `clang++`).
- `CXXFLAGS` : Derleme bayrakları (`-std=c++17 -Wall -O2`).
- `LDFLAGS` : Bağlayıcı bayrakları (`-L... -l...`).

#### Sihirli Otomatik Değişkenler:
- `$@` : Kuralın **hedef adını** temsil eder.
- `$<` : Kuralın **ilk bağımlılığını** temsil eder (Genellikle kaynak `.cpp` dosyası).
- `$^` : Kuralın **tüm bağımlılıklarını** temsil eder (Genellikle tüm `.o` nesne dosyaları).

---

### 6.4. Sahte Hedefler (.PHONY)

Dizinde `clean` veya `all` adında gerçek bir dosya varsa Make kuralı çalıştırmayabilir. Bu çakışmayı engellemek için dosya üretmeyen hedefler `.PHONY` olarak bildirilir:

```makefile
.PHONY: all clean run
```

---

### 6.5. Basit Makefile Örneği

Proje dizininde `Makefile` adında bir dosya oluşturup içine şunları yazın:

```makefile
# Derleyici ve Bayraklar
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Hedef çalıştırılabilir dosya
TARGET = program

# Varsayılan hedef
all: $(TARGET)

$(TARGET): main.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o
```

**Kullanım:**
```bash
make        # program'ı derler
make run    # derler ve çalıştırır
make clean  # üretilen ikili dosyaları siler
```

---

### 6.6. Profesyonel Modüler C++ Makefile Şablonu (G++ / Clang++ Seçimli)

Modüler, `src/`, `include/` ve `build/` klasör ayrımına sahip, hem `g++` hem de `clang++` ile çalışabilen profesyonel bir Makefile şablonu:

```makefile
# ==============================================================================
# KTÜ Bilgisayar Mühendisliği - Modüler C++ Makefile Şablonu
# ==============================================================================

# Derleyici Seçimi: Varsayılan g++'tır. Komut satırından 'make CXX=clang++' ile değiştirilebilir!
CXX ?= g++

# Derleyici ve Bağlayıcı Bayrakları
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -O2 -Iinclude
DEBUGFLAGS = -std=c++17 -Wall -Wextra -g -O0 -fsanitize=address -Iinclude

# Dizinler
SRC_DIR = src
INC_DIR = include
OBJ_DIR = build
BIN_DIR = bin

# Hedef İkili Dosya Adı
TARGET = $(BIN_DIR)/app

# Kaynak ve Nesne Dosyaları
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# ------------------------------------------------------------------------------
# Hedefler
# ------------------------------------------------------------------------------

.PHONY: all debug run clean check_compiler

# Varsayılan Üretim (Release) Derlemesi
all: check_compiler $(TARGET)

# Hata Ayıklama (Debug) Derlemesi
debug: CXXFLAGS = $(DEBUGFLAGS)
debug: check_compiler $(TARGET)

# Çalıştırılabilir Dosyayı Bağlama (Linking)
$(TARGET): $(OBJS) | $(BIN_DIR)
	@echo "==> Baglaniyor: $@"
	$(CXX) $(CXXFLAGS) $^ -o $@

# Her bir .cpp dosyasını .o nesne dosyasına derleme (Compilation)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@echo "==> Derleniyor: $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Çıktı Dizinlerini Otomatik Oluşturma
$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

# Programı Çalıştırma
run: all
	@echo "==> Program Baslatiliyor..."
	@./$(TARGET)

# Hangi Derleyicinin Kullanıldığını Ekrana Yazdırma
check_compiler:
	@echo "----------------------------------------"
	@echo "Aktif Derleyici: $(CXX)"
	@$(CXX) --version | head -n 1
	@echo "----------------------------------------"

# Temizlik
clean:
	@echo "==> Ciktilar temizleniyor..."
	rm -rf $(OBJ_DIR) $(BIN_DIR)
```

#### Bu Makefile Nasıl Kullanılır?

```bash
# 1. Varsayılan G++ ile derleme:
make

# 2. Clang++ ile derleme (Derleyiciyi anında değiştirme gücü!):
make CXX=clang++

# 3. AddressSanitizer ve Debug sembolleriyle derleme:
make debug

# 4. Derleyip hemen çalıştırma:
make run

# 5. Temizlik yapma:
make clean
```

---

## 7. Terminalde Üretkenlik: Kısayollar ve Süreç Yönetimi

### 7.1. En Çok Kullanılan Bash Kısayolları

| Kısayol | Görevi |
| :--- | :--- |
| `Tab` | Dosya ve komut isimlerini otomatik tamamlar (*En önemli kısayoldur*). |
| `Ctrl + C` | Çalışan programı anında durdurur / sonlandırır (*SIGINT* sinyali). |
| `Ctrl + Z` | Çalışan programı arka plana atıp askıya alır (*Suspend*). |
| `Ctrl + R` | Terminal geçmişinde geriye dönük arama yapar (*Reverse Search*). |
| `Ctrl + L` | Ekranı temizler (`clear` komutuyla aynıdır). |
| `Ctrl + A` | İmleci satırın en başına götürür. |
| `Ctrl + E` | İmleci satırın en sonuna götürür. |
| `Ctrl + U` | İmleçten satır başına kadar olan kısmı siler. |
| `!!` | Az önce çalıştırılan son komutu tekrar yürütür (Örn: `sudo !!`). |

---

### 7.2. Süreç Yönetimi (Process Management)

```bash
# Sistemde çalışan tüm süreçleri listeleme
ps aux

# Belirli bir programın PID (Process ID) numarasını bulma
pgrep -l app
# veya
ps aux | grep "app"

# Canlı sistem kaynakları ve süreç yöneticisi
top
# veya gelişmiş renkli sürümü
htop

# Bir süreci PID ile sonlandırma
kill 12345

# Zorla öldürme (SIGKILL - 9 sinyali)
kill -9 12345

# İsme göre tüm süreç örneklerini öldürme
killall app

# Bir programı doğrudan arka planda başlatma (& eklenir)
./uzun_islem_yapan_program &

# Arka plandaki işleri listeleme
jobs

# Arka plandaki işi ön plana (terminale) alma
fg %1
```

---

### 7.3. Bashrc ve Kişisel Kısayollar (Alias)

Sık kullandığınız uzun komutlar için `~/.bashrc` dosyanızın sonuna takma adlar (*alias*) ekleyerek terminal hızınızı 10 katına çıkarabilirsiniz:

```bash
# ~/.bashrc dosyasını açıp en altına ekleyin:
alias cbuild='g++ -std=c++17 -Wall -Wextra -O2'
alias cdebug='g++ -std=c++17 -Wall -Wextra -g -O0 -fsanitize=address'
alias ll='ls -la --color=auto'
alias cls='clear'

# Yapılan değişiklikleri hemen geçerli kılmak için:
source ~/.bashrc
```

Artık terminalden sadece şu komutu yazarak modern C++ standartlarında derleme yapabilirsiniz:
```bash
cbuild main.cpp -o app && ./app
```
