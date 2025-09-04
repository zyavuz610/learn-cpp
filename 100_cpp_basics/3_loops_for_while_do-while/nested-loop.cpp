// ic_ice_donguler.cpp
// İç içe for döngüleri kullanarak 1'den n'e kadar olan sayıların toplamını hesaplayan örnek.
#include <iostream>
using namespace std;

int main() {
    int top, n;
    cout << "N:";
    cin >> n;
    for(int i = 1; i <= n; i++) {
        top = 0;
        for(int j = 1; j <= i; j++) {
            top += j;
        }
        cout << "Toplam [1..." << i << "]: " << top << endl;
    }
    return 0;
}