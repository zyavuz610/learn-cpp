#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include <iomanip> // setw, setprecision, setfill, fixed, scientific, left, right için gerekli

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
  ortalamaları ve isimleri farklı I/O manipülatörleri ile ekrana yaz.
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

  // Not ortalamalarını hesapla ve isimleri büyük harfe çevir
  for(int i = 0; i < num; i++){
    avg[i] = func(midTermArr[i], final_[i]);
    names[i] = upperCase(names[i]);
  }

  cout << "\n========================================================" << endl;
  cout << "      FORMATLI CIKTI VE MANIPULATOR ORNEKLERI          " << endl;
  cout << "========================================================" << endl;

  // -------------------------------------------------------------------------
  // 1. setw() KULLANIMI:
  // setw(n) fonksiyonu, bir sonraki çıktının toplam alan genişliğini (field width) belirler.
  // Önemli: setw() sadece kendisinden hemen sonra gelen İLK çıktı nesnesi için geçerlidir.
  // -------------------------------------------------------------------------
  cout << "\n--- 1. setw() Kullanimi (Alan Genisligi Belirleme) ---" << endl;
  cout << "Aciklama: setw(15) ile isim alani 15 karakter, setw(10) ile ortalama alani 10 karaktere ayarlandi.\n";
  for(int i = 0; i < num; i++){
    cout << setw(15) << names[i] << setw(10) << avg[i] << endl;
  }

  // -------------------------------------------------------------------------
  // 2. left VE right KULLANIMI (Hizalama):
  // left: Çıktıyı belirlenen alan içinde sola dayalı yapar.
  // right: Çıktıyı belirlenen alan içinde sağa dayalı yapar (varsayılan davranıştır).
  // Önemli: left ve right ayarları kalıcıdır; başka bir hizalama seçilene kadar sürer.
  // -------------------------------------------------------------------------
  cout << "\n--- 2. left ve right Kullanimi (Sola ve Saga Hizalama) ---" << endl;
  cout << "Aciklama: Isimler sola dayali (left), ortalamalar ise saga dayali (right) yazdirildi.\n";
  for(int i = 0; i < num; i++){
    cout << left << setw(15) << names[i] 
         << right << setw(10) << avg[i] << endl;
  }

  // -------------------------------------------------------------------------
  // 3. fixed VE setprecision() KULLANIMI:
  // fixed: Kayan noktalı sayıları sabit ondalık biçiminde gösterir.
  // setprecision(n): fixed ile birlikte kullanıldığında, noktadan sonraki basamak sayısını belirler.
  // -------------------------------------------------------------------------
  cout << "\n--- 3. fixed ve setprecision(2) Kullanimi (Ondalik Basamak Kontrolu) ---" << endl;
  cout << "Aciklama: fixed ile setprecision(2) kullanilarak notlar virgulden sonra 2 basamakla sabitlendi.\n";
  cout << fixed << setprecision(2);
  for(int i = 0; i < num; i++){
    cout << left << setw(15) << names[i] 
         << ": " << avg[i] << endl;
  }

  // -------------------------------------------------------------------------
  // 4. scientific KULLANIMI:
  // scientific: Sayıları bilimsel (üstel, örn: 5.600e+01) gösterim formatına sokar.
  // Tekrar standart biçime dönmek için 'defaultfloat' manipülatörü kullanılır.
  // -------------------------------------------------------------------------
  cout << "\n--- 4. scientific Kullanimi (Bilimsel / Ustel Gosterim) ---" << endl;
  cout << "Aciklama: Ortalamalar bilimsel gosterim formatinda yazdirildi.\n";
  cout << scientific << setprecision(3);
  for(int i = 0; i < num; i++){
    cout << left << setw(15) << names[i] 
         << ": " << avg[i] << endl;
  }
  // Varsayılan kayan noktalı sayı moduna geri dön
  cout << defaultfloat;

  // -------------------------------------------------------------------------
  // 5. cout.fill() VE setfill() KULLANIMI (Dolgu Karakteri):
  // setw() ile oluşturulan boşlukları varsayılan boşluk ' ' yerine istenen karakterle doldurur.
  // cout.fill('.') üye fonksiyonu ile veya manipülatör olarak setfill('.') ile ayarlanabilir.
  // -------------------------------------------------------------------------
  cout << "\n--- 5. cout.fill('.') ve setfill('-') Kullanimi (Dolgu Karakterleri) ---" << endl;
  cout << "Aciklama: setw bosluklari nokta (cout.fill('.')) ve cizgi (setfill('-')) karakterleri ile dolduruldu.\n";
  
  // cout.fill('.') ile nokta dolgusu
  cout.fill('.');
  cout << "\n>> cout.fill('.') ile Cikti:" << endl;
  for(int i = 0; i < num; i++){
    cout << left << setw(15) << names[i] 
         << right << setw(10) << fixed << setprecision(1) << avg[i] << endl;
  }

  // setfill('-') ile cizgi dolgusu
  cout << "\n>> setfill('-') ile Cikti:" << endl;
  cout << setfill('-');
  for(int i = 0; i < num; i++){
    cout << left << setw(15) << names[i] 
         << right << setw(10) << fixed << setprecision(2) << avg[i] << endl;
  }

  // Dolgu karakterini tekrar standart boşluk karakterine döndürelim
  cout.fill(' ');

  // -------------------------------------------------------------------------
  // 6. TUM MANIPULATORLERIN BIRLESIMI (TABLO RAPORU):
  // setw, left, right, fixed, setprecision ve durum (SUCCESS/FAILED) kontrolü bir arada.
  // -------------------------------------------------------------------------
  cout << "\n========================================================" << endl;
  cout << "           OZET SONUC TABLOSU (KOMPOZIT KULLANIM)       " << endl;
  cout << "========================================================" << endl;
  cout << left << setw(15) << "OGRENCI ADI" 
       << right << setw(12) << "ORTALAMA" 
       << right << setw(15) << "DURUM" << endl;
  cout << setfill('=') << setw(42) << "" << setfill(' ') << endl;

  for(int i = 0; i < num; i++){
    cout << left << setw(15) << names[i] 
         << right << setw(12) << fixed << setprecision(2) << avg[i];
    
    if(avg[i] < 45){
      int k; "k is local in if statement";
      cout << right << setw(15) << "FAILED";
    } 
    else {
      cout << right << setw(15) << "SUCCESS";
    }
    cout << endl;
  }
  cout << setfill('=') << setw(42) << "" << setfill(' ') << endl;

  "To compile: g++ grades2.cpp -o run";
  "To run: ./run";
  "https://codeshare.io/G7m8NL";
  return 0;
}
