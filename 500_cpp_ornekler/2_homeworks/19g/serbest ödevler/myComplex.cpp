#include "myComplex.h"

myComplex::myComplex(){
  Real = 0;
  Imag = 0;
}
myComplex::myComplex(int _Real, int _Imag){
  Real = _Real;
  Imag = _Imag;
}
void myComplex::setReal(int _Real){
  Real = _Real;
}
void myComplex::setImag(int _Imag){
  Imag = _Imag;
}
int myComplex::getReal(){
  return Real;
}
int myComplex::getImage(){
  return Imag;
}
myComplex myComplex::operator+(const myComplex& c){
  myComplex obj;
  obj.Real = this->Real + c.Real;
  obj.Imag = this->Imag + c.Imag;
  return obj;
}
myComplex myComplex::operator-(const myComplex& c){
  myComplex obj;
  obj.Real = this->Real - c.Real;
  obj.Imag = this->Imag - c.Imag;
  return obj;
}
myComplex myComplex::operator*(int deger){
  myComplex obj;
  obj.Real = Real * deger;
  obj.Imag = Imag * deger;
  return obj;
}
void myComplex::print(){
  if(Real == 0 && Imag == -1)
    cout << " - i\n";
  else if(Real == 0 && Imag == 1)
    cout << " i\n";
  else if(Real == 0 && Imag < -1)
    cout << " - " << -1*Imag << "i\n";
  else if(Real == 0 && Imag > 1)
    cout << Imag << "i\n";
  else if(Real != 0 && Imag == -1)
    cout << Real <<  " - i\n";
  else if(Real != 0 && Imag == 1)
    cout << Real << " + i\n";
  else if(Imag < -1)
    cout << Real << "-" << -1*Imag << "i\n";
  else if(Imag == 0)
    cout << Real << "\n";
  else if(Imag > 1)
    cout << Real << " + " << Imag << "i\n";
  else
    cout << Real << " + " << Imag << "i\n";
}
myComplex::~myComplex(){
  //cout << "\n***Yıkıcı Çalıştı***";
}
