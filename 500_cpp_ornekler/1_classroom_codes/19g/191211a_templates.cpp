// https://repl.it/@ZaferYavuz1/191211a

//------------------------------------------------------
/*
#include <iostream>
using namespace std;

int MyMin(int _num1, int _num2){
  return (_num1 < _num2) ? _num1 : _num2;
}
char MyMin(char _num1, char _num2){
  return (_num1 < _num2) ? _num1 : _num2;
}
double MyMin(double _num1, double _num2){
  return (_num1 < _num2) ? _num1 : _num2;
}

int main() {
  cout << "Min:"<<MyMin(3,5)<<endl;
  cout << "Min:"<<MyMin(3.5,5.5)<<endl;
  cout << "Min:"<<MyMin('H','N')<<endl;
}
*/
//-----------------------------------------------
/*
#include <iostream>
using namespace std;

template <typename T>
T MyMin(T _num1, T _num2){
  return (_num1 < _num2) ? _num1 : _num2;
}

int main() {
  cout << "Min:"<<MyMin(3,5)<<endl;
  cout << "Min:"<<MyMin(3.5,5.5)<<endl;
  cout << "Min:"<<MyMin('H','N')<<endl;
  cout << "Min:"<<MyMin("Hüseyin","Zeynep")<<endl;
}
*/
//------------------------------------------------------

#include <iostream>
using namespace std;

class RGB{
  public:
    RGB(int _R=0,int _G=0,int _B=0);
    void setRGB(int _R=0,int _G=0,int _B=0);
    RGB getRGB();
    friend ostream & operator<<( ostream &output, const RGB &rgb );
  private:
    int R,G,B;
};

RGB::RGB(int _R,int _G,int _B){
  R = _R;
  G = _G;
  B = _B;
}

void RGB::setRGB(int _R,int _G,int _B){
  R = _R;
  G = _G;
  B = _B;
}
RGB RGB::getRGB(){
  return RGB(R,G,B);
}
ostream & operator<<( ostream &output, const RGB &rgb ){ 
  output << "(" << rgb.R << "," << rgb.G << "," <<rgb.B << ")";
  return output;            
} 
//-----------------------------------------------
// MyQueue.h
template <class T>
class MyQueue{
  public:
    MyQueue(int _n=10);
    void add(T _elm=0);
    T deque();
    void print();
    ~MyQueue();
  private:
    T* data;
    int N;
    int p1;
    int p2;
};
//---------------------------------------------------
// MyQueue.cpp
template <class T>
MyQueue<T>::MyQueue(int _n){
  N = _n;
  p1 = 0;
  p2 = 0;
  data = new T[N];
}
template <class T>
void MyQueue<T>::add(T _elm){
  data[p2] = _elm;
  p2++; 
}
template <class T>
T MyQueue<T>::deque(){
  T elm = data[p1];
  p1++;
  return elm;
}
template <class T>
void MyQueue<T>::print(){
  for(int i=p1;i<p2;i++){
    cout<<data[i]<<", ";
  }
  cout<<endl;
}
template <class T>
MyQueue<T>::~MyQueue(){
  delete []data;
}
//----------------------------------------------------
int main() {
  MyQueue<int> q1;
  q1.add(2);
  q1.add(3);
  q1.print();

  MyQueue<string> q2;
  q2.add("nurullah");
  q2.add("hüseyin");
  q2.add("hasan");
  q2.deque();
  q2.add("zeynep");
  q2.print();

  MyQueue<RGB> q3;
  q3.add(RGB(20,30,40));
  q3.add(RGB(200,130,140));
  q3.add(RGB(220,130,30));
  //q3.deque();
  q3.add(RGB(201,100,240));
  q3.print();
}