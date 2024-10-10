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
    double OrtalamaBul(){
      return (ort = (as + fn) / 2.0);
    }
    std::string harfNotHesapla(){
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
    void yaz(){
      std::cout <<std::setw(5)<<as
                <<std::setw(5)<<fn
                <<std::fixed<<std::setprecision(2)
                <<std::setw(7)<<ort
                <<std::setw(4)<<harf
                <<std::endl;
    }
    void setAS(int _as){
      as = _as;
    }
    void setFN(int _fn){
      fn = _fn;  
    }
  private:
    int as;
    int fn;
    double ort;
    std::string harf;
};



int main(){
  Ogrenci selim,busra;
  selim.setAS(100);
  selim.setFN(85);
  busra.setAS(76);
  busra.setFN(65);
  selim.OrtalamaBul();
  busra.OrtalamaBul();
  selim.harfNotHesapla();
  busra.harfNotHesapla();

  selim.yaz();
  busra.yaz();

  // referans kullanımı
  Ogrenci &rS = selim;
  rS.yaz();

  return 0;
}