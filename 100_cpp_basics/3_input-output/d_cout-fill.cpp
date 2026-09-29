#include <iostream>
#include <iomanip> // setw, setfill için gerekli

using namespace std;

int main() {
    double fiyat = 49.99;
    string urun = "Klavye";

    cout << "--- Varsayilan Cikis ---" << endl;
    cout << setw(15) << urun << setw(10) << fiyat << endl;

    cout << "\n--- setfill Kullanimi ---" << endl;
    // `setfill()` fonksiyonu, `setw()` ile belirlenen boşlukları doldurmak için
    // kullanılacak karakteri belirler. Bu, özellikle tablolar veya
    // formatlı çıktılar oluştururken faydalıdır.
    
    // Varsayılan dolgu karakteri boşluktur.
    // İlk olarak '*' karakterini dolgu olarak ayarlayalım.
    cout << setfill('*');
    
    // `setw()` ile genişlik belirleyerek çıktı alalım.
    cout << "Yildiz (*) ile doldurma:" << endl;
    cout << setw(15) << urun << setw(10) << fiyat << endl;
    
    // Şimdi '.' karakterini dolgu olarak ayarlayalım.
    cout << setfill('.');
    cout << "\nNokta (.) ile doldurma:" << endl;
    cout << setw(15) << urun << setw(10) << fiyat << endl;
    
    // `setfill()` fonksiyonu, `cout.fill()` ile de kullanılabilir.
    cout << "\n--- cout.fill Kullanimi ---" << endl;
    
    // Varsayılan dolgu karakterini ' ' olarak geri ayarlayalım.
    cout.fill(' ');
    cout << setw(15) << urun << setw(10) << fiyat << endl;

    // Farklı bir karakterle dolduralım.
    cout.fill('-');
    cout << "\nCizgi (-) ile doldurma:" << endl;
    cout << setw(15) << urun << setw(10) << fiyat << endl;
    
    return 0;
}