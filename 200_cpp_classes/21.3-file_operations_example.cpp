#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;
class Classroom{
  public:
    Classroom(){
      // 10 tane öğrenci olsun
      cout<<"Parametresiz Yapıcı çalıştı\n";
      this->n=10;
      this->ders = "XY";
      this->yer_ayir();
      this->ortalamaHesapla();
      this->isimAta();
    }
    Classroom(int _n){
      // ...
      cout<<"Parametreli Yapıcı  çalıştı\n";
      this->n = _n;
      this->ders = "XY";
      this->yer_ayir();
      this->ortalamaHesapla();
      this->isimAta();
    }
    Classroom(string _ders,int _n){
      // ...
      cout<<"Parametreli Yapıcı  çalıştı\n";
      this->n = _n;
      this->ders = _ders;
      this->yer_ayir();
      this->ortalamaHesapla();
      this->isimAta();
    }
    inline void yaz(){
      cout<<this->ders<<" Dersi\n";
      cout<<"ISIM\tSOYISIM\tAS\tFN\tOrt\n";
      for(int i=0;i<n;i++){
        cout<<tamad[i]<<"\t"<<as[i]<<"\t"<<fn[i]<<"\t"<<ort[i]<<"\n";
      }
    }
    void rasgele_erisimli_dosya_oku(string _dosyaad){
      ifstream dosya(_dosyaad);         // dosya tanımla ve aç
      dosya.seekg(0,ios::end);          // dosya sonuna atla
      cout  <<"Boyut:"
            <<dosya.tellg()             // tellg(): curserin bulunduğu yeri söyler
            <<endl;                     // dosyanın boyutu
      
      string str;
      dosya.seekg(0,ios::beg);          // dosyanın başına atla
      dosya>>str;                       // oku;
      cout  <<"Boyut:"
            <<dosya.tellg()             // tellg(): curserin bulunduğu yeri söyler
            <<endl;                     // dosyanın boyutu
      cout<<"Boy:"<<str.length()<<endl; // stringin boyutu

      dosya.seekg(1,ios::cur);          // dosyada bir ileri git
      dosya.seekg(-2,ios::cur);
      getline(dosya,str);               // dosyada bir satır oku
      cout<<str<<endl;


    }
    void rasgele_erisimli_dosya_yaz(string _dosyaad){
      fstream dosya(_dosyaad,ios::app);          // dosya tanımla ve aç
      dosya.seekp(0,ios::end);          // dosya sonuna atla
      cout  <<"Boyut:"
            <<dosya.tellp()             // tellg(): curserin bulunduğu yeri söyler
            <<endl;                     // dosyanın boyutu
      
      string str = "isim listesi\n";
      dosya<<str;                       // yaz (app modunda olduğu için dosya sonuna yazar)
      dosya.seekp(0,ios::beg);          // dosyanın başına atla
      cout  <<"Boyut:"
            <<dosya.tellp()             // tellg(): curserin bulunduğu yeri söyler
            <<endl;                     // dosyanın boyutu
      cout<<"Boy:"<<str.length()<<endl; // stringin boyutu

      dosya.seekp(0,ios::end);          // dosya sonuna atla
      cout  <<"Boyut:"
            <<dosya.tellp()             // tellg(): curserin bulunduğu yeri söyler
            <<endl;  


    }
    void yaz(string _dosya_yol){
  /* 
    dosyaya yazmak için 4 işlem
      1. ofstream dosya;              dosya tanımla
      2. dosya.open("dosya.txt");     dosya açma
      3. for(.....)                   dosyaya yazılacak değerler için döngü
          dosya<<str;                 dosyaya yaz (cout benzeri)
          ....    
      4. dosya.close();               dosyayı kapat
  */
    
      ofstream dosya;
      dosya.open(_dosya_yol);
      sirala();
      dosya<<this->ders<<" Dersi\n";
      for(int i=0;i<n;i++){
        dosya <<tamad[i]<<"\t"
              <<setw(2)<<as[i]<<"\t"
              <<setw(2)<<fn[i]<<"\t"
              <<setw(4)<<ort[i]<<endl;
      }
      int asT=0,fnT=0;
      float ortT=0.0;
      for(int i=0;i<n;i++){
        asT   += as[i];
        fnT   += fn[i];
        ortT  += ort[i];
      }
      dosya   <<setw(2)<<"--"<<"\t"
              <<setw(2)<<"--"<<"\t"
              <<setw(4)<<"----"<<endl;
      dosya   <<setw(2)<<asT/n<<"\t"
              <<setw(2)<<fnT/n<<"\t"
              <<setw(4)<<ortT/n<<endl;
      dosya.close();
    }
    void sirala(){
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          if(ort[j]<ort[j+1]){
            swap(as[j],as[j+1]);
            swap(fn[j],fn[j+1]);
            swap(ort[j],ort[j+1]);
          }
        }
      }
    }
    void ortalamaHesapla(){
      for(int i=0;i<n;i++){
        ort[i] = (as[i]+fn[i])/2.0;
      }
    }
    void isimAta(){
  /* 
    dosya okumak için 4 işlem
      1. ifstream dosya;              dosya tanımla
      2. dosya.open("isimler.txt");   dosya açma
      3. while(!dosya.eof()){         dosya sonuna gelene kadar
          dosya>>str;                 dosyadan oku (cin benzeri)
          ....    
      4. dosya.close();               dosyayı kapat          
  */
      const int aN = 100, sN = 50;
      ifstream dosya;
      dosya.open("isimler.txt");
      int i=0;
      string s1[aN],s2[sN],str;
      while(!dosya.eof()){
          dosya>>str;
        if(i<aN){
          s1[i] = str;
          //cout<<i<<" "<<s1[i]<<endl;
        }
        i++;
      }
      dosya.close();
      dosya.open("soyisimler.txt");
      i=0;
      while(!dosya.eof()){
          dosya>>str;
        if(i<sN){
          s2[i] = str;
          //cout<<i<<" "<<s2[i]<<endl;
        }
        i++;
      }
      dosya.close();
      int adIND,sadIND;

      srand (time(NULL));
      for(int i=0;i<n;i++){
        adIND = rand()%aN; // 0-99
        sadIND = rand()%sN; // 0-49
        tamad[i] = s1[adIND] + " " + s2[sadIND];
        //cout<<tamad[i]<<endl;
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
      as    = new int[n];
      fn    = new int[n];
      ort   = new float[n];
      tamad = new string[n];
      srand (time(NULL));
      for(int i=0;i<n;i++){
        as[i] = rand()%100 +1;
        fn[i] = rand()%100 +1;
      }
    }
    int *as;
    int *fn;
    float *ort;
    string *tamad;
    string ders;
    int n;
};
void yaz2(Classroom *c){
  cout<<"ISIM\tAS2\tFN2\tOrt2\n";
      for(int i=0;i<c->n;i++){
        c->ort[i] = (c->as[i]+c->fn[i])/2.0;
        cout<<c->as[i]<<"\t"<<c->fn[i]<<"\t"<<c->ort[i]<<"\n";
      }
}
int main() {
//-----------------------------------------------  
  // sıralı erişimli dosya işlemleri
  /*
  Classroom c(20);
  Classroom *cptr = new Classroom();
  Classroom *cptr2 = new Classroom("Nesne Yönelimli Programlama",300);
  c.yaz();
  cptr2->yaz("yenidosya.dat");

  delete cptr;
  delete cptr2;
  */
//-----------------------------------------------------
// rasgele eişimli dosya okuma
/*
  Classroom c("Veri Yapıları",10);
  c.rasgele_erisimli_dosya_oku("isimler.txt");
*/
//-----------------------------------------------------
// rasgele eişimli dosya okuma

  Classroom c("Veri Yapıları",10);
  c.rasgele_erisimli_dosya_yaz("soyisimler.txt");

//-------------------------------------------------------
/*  
## geçen ders ne gördük?
* dinamik bellek yönetimi, new, delete
* nesneye pointer, nesneyi fonksiyona parametre aktarma
* this işaretçisi
* nesne dizileri
* friend function
* inline function

## bu ders ne göreceğiz?
* dosya işlem türleri
  * sıralı erişim
  * rasgele erişim
* dosya işlemi için kullanılan yapılar
  * fstream : dosya giriş-çıkış
  * ofstream: dosya çıkış (dosyaya yazmak için)
  * ifstream: dosyadan okuma
* dosya açma modları
  * ios::app 
  * ios::ate 
  * ios::in 
  * ios::out 
  * ios::trunc 
  * ios::binary (dosyaya byte dizisi şeklinde erişim)


  */
}

