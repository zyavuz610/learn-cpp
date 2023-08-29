/*

* HBN: ham başarı notu, as ve fn ortalaması
    * HBN botu 15 ve altı hesaplamaya katılmaz
  * HBN notunun ortalamama ve standart sapması bulunur (sınıf için)
  * T notu hesapla (her öğrenci için 1 tane) 
    * T = ((HBN - HBNort)/HBNstd)*10 + 50
  * Tablo 1,2,3 e göre harfli not hesaplanır, 
  * Kaynak: http://www.ktu.edu.tr/dosyalar/08_00_00_f6570.pdf

ortalama, standart sapma bulanların ve Tablo 3'e göre harfli nota çevirenlerin tamamına 1 puan vereceğim, diğer tablo kısımları çok uzunmuş, Tablo 1'i yapan 1 paun, Tablo 2 yi yapan 1 puan şeklinde puanlandıracağız. Toplamda 3 puanlık ödev. 

Not: Puanlar arasınav notuna eklenmek üzere verilmektedir.
*/

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
#include <math.h>
#include <iomanip>
#define N 30
using namespace std;

class Classroom{
  public:
    Classroom(){
      // default 10 tane öğrenci olsun
      n=10;
      yer_ayir();
    }
    Classroom(int _n){
      // dinamik sayıda öğrenci olsun
      n = _n;
      yer_ayir();
    }
    void setHBN();
    void setBagilHBN();
    void standartSapma();
    void tNotHesaplama();
    void tablo1();
    void tablo2();
    void tablo3();
    void yaz(){
      
      if(n < 11){
        cout << "Sınıf Ortalaması: " << fixed << setprecision(2) << HBN << endl;
        cout<<"AS\tFN\tHBN \tHarf Notu\n";
      }
      else if(n >= 11 && n < 30){
        cout << "Sınıf Ortalaması: " << fixed << setprecision(2) << HBN << endl;
        cout << "1 Öğrenci Oranı: " << fixed << setprecision(2) << 1.0/n*100.0 << endl;
        cout<<"AS\tFN\tHBN \tHarf Notu\n";
      }
      else if(n >= 30){
        cout << "Sınıf Ortalaması: " << fixed << setprecision(2) << HBN << endl;
        cout << "Sınıf Bağıl Ortalaması: " << fixed << setprecision(2) << bagilHBN << endl;
        cout << "Sınıf Standart Sapması: " << fixed << setprecision(2) << HBNstd << endl;
        cout<<"AS\tFN\tHBN \tT Notu \tHarf Notu\n";
      }
      else { }
      float r = 4.123456789;
      for(int i=0;i<n;i++){
        if(n < 11){
          cout  << as[i]
                << "\t" << fn[i]
                << "\t" << fixed << setprecision(2) << hbn[i]
                << "\t" << fixed << setprecision(2) << harfNotu[i]
                <<"\n";
        }
        else if(n >= 11 && n < 30){
          cout  << as[i]
                << "\t" << fn[i]
                << "\t" << fixed << setprecision(2) << hbn[i]
                << "\t" << fixed << setprecision(2) << harfNotu[i]
                <<"\n";
        }
        else if(n >= 30){
          cout  << as[i]
                << "\t" << fn[i]
                << "\t" << fixed << setprecision(2) << hbn[i]
                << "\t" << fixed << setprecision(2) << tNotu[i]
                << "\t" << fixed << setprecision(2) << harfNotu[i]
                <<"\n";
        }
        else { break; }
        
      }
    }
  private:
    void yer_ayir(){
      as = new int[n];
      fn = new int[n];
      hbn = new float[n];
      tNotu = new float[n];
      harfNotu = new string[n];
      srand (time(NULL));
      for(int i=0;i<n;i++){
        as[i] = rand()%100 +1;
        fn[i] = rand()%100 +1;
      }
      setHBN();
    }
    int *as;
    int *fn;
    float *hbn;
    float *tNotu;
    string *harfNotu;
    float HBN;//sınıf ortalaması
    float bagilHBN;//15 üstü sınıf ortalaması
    float HBNstd;
    int n;
};

