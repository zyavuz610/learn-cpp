#include <iostream>
#include <string>
#include <cstring> // C karakter dizisi fonksiyonları için

using namespace std;

int main() {
    // --- 1. C++ std::string Sınıfı ile String Dizisi Oluşturma ---
    cout << "--- C++ std::string Dizisi ---" << endl;
    
    // std::string dizisi tanımlama ve ilk değer ataması
    string meyveler[] = {"Elma", "Armut", "Kiraz", "Muz"};
    
    // Dizi elemanlarını ekrana yazdırma
    cout << "Meyve listesi:" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << meyveler[i] << endl;
    }
    
    // Dizi elemanını değiştirme
    meyveler[2] = "Portakal";
    cout << "\nKiraz yerine Portakal eklendi:" << endl;
    cout << meyveler[2] << endl;
    
    // Dizideki bir elemanın uzunluğunu bulma
    cout << "\n'Portakal' kelimesinin uzunlugu: " << meyveler[2].length() << endl;

    cout << "\n----------------------------------------\n" << endl;
    
    // --- 2. C Karakter Dizileri (char dizisi) ile String Dizisi Oluşturma ---
    cout << "--- C Karakter Dizisi Dizisi (char dizisi) ---" << endl;
    
    // char dizisi dizisi tanımlama ve ilk değer ataması
    // Her bir string için maksimum boyutu belirtmek gerekir.
    char hayvanlar[4][15] = {"Kedi", "Kopek", "Fil", "Aslan"};
    
    // Dizi elemanlarını ekrana yazdırma
    cout << "Hayvan listesi:" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << hayvanlar[i] << endl;
    }
    
    // Dizi elemanını değiştirme
    // C karakter dizilerini değiştirmek için strcpy() fonksiyonu kullanılır.
    // DİKKAT: Yeni stringin boyutu, hedef dizinin boyutunu aşmamalıdır!
    strcpy(hayvanlar[2], "Kaplan");
    cout << "\nFil yerine Kaplan eklendi:" << endl;
    cout << hayvanlar[2] << endl;
    
    // Dizideki bir elemanın uzunluğunu bulma
    // strlen() fonksiyonu ile uzunluk bulunur.
    cout << "\n'Kaplan' kelimesinin uzunlugu: " << strlen(hayvanlar[2]) << endl;

    return 0;
}