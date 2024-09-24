# 2024-25 Güz Yarıyılı - Ders Planı

## Haftalara Göre Ders İçerikleri
* Hafta-1
  * Tanışma, dersin işleyişi
  * Değişkenler, sabitler, operatörler, karar ifadeleri, döngüler
  * string (karakter dizisi), string işlemleri
* Hafta-2
  * diziler: tek boyutlu (vector), iki boyutlu (matris), 3 ve daha fazla boyutlu (tensor)
  * Fonksiyonlar, fonksiyon çağırma yöntemleri, fonksiyondan değer geri döndürme
  * Örnek Uygulamalar (haftalık ödev verilebilecek konular)
    * 2, 10, 16 tabanından birinde verilen bir sayının başka bir tabana dönüşümü (fonksiyonla yapınız)
* Hafta-3
  * Formatlı girdi çıktı işlemleri, setw, setprecision, fixed, endl
  * cin, cout (advanced)
* Hafta-4
  * pointer, reference, dizi pointer ilişkisi
  * enum, namespaces, :: (scope operator)
  * dosya işlemleri, sıralı erişim, rasgele erişim
* Hafta-5
  * struct, composition, multi-level composition, union
* Hafta-6
  * class ve object, class üyeleri (değişkenler<özellik>, fonksiyonlar<davranış>)
  * constructor, parametreli constructor, destructor, copy constructor
  * getter(), setter() fonksiyonlar
  * public, private, protected
* Hafta-7
  * kuyruk (queue), yığın (stack), bağlı liste (linked list) örnekleri
  * implementation hiding
  * dosya işlemleri - örneklerle
* Hafta-8
  * this pointer, pointer to classes, basit pointer, class pointer, new, delete
  * inline functions, friend function
* Hafta-9
  * arasınav haftası
* Hafta-10
  * dynamic memory management (örnekler ile)
  * static members,
* Hafta-11
  * inheritance (1-level, public, protected, private inheritance, hierarchic inheritance)
* Hafta-12
  * polymorphizm, virtual functions and classes
  * pure virtual functions, abstract classes
* Hafta-13
  * function overloading, 
  * operator overloading, 
* Hafta-14
  * templates, template functions, template classes
  * command line parameters
* Hafta-15
  * telafi haftası, ödev kontrolleri
  * STL (Standard Template Library) örnekleri, pair, vector, list, map, set, stack, queue, iterator
  * STL algorithms, STL containers

--- 

## Kayıtlar (Logs)
* 1 - Pazartesi, 9-11
* 2 - Cuma, 8-10

