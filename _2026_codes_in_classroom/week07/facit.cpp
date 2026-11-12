#include <iostream>
#include <iomanip>

using namespace std;

/**
 * @brief Facit Mekanik Hesap Makinesi Sınıfı
 * 
 * Facit, 20. yüzyılın efsanevi İsveç yapımı mekanik hesap makinesidir.
 * Çalışma mantığında 3 temel kadran/register bulunur:
 * 1. aRegister (A Register / Temp): Tuş takımıyla girilen giriş değeri (ayar tamburu).
 * 2. accumulator (Akümülatör): Sonuç kadranı (tüm işlemlerin nihai sonucunun biriktiği yer).
 * 3. counter (Devir / Tur Sayacı): Çevirme kolunun (krank) kaç tur döndüğünü veya yapılan işlem sayısını tutar.
 */
class Facit {
private:
    double accumulator; // Sonuç kadranı (Akümülatör)
    double aRegister;   // A Register (Temp / Giriş değeri)
    int counter;        // Devir / İşlem sayacı

public:
    // Varsayılan Yapıcı (Constructor)
    Facit() {
        accumulator = 0.0;
        aRegister = 0.0;
        counter = 0;
    }

    // Parametreli Yapıcı (İsteğe bağlı başlangıç değeri ile)
    Facit(double initialAcc) {
        accumulator = initialAcc;
        aRegister = 0.0;
        counter = 0;
    }

    // Yıkıcı Metot (Destructor)
    ~Facit() {
        // Mekanik nesne sonlandırma
    }

    // --- Getter ve Setter Metotları ---
    void setA(double val) {
        aRegister = val;
    }

    double getA() const {
        return aRegister;
    }

    double getAccumulator() const {
        return accumulator;
    }

    int getCounter() const {
        return counter;
    }

    // --- Sıfırlama Kolları (Clearing Levers) ---
    void clearAccumulator() {
        accumulator = 0.0;
    }

    void clearA() {
        aRegister = 0.0;
    }

    void clearCounter() {
        counter = 0;
    }

    void clearAll() {
        clearAccumulator();
        clearA();
        clearCounter();
        cout << "[Facit Sıfırlandı: Tüm kadranlar temizlendi]\n";
    }

    // --- 4 İşlem Metotları ---

    /**
     * @brief Toplama işlemi (Addition)
     * Değeri A register'ına alır, akümülatöre ekler ve sayacı 1 artırır.
     */
    void add(double val) {
        aRegister = val;
        accumulator += aRegister;
        counter++;
    }

    // Parametresiz sürüm: A register'da hazır bulunan değeri ekler
    void add() {
        accumulator += aRegister;
        counter++;
    }

    /**
     * @brief Çıkarma işlemi (Subtraction)
     * Değeri A register'ına alır, akümülatörden çıkarır ve sayacı günceller.
     */
    void subtract(double val) {
        aRegister = val;
        accumulator -= aRegister;
        counter++;
    }

    // Parametresiz sürüm: A register'daki değeri çıkarır
    void subtract() {
        accumulator -= aRegister;
        counter++;
    }

    /**
     * @brief Çarpma işlemi (Multiplication)
     * 1. Doğrudan akümülatördeki mevcut değeri val ile çarpar.
     * 2. Facit mekanik mantığıyla: Çarpan A'ya yazılır ve kol 'val' tur çevrilir.
     */
    void multiply(double val) {
        aRegister = val;
        accumulator *= aRegister;
        counter++;
    }

    /**
     * @brief Mekanik Facit Mantığı ile Çarpma (Ardışık Toplama)
     * A register'daki sayı, kol 'turns' (tur) kadar çevrilerek akümülatöre eklenir.
     */
    void multiplyMechanical(int turns) {
        for (int i = 0; i < turns; ++i) {
            accumulator += aRegister;
            counter++;
        }
    }

    /**
     * @brief Bölme işlemi (Division)
     * Akümülatörü val değerine böler. Sıfıra bölme hatası kontrol edilir.
     */
    void divide(double val) {
        if (val == 0.0) {
            cout << "\n[HATA]: Sifira bolme yapilamaz! Islem iptal edildi.\n";
            return;
        }
        aRegister = val;
        accumulator /= aRegister;
        counter++;
    }

    /**
     * @brief Kadranları ve makinenin durumunu ekrana yazdırır.
     */
    void print() const {
        cout << "\n+---------------------------------------+\n";
        cout << "|      FACIT MEKANIK HESAP MAKINESI     |\n";
        cout << "+---------------------------------------+\n";
        cout << "| A Register (Temp) : " << setw(17) << aRegister << " |\n";
        cout << "| Counter    (Tur)  : " << setw(17) << counter   << " |\n";
        cout << "| Accumulator(Sonuc): " << setw(17) << accumulator << " |\n";
        cout << "+---------------------------------------+\n";
    }
};

int main() {
    cout << "=== FACIT HESAP MAKINESI TESTI ===\n";

    // 1. Nesne oluşturma
    Facit calc;
    calc.print();

    // 2. Toplama Testi: 0 + 25 = 25
    cout << "\n>> Toplama: 25 ekleniyor...";
    calc.add(25);
    calc.print();

    // 3. Toplama Testi: 25 + 15 = 40
    cout << "\n>> Toplama: 15 ekleniyor...";
    calc.add(15);
    calc.print();

    // 4. Çarpma Testi: 40 * 2 = 80
    cout << "\n>> Carpma: 2 ile carpiliyor...";
    calc.multiply(2);
    calc.print();

    // 5. Çıkarma Testi: 80 - 20 = 60
    cout << "\n>> Cikarma: 20 cikariliyor...";
    calc.subtract(20);
    calc.print();

    // 6. Bölme Testi: 60 / 3 = 20
    cout << "\n>> Bolme: 3'e bolunuyor...";
    calc.divide(3);
    calc.print();

    // 7. Sıfıra Bölme Hatası Testi
    cout << "\n>> Bolme: 0'a bolme deneniyor...";
    calc.divide(0);
    calc.print();

    // 8. Temizleme Testi
    cout << "\n>> Tum kadranlar temizleniyor...";
    calc.clearAll();
    calc.print();

    // 9. Mekanik Facit Mantığı Testi (A=12 ayarlanıp 4 tur kol çevriliyor: 12 x 4 = 48)
    cout << "\n=== MEKANIK TUR CEVIRME SIMULASYONU ===";
    cout << "\n>> A Register'a 12 giriliyor ve kol 4 tur cevriliyor (12 x 4)...";
    calc.setA(12);
    calc.multiplyMechanical(4);
    calc.print();

    return 0;
}

