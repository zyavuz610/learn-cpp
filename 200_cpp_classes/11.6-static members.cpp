/*
	* static anahtar kelimesi ile tanımlanır
	* anlamı şudur:
		* class tan kaç adet obje üretilirse üretilsin static üyenin sadece 1 adet kopyası olur.
		yani statik üye sınıftan türeyen tüm nesneler için ortaktır.
      * class tan hiç nesne üretilmese de statik üyeler bellekte oluşur.
	* static değişken ilk yaratıldığında 0 değeri alır (herhangi bir initialize yapılmasa bile)
	* 
*/

//--------------------------------------------------------------------------------------
/*
#include <iostream>
 
using namespace std;

class Box {
   public:
      static int objectCount;
      
      // Constructor definition
      Box(double l = 2.0, double b = 2.0, double h = 2.0) {
         cout <<"Constructor called." << endl;
         length = l;
         breadth = b;
         height = h;
         
         // Increase every time object is created
         objectCount++;
      }
      double Volume() {
         return length * breadth * height;
      }
      
   private:
      double length;     // Length of a box
      double breadth;    // Breadth of a box
      double height;     // Height of a box
};

// Initialize static member of class Box
int Box::objectCount = 0;

int main(void) {
   Box Box1(3.3, 1.2, 1.5);    // Declare box1
   Box Box2(8.5, 6.0, 2.0);    // Declare box2

   // Print total number of objects.
   cout << "Total objects: " << Box::objectCount << endl;

   return 0;
}
*/

//-----------------------------------------------------------------------------------
/*
	Static fonksiyonlar
		* bir fonk. statik olarak tanımlanırsa class tan türeyen nesnelerden bağımsız bir fonksiyon olur (java da public static void main() gibi)
		* static olarak tanımlanan fonksiyon class tan herhangi bir nesne tanımlanmasa da çağırılabilir
			class_name::func();
		* static fonk. sadece static üyelere ve class dışındaki fonk. erişebilir,
         - class method ları statik değişken ve methodlara erişebilir.	
		* static fonk. larda this pointer kullanılmaz
		* static fonk. lar sınıftan obje türetilip türetilmediğini öğrenmek için kullanılabilir.
*/
#include <iostream>
 
using namespace std;

class Box {
   public:
      static int objectCount;
      
      // Constructor definition
      Box(double l = 2.0, double b = 2.0, double h = 2.0) {
         cout <<"Constructor called." << endl;
         length = l;
         breadth = b;
         height = h;

         // Increase every time object is created
         objectCount++;
      }
      double Volume() {
         return length * breadth * height;
      }
      static int getCount() {
         return objectCount;
      }
      
   private:
      double length;     // Length of a box
      double breadth;    // Breadth of a box
      double height;     // Height of a box
};

// Initialize static member of class Box
int Box::objectCount = 0;

int main(void) {
   // Print total number of objects before creating object.
   cout << "Inital Stage Count: " << Box::getCount() << endl;

   Box Box1(3.3, 1.2, 1.5);    // Declare box1
   Box Box2(8.5, 6.0, 2.0);    // Declare box2

   // Print total number of objects after creating object.
   cout << "Final Stage Count: " << Box::getCount() << endl;

   return 0;
}
