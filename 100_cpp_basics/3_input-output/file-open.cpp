#include <iostream>
#include <fstream> // Dosya islemleri icin gerekli kutuphane

using namespace std;

int main() {
    // 1. Bir ofstream nesnesi olustur.
    // ofstream, dosyaya yazma islemleri icin kullanilir.
    // Nesneyi olustururken dosya adini parametre olarak verebiliriz.
    ofstream dosya_yazma("ornek.txt");

    // 2. Dosyanin basarili bir sekilde acilip acilmadigini kontrol et.
    // is_open() fonksiyonu, dosya acilmissa true, acilmamissa false dondurur.
    if (!dosya_yazma.is_open()) {
        cerr << "Hata: Dosya acilamadi!" << endl;
        return 1; // Programi hata koduyla sonlandir.
    }

    // 3. Dosyaya veri yaz.
    // << operatoru, cout ile ayni sekilde kullanilir.
    dosya_yazma << "Bu ilk satir.\n";
    dosya_yazma << "Bu da ikinci satir." << endl;
    dosya_yazma << 12345 << " sayisi da dosyaya yazilabilir." << endl;

    // 4. Dosyayi kapat.
    // Dosya islemleri bittikten sonra dosyayi kapatmak onemlidir.
    // Bu, kaynaklari serbest birakir ve verilerin diske yazilmasini garantiler.
    dosya_yazma.close();

    cout << "Dosya 'ornek.txt' basariyla olusturuldu ve icine yazildi." << endl;

    return 0;
}