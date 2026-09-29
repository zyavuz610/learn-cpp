#include <iostream>
#include <iomanip> // setw, left, right için gerekli

using namespace std;

int main() {
    string ad1 = "Ahmet";
    string ad2 = "Ayse";
    string ad3 = "Mehmet";

    double fiyat1 = 12.3;
    double fiyat2 = 125.75;
    double fiyat3 = 24.5;
    
    // Varsayılan hizalama sağa dayalıdır.
    cout << "--- Varsayilan Hizalama (Saga Dayali) ---" << endl;
    cout << setw(10) << "Urun" << setw(10) << "Fiyat" << endl;
    cout << setw(10) << ad1 << setw(10) << fiyat1 << endl;
    cout << setw(10) << ad2 << setw(10) << fiyat2 << endl;
    cout << setw(10) << ad3 << setw(10) << fiyat3 << endl;

    cout << "\n--- Sola Dayali Hizalama (left) ---" << endl;
    // `left` manipülatörü, bir sonraki çıktıyı belirlenen genişlikte sola hizalar.
    // Bu ayar, siz `right` veya `internal` kullanana kadar kalıcıdır.
    cout << left;
    cout << setw(10) << "Urun" << setw(10) << "Fiyat" << endl;
    cout << setw(10) << ad1 << setw(10) << fiyat1 << endl;
    cout << setw(10) << ad2 << setw(10) << fiyat2 << endl;
    cout << setw(10) << ad3 << setw(10) << fiyat3 << endl;

    cout << "\n--- Saga Dayali Hizalama (right) ---" << endl;
    // `right` manipülatörü, çıktıyı belirlenen genişlikte sağa hizalar.
    // Bu da kalıcı bir ayardır.
    cout << right;
    cout << setw(10) << "Urun" << setw(10) << "Fiyat" << endl;
    cout << setw(10) << ad1 << setw(10) << fiyat1 << endl;
    cout << setw(10) << ad2 << setw(10) << fiyat2 << endl;
    cout << setw(10) << ad3 << setw(10) << fiyat3 << endl;
    
    // Not: `left` ve `right` manipülatörleri, `cout.setf(ios_base::left)`
    // ve `cout.setf(ios_base::right)` şeklinde de kullanılabilir.
    
    return 0;
}