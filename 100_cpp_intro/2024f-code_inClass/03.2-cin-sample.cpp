#include <iostream>
using namespace std;
int main(){
    string ad;
    cout<<"Profil Adiniz:";
    cin>>ad;
    while(true){
        char ch; int a;
        cout<<"Karakter (cikmak icin 0): ";
        cin>>ch;
        a = static_cast<int>(ch);
        cout << ch << ": " << a << endl;
        if (ch == '0') break;
    }
    cout<<"Gule gule "<<ad<<endl;
    return 0;
}