/*
5. örnek
  *
 ***
*****
 ***
  *

*/
#include <iostream>
using namespace std;
int main(){
    int n=5;
    char ch1='*';
    for(int i=-n;i<=n;i++){
        for(int j=-n;j<=n;j++){
            if(i-j+n>0 && i-j-n<0 && i+j+n>0 && i+j-n<0){
                cout<<ch1;
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}