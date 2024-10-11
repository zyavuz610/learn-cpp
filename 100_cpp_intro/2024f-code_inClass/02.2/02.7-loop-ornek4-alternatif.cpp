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
    for(int i=-n;i<=n;i++){
        for(int j=-n;j<=n;j++){
            if(j<0 && i-j>0 && i+j<0){
                cout<<ch1;
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}