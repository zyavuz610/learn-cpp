#include <iostream>
#include <string>

using namespace std;

int main() {
    // birden çok değişkeni aynı anda giriş yapma örneği
    int yas;
    double boy;
    
    cout << "Yasinizi ve boyunuzu (metre cinsinden) girin (ornegin: 30 1.75):" << endl;
    cin >> yas >> boy;
    cout << "Yasiniz: " << yas << ", Boyunuz: " << boy << "m" << endl;
    
    // getline() ile boşluklu string alma örneği
    // cin'den sonra getline() kullanmadan önce buffer'ı temizlemeliyiz.
    // aksi halde cin'den kalan yeni satır karakteri getline() tarafından okunur.
    cin.ignore(); 
    
    string tam_ad;
    cout << "\nTam adinizi girin (bosluklu):" << endl;
    getline(cin, tam_ad);
    cout << "Girdiginiz tam ad: " << tam_ad << endl;

    // cin >> ile tek kelimelik string alma örneği
    string ilk_ad;
    cout << "\nIlk adinizi girin:" << endl;
    cin >> ilk_ad;
    cout << "Girdiginiz ilk ad: " << ilk_ad << endl;
    
    return 0;
}