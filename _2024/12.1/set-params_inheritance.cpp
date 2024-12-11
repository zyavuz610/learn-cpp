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