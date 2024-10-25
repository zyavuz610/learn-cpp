#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream dosyaOut;
    ifstream dosyaIn;
    string str;
    dosyaOut.open("out.txt",ios::out);
    dosyaIn.open("input.txt",ios::in);
    while(!dosyaIn.eof()){
        getline(dosyaIn,str);
        dosyaOut<<str<<endl;
    }
    dosyaOut.close();
    return 0;
}