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

class Rectangle : public Shape {
    public:
        Rectangle(int w, int h):Shape(w, h) { }
        int getArea() {
            return width * height;
        }
        int getPerimeter() {
            return 2 * (width + height);
        }
};
int main(void) {
    Rectangle rect(10, 20);
    cout << "Rectangle area: " << rect.getArea() << endl;
    cout << "Rectangle perimeter: " << rect.getPerimeter() << endl;
    rect.setWidth(15);
    rect.setHeight(25);
    cout << "Rectangle area: " << rect.getArea() << endl;
    cout << "Rectangle perimeter: " << rect.getPerimeter() << endl;
   return 0;
}

