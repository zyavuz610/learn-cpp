/*
# Operator Overloading
## Neden Gerekli?
   * bilinen operatörklerin nesneler için de çalışmasını sağlamak için kullanılır
   * Örn; Complex c1,c2;
   * c1 = c1 + c2;  
   * saat bilgilerinin farkının için operator overloading gerekli
   * benzer şekilde
      * komplex sayı toplanması
      * saat karşılaştırma
      * alan farkı vb..
   * operator anahtar kelimesi kullanılır
   * şu operatorler aşırı yüklenemz
      .   ::   ?:   sizeof
   * şu operatörler aşırı yüklenebilir
   * +, -, ++, *, /, <<, (), [], vd...
//------------------------------------------------------------   
aşırı yükleme, member funk. ya da friend func olarak tanımlanabilir
operatör AŞIRI YÜKLEME - friend funcion vs. member function
member func.
   "s1 + s2" ifadesi "s1.operator+(s2)" haline dönüşür. 
   Bu şu demek, fonk. ilk objenin alt fonk. olarak çağrılır.
friend func.
   * ancak s1 + s2 de ilk operand obje değilse problem oluşur.
   * 10 + s1, ya da s1 + 10 ifadeleri hata verir
   * s1 + 10 ifadesi aşırı yükleme ile düzeltilebilir
   * ancak yine de private elamanlara erişecek şekilde friend func. tanımlanarak problem çözülür,
   * aşağıda <<, >> kısmında örnek mevcut, bakınız...
   
*/



*/
//---------------------------------------------------------------------
/*
Function Call Operator () Overloading in C++
   ()
*/

/*
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
      
      // overload function call
      Distance operator()(int a, int b, int c) {
         Distance D;
         
         // just put random calculation
         D.feet = a + c + 10;
         D.inches = b + c + 100 ;

         return D;
      }
      
      // method to display distance
      void displayDistance() {
         cout << "F: " << feet << " I:" << inches << endl;
      }   
};

int main() {
   Distance D1(11, 10), D2;

   cout << "First Distance : "; 
   D1.displayDistance();

   D2 = D1(10, 10, 10); // invoke operator()
   cout << "Second Distance :"; 
   D2.displayDistance();

   D2(10,30,50);

   return 0;
}
*/
//----------------------------------------------------------------------------------------------
/*
Subscripting [] Operator Overloading in C++
   []
*/

/*
#include <iostream>
using namespace std;
const int SIZE = 10;

class safearay {
   private:
      int arr[SIZE];
      
   public:
      safearay() {
         register int i;
         for(i = 0; i < SIZE; i++) {
           arr[i] = i;
         }
      }
      
      int & operator[](int i) {
         if( i > SIZE ) {
            cout << "Index out of bounds" <<endl; 
            // return first element.
            return arr[0];
         }
         
         return arr[i];
      }
};

int main() {
   safearay A;

   cout << "Value of A[2] : " << A[2] <<endl;
   cout << "Value of A[5] : " << A[5]<<endl;
   cout << "Value of A[12] : " << A[12]<<endl;

   return 0;
}
*/
