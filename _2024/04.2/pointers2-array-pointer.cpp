#include <iostream>
using namespace std;

int main(){
    int *iPtr;
    int a[] = {5,10,15,20};
    iPtr = a; // çünkü dizinin ad aslında dizinin başlangıç adresini gösteren bir pointer'dır.
    iPtr = &a[2];  // iPtr=a; ile aynı
    cout<<&iPtr<<":"
        <<iPtr<<":"
        <<iPtr[0]<<endl;
    return 0;
}