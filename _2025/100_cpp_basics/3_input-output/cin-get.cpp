#include <iostream>

using namespace std;

int main() {
    char ch1, ch2, ch3;
    char buffer[20]; // Karakter dizisi tanımlama
    
    // cin.get(char_degisken) kullanımı
    cout << "Tek bir karakter girin (ornegin: A): ";
    cin.get(ch1); // A girilirse, 'A' karakterini okur
    cout << "Okunan karakter: " << ch1 << endl;
    
    // Not: Girdi akışında (input stream) Enter'a basıldığında oluşan '\n' karakteri kaldı.
    // Bir sonraki cin.get() bu karakteri okuyacak.
    cout << "Tek bir karakter daha girin: ";
    cin.get(ch2); // Önceki girdiden kalan '\n' karakterini okur.
    cout << "Okunan karakter: " << static_cast<int>(ch2) << " (ASCII degeri)" << endl;
    
    // Gördüğünüz gibi, Enter'dan kalan karakter sorun yarattı.
    // Bu yüzden cin.ignore() ile buffer'ı temizleyelim.
    cin.ignore();
    
    // Tekrar deneyelim
    cout << "Tek bir karakter daha girin: ";
    cin.get(ch3);
    cout << "Okunan karakter: " << ch3 << endl;
    
    // cin.get(char_dizisi, boyut) kullanımı
    cout << "\nEn fazla 19 karakterlik bir cumle girin: ";
    cin.get(buffer, 20); // 19 karakter veya Enter'a kadar okur
    cout << "Okunan cumle: " << buffer << endl;
    
    // cin.get() zincirleme kullanımı
    cout << "\nBir sehir ve ulke girin (ornegin: Istanbul Turkiye): ";
    char sehir[20], ulke[20];
    cin.get(sehir, 20, ' ').get(); // ' ' karakterine kadar okur, sonra o karakteri atlar.
    cin.get(ulke, 20);
    
    cout << "Girilen sehir: " << sehir << endl;
    cout << "Girilen ulke: " << ulke << endl;

    return 0;
}