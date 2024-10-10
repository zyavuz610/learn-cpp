/*
  int dizi1[] = {23,11,25,2,25,26,12,45,-1};
  int dizi2[] = {45,2,25,25,26,11,12,23,-1};

  bu şekilde 2 dizi veriliyor.

  kiyasla adında bir fonksiyon yazın ve bu 2 dizinin aynı elemanlara sahip olup olmadığını bulun. 
  dizi elemanları pozitif tamsayıdır.
  dizi boyutu verilmediğinden dizilerin sonunu belirtmek için -1 değeri kullanılmıştır.
  dizi boyutları farklı olabilir.
  diziler aynı değerlere sahipse 1, değilse 0 geri döndürsün.
  
*/

#include <iostream>
#include <iomanip>
using namespace std;

// fonk. tanımlamaları BURAYA
// global değişken kullanmayın!

int diziBoyut(int dizi[]){
  int i, say = 0;
  for(i = 0; dizi[i] != -1; i++){
    if(dizi[i] != -2){
      say++;
    }
  }
  return say;
}

bool esitMi(int dizi1[],int dizi2[]){//kıyasla fonksiyonunun ismi değiştirildi..
  // KODLAR BURAYA
  int i, j, control = 0;
  if(diziBoyut(dizi1) == diziBoyut(dizi2)){
    for(i = 0; dizi1[i] != -1; i++){
      for(j = 0; dizi2[j] != -1; j++){
        if(dizi1[i] == dizi2[j]){
          dizi2[j] = -2;
          control++;
          break;
        }
      }
    }
  }
  return (control == i) ? true : false;
}

bool denkMi(int dizi1[],int dizi2[]){//kıyasla2 fonksiyonunun ismi değiştirildi..
  // KODLAR BURAYA, Bonus için
  int i, j;
  for(i = 0; dizi1[i] != -1; i++){
    for(j = 0; dizi1[j] != -1; j++){
      if(i != j ){
        if(dizi1[i] == dizi1[j]){
          dizi1[j] = -2;
          
        }
      }
    }
  }
  for(i = 0; dizi2[i] != -1; i++){ 
    for(j = 0; dizi2[j] != -1; j++){
      if(i != j ){
        if(dizi2[i] == dizi2[j]){
          dizi2[j] = -2;
        }
      }
    }
  }
  return ( diziBoyut(dizi1) == diziBoyut(dizi2) ) ? true : false;
}

void yaz(int dizi1[],int dizi2[]){
  int i;
  cout << "dizi1[] = {";
  for(i = 0; dizi1[i] != -1; i++){
    cout << dizi1[i] << ",";
  }
  cout << "-1} " << setw(5) << " --> " << setw(5) << " Boyutu : " << diziBoyut(dizi1) << "\n";
  cout << "dizi2[] = {";
  for(i = 0; dizi2[i] != -1; i++){
    cout << dizi2[i] << ",";
  }
  cout << "-1} " << setw(5) << " --> " << setw(5) << " Boyutu : " << diziBoyut(dizi2) << "\n";
  cout << "-------------------------------------------------------\n";
}

int main() {
  // main() içerisine kod eklemeyin, burası olabildiğince sade olsun
  int dizi1[] = {1, 2, 2, -1};
  int dizi2[] = {1, 2, -1};
  int dizi1Boyut, dizi2Boyut, i;
  
  dizi1Boyut = diziBoyut(dizi1);
  dizi2Boyut = diziBoyut(dizi2);
  
  yaz(dizi1, dizi2);
  
  if(dizi1Boyut >= dizi2Boyut){
    i = esitMi(dizi1, dizi2);
    cout << "Dizilerin eşitlik durumu: " << i << endl;
  } else {
    i = esitMi(dizi2, dizi1);
    cout << "Dizilerin eşitlik durumu: " << i << endl;
  }
  
  cout << "---------------------------\n";
  
  // Bonus +1 puan
  // Dizileri küme gibi düşünfüğünüzde yani tekrarlı elemanları çıkarıp teke düşürtdüğünüzde ve karşılaştırdığınızda aynı ise bu kümeler eştir.
  int dizi3[] = {1, 2, 2, -1};
  int dizi4[] = {1, 2, -1};
  
  if(dizi1Boyut >= dizi2Boyut){
    if(i == 1){
      cout << "Dizilerin eşlik (denklik) durumu: " << 1 << endl;
    } else {
      cout << "Dizilerin eşlik (denklik) durumu: " << denkMi(dizi3, dizi4) << endl;
    }
  } else {
    cout << "Dizilerin eşlik (denklik) durumu: " << denkMi(dizi3, dizi4) << endl;
  }

  cout << "-----------------------------------\n";
}

//Written By Nurullah Demirci <--> (NTB <--> NOVA TEKNO&BILISIM )
//Öğrenci Bilgileri No: 244037 <--> 2.Öğretim
