#include <iostream>
using namespace std;
int main() {
  int    i, j=0, k; // i,j,k ismiyle kullanılabilen int türünde değişken tanımlanmıştır.
  i=5;
  j=-5;
  k=i*j;
  cout<<k<<endl;

  char   c='A', ch; // char tipi değiişkenler içerisinde 1 byte sayısal değer saklar ve ve bu deger ASCI kodudur. Değişken ASCI koduna karşılık gelen karakteri temsil eder.
  ch = 65;
  cout<<ch<<endl;

  /* örn:  ekrana klavyede bir karakter karşılığı olmayan sembol yazdır     */

  float  f, salary;  // reel sayı türünden değişkenler
  f = 2.0;
  salary = f*f + 8.5;
  cout<<salary<<endl;

  double d;
  d = -4.0;
  cout<<d*d<<endl;

  /*
  değişkenlere yaptıkları işi hatırlatıcı isimler verilmelidir.
  değişken isimleri büyük küçük harf duyarlıdır.
  değişken isimleri rakam ile başlayamaz.
  değişken isimleri özel karakterler içeremez.
  değişken isimleri anahtar kelimeler ile aynı olamaz.

  naming convention: camelCase, PascalCase, snake_case, kebab-case
    camelCase: 
      ilk kelime küçük harf, sonraki kelimeler büyük harfle başlar, 
      örneğin: camelCase, camelCaseVariable
    PascalCase: 
      ilk kelime büyük harf, sonraki kelimeler büyük harfle başlar, 
      örneğin: PascalCase, PascalCaseVariable
    snake_case, under_score: 
      kelimeler alt çizgi ile ayrılır, 
      örneğin: snake_case, snake_case_variable,
    kebab-case: 
      kelimeler tire ile ayrılır, 
      örneğin: kebab-case, kebab-case-variable, 
      C++ desteklemez, daha çok web programlama dillerinde (CSS) kullanılır
  */

}
