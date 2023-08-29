#include <iostream>
using namespace std;

class Shape{
  public:
    Shape(int _h=0,int _w=0){
      setWidthHeight(_h, _w);
      cout<<"Shape ctor\n";
    }
    void setWidthHeight(int _h=0,int _w=0){
      height  = _h;
      width   = _w;
    }
    void getWidthHeight(int &_h,int &_w){
      _h = height;
      _w = width;
    }
    ~Shape(){
      cout<<"Shape dtor\n";
    }
  protected:
    int height;
    int width;
};

class Rectangle:public Shape{
  public:
    Rectangle(int _h=0,int _w=0):Shape(_h,_w){
     // height  = _h;
     // width   = _w;
     cout<<"Rectangle ctor\n";
    }
    double getArea(){
      return width * height;
    }
    ~Rectangle(){
      cout<<"Rectangle dtor\n";
    }
    // setWidthHeight(...)
    // getWidthHeight(...)
  protected:
    // height, width, miras olarak alnıyor

  private:

};

int main() {
  Rectangle r(10,20);
  cout << "Area:" << r.getArea() << "\n";
  r.setWidthHeight(15, 20);
  cout << "Area:" << r.getArea() << "\n";
  return 0;
}