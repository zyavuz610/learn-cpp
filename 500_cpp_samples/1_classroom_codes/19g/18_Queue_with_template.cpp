//--------------------------------------
/*
// templates -> typename kullanmadan
#include <iostream>
using namespace std;

int Min(int _num1, int _num2){
  return (_num1 < _num2)?_num1:_num2;
}
float Min(float _num1, float _num2){
  return (_num1 < _num2)?_num1:_num2;
}
int main() {
  cout << Min((float)10.2,15.4) << "\n";
}
*/
//-----------------------------------------
/*
// templates -> typename kullanarak
#include <iostream>
using namespace std;

template <typename Tip>
Tip Min(Tip _num1, Tip _num2){
  return (_num1 < _num2)?_num1:_num2;
}
int main() {
  cout << Min((float)10.2,(float)15.4) << "\n";
  cout << Min(10.2,15.4) << "\n";
  cout << Min(10,15) << "\n";
  cout << Min('a','B') << "\n";
  cout << Min(true,false) << "\n";
  cout << Min("fatih","Ozge") << "\n";
}
*/
//-----------------------------------------
// Queue with template
#include <iostream>
using namespace std;

template <class Type>
class Queue{
  public:
    Queue(int _size=10){
      size = _size;
      data = new Type[size];  // new Tip[size];
      fptr = 0;
      rptr = 0;
    }
    void push(Type/*Tip*/ _elm){  // boyut kontrolü yapmadık
      data[rptr] = _elm;
      rptr++;
    }
    Type/*Tip*/ pop(){           // boyut kontrolü yapmadık
      return data[fptr++];
    }
    void print(){
      for(int i=fptr;i<rptr;i++){
        cout<<data[i]<<", ";
      }
      cout<<endl;
    }
  protected:
    Type *data;  // Tip *data;
    int size;
    int fptr;
    int rptr;
};

int main() {
  Queue<string> oop;
  oop.push("kerem");
  oop.push("fatihx2");
  oop.push("Özge");
  oop.push("Serkan");
  oop.print();
  cout<<oop.pop()<<endl;

  Queue<int> q1(30);
  q1.push(3);
  q1.push(23);
  q1.push(45);
  q1.print();
}