#include <iostream>
#include <string>

using namespace std;

// ==========================================
// SINIF TANIMLARI
// ==========================================

class VeriIsleyici {
protected:
    int* veriDizisi;
    int boyut;

public:
    VeriIsleyici(int b) : boyut(b) {
        veriDizisi = new int[boyut];
        cout << "[Base] " << boyut << " elemanlik yer ayrildi." << endl;
    }

    // Sanal Yıkıcı (Virtual Destructor) - ÇOK ÖNEMLİ
    virtual ~VeriIsleyici() {
        delete[] veriDizisi;
        cout << "[Base] Bellek temizlendi." << endl;
    }

    virtual void bilgiGoster() {
        cout << "--- Base Class: Standart Veri ---" << endl;
    }

    // Saf Sanal Metot (Pure Virtual)
    virtual void veriyiIsle() = 0; 
};

class SesVerisi : public VeriIsleyici {
public:
    SesVerisi(int b) : VeriIsleyici(b) { cout << "  -> SesVerisi olustu." << endl; }
    
    ~SesVerisi() override { cout << "  -> SesVerisi siliniyor." << endl; }

    void veriyiIsle() override {
        cout << ">> [SES] Frekanslar ayarlaniyor (Polimorfik Cagri)" << endl;
    }

    void bilgiGoster() override {
        cout << "--- Ses Dosyasi (" << boyut << " sample) ---" << endl;
    }
};

class GoruntuVerisi : public VeriIsleyici {
public:
    GoruntuVerisi(int b) : VeriIsleyici(b) { cout << "  -> GoruntuVerisi olustu." << endl; }

    ~GoruntuVerisi() override { cout << "  -> GoruntuVerisi siliniyor." << endl; }

    void veriyiIsle() override {
        cout << ">> [GORUNTU] Pikseller isleniyor (Polimorfik Cagri)" << endl;
    }

    void bilgiGoster() override {
        cout << "--- Goruntu Dosyasi (" << boyut << " piksel) ---" << endl;
    }
};

// ==========================================
// MAIN FONKSİYONU
// ==========================================
int main() {
    cout << "=== Polimorfik Dizi Ornegi ===\n" << endl;

    // 1. ADIM: Base Class tipinde bir işaretçi dizisi oluşturuyoruz.
    // Bu dizi, hem SesVerisi hem de GoruntuVerisi adreslerini tutabilir.
    const int nesneSayisi = 3;
    VeriIsleyici* islemeListesi[nesneSayisi];

    // 2. ADIM: Diziye farklı türden nesneler yüklüyoruz (Upcasting)
    // Listemiz 'VeriIsleyici' tipinde ama içine 'Ses' ve 'Goruntu' koyuyoruz.
    cout << "--- Nesneler Olusturuluyor ---" << endl;
    islemeListesi[0] = new SesVerisi(5);       // 1. Eleman: Ses
    islemeListesi[1] = new GoruntuVerisi(10);  // 2. Eleman: Görüntü
    islemeListesi[2] = new SesVerisi(3);       // 3. Eleman: Tekrar Ses

    cout << "\n--- Polimorfik Dongu Basliyor ---" << endl;

    // 3. ADIM: Tek bir döngü ile hepsini işliyoruz.
    // Hangi nesnenin hangi metodunun çağrılacağına çalışma zamanında (Runtime) karar verilir.
    for (int i = 0; i < nesneSayisi; i++) {
        cout << "\nNesne " << (i + 1) << " isleniyor:" << endl;
        
        // Pointer tipi Base olsa bile, nesnenin kendi 'bilgiGoster' metodu çalışır.
        islemeListesi[i]->bilgiGoster();
        
        // Pointer tipi Base olsa bile, nesnenin kendi 'veriyiIsle' metodu çalışır.
        islemeListesi[i]->veriyiIsle();
    }

    cout << "\n--- Temizlik Zamani ---" << endl;

    // 4. ADIM: Belleği temizliyoruz.
    // Base class yıkıcısı 'virtual' olduğu için doğru yıkıcılar zincirleme çalışır.
    for (int i = 0; i < nesneSayisi; i++) {
        delete islemeListesi[i]; 
        cout << "----------------------" << endl;
    }

    return 0;
}