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

class Triangle: public Shape {     // Derived class
   public:
      int getArea() { 
         return (width * height)/2; 
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
//---------------------------
/*
çıktı
	Total area: 35

*/
