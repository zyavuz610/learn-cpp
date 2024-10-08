/*
24 adet * yaz, başına rehber sayılar yaz

yanyana 24 adet yıldız

123456789012345678901234
************************

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