#include <iostream>
using namespace std;

// void myfunc(void);
// void myfunc(int,int);

void myfunc(int a,int b){
    int toplam = a+b;
    cout<<a<<" + "<<b<<" = "<<toplam<<endl;
}

int main(){
    // bu değerleri kullanıcıdan gerektiğinde burada alabiliriz
    myfunc(5,6);
    myfunc(10,16);
    return 0;
}

//----------------------------------------------------
