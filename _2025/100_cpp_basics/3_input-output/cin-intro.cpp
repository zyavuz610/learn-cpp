#include <iostream>

using namespace std;

int main() {
    int yil;

    cout << "Bir yil girin: ";
    cin >> yil;

    // Yüzyılın hesaplanması:
    // Yılın son iki basamağı 00 ise (örn: 1900), yüzyıl = (yıl / 100).
    // Aksi halde (örn: 1901), yüzyıl = (yıl / 100) + 1.
    int yuzyil = (yil % 100 == 0) ? (yil / 100) : (yil / 100) + 1;

    cout << "Girdiginiz yil " << yuzyil << ". yuzyila aittir." << endl;

    return 0;
}