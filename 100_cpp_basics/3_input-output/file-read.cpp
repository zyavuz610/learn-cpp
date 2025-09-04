#include <iostream>
#include <fstream> // Dosya işlemleri için gerekli
#include <string>

using namespace std;

int main() {
    // 1. Bir ifstream nesnesi oluştur.
    // ifstream, dosyadan okuma işlemleri için kullanılır.
    // Nesneyi oluştururken okunacak dosyanın adını parametre olarak ver.
    ifstream dosya_okuma("ornek.txt");

    // 2. Dosyanın başarılı bir şekilde açılıp açılmadığını kontrol et.
    // is_open() fonksiyonu, dosya açıldıysa true, açılmadıysa false döndürür.
    // Dosya yoksa veya okuma izni yoksa açılmayabilir.
    if (!dosya_okuma.is_open()) {
        cerr << "Hata: Dosya acilamadi veya bulunamadi!" << endl;
        return 1; // Programı hata koduyla sonlandır.
    }

    // 3. Dosyadan veri oku.
    // Farklı yöntemlerle okuma yapabiliriz:

    // Yöntem 1: Kelime kelime okuma
    // `>>` operatörü, boşluklara kadar olan kelimeleri okur.
    string kelime;
    cout << "--- Kelime kelime okuma ---" << endl;
    while (dosya_okuma >> kelime) {
        cout << kelime << endl;
    }

    // Okuma işlemi bittikten sonra dosya akışı "end-of-file" (eof) durumuna geçer.
    // Bu yüzden yeniden okumaya başlamadan önce akışı temizlemeliyiz.
    dosya_okuma.clear(); // Hata bayrağını temizle
    dosya_okuma.seekg(0); // Dosya imlecini en başa taşı

    // Yöntem 2: Satır satır okuma
    // getline() fonksiyonu, Enter tuşuna basılana kadar (yeni satır karakteri) okuma yapar.
    string satir;
    cout << "\n--- Satir satir okuma ---" << endl;
    while (getline(dosya_okuma, satir)) {
        cout << satir << endl;
    }

    // 4. Dosyayı kapat.
    // Dosya işlemleri bittikten sonra dosyayı kapatmak önemlidir.
    dosya_okuma.close();

    return 0;
}