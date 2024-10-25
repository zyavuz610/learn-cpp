#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream dosyaOut;
    ifstream dosyaIn;
    string str,str2;
    int starti=0,stopi;
    dosyaOut.open("out.txt",ios::out);
    dosyaIn.open("input3.txt",ios::in);
    while(!dosyaIn.eof()){
        getline(dosyaIn,str);
        for(int j=0;j<str.length();j++){
            stopi=str.length();
            if(str[j]==','){
                stopi=j;
                str2 = str.substr(starti,stopi);
                cout<<str2<<endl;
                break;
            }
        }
        dosyaOut<<str<<endl;
    }
    dosyaOut.close();
    return 0;
}