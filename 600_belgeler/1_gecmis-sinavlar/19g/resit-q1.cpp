#include<iostream>
using namespace std;
class myString{
    char *arr;
    int size;
  public:
    myString();
    myString(char *_str);
    void setString(char *_str);
    void upperCase();
    void lowerCase();
    friend void myPrint(myString &_str);
    myString operator+(myString &_myStr);
};
myString::myString(){
  char c[] = "Hello C++";
  setString(c);
}
myString::myString(char *_str){
  setString(_str);
}
void myString::setString(char *_str){
  int i=0;
  while(_str[i] != 0) i++;
  size = i;
  arr = new char[size];
  for(int i=0;i<size;i++) arr[i] = _str[i];
}

void myString::upperCase(){
  for(int i=0;i<size;i++){
    if(arr[i] >= 'a' && arr[i] <= 'z'){
      arr[i] = arr[i] - ('a' - 'A');
    }
  }
}

myString myString::operator+(myString &_myStr){
  int nsize = _myStr.size + this->size;
  int i;
  char *temp = new char[nsize];
  for(i=0;this->arr[i]!=0;i++){
    temp[i] = this->arr[i];
  }
  cout<<i;
  for(int j=0;j<_myStr.size;j++,i++){
    temp[i] = _myStr.arr[j];
  }
  temp[i] = 0;
  return myString(temp);
}

void myString::lowerCase(){
  for(int i=0;i<size;i++){
    if(arr[i] >= 'A' && arr[i] <= 'Z'){
      arr[i] = arr[i] + ('a' - 'A');
    }
  }
  /*
  int i=0;
  while(i<size){
    if(arr[i] >= 'A' && arr[i] <= 'Z'){
      arr[i] = arr[i] + ('a' - 'A');
    }
    i++;
  }
  */
}

void myPrint(myString &_str){
  cout<<_str.arr<<endl;
}

int main() {
  char cstr[] = "Zafer";
  myString s1(cstr),s2;
  s1.upperCase();
  s2.lowerCase();
  myPrint(s1);
  myPrint(s2);
  myString s3 = s2 + s1;
  myPrint(s3);
  return 0;
}