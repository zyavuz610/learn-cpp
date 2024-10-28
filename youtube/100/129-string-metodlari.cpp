/*
  String İşlemleri 2
    string namespace
    string birleştirme,
    string uzunluğu, size(), length()
    tür dönüştürme, stoi, to_string()
    
*/
#include <iostream>


int main() {
  std::cout << "Merhaba!\n";
  std::string s1="Trabzon";
  std::string s2="Bursa";
  int n = 130;
  std::string s3 = s1 + " " + s2 + std::to_string(n);
  std::cout<<s3<<std::endl;
  std::cout<<"s1 uzunluk:"<<s1.length()<<"\n";
  std::cout<<"s2 uzunluk:"<<s2.length()<<"\n";
  std::cout<<"s3 uzunluk:"<<s3.size()<<"\n";
  std::string str = "20";
  int m = 30;
  int sonuc = m + std::stoi(str);
  std::cout<<sonuc<<std::endl;
}