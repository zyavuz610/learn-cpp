#include <iostream>
#include <fstream>
#define SIZE 100
using namespace std;

int main(){
    ofstream dosyaOut;
    ifstream dosyaIn;
    string str;
    int n1,n2;
    int dizi1[SIZE],dizi2[SIZE];
    dosyaOut.open("output.txt",ios::out);
    dosyaIn.open("input1.txt",ios::in);
    dosyaIn>>n1;
    for(int i=0;i<n1;i++){
        dosyaIn>>dizi1[i];
    }

    for(int i=0;i<n1;i++){
        dosyaOut<<dizi1[i]<<" ";
        cout<<dizi1[i]<<" ";
    }
    dosyaIn.close();
    dosyaOut.close();
    return 0;
}