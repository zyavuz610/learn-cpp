#include <iostream>
using namespace std;

class myComplex {
  public:
    myComplex();
    myComplex(int _Real, int _Imag);
    void setReal(int _Real);
    void setImag(int _Imag);
    int getReal();
    int getImage();
    myComplex operator+(const myComplex& c);
    myComplex operator-(const myComplex& c);
    myComplex operator*(int deger);
    void print();
    ~myComplex();
  private:
    int Real, Imag, a;
};
