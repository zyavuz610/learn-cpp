#include <iostream>
#define MAX_SIZE 100
#define MAX_SES_DUZEYI 30
using namespace std;

class Kumanda {
private:
    string kanal_listesi[MAX_SIZE];
    int kanal_sayisi;
    int ses_duzeyi;
    int aktif_kanal;
    string TVisim;
public:
    Kumanda(string isim){
        kanal_listesi[0] = "atv"; kanal_sayisi++;
        kanal_listesi[1] = "show"; kanal_sayisi++;
        kanal_listesi[2] = "flash"; kanal_sayisi++;
        kanal_listesi[3] = "ht"; kanal_sayisi++;
        kanal_listesi[4] = "tv100"; kanal_sayisi++;
        kanal_listesi[5] = "fox"; kanal_sayisi++;
        kanal_listesi[6] = "trt"; kanal_sayisi++;
        ses_duzeyi = 10;
        aktif_kanal = 0;
        TVisim = isim;
    }
    void sesArttir(){
        if(ses_duzeyi < MAX_SES_DUZEYI){
            ses_duzeyi++;
        }
    }
    void sesAzalt(){
        if(ses_duzeyi > 0){
            ses_duzeyi--;
        }
    }
    void kanalYukari(){
        aktif_kanal = (aktif_kanal+1) % kanal_sayisi;
        aktifKanalYaz();
    }
    void kanalAsagi(){
        aktif_kanal = (aktif_kanal+kanal_sayisi-1) % kanal_sayisi;
        aktifKanalYaz();
    }
    void aktifKanalYaz(){
        cout<<TVisim<<"=> ";
        cout<<"Aktif Kanal:"<<kanal_listesi[aktif_kanal]<<endl;
    }
};

void menu(){
    cout<<"------------------------------"<<endl;
    cout<<"1. Aktif Kanal Yaz"<<endl;
    cout<<"2. Kanal Yukari"<<endl;
    cout<<"3. Kanal Aşagi"<<endl;
    cout<<"4. Ses Duzeyi Arttir"<<endl;
    cout<<"5. Ses Duzeyi Azalt"<<endl;
    cout<<"6. Diger TV'ye gec"<<endl;
    cout<<"7. Kapat"<<endl;
}

int main(){
    Kumanda k[3] = {Kumanda("A"),Kumanda("B"),Kumanda("C")};
    int N = 3,ind = 0,sec;
    while(true){
        menu();
        cout<< "Secim: ";
        cin>>sec;
        if(sec == 1){
            (k+ind)->aktifKanalYaz();
        }
        else if(sec == 2){
            k[ind].kanalYukari();
        }
        else if(sec == 3){
            k[ind].kanalAsagi();
        }
        else if(sec == 4){
            k[ind].sesArttir();
        }
        else if(sec == 5){
            k[ind].sesAzalt();
        }
        else if(sec == 6){
            ind = (ind+1) % N;
        }
        else if(sec == 7){
            cout<<"Bye..."<<endl;
            break;
        }
        else {
            break;
        }
    }
    return 0;
}