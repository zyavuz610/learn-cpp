#include <iostream>
#include <iomanip>
/* 
 class Ogrenci
 . as -> int
 . fn -> int
 . ort -> double
 . harf -> string
 ()ortalamaBul()
 ()haftNotHesapla()
*/

class Ogrenci{
  public:
    Ogrenci(){
      std::cout<<"Nesne oluşturuldu\n";
      as = 65;
      fn = 45;
    }
    Ogrenci(const std::string _ad,const std::string _soyad,const int _as, const int _fn){
      std::cout<<"Nesne oluşturuldu 2\n";
      as = _as;
      fn = _fn;
      ad = _ad;
      soyad = _soyad;
      OrtalamaBul();
      harfNotHesapla();
    }
    Ogrenci(const Ogrenci &o){ // copy constructor
      ad = "X";
      soyad = "Y";
      as = o.as;
      fn = o.fn;
      OrtalamaBul();
      harfNotHesapla();
    }
    ~Ogrenci(){
      std::cout<<ad<<" nesnesi silindi\n";
    }
    double OrtalamaBul();
    std::string harfNotHesapla();
    void yaz();
    void setAS(int _as);
    void setFN(int _fn);
    void setAD(std::string _ad);
    void setSOYAD(std::string _soyad);
    int getAS();
    int getFN();
    std::string getAD();
    std::string getSOYAD();
  private:
    std::string ad;
    std::string soyad;
    int as;
    int fn;
    double ort;
    std::string harf;
};



int main(){
  Ogrenci nuh,oznur;
  nuh.setAS(100);
  nuh.setFN(85);
  nuh.setAD("Nuh");
  nuh.setSOYAD("Aslan");
  oznur.setAS(76);
  oznur.setFN(65);
  oznur.setAD("Öznur");
  oznur.setSOYAD("Kök");
  nuh.OrtalamaBul();
  oznur.OrtalamaBul();
  nuh.harfNotHesapla();
  oznur.harfNotHesapla();

  nuh.yaz();
  oznur.yaz();

  Ogrenci melih;
  melih.setAD("Melih");
  melih.OrtalamaBul();
  melih.harfNotHesapla();
  melih.yaz();

  Ogrenci ahmet("Ahmet","Emin",75,45);
  ahmet.yaz();
  Ogrenci nurullah = ahmet; // hard copy
  nurullah.yaz();
  return 0;
}
//------------------------------------------
double Ogrenci::OrtalamaBul(){
  return (ort = (as + fn) / 2.0);
}
std::string Ogrenci::harfNotHesapla(){
  if(ort>=0 && ort<39){ harf = "FF";  }
  else if(ort<=45)    { harf = "DC";  }
  else if(ort<55)     { harf = "CC";  }
  else if(ort<65)     { harf = "CB";  }
  else if(ort<75)     { harf = "BB";  }
  else if(ort<85)     { harf = "BA";  }
  else if(ort<=100)   { harf = "AA";  }
  else                { harf = "E";   }
  return harf;
}
void Ogrenci::yaz(){
  std::cout <<std::setw(5)<<as
            <<std::setw(5)<<fn
            <<std::fixed<<std::setprecision(2)
            <<std::setw(7)<<ort
            <<std::setw(4)<<harf<<" "
            <<ad<<" "<<soyad
            <<std::endl;
}
void Ogrenci::setAS(int _as){
  as = _as;
}
void Ogrenci::setFN(int _fn){
  fn = _fn;  
}
void Ogrenci::setAD(std::string _ad){
  ad = _ad;
}
void Ogrenci::setSOYAD(std::string _soyad){
  soyad = _soyad;
}
int Ogrenci::getAS(){
  return as;
}
int Ogrenci::getFN(){
  return fn;
}
std::string Ogrenci::getAD(){
  return ad;
}
std::string Ogrenci::getSOYAD(){
  return soyad;
}