/*
PloyMorphizm
	* çok biçimlilik anlamı vardır, bir nesnenin ya da fonksiyonun kullanılma biçimine bağlı olarak farklı davranması anlamına gelir
  * C dilinde olmayan, C++ ile gelen bir özelliktir.
  * İki farklı açıdan "polymorphizm" kavramını sınıflandırmabiliriz.
    * programcı açısından (function overloading, templates, virtual functions)
      * kod yazılırken "polymorphizm" tasarlanır - overloading
      * kod çalıştırılırken "ploymorphizm" gerçekleştirilir. - overriding 
    * derleyici açısından (static (early, compile-time) binding, dynamic (late, run time) binding)  
  * C++ dilinde programcının kullanımına göre 3 farklı "polimorphizm" yöntemi vardır.
      1) "Function overloading" : En basit yöntem, farklı türde parametreler alan fonksiyon, hangi tür veya parametre sayısı ile çağrılırsa fonksiyonun o biçimi kullanılır. (otomatik tür dönüşümleri uygulanır)
      2) "Template Function/Template Class": parametrik yöntem, hangi tür ile fonk. çağrılırsa ya da nesne oluşturulursa o şekilde kullanılır.
        * "templates.cpp" kodunu inceleyin.
      3) "Virtual Function": Sanal fonksiyonlar yardımıyla gerçekleştirilir. miras ile ilişkisi vardır

Polymorphizm by Virtual Functions
	* şu şekilde bir miras sınıf hiyerarşisi olsun
		- base-class
			- derived-class1
			- derived-class2
	* base-class türünden bir pointer, derived-class1 ve derived-class2 sınıflarını adresleyebilir
	* böylece aynı kod farklı fonksiyonların çalıştırılmasını sağlayabilir
	* binding işlemi run-time binding olur, hangi fonksiyonun çağrılacağı koşma zamanında belli olur
*/

//------------------------------------------------------------------------------------------

#include <iostream> 
using namespace std;

class Shape {
   protected:
      int width, height;
      
   public:
      Shape( int a = 0, int b = 0){
         width = a;
         height = b;
      }
      int area() {
      // virtual int area() {  // polimorfizm için  
         cout << "Parent class area :" <<endl;
         return 0;
      }
};
class Rectangle: public Shape {
   public:
      Rectangle( int a = 0, int b = 0):Shape(a, b) { }
      
      int area () { 
         cout << "Rectangle class area :" <<endl;
         return (width * height); 
      }
};

class Triangle: public Shape {
   public:
      Triangle( int a = 0, int b = 0):Shape(a, b) { }
      
      int area () { 
         cout << "Triangle class area :" <<endl;
         return (width * height / 2); 
      }
};

// Main function for the program
int main() {
   Shape *shape;
   Rectangle rec(10,7);
   Triangle  tri(10,5);

   // store the address of Rectangle
   shape = &rec;
   
   // call rectangle area.
   shape->area();

   // store the address of Triangle
   shape = &tri;
   
   // call triangle area.
   shape->area();
   

   // burada polimorfizm yapabilmek için base class içinde virtual function olması gerekir
   return 0;
}


/*
Çıktı:
Parent class area :
Parent class area :

- bırada static binding yapıldığı için beklenen şekilde çalışmadı, 
- dynamic binding için sanal fonksiyon şeklinde tanımlanması gerekir
- şekil olarak anlatalım...
*/