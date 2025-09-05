#include <iostream>

using namespace std;
/*
 * Nesne Yönelimli Programlama (Object-Oriented Programming - OOP) Nedir?
 *
 * OOP, yazılımı gerçek dünyadaki nesnelere benzeyen, birbiriyle etkileşime giren
 * nesneler aracılığıyla modelleyen bir programlama paradigmasıdır.
 *
 * Her nesne, hem veriyi (özellikleri) hem de bu veri üzerinde işlem yapan
 * fonksiyonları (davranışları) bir araya getirir.
 *
 *
 * Neden İhtiyaç Duyulur?
 *
 * Geleneksel (prosedürel) programlama yaklaşımında, veri ve bu veri üzerinde
 * işlem yapan fonksiyonlar birbirinden ayrıdır. Bu durum, özellikle büyük ve
 * karmaşık projelerde kodun yönetimini, bakımını ve anlaşılırlığını zorlaştırır.
 *
 * Nesne yönelimli programlama, bu zorlukları aşarak daha düzenli, modüler ve
 * yeniden kullanılabilir kod yazmamızı sağlar.
 *
 *
 * Avantajları Nelerdir?
 *
 * 1. Kapsülleme (Encapsulation):
 * Veri ve veriyi işleyen metotları tek bir birim (nesne) içinde bir araya getirir.
 * Veriye dışarıdan doğrudan erişimi kısıtlayarak verinin güvenliğini sağlar.
 *
 * 2. Soyutlama (Abstraction):
 * Nesnenin iç işleyişini kullanıcıdan gizler ve yalnızca gerekli
 * işlevselliği sunar. Bu, karmaşıklığı azaltır ve programı daha anlaşılır hale getirir.
 *
 * 3. Kalıtım (Inheritance):
 * Mevcut bir sınıftan yeni bir sınıf oluşturmaya olanak tanır.
 * Böylece kod tekrarını önler ve kodun yeniden kullanılabilirliğini artırır.
 *
 * 4. Çok Biçimlilik (Polymorphism):
 * Farklı nesnelerin aynı metoda farklı şekillerde yanıt vermesini sağlar.
 * Bu, daha esnek ve genel amaçlı kod yazmamıza imkan tanır. Örneğin, bir
 * "Sekil" sınıfı altındaki "Kare" ve "Daire" nesnelerinin "alanHesapla"
 * fonksiyonu her biri için farklı çalışabilir.
 *
 * 5. Modülerlik ve Bakım Kolaylığı:
 * Programı, kolayca yönetilebilen bağımsız modüllere (nesnelere) ayırır.
 * Bir nesnede yapılan değişiklikler, diğer nesneleri etkilemez ve
 * hataların bulunmasını kolaylaştırır.
 */
// ---------------------------------------------------------------------
// Sınıf (Class) ve Yapı (Struct) Arasındaki Farklar
// C++'ta hem 'class' hem de 'struct' farklı veri tiplerini bir arada tutmak için kullanılır.
// Ancak, aralarında temel farklar vardır.

// 1. Varsayılan Erişim Belirleyicisi
//    - 'struct' yapısında üyeler (değişkenler ve fonksiyonlar) varsayılan olarak 'public'dır.
//    - 'class' yapısında ise üyeler varsayılan olarak 'private'dır.

// 2. Kullanım Amacı
//    - 'struct' genellikle sadece veri grupları için kullanılır ve C dilindeki yapıları anımsatır.
//    - 'class' ise hem veriyi hem de bu veri üzerinde işlem yapan fonksiyonları
//      (metotları) bir araya getirir. Bu, nesne yönelimli programlamanın (OOP)
//      önemli bir prensibi olan 'kapsüllemeyi' (encapsulation) destekler.

// Sonuç olarak,
// Her iki yapı da aynı yeteneklere sahiptir ve birbirlerinin yerine kullanılabilir.
// Ancak, kodun amacını ve tasarım niyetini daha net belirtmek için yaygın bir kural vardır:
//    - Basit veri grupları (örneğin, bir koordinat noktası) için 'struct' kullanın.
//    - Kapsülleme, kalıtım gibi OOP özelliklerini kullanacağınız durumlarda 'class' tercih edin.


class Box {
   public:
      double length;   // Length of a box
      double breadth;  // Breadth of a box
      double height;   // Height of a box
};

