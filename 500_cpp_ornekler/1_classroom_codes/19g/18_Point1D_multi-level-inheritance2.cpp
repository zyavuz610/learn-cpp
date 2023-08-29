#include <iostream>
#include <cmath>
using namespace std;

class Point1D{
  public:
    Point1D(double _x=0){
      x = _x;
    }
    void print(){
      cout << "(" << x 
           << ") --> "
           << getLen() << "\n";
    }
    double getLen(){
      return (x<0) ? -x : x;
    }
  protected:
    double x;
};

class Point2D:public Point1D{
  public:
    Point2D(double _x=0,double _y=0):Point1D(_x){
      //x = _x;  // üst class
      y = _y;
    }
    // mirastan print() geliyor
    // @override
    void print(){
      cout <<"("<< x <<","
           << y << ") "
           <<getLen() <<"\n";
    }

    // mirastan geliyor
    //@override
    double getLen(){
      return sqrt(x*x + y*y);
    }

  protected:
    double y;
    // double x; // mirastan gelen

};

class Point3D:public Point2D{
  public:
    Point3D(double _x=0,double _y=0,double _z=0):Point2D(_x,_y){
      z = _z;
    }
  // mirastan print() geliyor
    // @override
    void print(){
      cout <<"("<< x <<","
           << y <<","<<z<<") "
           << getLen() << "\n";
    }
    // mirastan geliyor
    //@override
    double getLen(){
      return sqrt(x*x + y*y + z*z);
    }
  protected:
    double z;
    // mirastan gelen
    // double x;
    // double y;
};

int main() {
  Point3D p3(3,4,5);
  Point1D p1(10);
  p1.print();
  p3.print();
  p3.Point1D::print();
  cout << "\n";
}