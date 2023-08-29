// https://repl.it/@ZaferYavuz1/191211b
/*
#include <iostream>
using namespace std;

int MyMax(int _a,int _b){
  return (_a > _b) ? _a : _b;
}

double MyMax(double _a,double _b){
  return (_a > _b) ? _a : _b;
}

int main() {
  int a=20,b=40;
  float x = 40.5,y=50.6;

  cout << "Max:"<<MyMax(a,b)<<"\n";
  cout << "Max:"<<MyMax(x,y)<<"\n";
}
*/
//-------------------------------------------------
/*
#include <iostream>
using namespace std;

template <typename MyType>
MyType MyMax(MyType _a,MyType _b){
  return (_a > _b) ? _a : _b;
}


int main() {
  int a=20,b=40;
  float x = 40.5,y=50.6;
  string name1 = "Ramin",name2="Merve";

  cout << "Max:"<<MyMax(a,b)<<"\n";
  cout << "Max:"<<MyMax(x,y)<<"\n";
  cout << "Max:"<<MyMax(name1,name2)<<"\n";

}
*/
//-------------------------------------------------
/*
#include <iostream>
using namespace std;

//----------------------------------------------------
// MyStack.h
template <class T>
class MyStack{
  public:
    MyStack(int _n=10);
    void push(T _x);
    T pop();
    void print();
    ~MyStack();
  protected:
    T *data;
    int ptr;
    int N;
};
//-----------------------------------------------------
// MyStack.cpp
template <class T>
MyStack<T>::MyStack(int _n){
  N = _n;
  ptr = 0;
  data = new T[N];
}

template <class T>
void MyStack<T>::push(T _x){
  data[ptr] = _x;
  ptr++;
}

template <class T>
T MyStack<T>::pop(){
  ptr--;
  return data[ptr];
}
template <class T>
void MyStack<T>::print(){
  for(int i=0;i<ptr;i++){
    cout<<data[i]<<" ";
  }
  cout<<endl;
}
template <class T>
MyStack<T>::~MyStack(){
  delete []data;
}
//-----------------------------------------------------

struct RGB{
  int R;
  int G;
  int B;
};
int main() {
  int a=20,b=40;

}

*/