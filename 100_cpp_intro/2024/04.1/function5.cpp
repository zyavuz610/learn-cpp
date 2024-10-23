#include <iostream>
using namespace std;

// void myfunc(void);
// void myfunc(int,int);

// fonksyon parametrelerinin const olması
int myfunc(const int a=1,const int b=2){
    //.....
    //a = 20; b=30;
    int toplam = a+b;
    return toplam;
}

int main(){
    // bu değerleri kullanıcıdan gerektiğinde burada alabiliriz
    int a=5,b=6,top;
    top = myfunc(a,b);
    cout<<"Toplam1 = "<<top<<endl;


    a=10; b=16;
    cout<<"Toplam2 = "<<myfunc()<<endl;
    return 0;
}

//----------------------------------------------------
