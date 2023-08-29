#include <iostream>
using namespace std;

class Point1D{
  public:
    Point1D(int _x=0){
      x = _x;
    }
    void setX(int _x){
      x = _x;
    }
    int getX(){
      return x;
    }
    int getLen(){
      return (x<0) ? -x : x;
    }

  protected:
    int x;
};

class Point2D:public Point1D{
  public:
    Point2D(int _x=0,int _y=0):Point1D(_x){
      y = _y;
      //x = _x;
      //setX(_x);
    }
    void setXY(int _x,int _y){
      y = _y;
      setX(_x);
    }
    void getXY(int &_x,int &_y){
      _y = y;
      _x = getX();
    }

    // @override
    int getLen(){
      int yLen = (y<0)?-y:y;
      return y + Point1D::getLen();
    }

  protected:
    // int x;
    int y;
  private:
};

class Point3D:public Point2D{
  public:
    Point3D(int _x=0,int _y=0, int _z=0):Point2D(_x,_y){
      z = _z;
    }
    void setXYZ(int _x,int _y, int _z){
      z = _z;
      setXY(_x,_y);
    }
    void getXYZ(int &_x,int &_y, int &_z){
      _z = z;
      int _xx,_yy;
      getXY(_xx,_yy);
      _y = _yy;
      _x = _xx;
    }
    int getLen(){
      int zLen = (z<0)?-z:z;
      return z + Point2D::getLen();
    }
  
  protected:
    // int x;
    // { int y}
    int z;

  // erişilemeyen  
};

int main() {
  Point3D p2(3,4,5);
  cout << p2.getLen();
}