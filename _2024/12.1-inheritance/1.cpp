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
int main(void) {
   Shape *shape;
   shape = new Shape(10, 20);
   cout << "Shape width: " << shape->getWidth() << endl;
   cout << "Shape height: " << shape->getHeight() << endl;
   shape->setWidth(15);
   shape->setHeight(25);
   cout << "Shape width: " << shape->getWidth() << endl;
   cout << "Shape height: " << shape->getHeight() << endl;
   return 0;
}
