#include <iostream>
using namespace std;

class Box {
   public:
      double getVolume(void) {
         return length * breadth * height;
      }
      void setLength( double len ) {
         length = len;
      }
      void setBreadth( double bre ) {
         breadth = bre;
      }
      void setHeight( double hei ) {
         height = hei;
      }
      
      // Overload + operator to add two Box objects.
      // Box3 = (Box1 + Box2); // Box1.operator+(Box2) gibi bir anlam taşır
      Box operator+(const Box& b) {
         Box box;
         box.length = this->length + b.length;
         box.breadth = this->breadth + b.breadth;
         box.height = this->height + b.height;
         return box;
      }
      
   private:
      double length;      // Length of a box
      double breadth;     // Breadth of a box
      double height;      // Height of a box
};

// Main function for the program
int main() {
   Box Box1;                // Declare Box1 of type Box
   Box Box2;                // Declare Box2 of type Box
   Box Box3;                // Declare Box3 of type Box
   double volume = 0.0;     // Store the volume of a box here
 
   // box 1 specification
   Box1.setLength(6.0); 
   Box1.setBreadth(7.0); 
   Box1.setHeight(5.0);
 
   // box 2 specification
   Box2.setLength(12.0); 
   Box2.setBreadth(13.0); 
   Box2.setHeight(10.0);
 
   // volume of box 1
   volume = Box1.getVolume();
   cout << "Volume of Box1 : " << volume <<endl;
 
   // volume of box 2
   volume = Box2.getVolume();
   cout << "Volume of Box2 : " << volume <<endl;

   // Add two object as follows:
   Box3 = Box1 + Box2;

   // volume of box 3
   volume = Box3.getVolume();
   cout << "Volume of Box3 : " << volume <<endl;

   return 0;
}

/*
2 operand alan aritmetik operatorler de aynı şekilde aşırı yüklenebilir.
operator+(const Box& b) fonksiyonu, Box sınıfının iki nesnesini toplamak için aşırı yüklenmiştir.
Box3 = Box1 + Box2; // Box1.operator+(Box2) gibi bir anlam taşır

operator-(const Box& b) gibi fonksiyonlar, Box sınıfının iki nesnesini çıkarmak için aşırı yüklenebilir.
örneğin, Box3 = Box1 - Box2; // Box1.operator-(Box2) gibi bir anlam taşır

operator/(const Box& b) gibi fonksiyonlar, Box sınıfının iki nesnesini bölmek için aşırı yüklenebilir.
örneğin, Box3 = Box1 / Box2; // Box1.operator/(Box2) gibi bir anlam taşır

operator*(const Box& b) gibi fonksiyonlar, Box sınıfının iki nesnesini çarpmak için aşırı yüklenebilir.
örneğin, Box3 = Box1 * Box2; // Box1.operator*(Box2) gibi bir anlam taşır

operator%(const Box& b) gibi fonksiyonlar, Box sınıfının iki nesnesini mod almak için aşırı yüklenebilir.
örneğin, Box3 = Box1 % Box2; // Box1.operator%(Box2) gibi bir anlam taşır

operator+=(const Box& b) gibi fonksiyonlar, Box sınıfının iki nesnesini toplayıp, sonucu ilk nesneye atamak için aşırı yüklenebilir.
örneğin, Box1 += Box2; // Box1.operator+=(Box2) gibi bir anlam taşır

operator-=(const Box& b) gibi fonksiyonlar, Box sınıfının iki nesnesini çıkarıp, sonucu ilk nesneye atamak için aşırı yüklenebilir.
örneğin, Box1 -= Box2; // Box1.operator-=(Box2) gibi bir anlam taşır

operator*=(const Box& b) gibi fonksiyonlar, Box sınıfının iki nesnesini çarparak, sonucu ilk nesneye atamak için aşırı yüklenebilir.
örneğin, Box1 *= Box2; // Box1.operator*=(Box2) gibi bir anlam taşır

operator/=(const Box& b) gibi fonksiyonlar, Box sınıfının iki nesnesini böler, sonucu ilk nesneye atamak için aşırı yüklenebilir.
örneğin, Box1 /= Box2; // Box1.operator/=(Box2) gibi bir anlam taşır
*/