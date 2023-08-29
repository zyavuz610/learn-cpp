/*

operator overloading example

*/

#include "myComplex.h"

int main() {
  myComplex c1(3,5),c2,c3;  // c2 = c3 = 0 + 0i
                            // c1 = 3 + 5i
  c2.setReal(2);
  c2.setImag(3);            // c2 = 2 + 3i
  c3 = c1 + c2;
  c3.print();               // c3 = 5 + 8i
  c3 = c1 - c2;
  c3.print();               // c3 = 1 + 2i
  //c3 = c1 - 2 * c2;
  c3 = c2 * 2;
  c3 = c1 - c3;
  c3.print();               // c3 = -1 - i
  c2.setReal(3);            // c2 = 3 + 3i
  c3 = c1 - c2;             // c3 = 2i
  c3.print();               
  cout<<"Real:"<<c3.getReal()<<", Imag:"<<c3.getImage()<<endl;
                            // Real:0, Image:2
}
/* *************************************************
   *Written by :  Nurullah Demirci
   *Department :  Computer Engineering <--> 2. Education
   *Number     :  244037
   *GSM        :  +90 531 356 0256
************************************************ */
