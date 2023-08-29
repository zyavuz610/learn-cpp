#include<iostream>
using namespace std;
#define PI 3.0
//-----------------------------------------------------------
// class declarations
class Shape{
    protected:
        double height;
        double width;
    public:
        Shape(double _height=0.,double _width=0.);
        virtual double getArea() = 0;
};
class Rectangle : public Shape{
    public:
        Rectangle(double _height=0.,double _width=0.);
        double getArea();
};
class Ellipse : public Shape{
    public:
        Ellipse(double _height=0.,double _width=0.);
        double getArea();
};
//-----------------------------------------------------------
// class implementations
Shape::Shape(double _height, double _width){
    height = _height;
    width  = _width;
}
Rectangle::Rectangle(double _height, double _width)
            :Shape(_height, _width){

            }

double Rectangle::getArea(){
    return height * width;
}
Ellipse::Ellipse(double _height, double _width)
            :Shape(_height, _width){

            }

double Ellipse::getArea(){
    return (height * width * PI)/4;
}
//-----------------------------------------------------------------
double getTotalArea(Shape *_ptr[],int _n){
    double sum = 0;
    for(int i=0;i<_n;i++){
        sum += _ptr[i]->getArea();
    }
    return sum;
}
//-----------------------------------------------------------------
int main(){
    Shape *ptr[5];
    Rectangle   r1(3.0,5.0);
    Rectangle   r2(3.5,4.0);
    Ellipse     e1(4.0,6.0);
    Ellipse     e2(4.0,7.0);
    ptr[0]=&r1; ptr[1]=&r2; ptr[2]=&e1; ptr[3]=&e2;
    double area = getTotalArea(ptr,4); 
    cout<<"Total Area: "<<area<<endl;
    return 0;
}