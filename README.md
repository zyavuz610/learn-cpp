Bu depo KTÜ Bilgisayar Mühendisliğinde okutulan **Nesne Yönelimli Programlama** dersinde görülen **C++** programlama diline ilişkin konuları ve örnek kodları içermektedir.

Ders içeriği aşağıda verilen mantıksal sırada anlatılmaktadır. Konularla ilgili bilinmesi gereken temel konular kaynak kodların içerisinde açıklama satırları olarak eklenmiştir. Kaynak kodları verildiği sırada sırasıyla incelemek ve çalıştırmak konu bütünlüğünün korunması için önemlidir.

Her kaynak dosyaların isimlendirmesi şu şekildedir: **XX.Y-abcd.cpp** , burada **XX**(konunun işleneceği haftayı), **Y**(konunun o haftadaki konu sırasını), ve **abcd**(kaynak dosyanın içeriğini) ifade etmektedir.

Kaynak kodlar genel olarak 4 bölümden oluşur. 
* **100_cpp_basics:** Temel C++ konularını içermektedir.
* **200_cpp_classes:** c++ nesne yönelimli programlama kavramlarını içerir.
* **300_cpp_STL:** C++ Standart Template Library (STL) konularını içerir
* **400_cpp_advanced:** İleri seviye C++ konuları

Bunların dışında; 
* **500_cpp_samples:** farklı kaynaklardan öğrencilerin kullanımı için paylaşılan tüm kodları içerir.
* **600_docs**: farklı belgeler içerir.
* **youtube**:[youtube oynatma listelerinde](https://www.youtube.com/playlist?list=PLqiHvxGteAQdk1kl7dnt_Cvy9veTYVPv9) anlatılan derslerin kaynak kodları

## Haftalara Göre Ders Planları (Müfredat)
Her gün değişen ve gelişen bilişim dünyasında KTÜ Bilgisayar Mühendisliğindeki "Nesne Yönelimli Programlama" isimli derste anlatılan C++ diline ilişkin ders notları, yazılan kodlar, verilen örnekler ve müfredat kısmi değişikliklere uğramaktadır.
* [2025](2025-guz-ders-plan.md) - __Aktif Dönem__
* [2024](2024-guz-ders-plan.md)
* [2023](2023-guz-ders-plan.md)
* [2019](2019-guz-ders-plan.md) - [Kaynak kodlar (Repl.it)](https://repl.it/@ZaferYavuz1)
* [2018](2018-guz-ders-plan.md)

# Ders İçeriği
## Temel C++ Konuları
* Giriş - Temel Konular
  * Ekrana çıktı almak (Hello world), C/C++ arasındaki farklar, C++'daki yenilikler
  * Veri Türleri (int, float, char, ...)
  * Değişken Tanımlama
  * static değişkenler
  * Yerel, global, formal değişkenler
  * Sabitler (constants (const), litterals, #define ...)
  * Operatörler ve Öncelikleri
* Karar İfadeleri
  * if, if-else, if-elseif-else
  * switch-case
  * koşul operatörü ( ? : )
* Döngü İfadeleri  
  * for, while, do-while
* Diziler
  * 1D diziler (vektör)
  * 2D diziler (matris)
  * 3D ve daha çok boyutlu diziler (tensör)
  * Stringler
    * C Style string
    * std::string
* Giriş-Çıkış
  * Standart girdi-çıktı
    * cin, cout
    * Basit formatlı girdi-çıktı, setw, setprecision
    * İleri düzey girdi çıktı
  * Dosya İşlemleri
    * Dosya okuma, yazma (fstream,ifstream, ofstream)
    * Dosya açma modları
    * Sıralı erişim ile dosya okuma/yazma
    * Rasgele erişimli dosyalar
    * Binary dosya okuma/yazma
* Pointer ve Referans
  * Basit pointer işlemleri, * ve & operatörü
  * Dizi-pointer ilişkisi
  * pointer aritmetiği
  * Referanslar
  * dinamik bellek yönetimi (new, delete) (1D, 2D)
* Yapılar
  * struct, struct dizisi
  * struct composition
  * enum
  * union
* Fonksiyonlar
  * Fonksiyon tanımlama, çağırma, parametre gönderme, geriye değer döndürme
  * Fonksiyona dizi gönderme
  * Fonksiyondan dizi geri döndürme
* Diğer Konular
  * namespaces

## Nesne Yönelimli Programlama (C++)
* sınıf ve nesne kavramı (class and object)
* class tanımlama
  * üye veri ve üye fonksiyonları
* erişim düzenleyiciler (access modifiers)
  * public, protected, private
* getters, setters
* constructors - yapıcılar
  * parametresiz, parametreli
  * kopya yapıcı (copy constructor)
* destructors - yıkıcılar
* Pointers
  * nesneye pointer (pointer to objects), nesne tanımlama (değişken ve pointer ile)
  * dinamik bellek yönetimi -> new, delete
  * this işaretçisi
  * nesne dizileri, yapıcı fonksiyonların çağrılması
  * fonksiyonlar ve nesneler 
    * parametre gönderme, 
    * nesne geri döndürme
  * inline functions
  * friend functions
  * static members
  * overloading - aşırı yükleme
    * function overloading
    * operator overloading
  * oluşum ve miras (composition and inheritance)
    * oluşum (composition)
    * 1 seviyeli miras
    * çok seviyeli miras
  * polymorphizm (çok biçimlilik)
    * polymorphizm
    * compile and run-time binding
    * virtual functions, abstract classes
  * templates
    * template functions
    * template classes
  * Diğer Konular
    * tip dönüşümleri
    * ön işlemci komutları
    * multi-threading (çok süreçli) programlama

## Standart Template Library (STL)
  * containers
  * pair
  * vector
  * list
  * queue
  * stack
  * iterators

## Tavsiye Edilen Siteler
Bu sitelerden bir ve/veya birkaçından seviye atlamak (c++ dili için) serbest ödev için verilecek eşik ödevinden muafiyet getirebilir. Bu yüzden boş kaldıkça bu araçları kullanarak alıştırma yapın, seviyeleri tamamlamaya çalışın.
* https://codesignal.com/ : Algoritma + Programlama
* https://www.hackerrank.com/
* https://projecteuler.net/

## Yararlı Kaynaklar
* https://www.tutorialspoint.com/cplusplus/index.htm
* https://www.geeksforgeeks.org/c-plus-plus/
* http://www.cplusplus.com/
* https://seyler.eksisozluk.com/kendi-basina-c-programlama-dili-ogrenmek-isteyenlere-tavsiyeler


