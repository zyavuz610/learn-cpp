// while_toplam.cpp
// while döngüsü kullanarak n adet sayının toplamını hesaplayan örnek.
#include <iostream>
using namespace std;

int main() {
    int i = 0, n, t;
    cout << "N:";
    cin >> n;
    int top = 0;
    while(i < n) {
        cout << "[" << i + 1 << "]:";
        cin >> t;
        top += t;
        cout << "Toplam: " << top << endl;
        i++;
    }
    return 0;
}