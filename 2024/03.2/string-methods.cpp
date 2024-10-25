#include <iostream>
#include <iomanip>
#include <cstring>

#define SIZE 50
using namespace std; // cin, cout için

int main(){
    string str = "Merhaba KTU";
    cout<<"Size:"<<str.size()<<endl;
    cout<<"Length:"<<str.length()<<endl;
    cout<<"Kapasite:"<<str.capacity()<<endl;
    str.append("abcde");
    cout<<"Kapasite2:"<<str.capacity()<<endl;
    str.shrink_to_fit();
    cout<<"Kapasite3:"<<str.capacity()<<endl;
    char cstr[SIZE];
    strcpy(cstr,str.c_str());
    cout<<"ilk karakter:"<<cstr[0] << " "<< static_cast<int>(cstr[0])<<endl;

    string str2 = "20,36,zafer,45,89";
    return 0;
}