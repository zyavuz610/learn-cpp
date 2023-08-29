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
      cout<<"Yapıcı çalıştı\n";
      this->n=10;
      this->yer_ayir();
    }
    Classroom(int _n){
      // ...
      cout<<"Yapıcı 2 çalıştı\n";
      this->n = _n;
      this->yer_ayir();
    }
    
    inline void yaz(){
      cout<<"AS\tFN\tOrt\n";
      for(int i=0;i<n;i++){
        ort[i] = (as[i]+fn[i])/2.0;
        cout<<as[i]<<"\t"<<fn[i]<<"\t"<<ort[i]<<"\n";
      }
    }
    
    ~Classroom(){
      cout<<"Yıkıcı çalıştı\n";
      delete this->as;
      delete this->fn;
      delete this->ort;
    }
    friend void yaz2(Classroom *c);
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
    string ders;
    int n;
};
void yaz2(Classroom *c){
  cout<<"AS2\tFN2\tOrt2\n";
      for(int i=0;i<c->n;i++){
        c->ort[i] = (c->as[i]+c->fn[i])/2.0;
        cout<<c->as[i]<<"\t"<<c->fn[i]<<"\t"<<c->ort[i]<<"\n";
      }
}
int main() {
  
  Classroom c;
  Classroom *c2;
  c2 = new Classroom(4);
  c.yaz();
  //c2->yaz();
  yaz2(c2);
  delete c2;
  c2 = new Classroom[10];
  delete c2;

  /*
## bugün ne gördük
* dinamik bellek yönetimi, new, delete
* nesneye pointer, nesneyi fonksiyona parametre aktarma
* this işaretçisi
* nesne dizileri
* friend function
* inline function



  */
}