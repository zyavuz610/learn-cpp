#include <iostream>
#include <iomanip>
#define SIZE 5
using namespace std; // cin, cout için

int main(){
    float asNotlar[SIZE] = {20,55,86,98,74};
    float fnNotlar[SIZE] = {55,65,75,58,99};
    string isimler[SIZE] = {
        "zafer",
        "yavuz",
        "ahmet",
        "elif",
        "betul"
    };
    //for(int i=0;i<SIZE;i++){ cin>>asNotlar[i];}   // kullanıcıdan değer almak
    cout<<setw(4)<<right<<"id";
    cout<<setw(14)<<right<<"isim";
    cout<<setw(8)<<right<<"asNot";
    cout<<endl<<"-------------------------------------"<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<setw(4)<<right<<i;
        cout<<setw(14)<<right<<isimler[i];
        cout<<setw(8)<<right<<asNotlar[i]<<endl;
    }
    cout << "C++ version: " << __cplusplus << endl;
    return 0;
}