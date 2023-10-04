# 2023-24 Güz Yarıyılı - Ders Planı

## Haftalara Göre Ders İçerikleri
* Hafta-1
  * Tanışma, dersin amacı, dersin içeriği, dersin işleyişi, dersin ödevleri, dersin sınavları
  * Değişken tanımlama, sabitler, operatörler, karar ifadeleri, tekrarlı ifadeler (döngüler)
  * Örnek Uygulamalar (haftalık ödev verilebilecek konular)
    * 1910 yılında 100 birim kazanan bir işletme her yıl %2 kazanç atışı ile 1940 yılında ne kadar kazanç sahibi olur?
    * Verilen bir çift sayının iki asal sayının toplamı şeklinde ifade edilmesi
* Hafta-2
  * Fonksiyonlar, fonksiyon çağırma yöntemleri, fonksiyondan değer geri döndürme
  * Formatlı girdi çıktı işlemleri, setw, setprecision, fixed, endl
  * Örnek Uygulamalar (haftalık ödev verilebilecek konular)
    * 2, 10, 16 tabanından birinde verilen bir sayının başka bir tabana dönüşümü (fonksiyonla yapınız)
    * ADC algoritmasının fonksiyonlar ile çözülmesi ve ara aşamaların tablo şeklinde gösterilmesi ([kaynak])(https://github.com/zyavuz610/labs_inKTU/blob/master/1_computer_org_lab/adc/analog_digital_converter(ADC).ipynb)
* Hafta-3
  * string (karakter dizisi), string işlemleri
  * diziler: tek boyutlu (vector), iki boyutlu (matris), 3 ve daha fazla boyutlu (tensor)
  * cin, cout (advanced)
* Hafta-4
  * pointer, reference, dizi pointer ilişkisi
  * enum, namespaces, :: (scope operator)
* Hafta-5
  * dosya işlemleri, sıralı erişim, rasgele erişim
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
  * **sınıf içi ödevler**
    * Türkiye nüfusunun bu yıl 85 milyon olduğunu dusunelim. Her yıl nüfusu %1.05 büyürse hangi yılda 100 milyonu geçeriz, 1 puan
    * 500 den küçük 7 veya 9 un katı olan sayıların toplamını ekrana uygun bir mesajla yazınız, 500 sayısını değiştirebileceğim, 1 puan. toplam sayının kaç haneli olduğunu bulmak, +1 puan