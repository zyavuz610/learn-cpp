/*
	- miras, OOP programlama için önemli bir kavramdır, 
		* yeniden kullanılabilir kod yazmak ya da kodun bakımını yapmakta (kod değişikliğinde) büyük kolaylık sağlar, 
		
            * örn; kişi sınıfından oğrenci ve öğretmen sınıfı miras alsın, kod kişi davranışı ile ilgili bir bakım gerektirse sadece kişi sınıfı değiştirilir, böylece öğrenci ve öğretmen bundan otomatik etkilenir, bunun tersi olsaydı, yani öğrenci ve öğretmen sınıfı ayrı yazılsaydı her 2 sınıf da değiştirilmek zorunda kalınacaktı (burada modelleme de önemli)
		
            * bir kere kişi sınıfı tanımlandığında öğrenci sınıfı için kişi özellikleri (ad, soyad vb.) yeniden tanımlanmak zorunda değil

	- miras alınan -> base class, kişi
	- miras alan -> derived class, öğrenci, öğretmen
	- miras ilişkisi bir "is a" ilişkisidir, yani "öğrenci 'is a' person"
	- başka bir örnek: mammal IS-A animal, dog IS-A mammal hence dog IS-A animal as well and so on.
		* animal < mammal < dog vb...
	- miras kavramına gerçek hayattan örnekler veriniz (sınıf içi takım çalışması)
	
	base-derived class tanımlama
		class "derived-class" [public|protected|private] "based-class"
	
*/

//----------------------------------------------------

/*
      * one-level inheritance
            base class        -> Shape
                  - width
                  - height
                  + setWidth(int)
                  + setHeight(int)
            derived class     -> Rectange : public Shape
                  + getArea()
*/

/*
#include <iostream>
using namespace std;

class Shape {                       // Base class
   public:
      void setWidth(int w) {
         width = w;
      }
      void setHeight(int h) {
         height = h;
      }
      
   protected:
      int width;
      int height;
};


class Rectangle: public Shape {     // Derived class
   public:
      int getArea() { 
         return (width * height); 
      }
};

int main(void) {
   Rectangle Rect;
 
   Rect.setWidth(5);
   Rect.setHeight(7);

   // Print the area of the object.
   cout << "Total area: " << Rect.getArea() << endl;

   return 0;
}
*/
//---------------------------
/*
çıktı
	Total area: 35

*/

//-------------------------------------------------------------------------------
/*
	parametrelere ilk değer atama
	base class'ın "parametreli yapıcı fonksiyonunu çağırma"
	çoklu miras
*/

/*
#include <iostream>
 
using namespace std;

// Base class
class Shape {
   public:
      Shape(){  width = 2;   height = 2;  }
      //Shape():width(5),height(5){ }

     // Shape(int width,int height){this->width=width; this->height=height;}
      Shape(int width,int height):width(width),height(height){}

      void setWidth(int w) {
         width = w;
      }
      void setHeight(int h) {
         height = h;
      }
      
   protected:
      int width;
      int height;
};

// Derived class
class Rectangle: public Shape {
   public:
      Rectangle(){}
      Rectangle(int h,int w):Shape(h,w){ }
      int getArea() { 
         return (width * height); 
      }
};

int main(void) {
   Rectangle Rect(10,10); 
  // Rect.setWidth(5);
  // Rect.setHeight(7);

   // Print the area of the object.
   cout << "Total area: " << Rect.getArea() << endl;

   return 0;
}

*/

//=================================================================================
/*
		Access Control and Inheritance
		- derived class base class'ın private olmayan tüm üyeşerine erişebilir.
		- derived class aşağıdaki üyeler hariç tüm methodları miras alır
			* constructor, destructor, copy constructor
			* overloaded operators
			* friend functions
			
		Miras Türleri
		- public:
			* sıklıkla kullanılır,
			* üyelere erişim şu şekilde olur,
				- base class'ta public elemanlar	> derived class'ta public olur
				- protected > protected
				- private	> asla erişilemez
		- protected:
			* üyelere erişim şu şekilde olur
				- public	> protected
				- protected > pretected
				- private	> asla erişilemez
		- private:
			* üyelere erişim şu şekilde olur
				- public	> private
				- protected > private
				- private	> asla erişilemez

*/