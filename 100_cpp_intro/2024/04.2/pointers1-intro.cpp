#include <iostream>
using namespace std;

int main(){
    int *iPtr;
    int a = 10;
    iPtr = &a;
    cout<<&iPtr<<":"
        <<iPtr<<":"
        <<*iPtr<<endl;
    return 0;
}