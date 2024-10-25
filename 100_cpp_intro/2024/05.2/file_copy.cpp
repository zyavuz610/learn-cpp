#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream dosyaOut;
    ifstream dosyaIn;
    string str;
    dosyaOut.open("out.txt",ios::app);
    dosyaIn.open("input.txt",ios::in);
    while(true){
        getline(dosyaIn,str);
        if (str == "q") break;
        dosyaOut<<str<<endl;
    }
    dosyaOut.close();
    return 0;
}