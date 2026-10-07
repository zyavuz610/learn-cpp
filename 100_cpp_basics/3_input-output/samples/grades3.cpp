#include <iostream>
#include <fstream>  // Dosya okuma (ifstream) ve yazma (ofstream) için gerekli
#include <string>
#include <limits>
#include <cctype>
#include <iomanip>  // setw, setprecision, setfill, fixed, scientific, left, right için gerekli

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

int main() {
  int _a , b_, c = 10, _, num1 ;
  cout << c << endl;
  cout << _ << endl;

  /*
  10 öğrenci düşünün
  Öğrenci verileri ve notları 'grades_input.txt' dosyasından okunacak.
  %40 arasınav
  %60 final olsun
  Ortalamalar hesaplanacak.
  Tüm formatlı çıktı örnekleri 'grades_output.txt' dosyasına yazılacak.
  */

  float midTermArr[SIZE];
  float final_[SIZE];
  string names[SIZE];
  float avg[SIZE] = {0}; // init
  int num = SIZE;

  // =========================================================================
  // 1. DOSYADAN VERİ OKUMA (ifstream)
  // =========================================================================
  const string inputFileName = "grades_input.txt";
  ifstream inputFile(inputFileName);

  // Dosyanın açılıp açılamadığını kontrol et
  if (!inputFile.is_open()) {
    cerr << "Hata: '" << inputFileName << "' dosyasi acilamadi! Lutfen dosyanin varligini kontrol edin." << endl;
    return 1;
  }

  cout << "=== '" << inputFileName << "' Dosyasindan Veriler Okunuyor ===" << endl;

  int count = 0;
  for (int i = 0; i < num; i++) {
    // peek() ile dosya sonu veya karakter kontrolü yapılabilir
    if (inputFile.peek() == EOF) {
      cout << "Uyari: Dosya sonuna (EOF) ulasildi. Beklenenden az kayit var." << endl;
      break;
    }

    // Dosyadan: isim, vize notu ve final notu okunuyor
    if (inputFile >> names[i] >> midTermArr[i] >> final_[i]) {
      count++;
      cout << "[" << count << "/" << num << "] Okundu -> " 
           << names[i] << " | Vize: " << midTermArr[i] 
           << " | Final: " << final_[i] << endl;
    } else {
      cerr << "Hata: Dosyadan veri okunurken gecersiz format tespit edildi!" << endl;
      inputFile.clear();
      inputFile.ignore(numeric_limits<streamsize>::max(), '\n');
      break;
    }
  }

  // Okuma tamamlandıktan sonra dosya kapatılır
  inputFile.close();
  cout << "Dosya okuma tamamlandi. Toplam " << count << " ogrenci kaydi alindi.\n" << endl;

  // Ortalamaları hesapla ve isimleri büyük harfe dönüştür
  for (int i = 0; i < count; i++) {
    avg[i] = func(midTermArr[i], final_[i]);
    names[i] = upperCase(names[i]);
  }

  // =========================================================================
  // 2. FORMATLI ÇIKTILARI DOSYAYA YAZMA (ofstream)
  // =========================================================================
  const string outputFileName = "grades_output.txt";
  ofstream outputFile(outputFileName);

  if (!outputFile.is_open()) {
    cerr << "Hata: '" << outputFileName << "' dosyasi yazmak icin acilamadi!" << endl;
    return 1;
  }

  outputFile << "========================================================\n";
  outputFile << "      FORMATLI CIKTI VE MANIPULATOR ORNEKLERI          \n";
  outputFile << "      (grades_output.txt Dosyasina Yazilmistir)        \n";
  outputFile << "========================================================\n\n";

  // -------------------------------------------------------------------------
  // 1. setw() KULLANIMI:
  // setw(n) fonksiyonu, bir sonraki çıktının toplam alan genişliğini (field width) belirler.
  // Önemli: setw() sadece kendisinden hemen sonra gelen İLK çıktı nesnesi için geçerlidir.
  // -------------------------------------------------------------------------
  outputFile << "--- 1. setw() Kullanimi (Alan Genisligi Belirleme) ---\n";
  outputFile << "Aciklama: setw(15) ile isim alani 15 karakter, setw(10) ile ortalama 10 karaktere ayarlandi.\n";
  for (int i = 0; i < count; i++) {
    outputFile << setw(15) << names[i] << setw(10) << avg[i] << "\n";
  }
  outputFile << "\n";

  // -------------------------------------------------------------------------
  // 2. left VE right KULLANIMI (Hizalama):
  // left: Çıktıyı belirlenen alan içinde sola dayalı yapar.
  // right: Çıktıyı belirlenen alan içinde sağa dayalı yapar (varsayılan davranıştır).
  // Önemli: left ve right ayarları kalıcıdır; başka bir hizalama seçilene kadar geçerli kalır.
  // -------------------------------------------------------------------------
  outputFile << "--- 2. left ve right Kullanimi (Sola ve Saga Hizalama) ---\n";
  outputFile << "Aciklama: Isimler sola dayali (left), ortalamalar saga dayali (right) yazdirildi.\n";
  for (int i = 0; i < count; i++) {
    outputFile << left << setw(15) << names[i] 
               << right << setw(10) << avg[i] << "\n";
  }
  outputFile << "\n";

  // -------------------------------------------------------------------------
  // 3. fixed VE setprecision() KULLANIMI:
  // fixed: Kayan noktalı sayıları sabit ondalık biçiminde gösterir.
  // setprecision(n): fixed ile birlikte kullanıldığında noktadan sonraki basamak sayısını belirler.
  // -------------------------------------------------------------------------
  outputFile << "--- 3. fixed ve setprecision(2) Kullanimi (Ondalik Basamak Kontrolu) ---\n";
  outputFile << "Aciklama: fixed ve setprecision(2) ile notlar virgulden sonra 2 basamakla sabitlendi.\n";
  outputFile << fixed << setprecision(2);
  for (int i = 0; i < count; i++) {
    outputFile << left << setw(15) << names[i] 
               << ": " << avg[i] << "\n";
  }
  outputFile << "\n";

  // -------------------------------------------------------------------------
  // 4. scientific KULLANIMI:
  // scientific: Sayıları bilimsel (üstel, örn: 5.600e+01) gösterim formatına sokar.
  // Tekrar standart biçime dönmek için 'defaultfloat' manipülatörü kullanılır.
  // -------------------------------------------------------------------------
  outputFile << "--- 4. scientific Kullanimi (Bilimsel / Ustel Gosterim) ---\n";
  outputFile << "Aciklama: Ortalamalar bilimsel (scientific) gosterim formatinda yazdirildi.\n";
  outputFile << scientific << setprecision(3);
  for (int i = 0; i < count; i++) {
    outputFile << left << setw(15) << names[i] 
               << ": " << avg[i] << "\n";
  }
  // Varsayılan kayan noktalı sayı moduna geri dön
  outputFile << defaultfloat;
  outputFile << "\n";

  // -------------------------------------------------------------------------
  // 5. cout.fill() VE setfill() KULLANIMI (Dolgu Karakteri):
  // setw() ile oluşturulan boşlukları varsayılan boşluk ' ' yerine istenen karakterle doldurur.
  // outputFile.fill('.') üye fonksiyonu ile veya manipülatör olarak setfill('-') ile ayarlanabilir.
  // -------------------------------------------------------------------------
  outputFile << "--- 5. outputFile.fill('.') ve setfill('-') Kullanimi (Dolgu Karakterleri) ---\n";
  outputFile << "Aciklama: setw bosluklari nokta (fill('.')) ve cizgi (setfill('-')) karakterleri ile dolduruldu.\n\n";

  // outputFile.fill('.') ile nokta dolgusu
  outputFile.fill('.');
  outputFile << ">> outputFile.fill('.') ile Cikti:\n";
  for (int i = 0; i < count; i++) {
    outputFile << left << setw(15) << names[i] 
               << right << setw(10) << fixed << setprecision(1) << avg[i] << "\n";
  }

  // setfill('-') ile çizgi dolgusu
  outputFile << "\n>> setfill('-') ile Cikti:\n";
  outputFile << setfill('-');
  for (int i = 0; i < count; i++) {
    outputFile << left << setw(15) << names[i] 
               << right << setw(10) << fixed << setprecision(2) << avg[i] << "\n";
  }

  // Dolgu karakterini tekrar standart boşluk karakterine döndürelim
  outputFile.fill(' ');
  outputFile << "\n";

  // -------------------------------------------------------------------------
  // 6. TÜM MANİPÜLATÖRLERİN BİRLEŞİMİ (ÖZET TABLO RAPORU):
  // setw, left, right, fixed, setprecision ve durum (SUCCESS/FAILED) kontrolü bir arada.
  // -------------------------------------------------------------------------
  outputFile << "========================================================\n";
  outputFile << "           OZET SONUC TABLOSU (KOMPOZIT KULLANIM)       \n";
  outputFile << "========================================================\n";
  outputFile << left << setw(15) << "OGRENCI ADI" 
             << right << setw(12) << "ORTALAMA" 
             << right << setw(15) << "DURUM" << "\n";
  outputFile << setfill('=') << setw(42) << "" << setfill(' ') << "\n";

  for (int i = 0; i < count; i++) {
    outputFile << left << setw(15) << names[i] 
               << right << setw(12) << fixed << setprecision(2) << avg[i];

    if (avg[i] < 45) {
      int k; "k is local in if statement";
      outputFile << right << setw(15) << "FAILED";
    } else {
      outputFile << right << setw(15) << "SUCCESS";
    }
    outputFile << "\n";
  }
  outputFile << setfill('=') << setw(42) << "" << setfill(' ') << "\n";

  // Dosyayı kapat
  outputFile.close();

  cout << "Tüm formatli ciktilar '" << outputFileName << "' dosyasina basariyla yazildi!" << endl;

  "To compile: g++ grades3.cpp -o run";
  "To run: ./run";
  "https://codeshare.io/G7m8NL";
  return 0;
}
