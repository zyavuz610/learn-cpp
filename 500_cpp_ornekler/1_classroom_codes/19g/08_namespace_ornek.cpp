//http://bit.do/fayED
//https://repl.it/@ZaferYavuz1/191008a
#include <iostream>
//using namespace std;
// first name space
int year;
int getCentury(){
  return year/100;
}

namespace first_space {
    int year;
    int getCentury(){
      return year/100 + 1;
    }
     void func() {
      std::cout << "Inside first_space" << std::endl;
   }
    // second name space
    namespace second_space {
        int year;
        int getCentury(){
          return (year%100==0)?year/100:year/100 + 1;
        }
      void func() {
          std::cout << "Inside second_space" << std::endl;
      }
    }
}
int main () {
   // Calls function from first name space.
   //using namespace first_space;
   first_space::func();
   
   // Calls function from second name space.
   first_space::second_space::func();

   year = 1900;
   std::cout<<"Global:\t"
            <<year<<":"
            <<getCentury()
            <<std::endl;

   first_space::year = 1900;
   std::cout<<"First:\t"
            <<first_space::year<<":"
            <<first_space::getCentury()
            <<std::endl;

   first_space::second_space::year = 1900;
   std::cout<<"Second:\t"
            <<first_space::second_space::year<<":"
            <<first_space::second_space::getCentury()
            <<std::endl;


   return 0;
}