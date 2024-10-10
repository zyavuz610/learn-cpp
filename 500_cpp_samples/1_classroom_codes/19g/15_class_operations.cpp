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
      as    = 50;
      fn    = 45;
      ad    = "X";
      soyad = "Y";
      ders  = "Z";
      std::cout<<"Nesne oluşturuldu\n";
    }
    Ogrenci(std::string _ad,std::string _soyad){
      ad    = _ad;
      soyad = _soyad;
      std::cout <<ad<<" "
                <<soyad<<" "
                <<"oluşturuldu\n";
    }
    Ogrenci(const Ogrenci &o){ // copy constructor
      ad = "Copy X";
      soyad = "Copy Y";
      as = o.as;
      fn = o.fn;
    }
    ~Ogrenci(){
      std::cout<<ad<<" nesnesi öldü\n";
    }
    double OrtalamaBul();
    std::string harfNotHesapla();
    void yaz();
    void setAS(int _as); // setter of as
    void setFN(int _fn); // setter of fn
    void setAD(std::string _ad);
    void setSOYAD(std::string _soyad);
    void setDERS(std::string _ders);
    int getAS();
    int getFN();
    std::string getAD();
    std::string getSOYAD();
    std::string getDERS();
  private:
    std::string ad;
    std::string soyad;
    std::string ders;
    int as;
    int fn;
    double ort;
    std::string harf;
};



int main(){
  Ogrenci selim,busra;
  selim.setAS(100);
  selim.setFN(85);
  selim.setAD("Selim");
  selim.setSOYAD("YALÇINKAYA");
  busra.setAS(76);
  busra.setFN(65);
  busra.setAD("Büşra");
  busra.setSOYAD("AYDIN");
  selim.OrtalamaBul();
  busra.OrtalamaBul();
  selim.harfNotHesapla();
  busra.harfNotHesapla();

  selim.yaz();
  busra.yaz();
  std::cout<<busra.getFN()<<std::endl;
  Ogrenci okan;
  std::string s1="Okan";
  Ogrenci ozcan(s1,"Özcan");
  ozcan.setAS(40);
  ozcan.setFN(80);
  Ogrenci gizem = ozcan; // hard copy
  gizem.OrtalamaBul();
  gizem.harfNotHesapla();
  gizem.yaz();

  return 0;
}

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
                <<ad<<" "
                <<soyad
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
void Ogrenci::setDERS(std::string _ders){
  ders = _ders;
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
std::string Ogrenci::getDERS(){
  return ders;
}