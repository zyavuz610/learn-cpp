#include <iostream>

using namespace std;

class MyClass {
  public:
    MyClass(){
      cout<<"non-parametric cstor is working\n";
      this->a = 0;
      this->b = 0;
    }
    MyClass(int a, int b=10){
      cout<<"parametric cstor is working\n";
      this->a = a;
      this->b = b;    
    }
    void setA(int a){ this->a = a;}
    void setB(int b){ this->b = b;}
    int getA(){ return this->a; }
    int getB(){ return this->b; }
    void print(){
      cout<<"(a,b)=("<<a<<","<<b<<")\n";
    }
    ~MyClass(){
      cout<<"dstor is working, good bye...\n";
    }
  private:
    int a;
    int b;
};

int main(){
  /*
  int a; a = 10;
  cout<<"a:"<<a<<endl;
  int b(20); // another way of the init
  int c = 30;
  cout<<"b:"<<b<<endl;
*/
  MyClass obj1; // default constructor
  
  {
    MyClass obj2(20,30);    
  } // dstor for obj2
  cout<<"---------------\n";
  MyClass * obj3 = new MyClass(40,50);
  int n = 5;
  string str = "bu bir yorumdur";
  cout<<str<<endl;
  
  delete obj3;
  cout<<"default parameter-----------\n";
  MyClass obj4, obj5(100), obj6(200,300);
  
  return 0;
  // dstor for obj1
}