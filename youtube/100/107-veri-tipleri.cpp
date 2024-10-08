#include <iostream>

using namespace std;


int main() {
  int i=54;     // tam sayı
  float f=2.4;  // reel sayı
  unsigned short int si = 32769;
  cout << "si:"<<si<<endl;
  cout << "Veri Tipleri" << "\n";
  cout << "veri tipi boyutu:"
       << sizeof(long double)
       << endl;
  
}

/*
Veri Tipleri:
  1.Sayısal
    tam sayı, => int
    reel sayı, => float, double
  2.Mantıksal Değer => bool => true, false
  3.Karakter => char => 'A' (65,ASCI)
  4.String => string, "merhaba"

Ön Belirleyiciler
  short -> int
  long, long long -> int, double
  signed *, -> char, int
  unsigned, -> char, int

Tanımlanabilecek Değişkenler ve Alabileceği Değerler
  short int si = -254;               
// 2 byte, -32,768 -- 32,767

unsigned short int usi = 65535;    
// 2 byte, 0 -- 65535

int i = -4;                        
// 4 byte, -2,147,483,648 -- 2,147,483,647

unsigned int ui = 4000000000;      
// 4 byte,0 -- 4,294,967,295 

long int li = -44;                  
// 8 byte, -(2^63) to (2^63)-1

unsigned long int uli = 40000000;  
// 8 byte, 0 -- (2^64)-1  (20 haneli)

char c = 48;                       
char c = '0';                     
// 1 byte, -128 -- 127

unsigned char uc = 200;            
// 1 byte, 0 -- 255

float f = -2.98e-9; // 298*10^-9                  
// 4 byte, virgülden sonra ~7 hane hassasiyet, ~40 rakamlı

double d = 2.56E+20; 256*10^20                   
// 8 byte, virgülden sonra ~15 hane hassasiyet, ~400 rakamlı

long double ld = 2.56E+12;             
// 16 byte, virgülden sonra ~15 hane hassasiyet, ~5000 rakamlı sayı
  
  

*/