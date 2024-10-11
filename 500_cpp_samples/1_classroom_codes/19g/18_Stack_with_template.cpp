#include <iostream>
using namespace std;

//------------------------------------------
// template kullanmadan
/*
int Max(int _num1,int _num2){
  if(_num1 > _num2){
    return _num1;
  }
  else{
    return _num2;
  }
  // return (_num1>_num2)?_num1:_num2;
}
float Max(float _num1,float _num2){
  // 2. yazım şekli
  return (_num1>_num2)?_num1:_num2;
}
int main() {
  cout << Max((float)5.0,(float)6.2) << "\n";
}
*/
//----------------------------------------------
// template kullanarak
/*
template <typename Tip>
Tip Max(Tip _num1,Tip _num2){
  return (_num1 > _num2)?_num1:_num2;
}
int main() {
  cout << Max("ali","ayse") << "\n";
}
*/
//----------------------------------------------
// class template
template <class Tip>
class Stack{
  public:
    Stack(int _size=10){
      size = _size;
      data = new Tip[size]; // new Tip[size];
      ptr = 0;
    }
    void push(Tip _elm){ // Tip _elm
      data[ptr] = _elm;
      ptr++;
      if(ptr>=size) ptr=size-1;
    }
    Tip pop(){
      if(ptr>0) ptr--;
      return data[ptr];
    }
    void resize(int _newsize){
      Tip *newdata;
      newdata = new Tip[_newsize];
      if(size < _newsize){
        for(int i=0;i<ptr;i++){
          newdata[i] = data[i];
        }
      }
      else{ // ????? bu kısım hatalı olabilir???
        for(int i=0;i<size;i++){
          newdata[i] = data[i];
        }
        ptr = size;
      }
      Tip *temp = data;
      data = newdata;
      delete [] temp;
      size = _newsize;
    }
    void print(){
      for(int i=ptr-1;i>=0;i--){
        cout<<data[i]<<", ";
      }
      cout<<endl;
    }
  protected:
    Tip *data;  // Tip *data;
    int size;
    int ptr;
};

int main(){
  Stack<char> s_char(20);
  s_char.push('A');
  s_char.push('B');
  s_char.push('C');
  s_char.push('D');
  s_char.print();

  Stack<string> ss;
  ss.push("Erdem");
  ss.push("Hüseyin");
  ss.push("Anıl");
  ss.push("Taha");
  ss.push("Gizem");
  ss.print();
  ss.pop();
  ss.print();
  ss.resize(20);
  ss.pop();
  ss.print();
  return 0;
}