#include <iostream>

using namespace std;

int main() {
    int n;
    double toplam = 0.0;
    
    // Sabit boyutlu bir dizi tanımlayalım.
    double sayilar[100]; 

    cout << "Kac adet sayi girmek istiyorsunuz? (Maksimum 100): ";
    cin >> n;

    if (n <= 0 || n > 100) {
        cout << "Lutfen 1 ile 100 arasinda bir tamsayi girin." << endl;
        return 1;
    }

    cout << "Lutfen " << n << " adet sayi girin:" << endl;

    // Sayıları kullanıcıdan alıp diziye ekleyelim.
    for (int i = 0; i < n; ++i) {
        cin >> sayilar[i];
    }

    // Dizideki sayıların toplamını bulalım.
    for (int i = 0; i < n; ++i) {
        toplam += sayilar[i];
    }

    cout << "Girdiginiz sayilarin toplami: " << toplam << endl;

    return 0;
}