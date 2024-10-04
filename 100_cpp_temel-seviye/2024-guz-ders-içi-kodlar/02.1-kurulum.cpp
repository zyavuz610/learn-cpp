/*
https://www.mingw-w64.org/ dan w64devkit indirin
dosyayı açın
yeni oluşan dizini C'ye kopyalayın
bin dizinin yolunu (C:\w64devkit\bin) sistem değişkenlerinden Path'e ekleyin

yanyana 24 adet yıldız

123456789012345678901234
************************

*/

#include <iostream>
using namespace std;
int main(){
    cout<<"herkese merhaba\n";
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