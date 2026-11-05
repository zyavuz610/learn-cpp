#include <iostream>
using namespace std;

class MyClass {
  public:
    MyClass(string name_ = "NULL", double value_=0.0){
      this->name = name_;
      this->value = value_;    
      cout<< this
        
        
        
        
        ->name <<"-> parametric cstor is called\n";
    }
    void print(){
      cout<<this->name <<": "<<this->value<<"\n";
    }
    ~MyClass(){
      cout<<this->name << "-> dstor is called, good bye...\n";
    }
  private:
    string name;
    double value;
};

int main(){
  // Ödev
  /*
  Coord c1, c2(3,4,"Point 2");
  Coord c3(5,12);
  cout<< c3.abs();
  c1.add(2,3);
  c2.sub(1,2);
  c3.add(c1);
  // bu 4 metodu içeren Coord class ını yazın
  */
  return 0;
}