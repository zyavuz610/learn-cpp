#include <iostream>
using namespace std;

class Kutu {
    public:
        Kutu();
        void getValues();
        double VolumeCalculation();
        void printData();
        void all_in_one();
        void set_en(double en_);
        void set_boy(double boy_);
        void set_yuk(double yuk_);
        double get_en();
        double get_boy();
        double get_yuk();
        double get_volume();
    private:
        double en;
        double boy;
        double yuk;
        double volume;
};

int main(){
    Kutu k1;
    int a = 0, b = 1;
    cout<<"Hacim:"<<k1.get_volume()<<endl;
    k1.set_en(10);   // k1.en = 10;  HATA!
    k1.set_boy(20);
    k1.set_yuk(35);
    k1.VolumeCalculation();
    cout<<"Hacim:"<<k1.get_volume()<<endl;
    return 0;
}

//-------------------------------------------------------------------
Kutu::Kutu(){
    en=1;
    boy=1;
    yuk=1;
    volume=10;
}
void Kutu::getValues(){
    cout<<"3 deger giriniz:";
    cin>>en>>boy>>yuk;
}

double Kutu::VolumeCalculation() {
    volume = en*boy*yuk;
    return volume;
}

void Kutu::printData(){
    cout<<"("<<en<<",";
    cout<<boy<<","<<yuk<<") ==> ";
    cout<<volume<<endl;
}

void Kutu::all_in_one(){
    getValues();
    VolumeCalculation();
    printData();
}

void Kutu::set_en(double en_){ en = en_;}
void Kutu::set_boy(double boy_)  { boy = boy_;}
void Kutu::set_yuk(double yuk_)  { yuk = yuk_;}
double Kutu::get_en()  {return en;}
double Kutu::get_boy()  {return boy;}
double Kutu::get_yuk()  {return yuk;}
double Kutu::get_volume()   {return volume;}