

//-------------------------------------------------------------------------------
/*
	parametrelere ilk değer atama
	base class'ın "parametreli yapıcı fonksiyonunu çağırma"
	çoklu miras
*/


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
      void print(){
         cout<<"width: "<<width<<", height: "<<height<<endl;
      }
      
   protected: // private olursa derived class erişemez
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
      void print(){ // override
         //Shape::print();
         cout<<"width: "<<width<<", height: "<<height<<endl;
         cout<<"Area: "<<getArea()<<endl;
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



//=================================================================================
/*
		Access Control and Inheritance (Erişim Kontrolü ve Miras),
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