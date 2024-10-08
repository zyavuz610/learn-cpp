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
    

    return 0;
}
