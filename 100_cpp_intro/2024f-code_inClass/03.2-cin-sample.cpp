#include <iostream>
using namespace std;
int main(){
    return 0;
    while(true){
        char ch; int a;
        cout<<"Karakter (çıkmak için 0): ";
        cin>>ch;
        a = static_cast<int>(ch);
        cout << ch << ": " << a << endl;
    }
}