/* 
Unary (Tekli) Operators Overloading in C++
   The increment (++) and decrement (--) operators.
   The unary minus (-) operator.
   The logical not (!) operator.
Kullanım şekli
   !obj, -obj, ++obj, --obj, (bazı durumlarda: obj++, obj-- kullanılabilir <postfix>)
*/

#include <iostream>
using namespace std;
 
class Distance {
   private:
      int feet;             // 0 to infinite
      int inches;           // 0 to 12
      
   public:
      // required constructors
      Distance() {
         feet = 0;
         inches = 0;
      }
      Distance(int f, int i) {
         feet = f;
         inches = i;
      }
      
      // method to display distance
      void displayDistance() {
         cout << "F: " << feet << " I:" << inches <<endl;
      }
      
      // overloaded minus (-) operator
      // d1 = -d; // d1 = d.operator-()
      Distance operator- () {
         feet = -feet;
         inches = -inches;
         return Distance(feet, inches);
         //----------
         Distance d;
         d.feet = -feet;
         d.inches = -inches;
         return d;
         
      //   Distance d;
      //   d.feet = -feet;
      //   d.inches = -inches;
      //   return d;
         
      }
};

int main() {
   Distance D1(11, 10), D2(-5, 11);
 
   -D1;                     // apply negation
   D1.displayDistance();    // display D1

   -D2;                     // apply negation
   D2.displayDistance();    // display D2

   return 0;
}

/*
operator-() fonksiyonu, Distance sınıfının bir üyesi olarak tanımlanmıştır. Bu fonksiyon, Distance sınıfının bir nesnesini negatif yapar.
örneğin, -D1; ifadesi, D1 nesnesini negatif yapar. Bu ifade, D1.operator-() fonksiyonunu çağırır.

operator++(), operator--(), operator!() gibi diğer tekli operatörler de aynı şekilde tanımlanabilir.

operator++ (), operator-- (), operator! (): prefix form, ++t, --t, !t
operator++ (int), operator-- (int): postfix form, t++, t--, 
    (int) ifadesi, sadece bir formalitedir ve fonksiyonun aşırı yüklenmesinde bir rol oynamaz.
*/