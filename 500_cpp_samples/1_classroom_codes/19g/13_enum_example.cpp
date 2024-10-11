#include <iostream>
using namespace std;
enum mat{bos=0,mayin=-1};
int main() {
  int m[16][16]={0};
  m[8][8] = mayin;
  cout << m[8][7];
}