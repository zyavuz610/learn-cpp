#include <iostream>

using namespace std;

/*
 * private: Bu tür değişkenlere ve metotlara sınıfın dışından doğrudan erişim mümkün değildir.
 * O yüzden public olarak tanımlanan getter() ve setter() metotları yardımıyla değerlerine erişilip değiştirilir.
 * public bir değişkene doğrudan değer atanabilirken, private bir değişkeni setter metodu aracılığıyla değiştirmek, değer üzerinde çeşitli kontroller yapma imkanı sunar.
 */
class Box {
public:
    double length;
    void setWidth(double wid);
    double getWidth(void);

private:
    double width;
};

// Member functions definitions
double Box::getWidth(void) {
    return width;
}

// Setter metotunda kontrol yaparak width değişkenini ayarla
void Box::setWidth(double wid) {
    // Genişlik değerinin pozitif olup olmadığını kontrol et.
    if (wid > 0) {
        width = wid;
    } else {
        // Eğer değer pozitif değilse, kullanıcıyı bilgilendir ve 0 olarak ayarla.
        cout << "Hata: Genislik degeri negatif veya sifir olamaz. Genislik 0 olarak ayarlandi." << endl;
        width = 0;
    }
}

// Main function for the program
int main() {
    Box box;

    // set box length without member function
    box.length = 10.0; // OK: because length is public
    cout << "Length of box: " << box.length << endl;

    // set box width with member function (gecerli deger)
    box.setWidth(10.0);
    cout << "Width of box: " << box.getWidth() << endl;

    // set box width with member function (gecersiz deger)
    box.setWidth(-5.0);
    cout << "Yeni width of box: " << box.getWidth() << endl;

    return 0;
}
