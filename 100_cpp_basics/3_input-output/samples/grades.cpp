#include <iostream>
#include <string>
#include <limits>
#include <cctype>

#define DIFF 32
#define SIZE 10
// #include "stdio.h"
using namespace std;

const float mC = 0.4, fC = 0.6;

float func(const float a, const float b){
  //::mC = 20; ERROR
  float mC = 0.1, fC = 0.9;
  return ::mC*a + ::fC*b;  
}

string upperCase(string str){
  int n = str.length();
  string rStr = str; // copy
  for(int i=0;i<n;i++){
    if(int(str[i]) >= int('a') && int(str[i]) <= 'z')
    rStr[i] = char(  int(str[i])  - DIFF);
  }
  return rStr;
}

// Not girişi sırasında hata kontrolü ve buffer temizleme yapan fonksiyon
float getGrade(const string& prompt) {
  float grade;
  while (true) {
    cout << prompt;

    // cin.peek() ile akıştaki sıradaki karaktere akıştan çıkarmadan bakılır
    char nextChar = cin.peek();
    if (nextChar != '\n' && !isdigit(nextChar) && nextChar != '+' && nextChar != '-') {
      cout << "Hatali karakter tespit edildi ('" << nextChar << "'). Sayisal bir deger giriniz!" << endl;
      cin.clear(); // Hata bayragini temizler
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Buffer'i temizler
      continue;
    }

    cin >> grade;

    // Sayı yerine harf gibi geçersiz bir girdi durumunda cin.fail() kontrolü
    if (cin.fail()) {
      cout << "Gecersiz not girisi yapildi!" << endl;
      cin.clear(); // cin.clear() ile hata bayraklari sifirlanir
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Buffer'daki hatali karakterler temizlenir
    } 
    else if (grade < 0 || grade > 100) {
      cout << "Not 0 ile 100 arasinda olmalidir!" << endl;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } 
    else {
      // Basarili okuma sonrasi satir sonundaki kalan karakterleri ('\n' dahil) temizle
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      return grade;
    }
  }
}

int main() {
  int _a , b_, c = 10, _, num1 ;
  cout<<c<<endl;
  cout<<_<<endl;

  /*
  10 öğrenci düşünün
  bir dizi tanımlayalım, içinde 10 öğrencinin arasınav ve final notları olsun.
  %40 arasınav
  %60 final olsun
  her öğrencinin adı olsun
  öğrenciden notları al, hata durumunda buffer temizle.
  ortalamaları bul ve ekrana yaz.  
  */

  float midTermArr[SIZE];
  float final_[SIZE];
  string names[SIZE];
  float avg[SIZE]={0}; // init
  int num = SIZE;

  cout << "=== " << num << " Ogrenci Icin Not Girisi ===" << endl;
  for (int i = 0; i < num; i++) {
    cout << "\n[" << (i + 1) << "/" << num << "] Ogrenci adi: ";
    cin >> names[i];
    midTermArr[i] = getGrade("  Arasinav (Vize) Notu (0-100): ");
    final_[i] = getGrade("  Final Notu (0-100): ");
  }

  cout << "\n=== Sonuclar ===" << endl;
  for(int i=0;i<num;i++){
    //avg[i] = mC * midTermArr[i] + fC * final_[i];
    avg[i] = func(midTermArr[i],final_[i]);
    names[i] = upperCase(names[i]);
    cout<< names[i] << ": "<< avg[i];
    if(avg[i]<45){
      int k; "k is local in if statement";
      cout<<" - FAILED";
    } 
    else cout<<" - SUCCESS";
    cout<<endl;
    
  }
"To compile: g++ sample2.cpp -o run";
"To run: ./run";
  "https://codeshare.io/G7m8NL";
  return 0;
}
