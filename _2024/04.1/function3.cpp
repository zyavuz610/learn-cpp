#include <iostream>
using namespace std;

// void myfunc(void);
// void myfunc(int,int);

// fonksiyon geridönüş değeri
int myfunc(int a,int b){
    int toplam = a+b;
    return toplam;
    // cout<<a<<" + "<<b<<" = "<<toplam<<endl;
}

int main(){
    // bu değerleri kullanıcıdan gerektiğinde burada alabiliriz
    int a=5,b=6,top;
    top = myfunc(a,b);
    cout<<a<<" + "<<b<<" = "<<top<<endl;


    a=10; b=16;
    cout<<a<<" + "<<b<<" = "<<myfunc(a,b)<<endl;
    return 0;
}

//----------------------------------------------------
