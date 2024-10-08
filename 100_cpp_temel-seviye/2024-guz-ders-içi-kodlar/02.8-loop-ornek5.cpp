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
    int bosN = n-1,bosDelta = -1;
    int yildizN = 1,yildizDelta = 2;
    char ch1='*';
    for(int i=0;i<2*n;i++){
        for(int j=0;j<bosN;j++){
            cout<<" ";
        }
        for(int j=0;j<yildizN;j++){
            cout<<ch1;
        }
        bosN+=bosDelta;
        yildizN+=yildizDelta;
        if(bosN==0){
            bosDelta=1;
            yildizDelta=-2;
        }
        cout<<endl;
    }
    return 0;
}