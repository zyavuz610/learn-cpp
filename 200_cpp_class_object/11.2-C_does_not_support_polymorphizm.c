#include <stdio.h>

int sum(int _a, int _b){
  return _a + _b;
}
/*
// C dilinde aşırı yükleme yok (polimorphizm yok)
// 2. bir fonk. tanımlamak HATA!!!
float sum(float _x, float _y){
  return _x + _y;
}
*/
int main(void) {
  printf("Toplam:%d\n",sum(6,3));
  return 0;
}