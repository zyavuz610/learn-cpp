/*
24 adet * yaz, başına rehber sayılar yaz

3. örnek
123456789012345678901234
***...***...***...***...
***...***...***...***...
...***...***...***...***
...***...***...***...***
***...***...***...***...
***...***...***...***...
...***...***...***...***
...***...***...***...***

*/
#include <iostream>
using namespace std;
int main(){
    int n=24,m=3,nh=8,mh=2;
    char ch1='*',ch2='.',ch11,ch22;
    cout<<"  ";
    for(int i=0;i<n;i++){
        cout<<( (i+1)%10 );
    }
    cout<<endl;
    for(int i=0;i<nh;i++){
        cout<<i<<" ";
        if((i/mh)%2==0){
            ch11=ch1;
            ch22=ch2;
        }
        else{
            ch11=ch2;
            ch22=ch1;
        }
        for(int j=0;j<n;j++){
            if((j/m)%2==0){
                cout<<ch11;
            }else{
                cout<<ch22;
            }
        }
        cout<<endl;
    }
    return 0;
}