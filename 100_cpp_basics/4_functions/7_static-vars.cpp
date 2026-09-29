#include <iostream>

using namespace std;

// Otomatik ve statik değişkenlerin farkını gösteren bir fonksiyon
void sayacFonksiyonu() {
    // Statik Değişken (static int)
    // - Yalnızca bir kez başlatılır.
    // - Programın ömrü boyunca bellekte kalır.
    // - Fonksiyon çağrıları arasında değerini korur.
    static int statik_sayac = 0; 
    
    // Otomatik Değişken (int)
    // - Her fonksiyon çağrısında yeniden oluşturulur ve başlatılır.
    // - Fonksiyonun çalışması bittiğinde yok olur.
    // - Değeri bir sonraki çağrıda korunmaz.
    int otomatik_sayac = 0; 

    cout << "Statik sayac: " << ++statik_sayac << endl;
    cout << "Otomatik sayac: " << ++otomatik_sayac << endl;
    cout << "------------------------" << endl;
}

int main() {
    cout << "Ilk cagri:" << endl;
    sayacFonksiyonu();

    cout << "Ikinci cagri:" << endl;
    sayacFonksiyonu();

    cout << "Ucuncu cagri:" << endl;
    sayacFonksiyonu();

    return 0;
}