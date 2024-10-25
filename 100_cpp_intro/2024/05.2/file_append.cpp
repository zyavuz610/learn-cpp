#include <iostream>
#include <fstream>
using namespace std;

int main(){
    cout<<"Merhaba Dünya!"<<endl;
    ofstream dosya;
    string str;
    dosya.open("out.txt",ios::app);
    while(true){
        cout<<"Girdi (cikmak icin q): ";
        getline(cin,str);
        if (str == "q") break;
        dosya<<str<<endl;
    }
    return 0;
}