#include <iostream>
using namespace std;

class Shape{
  public:
    Shape(int _h=0,int _w=0){
      this->height  = _h;
      this->width   = _w;
      cout<<"Shape constructor\n";
    }
    void setHeightWidth(int _h=0,int _w=0){
      this->height  = _h;
      this->width   = _w;
    }
    void getHeightWidth(int &_h,int &_w){
      _h = height;
      _w = width;
    }
    ~Shape(){
      cout<<"Shape destructor\n";
    }
  protected:
    int height;
    int width;
};

class Triangle:public Shape{
  public:
    Triangle(int _h=0,int _w=0):Shape(_h,_w){
      cout<<"Triangle constructor\n";
    }
    double getArea(){
      return (height * width) / 2.0;
    }
    ~Triangle(){
      cout<<"Triangle destructor\n";
    }
    // bu fonksiyonlar üst sınıftan miras ile alınmıştır
    // setHeightWidth(..)
    // getHeightWidth(..)
  protected:
    // şu an için başka data tanımına gerek yok
    // height ve width, miras olarak alınıyor
  private:
};
int main() {
  Triangle t(6,10);
  t.setHeightWidth(15,7);
  cout << "Area: "<<t.getArea()<<"\n";
}