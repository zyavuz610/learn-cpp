// for_alternatif.cpp
// for döngüsü içinde birden fazla ifade kullanarak n adet sayının toplamını hesaplayan alternatif örnek.
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "N:";
    cin >> n;
    for(int i = 0, t, top = 0; i < n; top += t, cout << "Toplam: " << top << endl, i++) {
        cout << "[" << i + 1 << "]:";
        cin >> t;
    }
    return 0;
}