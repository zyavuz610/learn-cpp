#include <iostream>
#include <iomanip> // setprecision, fixed ve scientific için gerekli

using namespace std;

int main() {
    double sayi = 1234.56789;

    cout << "--- Varsayilan Cikis Formati ---" << endl;
    cout << "Sayi: " << sayi << endl;

    cout << "\n--- fixed Kullanimi ---" << endl;
    // `fixed` format ayarını kalıcı olarak etkinleştirir. 
    // Ondalık noktadan sonraki basamak sayısını kontrol etmek için `setprecision` ile birlikte kullanılır.
    // Bu, sayıların her zaman sabit noktalı gösterimde çıkmasını sağlar.
    cout << fixed << setprecision(2);
    cout << "fixed ve setprecision(2) ile: " << sayi << endl;

    cout << "\n--- unsetf Kullanimi ---" << endl;
    // `unsetf` fonksiyonu, daha önce `setf` ile ayarlanan format bayraklarını kaldırır.
    // Örneğin, `ios_base::fixed` bayrağını kaldırarak `fixed` formatını devre dışı bırakır.
    // Bu, çıkış formatını varsayılan (bilimsel notasyon) haline döndürür.
    cout.unsetf(ios_base::fixed);
    cout << "fixed formati unsetf ile kaldirildi: " << sayi << endl;

    cout << "\n--- unsetf'in Etkisini Gosteren Farkli Ornek ---" << endl;
    
    double buyuk_sayi = 1234567890.123456;

    // `scientific` formatını kullanarak sayıyı bilimsel gösterimde yazalım.
    cout << "Bilimsel formatta (scientific): " << scientific << buyuk_sayi << endl;

    // `unsetf` ile `scientific` formatını kaldıralım ve varsayılana dönelim.
    cout.unsetf(ios_base::scientific);
    cout << "scientific formati unsetf ile kaldirildi: " << buyi << endl;

    return 0;
}