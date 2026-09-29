#include <iostream>
#include <string>

using namespace std;

int main() {
    int sayi;
    char karakter;
    string tam_isim;

    cout << "Bir sayi ve bir karakter girin (ornegin: 12 A): ";
    cin >> sayi >> karakter;

    // cin >> sayi ve cin >> karakter islemleri, girdi akisinda (input stream)
    // sayi ve karakteri okur. Ancak, Enter tusuna basildiginda olusan
    // '\n' (yeni satir) karakteri girdi akisinda kalir.
    // Eger bu '\n' karakterini temizlemezsek, sonraki getline() fonksiyonu
    // bos bir satir okur ve program beklenen gibi calismaz.

    // Ilk kullanimi: Buffer'daki tum karakterleri temizle
    // cin.ignore() fonksiyonu, bir karakteri (varsayilan) veya belirtilen
    // sayida karakteri (ilk parametre) belirli bir karakter (ikinci parametre)
    // gorulene kadar yok sayar.
    // numeric_limits<streamsize>::max() ile buffer'daki maksimum karakteri yok sayariz.
    // '\n' ile de yeni satir karakterine kadar durmasini soyleriz.
    // Bu, buffer'daki her seyi temizlemek icin guvenli bir yontemdir.
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Adinizi ve soyadinizi girin: ";
    getline(cin, tam_isim);

    cout << "--- Girdiler ---" << endl;
    cout << "Girilen sayi: " << sayi << endl;
    cout << "Girilen karakter: " << karakter << endl;
    cout << "Girilen tam isim: " << tam_isim << endl;
    cout << "------------------" << endl;

    // İkinci kullanimi: Belirli sayida karakteri yok sayma
    cout << "\nBir sehir kodu (orn. 34) ve sonrasinda herhangi bir metin girin: ";
    cin >> sayi;

    // cin.ignore(20, ' ');
    // Bu kullanim, 20 karaktere kadar veya bir bosluk (' ') gorulene kadar
    // girdi akisindaki karakterleri yok sayar.
    // Bu ornekte, sehirden sonra gelen bosluga kadar olan kismi atlayacaktir.
    cin.ignore(20, ' ');
    getline(cin, tam_isim);

    cout << "--- Girdiler ---" << endl;
    cout << "Girilen sehir kodu: " << sayi << endl;
    cout << "Girdinin geri kalani: " << tam_isim << endl;
    cout << "------------------" << endl;
    
    return 0;
}