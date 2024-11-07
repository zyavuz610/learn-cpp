#include <iostream>
using namespace std;

class Kutu {
    public:
        Kutu(); // ctor, yapıcı
        Kutu(double x); // ctor, tüm boyutları aynı değere ata
        Kutu(double,double,double);
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
    Kutu k1,k2[2],*k3,k4(1.5),*k5;
    k3 = new Kutu();
    k5 = new Kutu(0.5);
    cout<<"------------------------"<<endl;
    Kutu k6[3] = {Kutu(), Kutu(02), Kutu(1,2,3)};
    Kutu k7(2,3,4);
    new Kutu(4,5,6);
    return 0;
}


//-------------------------------------------------------------------
Kutu::Kutu(){
    en=0;
    boy=0;
    yuk=0;
    volume=0;
    cout<<"ctor calistirildi"<<endl;
}
Kutu::Kutu(double x){
    cout<<"ctor2 calistirildi"<<endl;
    en = boy = yuk = x;
    volume = en*boy*yuk;
}
Kutu::Kutu(double en_,double boy_,double yuk_){
    en = en_;
    boy = boy_;
    yuk = yuk_;
    volume = en*boy*yuk;
    cout<<"ctor3 calistirildi..."<<endl;
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