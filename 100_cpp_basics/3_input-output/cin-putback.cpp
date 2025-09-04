#include <iostream>

using namespace std;

int main() {
    char ch;

    cout << "Bir karakter girin: ";
    cin.get(ch); // Klavyeden bir karakter oku

    cout << "Girilen karakter: " << ch << endl;

    // cin.putback() fonksiyonu, okunan son karakteri geri girdi akışına koyar.
    // Bu, bir sonraki okuma işleminin aynı karakteri tekrar okumasını sağlar.
    // Bu örnekte, 'cin.get(ch)' ile okuduğumuz 'ch' karakterini geri itiyoruz.
    cin.putback(ch); 

    // Geri itilen karakteri tekrar okuyalım.
    char ch2;
    cin.get(ch2); 

    cout << "Geri itilen ve tekrar okunan karakter: " << ch2 << endl;

    return 0;
}