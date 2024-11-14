#include <iostream>
using namespace std;

int main() {
    /*
    tür dönüşümü (type conversion) ya da dönüşüm (conversion), bir veri türünü başka bir veri türüne dönüştürme işlemidir.
    C++'ta tür dönüşümü 2 şekilde yapılır:
    1. C-Style Cast: (int) x
    2. C++-Style Cast: static_cast<int>(x)

    veri kaybı olmadan dönüşüm yapılabilir, veri kaybı olabilecek dönüşümler için dönüşüm yapılırken dikkatli olunmalıdır.
    küçük türden büyük türe dönüşümde veri kaybı olmaz, büyük türden küçük türe dönüşümde veri kaybı olabilir.
    örneğin; 
    int i = 10;
    double d = (double)i;  // int'ten double'a dönüşümde veri kaybı olmaz

    double d = 3.14;
    int i = (int)d;  // double'dan int'e dönüşümde veri kaybı olabilir

    bunların dışında tür dönüşümü otomatik olarak yapılır, örneğin;
    int i = 10;
    double d = i;  // int'ten double'a dönüşüm otomatik yapılır

    */
    double d = 3.14;
    int i = (int)d;  // C-Style Cast
    cout << "C-Style Cast ile double'dan int'e dönüştürülen değer: " << i << std::endl;
    
// -------------------------------------------------------
    /*
    // C++'ta static_cast kullanımı, C++ tarzı dönüşüm
     double d = 4.56;
    int i = static_cast<int>(d);  // static_cast kullanarak dönüşüm
    cout << "static_cast ile double'dan int'e dönüştürülen değer: " << i << std::endl;
    */

//---------------------------------------------------------------------
/*
bunların dışında
Özet:
dynamic_cast: Çalışma zamanında tür güvenliğini kontrol eden, kalıtım yapılarında kullanılan dönüşüm.
    Base* basePtr = new Derived();  // Base türünde işaretçi, Derived nesnesini işaret ediyor.
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);  // dynamic_cast ile dönüşüm

const_cast: const veya volatile niteliklerini kaldırıp eklemek için kullanılır.
    const int x = 10;  // const bir değişken
    // const_cast ile const niteliğini kaldırmak
    int& y = const_cast<int&>(x);  // Referans üzerinden const kaldırıldı
    // y içeriği artık değiştirilebilir.

reinterpret_cast: Bellek seviyesinde bit düzeyinde dönüşümler yapar, dikkatli kullanılmalıdır.
    int num = 65;
    char* ch = reinterpret_cast<char*>(&num);
*/  

    return 0;
}