//---------------------------------------------------------
/*
isimler.txt
-----------------------
MANSUR KÜRŞAD
JALE
ALİ
MAHMUT
GAMZE
MİRAÇ
YÜCEL
KUBİLAY
HAYATİ
BEDRİYE MÜGE
BİRSEN
SERDAL
BÜNYAMİN
ÖZGÜR
FERDİ
REYHAN
İLHAN
GÜLŞAH
NALAN
SEMİH
ERGÜN
FATİH
ŞENAY
SERKAN
EMRE
BAHATTİN
IRAZCA
HATİCE
BARIŞ
REZAN
FATİH
FUAT
GÖKHAN
ORHAN
MEHMET
EVREN
OKTAY
HARUN
YAVUZ
PINAR
MEHMET
UMUT
MESUDE
HÜSEYİN CAHİT
HAŞİM ONUR
EYYUP SABRİ
MUSTAFA
MUSTAFA
UFUK
AHMET ALİ
MEDİHA
HASAN
KAMİL
NEBİ
ÖZCAN
NAGİHAN
CEREN
SERKAN
HASAN
YUSUF KENAN
ÇETİN
TARKAN
MERAL LEMAN
ERGÜN
KENAN AHMET
URAL
YAHYA
BENGÜ
FATİH NAZMİ
DİLEK
MEHMET
TUFAN AKIN
MEHMET
TURGAY YILMAZ
GÜLDEHEN
GÖKMEN
BÜLENT
EROL
BAHRİ
ÖZEN ÖZLEM
SELMA
TUĞSEM
TESLİME NAZLI
GÜLÇİN
İSMAİL
MURAT
EBRU
TÜMAY
AHMET
EBRU
HÜSEYİN YAVUZ
BAŞAK
AYŞEGÜL
EVRİM
YASER
ÜLKÜ
ÖZHAN
UFUK
AKSEL
FULYA

*/
//---------------------------------------------------------
/*
soyisimler.txt
----------------------
ŞEN
KANDEMİR
ÇEVİK
ERKURAN
TÜTEN
ÖZTÜRK
YÜZBAŞIOĞLU
VURAL
YÜCEL
SÖNMEZ
ERTEKİN
DEDE
UYANIK
ASLAN
AKBULUT
ORHON
UZ
YAVUZ
ERDEM
KULAÇ
KAYA
SELVİ
AKPINAR
ABACIOĞLU
ÇAY
IŞIK
ÖZER
ÖZDEMİR
ÖZTÜRK
TAHTACI
BÜYÜKCAM
KULAKSIZ
AKSEL
EROĞLU
KARAKUM
DAL
ÖCAL
AYHAN
YİĞİT
YARBİL
CANACANKATAN
GÜMÜŞAY
MURT
HALHALLI
ULUÖZ
ŞEYHANLI
ÇALIŞKANTÜRK
YILMAZ
SARAÇOĞLU
SEZER

*/