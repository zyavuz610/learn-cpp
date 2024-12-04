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

//--------------------------------------------------------------------
/*
Relational Operators Overloading in C++
   <, >, <=, >=, ==, etc.
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
      
      // method to display distance
      void displayDistance() {
         cout << "F: " << feet << " I:" << inches <<endl;
      }
      
      // overloaded minus (-) operator
      Distance operator- () {
         feet = -feet;
         inches = -inches;
         return Distance(feet, inches);
      }
      
      // overloaded < operator
      bool operator <(const Distance& d) {
         if(feet < d.feet) {
            return true;
         }
         if(feet == d.feet && inches < d.inches) {
            return true;
         }
         
         return false;
      }
};

int main() {
   Distance D1(11, 10), D2(5, 11);
 
   if( D1 < D2 ) {
      cout << "D1 is less than D2 " << endl;
   } else {
      cout << "D2 is less than D1 " << endl;
   }
   
   return 0;
}
*/
//-------------------------------------------------------------------
/*
Input/Output Operators Overloading in C++
   <<, >>
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
      // ofstream ofile --> ostream türünden nesne
      // cout --> ostream
      friend ostream & operator<<( ostream &output, const Distance &D ) { 
         output << "F : " << D.feet << " I : " << D.inches;
         return output;            
      }

      // Kullanımı:
      // Distance d(1,2);
      // cout<<d;

      friend istream &operator>>( istream  &input, Distance &D ) { 
         input >> D.feet >> D.inches;
         return input;            
      }

      // Kullanımı
      // Distance d;
      // cin>>d;
};

int main() {
   Distance D1(11, 10), D2(5, 11), D3;

   cout << "Enter the value of object : " << endl;
   cin >> D3;
   cout << "First Distance : " << D1 << endl;
   cout << "Second Distance :" << D2 << endl;
   cout << "Third Distance :" << D3 << endl;

   return 0;
}
*/
//---------------------------------------------------------------------------------
/*
## Overloading Increment ++ & Decrement --
   * ++, --
   * Kullanımı: 
   Time t(13,20);
   t++;  --> postfix kullanım
   ++t;   --> normal kullanım
*/

/*
#include <iostream>
using namespace std;
 
class Time {
   private:
      int hours;             // 0 to 23
      int minutes;           // 0 to 59
      
   public:
      // required constructors
      Time() {
         hours = 0;
         minutes = 0;
      }
      Time(int h, int m) {
         hours = h;
         minutes = m;
      }
      
      // method to display time
      void displayTime() {
         cout << "H: " << hours << " M:" << minutes <<endl;
      }
      
      // overloaded prefix ++ operator, ++t
      Time operator++ () {
         ++minutes;          // increment this object
         if(minutes >= 60) {
            ++hours;
            minutes -= 60;
         }
         return Time(hours, minutes);
      }
      
      // overloaded postfix ++ operator
      // t++;
      Time operator++( int ) {
      
         // save the orignal value
         Time T(hours, minutes);
         
         // increment this object
         ++minutes;                    
         
         if(minutes >= 60) {
            ++hours;
            minutes -= 60;
         }
         // return old original value
         return T; 
      }
};

int main() {
   Time T1(11, 59), T2(10,40);
 
   ++T1;                    // increment T1
   T1.displayTime();        // display T1
   ++T1;                    // increment T1 again
   T1.displayTime();        // display T1
 
   T2++;                    // increment T2
   T2.displayTime();        // display T2
   T2++;                    // increment T2 again
   T2.displayTime();        // display T2
   return 0;
}
*/
//---------------------------------------------------------------------------------
/*
Assignment Operators Overloading in C++
   =
   obj = obj2;
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
      void operator = (const Distance &D ) { 
         feet = D.feet;
         inches = D.inches;
      }
      
      // method to display distance
      void displayDistance() {
         cout << "F: " << feet <<  " I:" <<  inches << endl;
      }
};

int main() {
   Distance D1(11, 10), D2(5, 11);

   cout << "First Distance : "; 
   D1.displayDistance();
   cout << "Second Distance :"; 
   D2.displayDistance();

   // use assignment operator
   D1 = D2;
   cout << "First Distance :"; 
   D1.displayDistance();

   return 0;
}
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
