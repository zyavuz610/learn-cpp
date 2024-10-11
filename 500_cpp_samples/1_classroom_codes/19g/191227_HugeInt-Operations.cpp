#include <iostream>
#define N 100

using namespace std;

class HugeInt{
  public:
    HugeInt(string _initValue="0"){
      size = _initValue.length();
      int i,j;
      for(i=0;i<_initValue.length();i++){
        digits[i] = _initValue[size-i-1] - '0';
      }
      for(j=i;j<N;j++){
        digits[j] = 0;
      }
    }
    string toString(){
      string temp = "";
      for(int i=size-1;i>=0;i--){
        temp.push_back((char)(digits[i]+'0'));
      }
      return temp;
    }
    void print(){
      for(int i=size-1;i>=0;i--){
        cout<<digits[i];
      }
    }
    HugeInt operator+(HugeInt _param){
      HugeInt temp;
      int maxLen = (size>_param.size)?size:_param.size;
      int carry = 0;
      int t,i;
      for(i=0;i<maxLen+1;i++){
        t = digits[i] + _param.digits[i] + carry;
        temp.digits[i] = t % 10;
        carry = t / 10;
      }
        temp.size = (temp.digits[i-1])?maxLen + 1:maxLen;
      return temp;
    }
    HugeInt operator*(HugeInt _param){
      HugeInt temp;
      int maxLen = size + _param.size;
      int num, p = 1;
      for(int i=0;i<size;i++){
        num = digits[i] * p;
        p *= 10;
        for(int j=0;j<num;j++){
          temp = temp + _param;
        }
      }
      return temp;
      

      // 2. algoritma
      /*
        çarpma işlemi hızlandırılabilir
        burada hızlandırma kodu yazabilirsiniz.
      */

    }

  private:
    int digits[N];
    int size;
};

int main() {
  HugeInt h("999");
  HugeInt h1("297");
  cout<<h.toString()<<endl;
  h = h1 * h;
  // çıkarma işlemini siz yapın
  h.print();
}