// continue_ornegi.cpp
// continue deyiminin döngü adımını nasıl atladığını gösteren örnek.
#include <iostream>
using namespace std;

int main() {
    int i;
    for(i = 0; i < 10; i++) {
        if(i == 6) continue;
        cout << i << endl;
    }
    return 0;
}