int main() {
   Box Box1;        // Declare Box1 of type Box
   Box Box2;        // Declare Box2 of type Box
   double volume = 0.0;     // Store the volume of a box here
/*
    . Box bir veri türü yani tip tir.
    . Box1 ise bir nesnedir ve genelde gerçek hayatta bir nesneye karşılık gelir
    . (doğal olarak nesnenin özellikleri (üye değişkenleri) ve bu özellikler üzerinde işlem yapan fonksiyonlar (üye fonksiyonlar=davranışlar) bulunmaktadır)
*/

/*
    . operatörü elemanlara erişim için kullanılır
    = operatörü direk nesnelerin birbirine atanmasında kullanılır (pointer olmayacak)
    DENE
        Box1 = Box2;
*/
 
   // box 1 specification
   Box1.height = 5.0; 
   Box1.length = 6.0; 
   Box1.breadth = 7.0;

   // box 2 specification
   Box2.height = 10.0;
   Box2.length = 12.0;
   Box2.breadth = 13.0;
   
   // volume of box 1
   volume = Box1.height * Box1.length * Box1.breadth;
   cout << "Volume of Box1 : " << volume <<endl;

   // volume of box 2
   volume = Box2.height * Box2.length * Box2.breadth;
   cout << "Volume of Box2 : " << volume <<endl;
   return 0;
}
//---------------------------------------------------------------------
/*
burada Box sınıfında bazı problemler var.
1. değişkenler ve fonksiyonlar ayrı ayrı tanımlanıyor, hep birlikte tanımlanması iyi,
2. değişkenler public, dışarıdan erişilebilir, bu iyi değil, private olmalı,
3. değişkenlere erişim ve değişiklik için fonksiyonlar yok, bu iyi değil
bunu ilerleyen derslerde düzelteceğiz
*/
//-----------------------------------------------------
/*  bir başka örnek (öğrenci sınıfı da verilebilir)
class clockType {
public:
    void setTime(int, int, int);
    void getTime(int&, int&, int&);
    void printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    
    // burada class parametre olarak gönderiliyor, 
    // foksiyon çağrısında call by value, call by reference, call by pointer yöntemleri kullanılabilir
    // class türü geri dönüş değeri olabilir
    bool equalTime(const clockType& otherTime) const;

private:
    int hr;
    int min;
    int sec;
};

*/

//-----------------------------------------------------
/*
 * Sınıf (Class) ve Nesne (Object) Arasındaki Fark Nedir?
 *
 * En basit ifadeyle, bir **sınıf (class)** bir **plan**, **kalıp** veya **şablon** gibidir.
 * Bir **nesne (object)** ise bu plandan oluşturulmuş **somut bir örnektir**.
 *
 * ---
 *
 * 1. Sınıf (Class): Plan
 *
 * - Bir sınıf, nesnelerin hangi özelliklere (veri üyeleri) ve hangi davranışlara (metotlar) sahip olacağını tanımlar.
 * - Sınıfın kendisi bellekte bir yer kaplamaz, yalnızca bir veri tipi tanımlamasıdır.
 * - Örneğin, bir "Araba" sınıfı; renk, marka, model gibi özelliklere ve hızlanma, fren yapma gibi davranışlara sahip olacağını belirtir.
 *
 * class Araba {
 * string renk;
 * string marka;
 * void hizlan();
 * };
 *
 * ---
 *
 * 2. Nesne (Object): Somut Örnek
 *
 * - Bir nesne, bir sınıftan türetilmiş, fiziksel olarak bellekte yer kaplayan gerçek bir varlıktır.
 * - Her nesnenin, ait olduğu sınıfın belirlediği özelliklere özel değerleri vardır.
 * - Aynı sınıftan birden fazla nesne oluşturulabilir ve her birinin kendine özgü verileri olabilir.
 *
 * Araba araba1; // Birinci nesne
 * araba1.renk = "Kirmizi";
 * araba1.marka = "Ferrari";
 *
 * Araba araba2; // İkinci nesne
 * araba2.renk = "Mavi";
 * araba2.marka = "BMW";
 *
 * ---
 *
 * Özet
 *
 * class Araba;      // Bu bir **plan**dır. (Soyut)
 * Araba araba1;     // Bu **plandan oluşturulmuş somut bir nesnedir.** (Gerçek)
 *
 * Herhangi bir yapı inşa etmeden önce bir plana ihtiyacınız olduğu gibi,
 * bir nesne oluşturmadan önce de onu tanımlayacak bir sınıfa ihtiyacınız vardır.
 */