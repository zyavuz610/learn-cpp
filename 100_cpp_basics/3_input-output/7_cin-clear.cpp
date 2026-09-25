#include <iostream>
#include <limits>

using namespace std;

int main() {
    int sayi;

    cout << "Bir tam sayi girin: ";
    cin >> sayi;

    // Kullanici bir tamsayi yerine bir harf veya kelime girerse ne olur?
    // Örnek: "abc"
    // Bu durumda, girdi akisi (cin) hatali duruma gecer ve sonraki okuma
    // islemleri basarisiz olur. Programimiz beklenen gibi calismaz.
    
    // Girdi akisinin durumunu kontrol edelim.
    // cin.fail() fonksiyonu, bir hata olusup olusmadigini kontrol eder.
    if (cin.fail()) {
        cout << "\n--- Hata olustu! ---" << endl;
        cout << "Gecerli bir tamsayi girilmedi." << endl;
        
        // cin.clear() fonksiyonu, girdi akisindaki hata bayraklarini temizler.
        // Bu, akisi normal calisma durumuna geri dondurur.
        // Ancak, hatali karakterler hala buffer'da kalir.
        cout << "Hata bayraklari temizleniyor..." << endl;
        cin.clear();
        
        // Hatali karakterleri buffer'dan atmak icin cin.ignore() kullanmaliyiz.
        // Yoksa bir sonraki okuma islemi yine ayni hatali karakterleri okumaya calisir.
        cout << "Buffer'daki hatali karakterler temizleniyor..." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Artik girdi akisi normale döndü. Yeni bir okuma islemi deneyebiliriz.
    int yeni_sayi;
    cout << "\nLutfen gecerli bir tamsayi girin: ";
    cin >> yeni_sayi;

    cout << "Girdiginiz yeni sayi: " << yeni_sayi << endl;

    return 0;
}