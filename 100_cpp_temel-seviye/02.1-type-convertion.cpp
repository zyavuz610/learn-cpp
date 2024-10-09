#include <iostream>
using namespace std;

int main() {
    /*
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
