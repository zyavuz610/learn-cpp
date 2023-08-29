#include <iostream>

typedef struct Book{
  int a;
  int b;
} 
tams;

tams b1[100];

int year = 1900;
int getCentury(){
  return year/100;
}
namespace std{
  int year = 1917;
  int getCentury(){
    return year/100 + 1;
  }
  namespace second{
    int year = 1909;
    int getCentury(){
      //return (year+99)/100;
      return (year%100==0)?year/100:year/100+1;
    }
  }
  void print(std::string cout){
    std::cout<<cout<<std::endl;
  }
}

int main() {
  std::cout <<"Global:\t"<<year<<":"
            <<getCentury()<<std::endl;
  
  std::cout <<"First:\t"<<std::year<<":"
            <<std::getCentury()<<std::endl;
  
  std::cout <<"Global:\t"<<std::second::year<<":"
            <<std::second::getCentury()<<std::endl;

  std::print("Merhaba KTÜ!");
}