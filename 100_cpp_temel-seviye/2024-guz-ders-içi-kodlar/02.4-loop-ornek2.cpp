/*
24 adet * yaz, başına rehber sayılar yaz

2. örnek
123456789012345678901234
***...***...***...***...

*/
#include <iostream>
using namespace std;
int main(){
    int n=24,m=3;
    char ch1='*',ch2='.';
    for(int i=0;i<n;i++){
        cout<<( (i+1)%10 );
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        if((i/m)%2==0){
            cout<<ch1;
        }else{
            cout<<ch2;
        }
    }
    return 0;
}