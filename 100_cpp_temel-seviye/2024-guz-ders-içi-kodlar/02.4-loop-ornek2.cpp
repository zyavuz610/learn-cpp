/*
24 adet * yaz, başına rehber sayılar yaz
*/
#include <iostream>
using namespace std;
int main(){
    int n=24;
    for(int i=0;i<n;i++){
        cout<<( (i+1)%10 );
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<"*";
    }
    return 0;
}