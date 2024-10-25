#include <iostream>
using namespace std;

// void myfunc(void);
// void myfunc(int,int);

// parametreler için default değerler alması ve çağrılması
int myfunc(int a=1,int b=2){
    int toplam = a+b;
    return toplam;
}

int main(){
    // bu değerleri kullanıcıdan gerektiğinde burada alabiliriz
    int a=5,b=6,top;
    top = myfunc(a);
    cout<<"Toplam = "<<top<<endl;


    a=10; b=16;
    cout<<"Toplam = "<<myfunc()<<endl;
    return 0;
}

//----------------------------------------------------
