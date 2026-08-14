// iostream kütüphanesini dahil eder (giriş/çıkış işlemleri için gerekli)
#include <iostream>

// std namespace'ini kullanmak için std:: yazmamıza gerek kalmaması için
using namespace std;

int main() {
  // Ekrana "Merhaba herkese" yazısını yazdırır
  cout << "Merhaba herkese\n";
  
  // Programı başarıyla bitirdiğini belirtir ve 0 değerini döndürür
  return 0;
}

/*
C ve C++ arasındaki benzerlikler nelerdir?
- Her iki dilin de benzer bir sözdizimi vardır.
- Her iki dilin de kod yapısı aynıdır.
- Her iki dilin de derlemesi benzerdir. "gcc" derleyicisi C ve C++ için kullanılabilir.
  gcc hello.c -o hello
- Her iki dilin de temel sözdizimi aynıdır. C'nin neredeyse tüm operatörleri ve anahtar kelimeleri C++'da da mevcuttur ve aynı işi yapar.
- C++'ın C'den biraz daha geniş bir grameri vardır, ancak temel grammer aynıdır.
- Her iki dilin de temel bellek modeli donanıma çok yakındır. Yani C ve C++'ın bellek modeli donanıma çok yakındır.
- Her iki dilde de yığın, yığın, dosya kapsamı ve statik değişkenlerin aynı kavramları vardır.

C ve C++ arasındaki farklar nelerdir? C	vs C++
=======================================
- C 1969 yılında Dennis Ritchie TARAFINDAN AT&T Bell Labs'de geliştirilmeye başlandı. 1973 yılında C'nin ilk sürümü yayınlandı. "A System Programming Language" olarak adlandırıldı. Bir çok özelliğini daha önce kullanılan B programlama dilinden almıştır. Bu nedenle adına C verilmiştir.
- C++ dili ise Bjarne Stroustrup tarafından 1979 yılında Bell Lab'ta geliştirildi. İlk başlarda dilin adı "C with Objects" olarak anılıyordu. 1983 yılında C++ olarak adlandırılmaya başlandı.
- Dennis Ritchie 2011 yılında öldü. Bjarne Stroustrup hala hayattadır.
=======================================
- C dili polymorphism, encapsulation, inheritance gibi özellikleri desteklemez. Bu nedenle C nesne yönelimli programlamayı desteklemez.
- C++ nesne yönelimli programlama dili olduğu için polymorphism, encapsulation, inheritance gibi özellikleri destekler.
=======================================
- C, C++'ın alt kümesidir.
- C++ C'nin üst kümesidir.
=======================================
- C dili 32 anahtar kelime içerir.
- C++ dili 52 anahtar kelime içerir.
=======================================
- C dili fonksiyonlarla çalışır. C'de fonksiyonlar ayrı ayrı çalışır. Procedurel bir dildir. Veri ve fonksiyonlar ayrıdır.
- C++ dili nesne yönelimli programlama dili olduğu için veri ve fonksiyonlar bir arada çalışır. Ancak C gibi procedural bir dil olarak da kullanılabilir. Bu yüzden C++ hibrit bir dildir.
=======================================
- Veri ve fonksiyonlar C'de ayrıdır. Çünkü C procedural bir programlama dilidir.
- Veri ve fonksiyonlar C++'da bir nesne şeklinde bir arada kapsüllenir.
=======================================
- C dili information hiding'i desteklemez. Information hiding veri gizleme demektir. Veri yapılarının ve operatörlerin amaçlandığı gibi kullanılmasını sağlamak için Encapsulation ile veri gizlenir. Information hiding veri gizleme demektir.
- C++ dili information hiding'i destekler.
=======================================
- C dilinde builtin data types desteklenir.
- C++ dilinde builtin ve user-defined data types desteklenir (örn:string).
=======================================
- C dili function driven bir dildir. Çünkü C procedural bir programlama dilidir. Bir çok işlem fonksiyonlarla yapılır. Ekrana çıktı için printf() fonksiyonu kullanılır. - (ana bileşen:fonksiyon)
- C++ dili object driven bir dildir. Çünkü C++ nesne yönelimli programlama dildir. Bir çok işlem nesnelerle yapılır. Ekrana çıktı için cout nesnesi kullanılır. - (ana bileşen, nesne)
=======================================
- C dili operator overloading'i desteklemez. C++ dili operator overloading'i destekler. Operator overloading operatör aşırı yüklenmesi demektir. Bir operatörün birden fazla anlamı olabilir. Örneğin; + operatörü sayıları toplamak için kullanılır. Ama aynı operatör stringleri birleştirmek için de kullanılabilir.
=======================================
- C dilinde fonksiyonlar struct içinde tanımlanamaz.
- C++ dilinde fonksiyonlar struct (class) içinde tanımlanabilir.
=======================================
- C dilinde namespace özelliği yoktur. C++ dilinde namespace özelliği vardır. Namespace isim alanı demektir. Namespace özelliği isim çakışmalarını önler.
=======================================
- C dilinde header kullanımı #include <stdio.h> şeklindedir.
- C++ dilinde header kullanımı #include <iostream> şeklindedir.
=======================================
- C dilinde pointer aritmetiği vardır. Referans değişkenleri yoktur.
- C++ dilinde pointer aritmetiği vardır. Referans değişkenleri vardır.
=======================================
- C dilinde virtual ve friend fonksiyonlar yoktur. C++ dilinde virtual ve friend fonksiyonlar vardır. Virtual fonksiyonlar çok biçimlilik (polymorphism) için kullanılır. Friend fonksiyonlar ise veri gizleme (information hiding) için kullanılır.
=======================================
- C dili miras (inheritance) özelliğini desteklemez. C++ dili miras (inheritance) özelliğini destekler.
=======================================
- C dili veri yerine prosedür odaklıdır. C++ dili veri odaklıdır.
=======================================
- Dinaik bellek yönetimi için C dilinde malloc() ve calloc() fonksiyonları kullanılır. Bellekten alan silinirken free() fonksiyonu kullanılır.
- Dinamik bellek yönetimi için C++ dilinde new ve delete operatörleri kullanılır.
=======================================
- Exception handling (istisna durum yönetimi) C dilinde desteklenmez. C++ dilinde exception handling (istisna durum yönetimi) desteklenir.
=======================================

Ref: https://www.geeksforgeeks.org/difference-between-c-and-c/
*/
