# 2019-20 Güz Yarıyılı - Ders Planı

## Hafta 01
* Tanışma
* Ders Konularının tanıtılması
* Programlamaya giriş ve veri yapıları ağacı
* "Merhaba Dünya" ve cpp programının genel yapısı
* C ve C++ arasındaki farklar
* Veri Tipleri, Değişken Tanımlama (enum)
* Global, lokal ve formal değişkenler
* Sabitler (litterals), const, #define
* Operatörler ve Öncelikleri (koşul operatörü -> ? :)
* Karar İfadeleri (if, elseif, else, switch-case, )
* iç içe karar ifadeleri
* Tekrarlı İfadeler (for, while, do-while)
* Örnek: girilen sayı çift ise iki asal sayı toplamı şeklinde ifade edin.
  
## Hafta 02
* Örnekler: 10 adet not için max, min, ortalama, 2. max, 2. min, standart sapma bulma
  * 1) ekrana yıldızlarla farklı şekiller çizin, 
  * 2) girilen sayının asal çarpanlarını bulun, 
  * 3) 1000 den küçük fibonacci sayılarını bulun, 
  * 4) girilen sayıyı asal çarpanlarına ayırın, asal ise bir şey yapmayın
* Basit girdi çıktı işlemleri: cin, cout, setw, setprecision, fixed, endl
* fonksiyonlar, fonksiyon çağırma yöntemleri (call by value, call by pointer, call by reference), fonksiyondan değer geri döndürme
* Örnek 2: öğrenci not ortalaması hesabı
  * değişken tanımlama, değişken türleri, int bölme, tür dönüşümü
  * notların ekrana yazılması (setw,setprecision,fixed)
  * öğrenci numarası palindrome bir numara mı? (tam sayı olarak, dizi kullanmadan işlem yap)

## Hafta 03
* diziler: tek boyutlu (vector), iki boyutlu (matris), 3 ve daha fazla boyutlu (tensor)
* örnek uygulamalar: 
  * notları dizide sakla, ort, min, max, std sapma bul, sırala
  * dizide geometrik olarak orta değer bulma,
  * 2D uzayda (matris) orta değer bulunması,
  * matris satırlar toplamı, sütunlar toplamı, matris çarpımı, transpoze.
  
## Hafta 04
* string (karakter dizisi): 1) karakter dizisi şeklinde (char str[100]) 2) string tipi şeklinde
* örnek string uygulamalar: 
  * kelime büyük harf yap, 
  * boşluktan böl, virgülden böl, 
  * sonuna ekle, başındaki ve sonundaki boşlukları sil, tersten yaz
* string işlemleri (advanced)
* pointer, reference,
* dizi pointer ilişkisi
* cin, cout advanced
* enum, namespaces, :: (scope operator)

## Hafta 05
* class, struct vs class, 
* class üyeleri (değişkenler<özellik>, fonksiyonlar<davranış>), 
* :: operatörü, 
* public, private, protected
* getter(), setter() fonksiyonlar
* constructor, parametreli constructor, 
* destructor, copy constructor
  
## Hafta 06
* data abstraction,
* friend function, inline functions, 
* this pointer
* pointer to classes, 
* basit pointer, class pointer, new, delete
* dosya işlemleri, sıralı erişim
  * ofstream out,ifstream in, fstream
  * ios::app,ios::in,ios::out,ios::ate,ios::trunc
  * infile.eof(), infile>>, outfile<<
* dosya işlemleri, rasgele erişim
  * inf.seekg(),inf.seekp()
  * getline(inf,strData)
  * --> byte stream: read(), write()

## Hafta 07
* dosya işlemleri - örneklerle
  * rasgele erişim
  * binary dosya okuma/yazma
    * f.read(arr,n), f.write(arr,n) -- arr must be char array
* iplementation hiding

## Hafta 08
* dynamic memory management (örnekler ile)
  * 1D, 2D
* static members
* function overloading
* operator overloading
  * binary operator overloading
  * unary operator overloading
  * conditional operator overloading
  * assignment operator overloading
  * stream operator overloading (<<, >>)
  * function call operator overloading
  * [] indexing operator overloading
<code>
    c3 = c1 + c2;     // operator overloading
    c3 = c1.sum(c2);  // normalde yapılması gereken
</code>

## Hafta 09
* ------------------- ARASINAV HAFTASI ---------------------------

## Hafta 10
* struct dizileri, struct composition
* struct, yapılara giriş
* composition, multi-level composition (oluşum, çok seviyeli (iç içe) oluşumlar)
* inheritance (1-level, public, protected, private inheritance)
  
## Hafta 11
* templates
  * template functions
  * template classes
* inheritance in advanced 
  * multi-level inheritance : 
    * (Point1D > Point2D > Point3D) örneği, 
  * multiple inheritance : 
    * Person > Student, Person > Lecturer, Employee > Lecturer
      * Lecturer, hem Person hem de Employee sınıfından miras alıyor (ters ağaç şeklinde)
    * (ambiguity=belirsizlik durumu), 
  * hierarchic : 
    * Matrix > Table, Matrix > Image (ödevde olduğu gibi)
      * Matrix sınıfından hem Image, hem de Table sınıfı miras alıyor (ağaç şeklinde)

## Hafta 12
* polimorfizm
  * static binding, dynamic binding
  * function overloading, templates, virtual functions
* virtual functions and classes
  
## Hafta 13
* polymorphizm, templates => örnekler
* Eksik kalan konuların telafisi
  
## Hafta 14
* command line parameters
* Eksik kalan konuların telafisi
* uygulama

## Hafta 15 (telafi haftası)
* Eksik kalan konuların telafisi
* ödev kontrol

## Hafta 16-17
* ---------------------------- Final haftası -----------------------
