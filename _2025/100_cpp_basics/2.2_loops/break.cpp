// break_ornegi.cpp
// break deyiminin for döngüsünü nasıl sonlandırdığını gösteren örnek.
#include <iostream>
using namespace std;

int main() {
    int i;
    for(i = 0; i < 10; i++) {
        if(i == 6) break;
        cout << i << endl;
    }
    return 0;
}