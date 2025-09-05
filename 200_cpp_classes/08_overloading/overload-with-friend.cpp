#include <iostream>

using namespace std;

class Vektor {
public:
    // Yapıcı metot (Constructor)
    Vektor(double x = 0.0, double y = 0.0) : x_koord(x), y_koord(y) {}

    // Vektörün koordinatlarını yazdıran fonksiyon
    void yazdir() const {
        cout << "(" << x_koord << ", " << y_koord << ")" << endl;
    }

    // Aritmetik operatör overloading için friend fonksiyon bildirimi
    // Bu fonksiyon, Vektor sınıfının özel üyelerine erişebilir.
    friend Vektor operator+(const Vektor& v1, const Vektor& v2);

private:
    double x_koord;
    double y_koord;
};

// Vektor'lerin toplanması için `friend` fonksiyonun implementasyonu
// Bu fonksiyon sınıfın dışında, global bir fonksiyondur.
// friend bildirimi sayesinde Vektor nesnelerinin private üyelerine doğrudan erişir.
Vektor operator+(const Vektor& v1, const Vektor& v2) {
    // x ve y koordinatlarını toplayarak yeni bir Vektor nesnesi oluştur ve döndür
    return Vektor(v1.x_koord + v2.x_koord, v1.y_koord + v2.y_koord);
}

int main() {
    // Vektor nesneleri oluşturalım
    Vektor v1(2.5, 3.0);
    Vektor v2(1.0, 4.5);
    Vektor v3; // Varsayılan yapıcı ile (0, 0)

    cout << "Vektor 1: ";
    v1.yazdir();
    
    cout << "Vektor 2: ";
    v2.yazdir();

    // Aritmetik toplama operatörünü (friend fonksiyon) kullanma
    // Bu satır, aslında `operator+(v1, v2)` çağrısıdır.
    v3 = v1 + v2;

    cout << "\nİki vektorun toplami: ";
    v3.yazdir();

    return 0;
}