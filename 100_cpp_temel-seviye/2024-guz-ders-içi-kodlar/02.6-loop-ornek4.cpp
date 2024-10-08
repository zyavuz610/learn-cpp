/*
4. örnek
*
**
***
****
*****
****
***
**
*

*/
#include <iostream>
using namespace std;
int main(){
    int n=5,m;
    char ch1='*';
    cout<<endl;
    for(int i=0;i<2*n-1;i++){
        if(i<n){
            m=i+1;
        }else{
            m=2*n-i-1;
        }
        for(int j=0;j<m;j++){
            cout<<ch1;
        }
        cout<<endl;
    }
    return 0;
}