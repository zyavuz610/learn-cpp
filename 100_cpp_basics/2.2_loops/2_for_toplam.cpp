// for_toplam.cpp
// Kullanıcının girdiği n adet sayının toplamını hesaplayan for döngüsü örneği.
#include <iostream>
using namespace std;

int main() {
    int i, n, t;
    cout << "N:";
    cin >> n;
    int top = 0;
    for(i = 0; i < n; i++) {
        cout << "[" << i + 1 << "]:";
        cin >> t;
        top += t;
        cout << "Toplam: " << top << endl;
    }
    return 0;
}