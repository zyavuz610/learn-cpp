// Include iostream library for input/output operations
#include <iostream>

// Using namespace std to avoid writing std:: prefix repeatedly
using namespace std;

int main() {
  // Display text to console using cout (console output)
  cout << "Hello everyone\n";
  
  // Return 0 to indicate successful program termination
  return 0;
}

/*
============================================
COMPARING C vs C++
============================================

SIMILARITIES:
- Both languages share similar syntax and structure
- Both use 'gcc' compiler (C/C++ compatible)
- Almost all C operators and keywords exist in C++
- Both have similar memory models close to hardware
- Both support stack, heap, scope, and static variables

DIFFERENCES - OVERVIEW:
- C: Developed by Dennis Ritchie (1973) at AT&T Bell Labs
  Called "A System Programming Language"
- C++: Developed by Bjarne Stroustrup (1979) at Bell Labs
  Originally called "C with Objects"

KEY DISTINCTIONS:
- C does NOT support OOP (no inheritance, polymorphism, encapsulation)
- C++ supports full Object-Oriented Programming features
- C: Procedural - data and functions are separate
- C++: Hybrid language - combines OOP with procedural approach
- C has ~32 keywords; C++ has ~52 keywords
- C++ supports information hiding (encapsulation)
- C is a subset of C++ (mostly compatible)

LANGUAGE PARADIGM:
- C: Procedural programming language
  * Focus on functions and procedures
  * Data and operations separated
- C++: Multi-paradigm language
  * Object-Oriented Programming (OOP)
  * Procedural programming (also supported)
  * Data and functions encapsulated in objects

ENCAPSULATION & DATA HIDING:
- C: No built-in encapsulation or access control
- C++: Supports private, public, protected members
  * Protects data through access modifiers
  * Implements information hiding principle

WHEN TO USE WHICH:
- Use C for: System programming, embedded systems, simplicity
- Use C++ for: Large-scale applications, game development, complex projects
- Many modern projects use C++ for its OOP advantages

INTERESTING FACTS:
- Dennis Ritchie (C creator): 1941-2011
- Bjarne Stroustrup (C++ creator): Still active in 2024
- C++ remains powerful for performance-critical applications
- Understanding C helps learn C++ concepts
*/
/*
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