int main() {
  Classroom c(N);
  if(N < 11) c.tablo3();
  else if(N >= 10 && N < 30) c.tablo2();
  else {
    c.setBagilHBN();
    c.standartSapma();
    c.tNotHesaplama();
    c.tablo1();
  }
  c.yaz();
  
}
//  * HBN: ham başarı notu, as ve fn ortalaması
void Classroom::setHBN(){
  HBN = 0.0;
  for(int i = 0; i < n; i++){
    hbn[i] = ((as[i] + fn[i]) / 2.0);
    HBN += hbn[i];
  }
  HBN /= n;
}
//   * Bağıl HBN notu ortalaması. 15 ve altı hesaplamaya katılmaz
void Classroom::setBagilHBN(){
  float _bagilHBN = 0.0;
  float counter = 0.0;
  for(int i = 0; i < n; i++){
    if(hbn[i] > 15){
      _bagilHBN += hbn[i];
      counter++;
    }
  }
  if(counter >= 1.0)
    bagilHBN =  _bagilHBN /= counter;
  else
    bagilHBN =  _bagilHBN;
}
//* HBN notu standart sapması. 15 ve altı hesaplamaya katılmaz (sınıf için)
void Classroom::standartSapma(){
  float _sS = 0.0;
  float _standartSapma = 0.0;
  float counter = 0.0;
  for(int i = 0; i < n; i++){
    if(hbn[i] > 15){
      //cout << endl << hbn[i];
      _sS = hbn[i] - bagilHBN;
      //cout << " -- " << _sS;
      _sS = _sS * _sS;
      //cout << " -- " << _sS;
      _standartSapma = _standartSapma + _sS;
      counter++;
    }
  }
  if(counter >= 2.0)
    _standartSapma /= (counter-1.0);

  //cout << endl << counter << endl << _standartSapma << endl << sqrt(_standartSapma);
  HBNstd = sqrt(_standartSapma);
}
//  * T notu hesapla (her öğrenci için 1 tane) 
//   * T = ((HBN - HBNort)/HBNstd)*10 + 50
void Classroom::tNotHesaplama(){
  for(int i = 0; i < n; i++){
    tNotu[i] = ((hbn[i] - bagilHBN)/HBNstd)*10 + 50;
  }
}
void Classroom::tablo3(){
  for(int i = 0; i < n; i++){
    if(fn[i] >= 45){
      if(hbn[i] >= 90.0 && hbn[i] <= 100.0){ harfNotu[i] = "AA"; }
      else if(hbn[i] >= 80.0 && hbn[i] <= 89.0){ harfNotu[i] = "BA"; }
      else if(hbn[i] >= 75.0 && hbn[i] <= 79.0){ harfNotu[i] = "BB"; }
      else if(hbn[i] >= 70.0 && hbn[i] <= 74.0){ harfNotu[i] = "CB"; }
      else if(hbn[i] >= 60.0 && hbn[i] <= 69.0){ harfNotu[i] = "CC"; }
      else if(hbn[i] >= 50.0 && hbn[i] <= 59.0){ harfNotu[i] = "DC"; }
      else if(hbn[i] >= 40.0 && hbn[i] <= 49.0){ harfNotu[i] = "DD"; }
      else if(hbn[i] >= 30.0 && hbn[i] <= 39.0){ harfNotu[i] = "FD"; }
      else if(hbn[i] >= 0.0 && hbn[i] <= 29.0){ harfNotu[i] = "FF"; }
      else harfNotu[i] = "K";
    }
    else
      harfNotu[i] = "FF";
  }
}
void Classroom::tablo1(){
  float d1 = 59.0, d2 = 54.0, d3 = 49.0, d4 = 44.0;
  float d5 = 39.0, d6 = 34.0, d7 = 29.0, d8 = 24.0;
  float r = 0.0;
  //cout << bagilHBN <<endl;
  for(int i = 0; i < n; i++){
    if(bagilHBN >= 80.0 && bagilHBN <= 100.0) tablo3();
    else if(bagilHBN > 70.0 && bagilHBN < 80.0){
      if(fn[i] >= 45){
        if(tNotu[i] >= d1+r && tNotu[i] <= 100.0){ harfNotu[i] = "AA"; }
        else if(tNotu[i] >= d2+r && tNotu[i] < d1+r){ harfNotu[i] = "BA"; }
        else if(tNotu[i] >= d3+r && tNotu[i] < d2+r){ harfNotu[i] = "BB"; }
        else if(tNotu[i] >= d4+r && tNotu[i] < d3+r){ harfNotu[i] = "CB"; }
        else if(tNotu[i] >= d5+r && tNotu[i] < d4+r){ harfNotu[i] = "CC"; }
        else if(tNotu[i] >= d6+r && tNotu[i] < d5+r){ harfNotu[i] = "DC"; }
        else if(tNotu[i] >= d7+r && tNotu[i] < d6+r){ harfNotu[i] = "DD"; }
        else if(tNotu[i] >= d8+r && tNotu[i] < d7+r){ harfNotu[i] = "FD"; }
        else if(tNotu[i] >= 0.0 && tNotu[i] <= d8+r){ harfNotu[i] = "FF"; }
        else harfNotu[i] = "K";
      }
      else harfNotu[i] = "FF";
    }
    else if(bagilHBN > 62.5 && bagilHBN <= 70.0){
      r = 2.0;
      if(fn[i] >= 45){
        if(tNotu[i] >= d1+r && tNotu[i] <= 100.0){ harfNotu[i] = "AA"; }
        else if(tNotu[i] >= d2+r && tNotu[i] < d1+r){ harfNotu[i] = "BA"; }
        else if(tNotu[i] >= d3+r && tNotu[i] < d2+r){ harfNotu[i] = "BB"; }
        else if(tNotu[i] >= d4+r && tNotu[i] < d3+r){ harfNotu[i] = "CB"; }
        else if(tNotu[i] >= d5+r && tNotu[i] < d4+r){ harfNotu[i] = "CC"; }
        else if(tNotu[i] >= d6+r && tNotu[i] < d5+r){ harfNotu[i] = "DC"; }
        else if(tNotu[i] >= d7+r && tNotu[i] < d6+r){ harfNotu[i] = "DD"; }
        else if(tNotu[i] >= d8+r && tNotu[i] < d7+r){ harfNotu[i] = "FD"; }
        else if(tNotu[i] >= 0.0 && tNotu[i] <= d8+r){ harfNotu[i] = "FF"; }
        else harfNotu[i] = "K";
      }
      else harfNotu[i] = "FF";
    }
    else if(bagilHBN > 57.5 && bagilHBN <= 62.5){
      r = 4.0;
      if(fn[i] >= 45){
        if(tNotu[i] >= d1+r && tNotu[i] <= 100.0){ harfNotu[i] = "AA"; }
        else if(tNotu[i] >= d2+r && tNotu[i] < d1+r){ harfNotu[i] = "BA"; }
        else if(tNotu[i] >= d3+r && tNotu[i] < d2+r){ harfNotu[i] = "BB"; }
        else if(tNotu[i] >= d4+r && tNotu[i] < d3+r){ harfNotu[i] = "CB"; }
        else if(tNotu[i] >= d5+r && tNotu[i] < d4+r){ harfNotu[i] = "CC"; }
        else if(tNotu[i] >= d6+r && tNotu[i] < d5+r){ harfNotu[i] = "DC"; }
        else if(tNotu[i] >= d7+r && tNotu[i] < d6+r){ harfNotu[i] = "DD"; }
        else if(tNotu[i] >= d8+r && tNotu[i] < d7+r){ harfNotu[i] = "FD"; }
        else if(tNotu[i] >= 0.0 && tNotu[i] <= d8+r){ harfNotu[i] = "FF"; }
        else harfNotu[i] = "K";
      }
      else harfNotu[i] = "FF";
    }
    else if(bagilHBN > 52.5 && bagilHBN <= 57.5){
      r = 6.0;
      if(fn[i] >= 45){
        if(tNotu[i] >= d1+r && tNotu[i] <= 100.0){ harfNotu[i] = "AA"; }
        else if(tNotu[i] >= d2+r && tNotu[i] < d1+r){ harfNotu[i] = "BA"; }
        else if(tNotu[i] >= d3+r && tNotu[i] < d2+r){ harfNotu[i] = "BB"; }
        else if(tNotu[i] >= d4+r && tNotu[i] < d3+r){ harfNotu[i] = "CB"; }
        else if(tNotu[i] >= d5+r && tNotu[i] < d4+r){ harfNotu[i] = "CC"; }
        else if(tNotu[i] >= d6+r && tNotu[i] < d5+r){ harfNotu[i] = "DC"; }
        else if(tNotu[i] >= d7+r && tNotu[i] < d6+r){ harfNotu[i] = "DD"; }
        else if(tNotu[i] >= d8+r && tNotu[i] < d7+r){ harfNotu[i] = "FD"; }
        else if(tNotu[i] >= 0.0 && tNotu[i] <= d8+r){ harfNotu[i] = "FF"; }
        else harfNotu[i] = "K";
      }
      else harfNotu[i] = "FF";
    }
    else if(bagilHBN > 47.5 && bagilHBN <= 52.5){
      r = 8.0;
      if(fn[i] >= 45){
        if(tNotu[i] >= d1+r && tNotu[i] <= 100.0){ harfNotu[i] = "AA"; }
        else if(tNotu[i] >= d2+r && tNotu[i] < d1+r){ harfNotu[i] = "BA"; }
        else if(tNotu[i] >= d3+r && tNotu[i] < d2+r){ harfNotu[i] = "BB"; }
        else if(tNotu[i] >= d4+r && tNotu[i] < d3+r){ harfNotu[i] = "CB"; }
        else if(tNotu[i] >= d5+r && tNotu[i] < d4+r){ harfNotu[i] = "CC"; }
        else if(tNotu[i] >= d6+r && tNotu[i] < d5+r){ harfNotu[i] = "DC"; }
        else if(tNotu[i] >= d7+r && tNotu[i] < d6+r){ harfNotu[i] = "DD"; }
        else if(tNotu[i] >= d8+r && tNotu[i] < d7+r){ harfNotu[i] = "FD"; }
        else if(tNotu[i] >= 0.0 && tNotu[i] <= d8+r){ harfNotu[i] = "FF"; }
        else harfNotu[i] = "K";
      }
      else harfNotu[i] = "FF";
    }
    else if(bagilHBN > 42.5 && bagilHBN <= 47.5){
      r = 10.0;
      if(fn[i] >= 45){
        if(tNotu[i] >= d1+r && tNotu[i] <= 100.0){ harfNotu[i] = "AA"; }
        else if(tNotu[i] >= d2+r && tNotu[i] < d1+r){ harfNotu[i] = "BA"; }
        else if(tNotu[i] >= d3+r && tNotu[i] < d2+r){ harfNotu[i] = "BB"; }
        else if(tNotu[i] >= d4+r && tNotu[i] < d3+r){ harfNotu[i] = "CB"; }
        else if(tNotu[i] >= d5+r && tNotu[i] < d4+r){ harfNotu[i] = "CC"; }
        else if(tNotu[i] >= d6+r && tNotu[i] < d5+r){ harfNotu[i] = "DC"; }
        else if(tNotu[i] >= d7+r && tNotu[i] < d6+r){ harfNotu[i] = "DD"; }
        else if(tNotu[i] >= d8+r && tNotu[i] < d7+r){ harfNotu[i] = "FD"; }
        else if(tNotu[i] >= 0.0 && tNotu[i] <= d8+r){ harfNotu[i] = "FF"; }
        else harfNotu[i] = "K";
      }
      else harfNotu[i] = "FF";
    }
    else if(bagilHBN >= 0.0 && bagilHBN <= 42.5){
      r = 12.0;
      if(fn[i] >= 45){
        if(tNotu[i] >= d1+r && tNotu[i] <= 100.0){ harfNotu[i] = "AA"; }
        else if(tNotu[i] >= d2+r && tNotu[i] < d1+r){ harfNotu[i] = "BA"; }
        else if(tNotu[i] >= d3+r && tNotu[i] < d2+r){ harfNotu[i] = "BB"; }
        else if(tNotu[i] >= d4+r && tNotu[i] < d3+r){ harfNotu[i] = "CB"; }
        else if(tNotu[i] >= d5+r && tNotu[i] < d4+r){ harfNotu[i] = "CC"; }
        else if(tNotu[i] >= d6+r && tNotu[i] < d5+r){ harfNotu[i] = "DC"; }
        else if(tNotu[i] >= d7+r && tNotu[i] < d6+r){ harfNotu[i] = "DD"; }
        else if(tNotu[i] >= d8+r && tNotu[i] < d7+r){ harfNotu[i] = "FD"; }
        else if(tNotu[i] >= 0.0 && tNotu[i] <= d8+r){ harfNotu[i] = "FF"; }
        else harfNotu[i] = "K";
      }
      else harfNotu[i] = "FF";
    }
    else break;
  }
}
void Classroom::tablo2(){
  int tempAS, tempFN;
  float tempHBN;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(hbn[i] > hbn[j]){
        tempAS = as[i]; tempFN = fn[i]; tempHBN = hbn[i];
        as[i] = as[j];  fn[i] = fn[j];  hbn[i] = hbn[j];
        as[j] = tempAS; fn[j] = tempFN; hbn[j] = tempHBN;
      }
    }
  }
  setHBN();
  float oran = 0.0, arti = 0.0;
  arti = (1.00 / n) * 100.0;
  oran = arti;
  //cout << fixed << setprecision(2) << oran << endl;
  //cout << fixed << setprecision(2) << HBN << endl;
  for(int i = 0; i < n; i++){
    if(HBN >= 80.00 && HBN <= 100.00){ tablo3(); break; }
    else if(HBN > 70.00 && HBN < 80.00){
      if(fn[i] >= 45){
        if(oran >= 0.00 && oran <= 24.00){ harfNotu[i] = "AA"; }
        else if(oran > 24.00 && oran <= 39.20){ harfNotu[i] = "BA"; }
        else if(oran > 39.20 && oran <= 62.00){ harfNotu[i] = "BB"; }
        else if(oran > 62.00 && oran <= 73.60){ harfNotu[i] = "CB"; }
        else if(oran > 73.60 && oran <= 91.00){ harfNotu[i] = "CC"; }
        else if(oran > 91.00 && oran <= 95.80){ harfNotu[i] = "DC"; }
        else if(oran > 95.80 && oran <= 99.00){ harfNotu[i] = "DD"; }
        else if(oran > 99.00 && oran <= 99.50){ harfNotu[i] = "FD"; }
        else if(oran > 99.50 && oran <= 100.00){ harfNotu[i] = "FF"; }
        else harfNotu[i] = "K";
      }
      else harfNotu[i] = "FF";
    }
    else if(HBN > 62.50 && HBN <= 70.00){
      if(fn[i] >= 45){
        if(oran >= 0.00 && oran <= 18.00){ harfNotu[i] = "AA"; }
        else if(oran > 18.00 && oran <= 32.40){ harfNotu[i] = "BA"; }
        else if(oran > 32.40 && oran <= 54.00){ harfNotu[i] = "BB"; }
        else if(oran > 54.00 && oran <= 66.80){ harfNotu[i] = "CB"; }
        else if(oran > 66.80 && oran <= 86.00){ harfNotu[i] = "CC"; }
        else if(oran > 86.00 && oran <= 93.20){ harfNotu[i] = "DC"; }
        else if(oran > 93.20 && oran <= 98.00){ harfNotu[i] = "DD"; }
        else if(oran > 98.00 && oran <= 99.00){ harfNotu[i] = "FD"; }
        else if(oran > 99.00 && oran <= 100.00){ harfNotu[i] = "FF"; }
        else harfNotu[i] = "K";
      }
      else harfNotu[i] = "FF";
    }
    else if(HBN > 57.5 && HBN <= 62.5){
      if(fn[i] >= 45){
        if(oran >= 0.00 && oran <= 14.00){ harfNotu[i] = "AA"; }
        else if(oran > 14.00 && oran <= 26.80){ harfNotu[i] = "BA"; }
        else if(oran > 26.80 && oran <= 46.00){ harfNotu[i] = "BB"; }
        else if(oran > 46.00 && oran <= 60.40){ harfNotu[i] = "CB"; }
        else if(oran > 60.40 && oran <= 82.00){ harfNotu[i] = "CC"; }
        else if(oran > 82.00 && oran <= 91.00){ harfNotu[i] = "DC"; }
        else if(oran > 91.00 && oran <= 97.00){ harfNotu[i] = "DD"; }
        else if(oran > 97.00 && oran <= 98.50){ harfNotu[i] = "FD"; }
        else if(oran > 98.50 && oran <= 100.00){ harfNotu[i] = "FF"; }
        else harfNotu[i] = "K";
      }
      else harfNotu[i] = "FF";
    }
    else if(HBN > 52.5 && HBN <= 57.5){
      if(fn[i] >= 45){
        if(oran >= 0.00 && oran <= 10.00){ harfNotu[i] = "AA"; }
        else if(oran > 10.00 && oran <= 21.60){ harfNotu[i] = "BA"; }
        else if(oran > 21.60 && oran <= 39.00){ harfNotu[i] = "BB"; }
        else if(oran > 39.00 && oran <= 53.80){ harfNotu[i] = "CB"; }
        else if(oran > 53.80 && oran <= 76.00){ harfNotu[i] = "CC"; }
        else if(oran > 76.00 && oran <= 88.00){ harfNotu[i] = "DC"; }
        else if(oran > 88.00 && oran <= 96.00){ harfNotu[i] = "DD"; }
        else if(oran > 96.00 && oran <= 98.00){ harfNotu[i] = "FD"; }
        else if(oran > 98.00 && oran <= 100.00){ harfNotu[i] = "FF"; }
        else harfNotu[i] = "K";
      }
      else harfNotu[i] = "FF";
    }
    else if(HBN > 47.50 && HBN <= 52.50){
      if(fn[i] >= 45){
        if(oran >= 0.00 && oran <= 7.00){ harfNotu[i] = "AA"; }
        else if(oran > 7.00 && oran <= 16.60){ harfNotu[i] = "BA"; }
        else if(oran > 16.60 && oran <= 31.00){ harfNotu[i] = "BB"; }
        else if(oran > 31.00 && oran <= 46.20){ harfNotu[i] = "CB"; }
        else if(oran > 46.20 && oran <= 69.00){ harfNotu[i] = "CC"; }
        else if(oran > 69.00 && oran <= 83.40){ harfNotu[i] = "DC"; }
        else if(oran > 83.40 && oran <= 93.00){ harfNotu[i] = "DD"; }
        else if(oran > 93.00 && oran <= 96.50){ harfNotu[i] = "FD"; }
        else if(oran > 96.50 && oran <= 100.00){ harfNotu[i] = "FF"; }
        else harfNotu[i] = "K";
      }
      else harfNotu[i] = "FF";
    }
    else if(HBN > 42.50 && HBN <= 47.5){
      if(fn[i] >= 45){
        if(oran >= 0.00 && oran <= 4.00){ harfNotu[i] = "AA"; }
        else if(oran > 4.00 && oran <= 12.00){ harfNotu[i] = "BA"; }
        else if(oran > 12.00 && oran <= 24.00){ harfNotu[i] = "BB"; }
        else if(oran > 24.00 && oran <= 38.80){ harfNotu[i] = "CB"; }
        else if(oran > 38.80 && oran <= 61.00){ harfNotu[i] = "CC"; }
        else if(oran > 61.00 && oran <= 78.40){ harfNotu[i] = "DC"; }
        else if(oran > 78.40 && oran <= 90.00){ harfNotu[i] = "DD"; }
        else if(oran > 90.00 && oran <= 95.00){ harfNotu[i] = "FD"; }
        else if(oran > 95.00 && oran <= 100.00){ harfNotu[i] = "FF"; }
        else harfNotu[i] = "K";
      }
      else harfNotu[i] = "FF";
    }
    else if(HBN >= 0.00 && HBN <= 42.50){
      if(fn[i] >= 45){
        if(oran >= 0.0 && oran <= 3.00){ harfNotu[i] = "AA"; }
        else if(oran > 3.00 && oran <= 9.00){ harfNotu[i] = "BA"; }
        else if(oran > 9.00 && oran <= 18.00){ harfNotu[i] = "BB"; }
        else if(oran > 18.00 && oran <= 32.40){ harfNotu[i] = "CB"; }
        else if(oran > 32.40 && oran <= 54.00){ harfNotu[i] = "CC"; }
        else if(oran > 54.00 && oran <= 73.20){ harfNotu[i] = "DC"; }
        else if(oran > 73.20 && oran <= 86.00){ harfNotu[i] = "DD"; }
        else if(oran > 86.00 && oran <= 93.00){ harfNotu[i] = "FD"; }
        else if(oran > 93.00 && oran <= 100.00){ harfNotu[i] = "FF"; }
        else harfNotu[i] = "K";
      }
      else harfNotu[i] = "FF";
    }
    else harfNotu[i] = "HATA";
    oran += arti;
  }
}

// *Writen By Nurullah Demirci
//  *No: 244037
//  *Class: 2. Öğretim
