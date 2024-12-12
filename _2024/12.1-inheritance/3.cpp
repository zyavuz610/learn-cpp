#include <iostream>
using namespace std;

class Shape {                       // Base class
   public:
      Shape() {
         width = 0;
         height = 0;
         cout<<"Shape constructor called"<<endl;
      }
      Shape(int w, int h) {
         width = w;
         height = h;
         cout<<"Shape constructor called"<<endl;
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
      ~Shape(){cout<<"Shape destructor called"<<endl;}
   protected:
      int width;
      int height;
};

class Rectangle : public Shape {
    public:
        Rectangle():Shape() { 
            cout<<"Rectangle constructor called"<<endl;
        }
        Rectangle(int w, int h):Shape(w, h) { 
            cout<<"Rectangle constructor called"<<endl;
        }
        int getArea() {
            return width * height;
        }
        int getPerimeter() {
            return 2 * (width + height);
        }
        ~Rectangle(){cout<<"Rectangle destructor called"<<endl;}
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

