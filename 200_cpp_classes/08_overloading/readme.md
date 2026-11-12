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
11. [Kodları Derleme ve Çalıştırma Rehberi (Komut Tablosu)](#11-kodları-derleme-ve-çalıştırma-rehberi-komut-tablosu)
12. [Pekiştirme Alıştırmaları (Çözümlü Sorular)](#12-pekiştirme-alıştırmaları-çözümlü-sorular)
13. [Öğrenciler İçin Ev Ödevleri](#13-öğrenciler-için-ev-ödevleri)

---

## 1. Fonksiyon Aşırı Yükleme (Function Overloading) ve İmza Kuralları

İlgili kaynak dosyalar: [function-overloading.cpp](function-overloading.cpp), [c-polymorphizm.c](c-polymorphizm.c)

Fonksiyon aşırı yükleme (*function overloading*), aynı etki alanı (*scope*) içerisinde **aynı isme sahip**, ancak **parametre listeleri birbirinden farklı** olan birden çok fonksiyon tanımlanabilmesidir. Bu mekanizma nesne yönelimli programlamada **Statik (Derleme Zamanı / Erken Bağlama) Çok Biçimlilik (Static / Compile-Time Polymorphism)** olarak adlandırılır.

### 1.1. C vs C++: Neden Aşırı Yüklemeye İhtiyaç Duyuldu?
- **C Dilinin Kısıtı:** C dilinde her fonksiyon adı sembol tablosunda benzersiz olmalıdır. Örneğin tamsayıları toplayan `int sum(int, int)` fonksiyonu varken ondalıklı sayılar için `float sum(float, float)` tanımlanamaz (Derleyici `redefinition of 'sum'` hatası verir). Bu nedenle standart C kütüphanesinde mutlak değer için `abs()`, `fabs()`, `labs()` gibi farklı tipler için ayrı isimler uydurulmuştur (Bkz: [c-polymorphizm.c](c-polymorphizm.c)).
- **C++ Çözümü:** C++ dili, çağıran kodun türlerine bakarak hangi fonksiyonun çağrılacağına **derleme anında** karar verir. Bu sayede geliştirici tek bir anlamlı isim (`topla`, `yazdir`, `alan`) kullanarak temiz ve tutarlı bir arayüz tasarlayabilir.

### 1.2. Fonksiyon İmzası (Function Signature) ve Kurallar

Derleyicinin iki fonksiyonu birbirinden ayırt etmek için kullandığı kimlik bilgisine **fonksiyon imzası (*signature*)** denir.

#### İmzaya Dahil Olan Öğeler (Ayırt Edici Özellikler):
1. **Fonksiyonun Adı:** İsmin aynı olması şarttır.
2. **Parametre Sayısı:** Örneğin `f(int)` ile `f(int, int)` farklı imzalardır.
3. **Parametre Veri Tipleri:** Örneğin `f(int)` ile `f(double)` farklı imzalardır.
4. **Parametrelerin Sıralaması:** Örneğin `f(int, double)` ile `f(double, int)` farklı imzalardır.
5. **Referans ve Gösterici Nitelikleri:** `f(int&)` ile `f(const int&)` veya `f(int*)` ile `f(const int*)` farklı imzalardır.
6. **Üye Fonksiyonlarda `const` Niteleyicisi:** Bir sınıfın üye metodunda `void display()` ile `void display() const` iki ayrı fonksiyondur (nesne sabit ise `const` olan çağrılır).

#### İmzaya Kesinlikle Dahil OLMAYANLAR (Aşırı Yükleme İçin Yetersiz Durumlar):
1. **Geri Dönüş Değeri (`Return Type`):**
   ```cpp
   int calculate(int x);
   double calculate(int x); // COMPILER ERROR! (call cannot be resolved by return type alone)
   ```
   > [!WARNING]
   > **Neden Dönüş Tipi İmzaya Dahil Değildir?**  
   > Çünkü C++'ta bir fonksiyon `calculate(10);` şeklinde dönüş değeri bir değişkene atanmadan (göz ardı edilerek) çağrılabilir. Bu durumda derleyici hangi fonksiyonun çalıştırılmak istendiğini asla bilemez!
2. **Parametre İsimleri:** Prototipteki `void draw(int width)` ile `void draw(int w)` tamamen aynıdır.
3. **Değer ile Aktarımda (`Pass-by-value`) `const` Niteleyicisi:**
   ```cpp
   void print(int x);
   void print(const int x); // COMPILER ERROR! (redefinition of 'void print(int)')
   ```
   Çünkü fonksiyon çağrılırken argüman zaten kopyalanır; çağıran taraf açısından parametrenin içeride sabit olması bir fark yaratmaz.
4. **Tür Takma Adları (`typedef` / `using`):**
   ```cpp
   typedef int Integer;
   void test(int x);
   void test(Integer x); // COMPILER ERROR! (Integer is not a distinct type, just an alias)
   ```

---

### 1.3. Arka Planda Ne Olur? Name Mangling (İsim Bozma / Süsleme) ve `extern "C"`

C++ derleyicisi, aşırı yüklenmiş fonksiyonları derlerken ve bağlarken (*linking*) her birine sembol tablosunda benzersiz bir isim atar. Bu işleme **Name Mangling (İsim Süsleme)** denir.

Örneğin GCC/Clang derleyicisinde:
- `void print(int)` $\rightarrow$ `_Z5printi`
- `void print(double)` $\rightarrow$ `_Z5printd`
- `void print(int, double)` $\rightarrow$ `_Z5printid`

```
[Kaynak Kod: print(5)] ─────▶ [Derleyici: Mangling] ─────▶ [_Z5printi(5) Makine Kodu]
```

#### C ile C++ Kodlarını Birlikte Kullanma (`extern "C"`):

C derleyicileri *name mangling* yapmaz; sembol tablosuna fonksiyonu doğrudan kaynak kodda yazılan adıyla (örneğin `c_add`) kaydeder. C++ derleyicisi ise aşırı yüklemeyi destekleyebilmek için fonksiyon isimlerini parametre tipleriyle süsler (örneğin `_Z5c_addii`).

Bu durum, C dilinde önceden yazılmış ve derlenmiş bir kütüphaneyi veya `.c` dosyasını C++ projesine dahil ettiğinizde kritik bir bağlayıcı (*linker*) sorununa yol açar. C++ derleyicisi süslenmiş bir sembol ararken, C nesne dosyasında (`.o`) yalın C ismi yer alır. Bu uyumsuzluğu çözmek ve C++ derleyicisine **"Bu fonksiyon için isim süsleme yapma, C standart bağlantı kurallarını kullan"** demek için `extern "C"` blokları kullanılır.

---

##### 🔍 Sembol Tablosu Karşılaştırması

| Dil & Derleyici | Kaynak Koddaki Tanım | Sembol Tablosundaki Adı (*Symbol Name*) |
| :--- | :--- | :--- |
| **C (`gcc`)** | `int c_add(int, int);` | `c_add` (Yalın, süslemesiz) |
| **C++ (`g++`)** (Standart) | `int c_add(int, int);` | `_Z5c_addii` (Süslenmiş / Mangled) |
| **C++ (`g++`)** (`extern "C"`) | `extern "C" int c_add(int, int);` | `c_add` (C ile tam uyumlu!) |

---

##### 💻 Örnek Senaryo: C Fonksiyonunu C++ İçerisinden Çağırma

###### 1. Adım: C Kaynak Dosyası (`c_calculator.c`)
C dilinde yazılmış basit bir matematik kütüphanesi:
```c
/* c_calculator.c - C source file */
#include <stdio.h>

int c_add(int a, int b) {
    printf("[C Code] c_add executed: %d + %d\n", a, b);
    return a + b;
}

int c_multiply(int a, int b) {
    printf("[C Code] c_multiply executed: %d * %d\n", a, b);
    return a * b;
}
```

###### 2. Adım: Hem C Hem C++ Uyumlu Başlık Dosyası (`c_calculator.h`)
> [!TIP]
> **Endüstri Standardı (`__cplusplus` Makrosu):**  
> `extern "C"` sözdizimi C diline ait değildir, C++'a özgüdür. Bu nedenle bir başlık dosyasının **hem saf C hem de C++ programları tarafından sorunsuz `#include` edilebilmesi** için `#ifdef __cplusplus` ön işlemci koşulu kullanılır. C++ derleyicisi `__cplusplus` makrosunu otomatik tanımlar; C derleyicisi ise bu satırları atlar.

```c
/* c_calculator.h - Common header compatible with C and C++ */
#ifndef C_CALCULATOR_H
#define C_CALCULATOR_H

#ifdef __cplusplus
extern "C" {
#endif

// Function prototypes linked using C conventions
int c_add(int a, int b);
int c_multiply(int a, int b);

#ifdef __cplusplus
}
#endif

#endif // C_CALCULATOR_H
```

###### 3. Adım: C++ Ana Programı (`main.cpp`)
C++ kodumuz hem kendi aşırı yüklenmiş fonksiyonlarını kullanır hem de C dilinde yazılmış kütüphaneyi sorunsuz çağırır:

```cpp
/* main.cpp - Modern C++ source code */
#include <iostream>
#include <string>
#include "c_calculator.h" // extern "C" protected header file

using namespace std;

// C++ overloaded functions:
double add(double a, double b) {
    cout << "[C++ Code] Overloaded add(double, double) executed\n";
    return a + b;
}

string add(const string& a, const string& b) {
    cout << "[C++ Code] Overloaded add(string, string) executed\n";
    return a + " " + b;
}

int main() {
    cout << "=== 1. Invoking Functions Written in C ===" << endl;
    // Calling C functions seamlessly from C++:
    int sumResult = c_add(15, 25);
    cout << "c_add Result: " << sumResult << "\n\n";

    int productResult = c_multiply(6, 7);
    cout << "c_multiply Result: " << productResult << "\n\n";

    cout << "=== 2. C++ Overloaded Functions ===" << endl;
    cout << "Floating Point Sum: " << add(3.14, 2.71) << "\n\n";
    cout << "String Concatenation: " << add(string("Computer"), string("Engineering")) << "\n";

    return 0;
}
```

---

##### ⚠️ `extern "C"` Kullanılmazsa Ne Olur? (Hata Analizi)

Eğer başlık dosyasında veya prototip bildiriminde `extern "C"` bloğunu kaldırır ve `main.cpp` dosyasını derlemeye çalışırsanız:

1. Derleme aşaması (*compilation*) sözdizimsel olarak geçer (`.o` oluşur).
2. Ancak **Bağlayıcı (Linker - `ld`)** aşamasında şu meşhur hata meydana gelir:

```text
undefined reference to `c_add(int, int)'
undefined reference to `c_multiply(int, int)'
collect2.exe: error: ld returned 1 exit status
```

**Hatanın Sebebi:**  
C++ derleyicisi `main.cpp` içinde `_Z5c_addii` sembolünü aramıştır; ancak `c_calculator.o` dosyası C derleyicisi (`gcc`) ile derlendiği için sembol tablosunda sadece `c_add` vardır. İsimler uyuşmadığı için bağlayıcı aradığı fonksiyonu bulamaz ve bağlantıyı koparır. `extern "C"` bu süslemeyi kapatarak iki dünyanın birbiriyle konuşmasını sağlar.

---

##### 🔨 Bu Kodları Terminalden Derleme ve Bağlama Adımları

C ve C++ dosyalarının birlikte derlenip tek bir çalıştırılabilir ikiliye dönüştürülmesi iki adımda gerçekleştirilir:

```bash
# Adım 1: C kaynak dosyasını gcc ile bağımsız nesne dosyasına (.o) derleyin:
gcc -c c_calculator.c -o c_calculator.o

# Adım 2: C++ ana programı ile C nesne dosyasını g++ ile birbirine bağlayın (Linking):
g++ main.cpp c_calculator.o -o program

# Adım 3: Çalıştırın:
./program          # Linux / macOS / Git Bash
.\program.exe      # Windows PowerShell / CMD
```

---

### 1.4. Aşırı Yükleme Çözümleme Aşamaları (Overload Resolution) ve Belirsizlik (Ambiguity)

Derleyici bir fonksiyon çağrısıyla karşılaştığında şu 3 adımı uygular:
1. **Aday Fonksiyonlar (Candidate Functions):** Çağrılan isimle aynı ada sahip ve o kapsamda görünür olan tüm fonksiyonlar listelenir.
2. **Uygun Fonksiyonlar (Viable Functions):** Parametre sayısı uyan ve gönderilen argümanların örtük dönüşümle (*implicit conversion*) atanabildiği fonksiyonlar seçilir.
3. **En İyi Eşleşme (Best Match):** Aşağıdaki öncelik sırasına göre en uygun olan seçilir:
   - **Seviye 1 (Tam Eşleşme - Exact Match):** Tip doğrudan uyuşuyor veya lvalue/rvalue / const niteliği tam oturuyor.
   - **Seviye 2 (Yükseltme - Type Promotion):** `char`, `short`, `bool` $\rightarrow$ `int`; `float` $\rightarrow$ `double`.
   - **Seviye 3 (Standart Dönüşüm - Standard Conversion):** `int` $\rightarrow$ `double`, `double` $\rightarrow$ `int`, `derived*` $\rightarrow$ `base*`.
   - **Seviye 4 (Kullanıcı Tanımlı Dönüşüm - User-Defined Conversion):** Sınıf kurucuları (`converting constructor`) veya dönüşüm operatörleri (`operator Type()`).

#### ⚠️ Kritik Derleme Hataları: Belirsiz Çağrı (Ambiguity)
Birden fazla uygun fonksiyon aynı eşleşme seviyesinde kaldığında derleyici seçim yapamaz ve `call of overloaded '...' is ambiguous` derleme hatası verir:

1. **Varsayılan Argüman (Default Argument) ile Çakışma:**
   ```cpp
   void calculate(int a);
   void calculate(int a, int b = 0);

   calculate(10); // ERROR! Compiler cannot resolve which overload is intended!
   ```
2. **Eşit Mesafeli Tip Dönüşümü:**
   ```cpp
   void display(long x);
   void display(double x);

   display(5); // ERROR! 5 is int. Both int->long and int->double have equal conversion rank!
   ```
3. **Değer ile Referans Geçişi Arasındaki Belirsizlik:**
   ```cpp
   void print(int x);
   void print(int& x);

   int number = 20;
   print(number); // ERROR! 'number' can be passed by value or bound to reference!
   ```

---

### 1.5. Kapsamlı Kod Örneği: Fonksiyon Aşırı Yükleme

```cpp
#include <iostream>
#include <string>

using namespace std;

// 1. Overloading based on fundamental types
void printValue(int value) {
    cout << "[int] Integer value: " << value << endl;
}

void printValue(double value) {
    cout << "[double] Floating point value: " << value << endl;
}

void printValue(const string& text) {
    cout << "[string] Text data: " << text << endl;
}

// 2. Overloading based on parameter count
void printValue(int val1, int val2) {
    cout << "[int, int] Two integers: " << val1 << " and " << val2 << endl;
}

// 3. Overloading based on parameter ordering
void listEmployee(const string& name, int id) {
    cout << "Employee: " << name << " (ID: " << id << ")" << endl;
}

void listEmployee(int id, const string& name) {
    cout << "ID: " << id << " -> Employee: " << name << endl;
}

// 4. Distinction between non-const reference and const reference
void updateValue(int& x) {
    x += 10;
    cout << "[int&] Modified via l-value reference: " << x << endl;
}

void updateValue(const int& x) {
    cout << "[const int&] Read-only or temporary (r-value) value: " << x << endl;
}

int main() {
    cout << "--- 1. Type-Based Overloading ---" << endl;
    printValue(42);                        // Calls [int]
    printValue(3.1415);                    // Calls [double]
    printValue(string("C++ Programming")); // Calls [string]

    cout << "\n--- 2. Parameter Count and Ordering ---" << endl;
    printValue(10, 20);                    // Calls [int, int]
    listEmployee("Alice", 101);
    listEmployee(102, "Bob");

    cout << "\n--- 3. Reference vs Const Reference ---" << endl;
    int a = 5;
    updateValue(a);                        // Variable passed: calls int& (a becomes 15)
    updateValue(100);                      // 100 is temporary r-value: calls const int&

    return 0;
}
```

---

## 2. this Göstericisi ve Metot Zincirleme (Method Chaining)

İlgili kaynak dosya: [this-pointer.cpp](this-pointer.cpp)

`this`, C++ dilinde bir sınıfın **statik olmayan herhangi bir üye fonksiyonu çağrıldığında**, o an o fonksiyonu yürüten nesnenin **bellekteki adresini tutan örtük (implicit) bir göstericidir (pointer)**.

---

### 2.1. `this` Göstericisinin Felsefesi ve Bellek Mimarisi

Bir `Clock` sınıfından 100 adet nesne ürettiğimizi varsayalım:
```cpp
Clock c1, c2, c3, ..., c100;
```
Bellekte ne olur?
- Her bir nesnenin üye değişkenleri (`hours`, `minutes`, `seconds`) bellekte (Stack veya Heap) **ayrı ayrı yer tutar** (100 farklı bellek bloğu).
- Ancak üye fonksiyonların makine kodları (`print()`, `setTime()`) belleğin **Kod Bölümünde (Code / Text Segment) SADECE TEK BİR KOPYA** olarak saklanır!

Peki, `c1.print()` ve `c2.print()` çağrıldığında çalışan aynı makine kodu, `c1`'in mi yoksa `c2`'nin mi değişkenlerini yazdıracağını nereden bilir?

#### Gizli Parametre Mekanizması:
Derleyici, siz farkında olmadan üye fonksiyon çağrılarını ve tanımlarını dönüştürür:

```cpp
// 1. Bizim yazdigimiz cagri:
myClock.setTime(14, 45, 15);

// 2. Derleyicinin arka planda urettigi gercek cagri:
Clock::setTime(&myClock, 14, 45, 15);
```

Fonksiyonun arka plandaki prototipi ise şöyledir:
```cpp
// Derleyici 'this' isaretcisini ilk parametre olarak gizlice ekler:
void Clock::setTime(Clock* const this, int hours, int minutes, int seconds) {
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
}
```

---

### 2.2. `this` Göstericisinin Türü ve Nitelikleri

1. **Sabit Bir İşaretçidir (`T* const this`):**
   `this` bir r-value ifadedir. `this` göstericisinin işaret ettiği adres fonksiyon içinde değiştirilemez:
   ```cpp
   this = &otherObject; // COMPILER ERROR! (l-value required as left operand of assignment)
   ```
2. **`const` Üye Fonksiyonlarda Durumu (`const T* const this`):**
   Bir üye fonksiyon `void print() const` şeklinde bildirildiğinde, `this` göstericisinin tipi `const Clock* const this` haline gelir. Bu sayede o fonksiyon içinde hiçbir üye değişkenin değeri değiştirilemez:
   ```cpp
   void Clock::print() const {
       // this->hours = 12; // COMPILER ERROR! Cannot modify member in const function
       cout << this->hours << ":" << this->minutes << endl; // Valid (read-only)
   }
   ```
3. **Neden `static` Üye Fonksiyonlarda `this` Göstericisi Yoktur?**
   `static` fonksiyonlar nesnelere değil, doğrudan sınıfın kendisine aittir (`Clock::getTotalClocks()`). Fonksiyon çağrılırken ortada bir nesne örneği veya nesne adresi bulunmaz. Bu nedenle:
   - `static` fonksiyonlar içinde `this` kullanılamaz.
   - `static` fonksiyonlar sınıfın statik olmayan üye değişkenlerine doğrudan erişemez.

---

### 2.3. `this` Göstericisinin 5 Temel Kullanım Alanı

| No | Kullanım Alanı | Açıklama | Tipik Örnek Kod |
| :---: | :--- | :--- | :--- |
| **1** | **İsim Gölgelemesini Önleme** (*Name Shadowing / Hiding*) | Parametre adı ile üye değişken adı aynı olduğunda karışıklığı giderir. | `this->hours = hours;` |
| **2** | **Metot Zincirleme** (*Method Chaining / Fluent Interface*) | Fonksiyondan nesnenin kendisini (`return *this;`) referans döndürerek ardışık çağrılar sağlar. | `c.setHours(10).setMinutes(30).print();` |
| **3** | **Kendine Atama Kontrolü** (*Self-Assignment Check*) | Atama operatöründe (`operator=`) nesnenin kendisine atanmasını (`a = a;`) denetler. | `if (this == &other) return *this;` |
| **4** | **Kendini Dışarı Parametre Geçme** | Nesnenin kendisini başka bir sınıfa veya fonksiyona argüman olarak iletmesini sağlar. | `logger.log(*this);` veya `log(this);` |
| **5** | **Nesne Kimliği Karşılaştırması** | İki referansın aynı bellek adresindeki nesneyi gösterip göstermediğini doğrular. | `bool isSame = (this == &otherObject);` |

---

### 2.4. Metot Zincirleme (Method Chaining): Neden Referans (`Clock&`) Dönülmelidir?

Metot zincirleme yaparken dönüş tipini `Clock` (değer ile) mi yoksa `Clock&` (referans ile) mi belirlediğiniz hayati önem taşır:

```cpp
// INCORRECT APPROACH: Returning by value (Clock)
Clock setHours(int h) {
    this->hours = h;
    return *this; // WARNING: Creates a temporary COPY of the object!
}

// CORRECT APPROACH: Returning by reference (Clock&)
Clock& setHours(int h) {
    this->hours = h;
    return *this; // Returns reference to the original object (No copy!)
}
```

> [!CAUTION]
> Eğer `Clock` (değer) dönerseniz; her zincirleme adımında yeni ve geçici bir kopya oluşturulur. Bir sonraki fonksiyon bu geçici kopya üzerinde çalışır ve zincir bittiğinde kopyalar bellekten silinir. Sonuç olarak asıl nesneniz güncellenmemiş olur! Bu yüzden zincirleme çağrılarda her zaman **referans (`Sinif&`)** döndürülmelidir.

---

### 2.5. Kapsamlı Kod Örneği: `this` Göstericisi ve Metot Zincirleme

```cpp
#include <iostream>
#include <iomanip>

using namespace std;

class Clock {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Constructor with default parameter values
    Clock(int hours = 0, int minutes = 0, int seconds = 0) {
        // Use case 1: Resolving name hiding when parameter names match member variables
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }

    // Use case 2: Method chaining returning *this reference (Fluent API)
    Clock& setHours(int hours) {
        this->hours = (hours >= 0 && hours < 24) ? hours : 0;
        return *this; // Returns reference to the current object
    }

    Clock& setMinutes(int minutes) {
        this->minutes = (minutes >= 0 && minutes < 60) ? minutes : 0;
        return *this;
    }

    Clock& setSeconds(int seconds) {
        this->seconds = (seconds >= 0 && seconds < 60) ? seconds : 0;
        return *this;
    }

    // Display memory address of the current object
    void printAddress() const {
        cout << "Memory address of this object (this): " << this << endl;
    }

    // const member function: type of this is 'const Clock* const this'
    void print() const {
        cout << setfill('0') << setw(2) << this->hours << ":"
             << setw(2) << this->minutes << ":"
             << setw(2) << this->seconds << endl;
    }

    // Use case 5: Checking object identity via memory address
    bool isSameObject(const Clock& other) const {
        return this == &other; // Returns true if both references point to the same instance
    }
};

int main() {
    cout << "=== 1. Inspecting Object Addresses via this Pointer ===" << endl;
    Clock clock1(9, 15, 30);
    Clock clock2(12, 0, 0);

    cout << "clock1: ";
    clock1.printAddress();
    cout << "clock1 address (&clock1): " << &clock1 << endl;

    cout << "clock2: ";
    clock2.printAddress();
    cout << "clock2 address (&clock2): " << &clock2 << endl;

    cout << "\n=== 2. Method Chaining with *this ===" << endl;
    cout << "clock1 before chaining: ";
    clock1.print();

    cout << "clock1 after cascading updates: ";
    // Method chaining call (Cascading)
    clock1.setHours(21).setMinutes(45).setSeconds(59).print();

    cout << "\n=== 3. Object Identity Comparison ===" << endl;
    Clock& clockRef = clock1;
    cout << "Are clock1 and clockRef the same object? " 
         << (clock1.isSameObject(clockRef) ? "YES (Same Address)" : "NO") << endl;
    cout << "Are clock1 and clock2 the same object? " 
         << (clock1.isSameObject(clock2) ? "YES (Same Address)" : "NO (Different Address)") << endl;

    return 0;
}
```

---

## 3. Operatör Aşırı Yüklemeye Giriş ve Temel Kurallar

İlgili kaynak dosya: [operator-overloading.cpp](operator-overloading.cpp)

Operatör aşırı yükleme, yerleşik operatörlerin (`+`, `-`, `==`, `<<` vb.) nesneler üzerinde doğal ve okunabilir bir şekilde çalışmasını sağlar (örn: `c1 + c2`).

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
> **Değişme Özelliği (Commutativity) Sorunu:** `c1 + 5.0` işlemi üye fonksiyon ile çözülebilir (`c1.operator+(5.0)`). Ancak `5.0 + c1` yazıldığında sol taraf `double` olduğu için üye metot çağrılamaz! Bu tür simetrik durumlarda **`friend` fonksiyon kullanılması zorunludur**.

---

## 5. İkili (Binary) ve Aritmetik Operatörlerin Aşırı Yüklenmesi (+, -, *)

İlgili kaynak dosya: [binary-operators.cpp](binary-operators.cpp)

Karmaşık sayı (*Complex Number*) sınıfı üzerinde `+` operatörünü inceleyelim:

```cpp
#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overload operator+ as a member function
    Complex operator+(const Complex& other) const {
        return Complex(this->real + other.real, this->imag + other.imag);
    }

    void print() const {
        cout << real << " + " << imag << "i" << endl;
    }

    // friend function prototype for commutative addition (double + Complex)
    friend Complex operator+(double scalar, const Complex& c);
};

// Non-member friend function definition
Complex operator+(double scalar, const Complex& c) {
    return Complex(scalar + c.real, c.imag);
}

int main() {
    Complex c1(2.5, 3.0), c2(1.5, 2.0);
    Complex c3 = c1 + c2;    // Invokes c1.operator+(c2)
    Complex c4 = 10.0 + c1;  // Invokes operator+(10.0, c1) - friend function

    c3.print(); // 4 + 5i
    c4.print(); // 12.5 + 3i
    return 0;
}
```

---

## 6. İlişkisel (Relational) Operatörler (==, !=, <, >)

İlgili kaynak dosya: [relational-operators.cpp](relational-operators.cpp)

İlişkisel operatörler iki nesneyi karşılaştırır ve geriye her zaman `bool` (`true`/`false`) döndürür:

```cpp
class Time {
    int totalSeconds;
public:
    Time(int s) : totalSeconds(s) {}

    bool operator==(const Time& other) const {
        return this->totalSeconds == other.totalSeconds;
    }

    bool operator<(const Time& other) const {
        return this->totalSeconds < other.totalSeconds;
    }

    bool operator!=(const Time& other) const {
        return !(*this == other); // Implemented via operator== (Best practice)
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

class Counter {
private:
    int value;
public:
    Counter(int v = 0) : value(v) {}

    // 1. Prefix Increment (++obj): Increment value and return reference to current object
    Counter& operator++() {
        ++value;
        return *this;
    }

    // 2. Postfix Increment (obj++): Save old value, increment, return copy of old state
    Counter operator++(int) { // Dummy 'int' parameter indicates postfix increment
        Counter temp = *this;
        value++;
        return temp; // Return old state by value
    }

    int getValue() const { return value; }
};
```

---

## 8. Akış Giriş-Çıkış Operatörleri (<< ve >>)

İlgili kaynak dosya: [iostream-operators.cpp](iostream-operators.cpp)

`cout << nesne` veya `cin >> nesne` yazabilmek için `std::ostream&` ve `std::istream&` alan `friend` fonksiyonlar tanımlanır:

```cpp
#include <iostream>
using namespace std;

class Point {
private:
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Stream Insertion (<<): Returns ostream& to support cascading calls (cout << p1 << p2)
    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

    // Stream Extraction (>>): cin >> p
    friend istream& operator>>(istream& is, Point& p) {
        cout << "Enter X and Y: ";
        is >> p.x >> p.y;
        return is;
    }
};

int main() {
    Point p(10, 20);
    cout << "Point coordinates: " << p << endl; // (10, 20)
    return 0;
}
```

---

## 9. Atama (=) ve İndis ([]) Operatörleri

İlgili kaynak dosyalar: [assing-operator.cpp](assing-operator.cpp), [subscript-operator.cpp](subscript-operator.cpp)

### 1. Atama Operatörü (`operator=`)
Nesneye başka bir nesne atandığında (`a = b;`) derin kopyalama yapılmasını sağlar. **Kendine atama kontrolü (`this == &other`) hayati önem taşır:**
```cpp
class ArrayManager {
    int* data;
    int size;
public:
    ArrayManager& operator=(const ArrayManager& other) {
        if (this == &other) return *this; // Self-assignment check

        delete[] data; // 1. Deallocate old buffer
        size = other.size;
        data = new int[size]; // 2. Allocate new buffer
        for (int i = 0; i < size; i++) data[i] = other.data[i]; // 3. Deep copy elements

        return *this;
    }
};
```

### 2. İndis Operatörü (`operator[]`)
Nesnenin dizi gibi `nesne[i]` şeklinde kullanılmasını sağlar. Hem okuma hem yazma yapılabilmesi için referans dönmelidir:
```cpp
int& operator[](int index) {
    return data[index];
}
```

---

## 10. Ekstra: C++20 Uzay Gemisi Operatörü (<=>) ve Functor Yapısı (operator())

İlgili kaynak dosya: [function-operator.cpp](function-operator.cpp)

### 1. Functor (Fonksiyon Çağrı Operatörü `operator()`)
Bir sınıf nesnesinin fonksiyon gibi çağrılabilmesini sağlar:
```cpp
class Multiplier {
    int factor;
public:
    Multiplier(int f) : factor(f) {}
    int operator()(int x) const { return x * factor; }
};

Multiplier multiplyByFive(5);
cout << multiplyByFive(10); // Outputs 50 (Object invoked like a function)
```

### 2. Üç Yönlü Karşılaştırma / Uzay Gemisi Operatörü (`<=>` - C++20)
Tek bir operatörle `<, <=, ==, !=, >=, >` operatörlerinin tamamının derleyici tarafından otomatik üretilmesini sağlar:
```cpp
#include <compare>
class Score {
    int points;
public:
    auto operator<=>(const Score&) const = default; // Generates all comparisons automatically!
};
```

---

## 11. Kodları Derleme ve Çalıştırma Rehberi (Komut Tablosu)

Bu dizindeki operatör aşırı yükleme programlarını terminal üzerinden derlemek ve çalıştırmak için:

```bash
# Genel Şablon:
g++ -std=c++17 -Wall dosya_adi.cpp -o app
./app         # Linux / macOS / Git Bash
.\app.exe     # Windows PowerShell / CMD
```

### Hızlı Başvuru Komut Tablosu

| Kaynak Kod Dosyası | Açıklama | Hızlı Derleme ve Çalıştırma (Bash / Linux / Mac) | Hızlı Derleme ve Çalıştırma (Windows PowerShell) |
| :--- | :--- | :--- | :--- |
| `function-overloading.cpp` | Fonksiyon Aşırı Yükleme Örnekleri | `g++ -std=c++17 function-overloading.cpp -o app && ./app` | `g++ -std=c++17 function-overloading.cpp -o app; .\app.exe` |
| `c-polymorphizm.c` | C Dilinde Aşırı Yükleme Sınırlılığı | `gcc c-polymorphizm.c -o app && ./app` | `gcc c-polymorphizm.c -o app; .\app.exe` |
| `this-pointer.cpp` | `this` Göstericisi ve Zincirleme | `g++ -std=c++17 this-pointer.cpp -o app && ./app` | `g++ -std=c++17 this-pointer.cpp -o app; .\app.exe` |
| `binary-operators.cpp` | İkili Operatörler (`+`, `-`, `*`) | `g++ -std=c++17 binary-operators.cpp -o app && ./app` | `g++ -std=c++17 binary-operators.cpp -o app; .\app.exe` |
| `unary-operator.cpp` | Tekli Operatörler (`-`, `!`) | `g++ -std=c++17 unary-operator.cpp -o app && ./app` | `g++ -std=c++17 unary-operator.cpp -o app; .\app.exe` |
| `increment-operator.cpp` | Ön/Son Artırma (`++`, `--`) | `g++ -std=c++17 increment-operator.cpp -o app && ./app` | `g++ -std=c++17 increment-operator.cpp -o app; .\app.exe` |
| `relational-operators.cpp` | Karşılaştırma (`==`, `<`, `>`) | `g++ -std=c++17 relational-operators.cpp -o app && ./app` | `g++ -std=c++17 relational-operators.cpp -o app; .\app.exe` |
| `iostream-operators.cpp` | Akış Giriş/Çıkış (`<<`, `>>`) | `g++ -std=c++17 iostream-operators.cpp -o app && ./app` | `g++ -std=c++17 iostream-operators.cpp -o app; .\app.exe` |
| `assing-operator.cpp` | Atama Operatörü (`=`) | `g++ -std=c++17 assing-operator.cpp -o app && ./app` | `g++ -std=c++17 assing-operator.cpp -o app; .\app.exe` |
| `subscript-operator.cpp` | İndis Operatörü (`[]`) | `g++ -std=c++17 subscript-operator.cpp -o app && ./app` | `g++ -std=c++17 subscript-operator.cpp -o app; .\app.exe` |
| `friend-function.cpp` | Arkadaş (`friend`) Fonksiyonlar | `g++ -std=c++17 friend-function.cpp -o app && ./app` | `g++ -std=c++17 friend-function.cpp -o app; .\app.exe` |
| `overload-with-friend.cpp` | `friend` ile Simetrik Aşırı Yükleme | `g++ -std=c++17 overload-with-friend.cpp -o app && ./app` | `g++ -std=c++17 overload-with-friend.cpp -o app; .\app.exe` |
| `function-operator.cpp` | Fonksiyon Çağrı Operatörü `()` | `g++ -std=c++17 function-operator.cpp -o app && ./app` | `g++ -std=c++17 function-operator.cpp -o app; .\app.exe` |

---

## 12. Pekiştirme Alıştırmaları (Çözümlü Sorular)

### Soru 1: Ön ve Son Artırma Çıktı Analizi
Aşağıdaki kodun çıktısı nedir?
```cpp
#include <iostream>
using namespace std;

class Number {
    int n;
public:
    Number(int n) : n(n) {}
    Number& operator++() { ++n; return *this; }
    Number operator++(int) { Number t = *this; n++; return t; }
    int val() const { return n; }
};

int main() {
    Number num(5);
    Number a = ++num;
    Number b = num++;
    cout << "num:" << num.val() << " a:" << a.val() << " b:" << b.val() << endl;
    return 0;
}
```
**Çözüm:**
- `++num`: `num` 6 olur, referansı `a`'ya kopyalanır (`a = 6`).
- `num++`: Eski değer (6) geçici nesnede saklanır, `num` 7 olur. `b`'ye eski değer atanır (`b = 6`).
- Çıktı: `num:7 a:6 b:6`.

---

### Soru 2: Fonksiyon Aşırı Yükleme ve Belirsizlik (Ambiguity) Analizi
Aşağıdaki C++ kodunun derleme durumunu ve olası hataları analiz ediniz:
```cpp
#include <iostream>
using namespace std;

void print(int x) { cout << "int: " << x << endl; }
void print(double x) { cout << "double: " << x << endl; }
void print(int x, int y = 5) { cout << "int, int: " << x << ", " << y << endl; }

int main() {
    print(3.14);  // (A)
    print('A');   // (B)
    print(10);    // (C)
    return 0;
}
```
**Çözüm:**
- `(A) print(3.14);`: Sorunsuz derlenir. `3.14` bir `double` literali olduğu için Seviye 1 (Exact Match - Tam Eşleşme) ile `print(double)` çağrılır. Çıktı: `double: 3.14`.
- `(B) print('A');`: Sorunsuz derlenir. `'A'` bir `char` türündedir. C++ kurallarına göre `char`, integral yükseltme (*integral promotion*) ile `int` türüne terfi eder (Seviye 2). Bu nedenle `print(int)` çağrılır. Çıktı: `int: 65`.
- `(C) print(10);`: **DERLEME HATASI VERİR! (Ambiguous call)**. `10` bir `int`'tir. Derleyici karşısında iki uygun fonksiyon görür: `void print(int)` ve ikinci parametresi varsayılan değere (`y = 5`) sahip olan `void print(int, int = 5)`. Her ikisi de tek bir `int` argüman ile çağrılabilir ve ikisi de tam eşleşmedir. Derleyici hangisinin kastedildiğini çözemez ve derleme hatası üretir.

---

### Soru 3: `this` Göstericisi ve Metot Zincirlemede Değer vs Referans Farkı
Aşağıdaki sınıf tasarımında `add` fonksiyonunun dönüş tipi `Counter&` yerine `Counter` olsaydı `main` içindeki zincirleme işleminin sonucunda `c.getCount()` ne olurdu?
```cpp
#include <iostream>
using namespace std;

class Counter {
    int count;
public:
    Counter(int c = 0) : count(c) {}
    
    // Notice: Returns by value (Counter) instead of by reference (Counter&)
    Counter add(int x) {
        count += x;
        return *this;
    }
    int getCount() const { return count; }
};

int main() {
    Counter c(10);
    c.add(5).add(20);
    cout << "Result: " << c.getCount() << endl;
    return 0;
}
```
**Çözüm:**
- Konsola **Result: 15** yazılır (Beklenen 35 değildir!).
- **Nedeni:** `c.add(5)` çağrıldığında `c.count` değeri 15 olur. Ancak fonksiyon `Counter` (değer ile) döndüğü için `*this` ifadesi `c` nesnesinin bellekte **isimsiz, geçici bir kopyasını** (*temporary copy*) üretir.
- Ardından gelen `.add(20)` çağrısı `c` nesnesi üzerinde değil, bu **geçici kopya** üzerinde çalışır ve kopyanın değerini 35 yapar.
- İfade satırı bittiğinde geçici kopya bellekten tamamen silinir.
- Asıl `c` nesnesinin değeri ise ilk adımda kaldığı gibi `15` olarak kalır. Zincirleme çağrıların asıl nesneyi değiştirebilmesi için fonksiyonun mutlaka `Counter&` (referans) döndürmesi şarttır!

---

## 13. Öğrenciler İçin Ev Ödevleri

### Ödev 1: Tam Kapsamlı Karmaşık Sayı Kütüphanesi (`Complex`)
- **Görev:** `Complex` sınıfı için `+`, `-`, `*`, `/`, `==`, `!=`, `+=`, `-=`, `<<`, `>>` operatörlerinin tamamını aşırı yükleyiniz. `(a + bi) / (c + di)` bölme kuralını formüle uygun olarak kodlayınız.

### Ödev 2: Dinamik Güvenli String Sınıfı (`MyString`)
- **Görev:** Kendi string sınıfınızı tasarlayınız:
  - `+` ile string birleştirme,
  - `==` ile metin eşitliği,
  - `[]` ile sınır kontrollü karaktere erişim (`at()`),
  - `=` operatöründe derin kopyalama ve bellek temizliği.

### Ödev 3: Polinom Sınıfı ve Cebirsel İşlemler (`Polynomial`)
- **Görev:** $P(x) = a_n x^n + \dots + a_1 x + a_0$ biçimindeki polinomları temsil eden `Polynomial` sınıfı tasarlayınız. İki polinomun toplanması (`+`), çarpılması (`*`) ve $x$ değeri verilerek polinomun hesaplanması (`operator()(double x)`) işlemlerini aşırı yükleyiniz.
