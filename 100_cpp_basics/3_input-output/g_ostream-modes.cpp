#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string dosyaAdi = "ornek_modlar.txt";

    // ios::out modu: Dosya zaten varsa içeriğini siler ve yeni yazmaya başlar.
    // Bu varsayılan moddur.
    // ios::trunc modu da aynı işlevi görür ve belirtilmezse varsayılan olarak etkindir.
    cout << "--- ios::out modu (varsayilan) ---" << endl;
    ofstream dosyaOut(dosyaAdi, ios::out);
    if (dosyaOut.is_open()) {
        dosyaOut << "Bu satir ios::out modunda yazildi.\n";
        dosyaOut.close();
        cout << "'" << dosyaAdi << "' icerigi silinip yeniden yazildi." << endl;
    } else {
        cerr << "Hata: Dosya acilamadi." << endl;
    }

    // ios::app modu: Dosya zaten varsa içeriğini silmez, yazma işlemini dosyanın sonundan devam ettirir.
    cout << "\n--- ios::app modu (ekleme) ---" << endl;
    ofstream dosyaApp(dosyaAdi, ios::app);
    if (dosyaApp.is_open()) {
        dosyaApp << "Bu satir ios::app modunda eklendi.\n";
        dosyaApp.close();
        cout << "'" << dosyaAdi << "' dosyasina yeni satir eklendi." << endl;
    } else {
        cerr << "Hata: Dosya acilamadi." << endl;
    }

    // ios::trunc modu: Dosya varsa içeriğini siler ve yeni yazmaya başlar.
    // Tek başına kullanılması `ios::out` ile aynı işlevi görür.
    cout << "\n--- ios::trunc modu (kesme) ---" << endl;
    ofstream dosyaTrunc(dosyaAdi, ios::trunc);
    if (dosyaTrunc.is_open()) {
        dosyaTrunc << "Bu satir ios::trunc modunda yazildi.\n";
        dosyaTrunc.close();
        cout << "'" << dosyaAdi << "' icerigi kesilip yeniden yazildi." << endl;
    } else {
        cerr << "Hata: Dosya acilamadi." << endl;
    }

    // ios::ate modu: Yazma/okuma konumunu dosyanın sonuna ayarlar.
    // Dosya varsa içeriğini silmez, ancak yazma/okuma pozisyonunu dosyanın sonuna koyar.
    // `app`'ten farklı olarak, `seekp` gibi konumlandırma fonksiyonlarıyla dosyanın herhangi bir yerine yazabiliriz.
    cout << "\n--- ios::ate modu (sona konumlandir) ---" << endl;
    ofstream dosyaAte(dosyaAdi, ios::ate);
    if (dosyaAte.is_open()) {
        // Şu an imleç dosyanın sonunda.
        dosyaAte << "Bu satir ios::ate modunda eklendi.\n";
        dosyaAte.close();
        cout << "'" << dosyaAdi << "' dosyasina yeni satir eklendi." << endl;
    } else {
        cerr << "Hata: Dosya acilamadi." << endl;
    }

    return 0;
}