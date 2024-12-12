#include <iostream>
using namespace std;

class Shape {                       // Base class
   public:
      Shape() {
         width = 0;
         height = 0;
      }
      Shape(int w, int h) {
         width = w;
         height = h;
      }
      void setWidth(int w) {
         width = w;
      }
      void setHeight(int h) {
         height = h;
      }
      int getWidth() {
         return width;
      }
      int getHeight() {
         return height;
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
   Shape *shape;
   shape = new Shape(10, 20);
   cout << "Shape width: " << shape->getWidth() << endl;
   cout << "Shape height: " << shape->getHeight() << endl;
   /*
   Rectangle Rect;
 
   Rect.setWidth(5);
   Rect.setHeight(7);
   // Print the area of the object.
   cout << "Total area of Rect: " << Rect.getArea() << endl;

   Triangle Tri;
    Tri.setWidth(5);
    Tri.setHeight(7);
    // Print the area of the object.
    cout << "Total area of Tri: " << Tri.getArea() << endl;
   */

   return 0;
}
//---------------------------
/*
çıktı
	Total area: 35

*/
