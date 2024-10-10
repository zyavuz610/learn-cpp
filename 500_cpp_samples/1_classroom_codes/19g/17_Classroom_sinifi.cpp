// https://repl.it/@ZaferYavuz1/191018c
/*
  * HBN: ham başarı notu, as ve fn ortalaması
    * HBN botu 15 ve altı hesaplamaya katılmaz
  * HBN notunun ortalamama ve standart sapması bulunur (sınıf için)
  * T notu hesapla (her öğrenci için 1 tane) 
    * T = ((HBN - HBNort)/HBNstd)*10 + 50
  * Tablo 1,2,3 e göre harfli not hesaplanır
  * Kaynak: http://www.ktu.edu.tr/dosyalar/08_00_00_f6570.pdf
*/
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

class Classroom{
  public:
    Classroom(){
      // 10 tane öğrenci olsun
      n=10;
      yer_ayir();
    }
    Classroom(int _n){
      // ...
      n = _n;
      yer_ayir();
    }
    void yaz(){
      cout<<"AS\tFN\tOrt\n";
      for(int i=0;i<n;i++){
        ort[i] = (as[i]+fn[i])/2.0;
        cout<<as[i]<<"\t"<<fn[i]<<"\t"<<ort[i]<<"\n";
      }
    }
  private:
    void yer_ayir(){
      as = new int[n];
      fn = new int[n];
      ort = new float[n];
      srand (time(NULL));
      for(int i=0;i<n;i++){
        as[i] = rand()%100 +1;
        fn[i] = rand()%100 +1;
      }

    }
    int *as;
    int *fn;
    float *ort;
    int n;
};

int main() {
  Classroom c(40);
  c.yaz();
}