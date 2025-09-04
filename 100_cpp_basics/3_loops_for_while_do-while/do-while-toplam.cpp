// do_while_toplam.cpp
// do-while döngüsü kullanarak n adet sayının toplamını hesaplayan örnek.
#include <iostream>
using namespace std;

int main() {
    int i = 0, n, t, top = 0;
    cout << "N:";
    cin >> n;
    do {
        cout << "[" << i + 1 << "]:";
        cin >> t;
        top += t;
        cout << "Toplam: " << top << endl;
        i++;
    } while(i < n);
    return 0;
}