[Sınıf İçi Kodlar](https://replit.com/@ZaferYavuz1/cpp-100a)

---

* H01/1
  * tanışma, ders hakkında bilgi
  * C++ ile C Karşılaştırma
  * **tavsiye edilen izleme listesi**
    * [C++ 100 - C++ ile Programlama ve Yol Haritası](https://www.youtube.com/watch?v=2GFTynfGG90&list=PLqiHvxGteAQdk1kl7dnt_Cvy9veTYVPv9&index=1)
    * [C++ 101 - Kurulum (Replit.com) ve İlk Program (Hello World)](https://www.youtube.com/watch?v=DniXkYikXTY&list=PLqiHvxGteAQdk1kl7dnt_Cvy9veTYVPv9&index=2)
* H01/2
  * c++ dilinde ilk program (ekrana çıktı alma)
  * yorumlar, ifade sonlandırma, blok kavramı, farklı kod yazma biçimleri, 
  * identifiers (tanımlayıcılar), değişken, fonksiyon, class, module ... isimleri
  * c++ dilinde keywords, whitespace
  * ilk program, komut satırından derleme, çalıştırma
  * veri türleri, değişkenler ve değişken tanımlama
  * lokal ve global değişkenler
  * Sabitler, litteral sabitler
  * operatörler (aritmetik, karşılaştırma, lojik, atama)
  * karar deyimleri (if, else, switch-case)
  * döngü ifadeleri (for, while, do-while)
  * **tavsiye edilen izleme listesi**
    * [C++ 102 - Ekrana çıktı alma | cout | yeni satır | birden çok ifadenin ekrana yazılması](https://www.youtube.com/watch?v=aeoW4LDX2GM&list=PLqiHvxGteAQdk1kl7dnt_Cvy9veTYVPv9&index=3)
    * [C++ 103 - Yorum (Comment) Ekleme](https://www.youtube.com/watch?v=qxVvfoXBJ2I&list=PLqiHvxGteAQdk1kl7dnt_Cvy9veTYVPv9&index=4)
    * [C++ 104 - Değişkenler ve Değişken İsimlendirme Kuralları (Variables)](https://www.youtube.com/watch?v=6E_Z-8gW-7s&list=PLqiHvxGteAQdk1kl7dnt_Cvy9veTYVPv9&index=5)
    * [C++ 105 - Aritmetik Operatörler 1 | Toplama ve Çıkarma](https://www.youtube.com/watch?v=7mkoK2cUjI4&list=PLqiHvxGteAQdk1kl7dnt_Cvy9veTYVPv9&index=6)
    * [C++ 106 - Aritmetik Operatörler 2 | Çarpma, Bölme ve Mod (Kalan Bulma) İşlemleri](https://www.youtube.com/watch?v=RVpL0dPoQjM&list=PLqiHvxGteAQdk1kl7dnt_Cvy9veTYVPv9&index=7)
    * [C++ 107 - Veri Tipleri ve Boyutları](https://www.youtube.com/watch?v=jLNKzNrTn2A&list=PLqiHvxGteAQdk1kl7dnt_Cvy9veTYVPv9&index=8)
    * [C++ 108 - Veri Tipleri Kullanımı | bool, char, short int, long double, sonsuz ve tanımsız (inf, nan)](https://www.youtube.com/watch?v=ykaI9gw3zQM&list=PLqiHvxGteAQdk1kl7dnt_Cvy9veTYVPv9&index=9)
    * [C++ 109 - Kullanıcıdan Girdi Almak | cin | getline ()](https://www.youtube.com/watch?v=D1V_kRhzhGE&list=PLqiHvxGteAQdk1kl7dnt_Cvy9veTYVPv9&index=10)
    * [C++ 110 - Koşullu İfadelere Giriş | if](https://www.youtube.com/watch?v=rg8bCswVlnQ&list=PLqiHvxGteAQdk1kl7dnt_Cvy9veTYVPv9&index=11)
    * [C++ 111 - Karşılaştırma Operatörleri | eşitlik | eşit değil | küçük | büyük | küçük veya büyük eşit](https://www.youtube.com/watch?v=4Lp0j1Pl1e0&list=PLqiHvxGteAQdk1kl7dnt_Cvy9veTYVPv9&index=12)
    * [C++ 112 - Koşul İfadeleri 2 | if | else if | else, Harf Notu Hesaplama](https://www.youtube.com/watch?v=vmVHvQr_aVc&list=PLqiHvxGteAQdk1kl7dnt_Cvy9veTYVPv9&index=13)
    * [C++ 113 - Döngüler : Tekrarlı Yapılar | for | while | do while](https://www.youtube.com/watch?v=tF8Tg1EiHeU&list=PLqiHvxGteAQdk1kl7dnt_Cvy9veTYVPv9&index=14)
    * [C++ 114 - Döngüler 1 | for döngüsü örneği](https://www.youtube.com/watch?v=nGCcRHy4Evg&list=PLqiHvxGteAQdk1kl7dnt_Cvy9veTYVPv9&index=15)
    * [C++ 115 - Döngüler 2 | while döngüsü](https://www.youtube.com/watch?v=xI0IUhVwlHE&list=PLqiHvxGteAQdk1kl7dnt_Cvy9veTYVPv9&index=16)
    * [C++ 116 - Döngüler 3 | do-while döngüsü | for, while, do-while döngüleri karşılaştırma ve özet](https://www.youtube.com/watch?v=zZ3pOIQZfhQ&list=PLqiHvxGteAQdk1kl7dnt_Cvy9veTYVPv9&index=17)
    * [C++ 117 - Döngü Örnekleri 1 | 1-100 arası tek ve çift sayılar](https://www.youtube.com/watch?v=4P5WthNPjp0&list=PLqiHvxGteAQdk1kl7dnt_Cvy9veTYVPv9&index=18)
    * [C++ 118 - Döngü Örnekleri 2 | 1-n arası sayıları toplama | artırma , azaltma ve aritmetik atama](https://www.youtube.com/watch?v=nclJZGLw2bk&list=PLqiHvxGteAQdk1kl7dnt_Cvy9veTYVPv9&index=19)
    * [C++ 119 - Döngü Örnekleri 3 | Hesap Makinesi Örneği (Toplama)](https://www.youtube.com/watch?v=PSOrKoUq-Gs&list=PLqiHvxGteAQdk1kl7dnt_Cvy9veTYVPv9&index=20)
    * [C++ 120 - Döngüler 4 | break ve continue deyimleri | Hesap Makinesi (Toplama) Örneği](https://www.youtube.com/watch?v=L5PxGoTqAz4&list=PLqiHvxGteAQdk1kl7dnt_Cvy9veTYVPv9&index=21)
    * [C++ 121 - Döngü Örnekleri 4 | Hesap Makinesi (4 işlem)](https://www.youtube.com/watch?v=PYbjjoafv8w&list=PLqiHvxGteAQdk1kl7dnt_Cvy9veTYVPv9&index=22)
    * [C++ 122 - Döngü Örnekleri 5 | Maximum, Minimum Bulma Problemi](https://www.youtube.com/watch?v=99sreSHbP2k&list=PLqiHvxGteAQdk1kl7dnt_Cvy9veTYVPv9&index=23)
  * **sınıf içi ödevler**
    * Türkiye nüfusunun bu yıl 85 milyon olduğunu dusunelim. Her yıl nüfusu %1.05 büyürse hangi yılda 100 milyonu geçeriz, 1 puan
    * 500 den küçük 7 veya 9 un katı olan sayıların toplamını ekrana uygun bir mesajla yazınız, 500 sayısını değiştirebileceğim, 1 puan. toplam sayının kaç haneli olduğunu bulmak, +1 puan