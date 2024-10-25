#include <iostream>
#include <fstream>
using namespace std;

int main(){
    cout<<"Merhaba Dünya!"<<endl;
    ofstream dosya;
    dosya.open("out.txt");
    dosya<<"Merhaba KTÜ!"<<endl;

    return 0;
}