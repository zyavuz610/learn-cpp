#include <iostream>
#include <cctype> // isdigit fonksiyonu için

using namespace std;

int main() {
    cout << "Sayisal bir deger girin, ardindan bir harf (ornegin: 123a): ";

    char ch;
    
    // peek() fonksiyonu, girdi akışındaki bir sonraki karakteri okur,
    // ancak onu akıştan çıkarmaz.
    // Bu, akıştaki bir sonraki karakterin ne olduğunu anlamamızı sağlar,
    // böylece ona göre bir işlem yapabiliriz.

    ch = cin.peek();

    // isdigit(ch) fonksiyonu, ch'nin bir rakam olup olmadığını kontrol eder.
    if (isdigit(ch)) {
        int sayi;
        cin >> sayi; // Akıştaki rakamı oku ve 'sayi' değişkenine ata
        cout << "Bir sayi okundu: " << sayi << endl;
    } else {
        cout << "Bir sayi girisi bekleniyordu, ancak ilk karakter bir rakam degil." << endl;
    }
    
    cout << "---" << endl;

    // Tekrar deneyelim ve bu sefer kalan karakteri okuyalım.
    cout << "Kalan karakterleri okuma:" << endl;
    cin.get(ch); // Akıştaki sonraki karakteri (yani ilk harfi) oku
    cout << "Okunan karakter: " << ch << endl;

    return 0;
}