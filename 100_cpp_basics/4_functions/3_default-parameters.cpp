#include <iostream>
#include <string>

using namespace std;

// Bu fonksiyon, bir selamlama mesajı oluşturur.
// `selam` ve `noktalama` parametreleri için varsayılan değerler belirledik.
// Bu sayede, bu parametreler çağrı sırasında belirtilmezse varsayılan değerler kullanılır.
void selamlama(string isim, string selam = "Merhaba", string noktalama = "!") {
    cout << selam << ", " << isim << noktalama << endl;
}

int main() {
    // Örnek 1: Tüm parametreleri manuel olarak girme.
    cout << "--- Tam Parametreli Cagri ---" << endl;
    selamlama("Ali", "Selam", "!");

    // Örnek 2: Son parametreyi atlayarak, varsayılan değerini kullanma.
    // Fonksiyon, `noktalama` parametresi için varsayılan değeri olan "!" kullanır.
    cout << "\n--- Son Parametresi Atlanmis Cagri ---" << endl;
    selamlama("Ayse", "Günaydin");

    // Örnek 3: Son iki parametreyi atlayarak, varsayılan değerlerini kullanma.
    // Fonksiyon, `selam` için "Merhaba" ve `noktalama` için "!" kullanır.
    cout << "\n--- Iki Parametresi Atlanmis Cagri ---" << endl;
    selamlama("Fatma");
    
    // Not: Varsayılan parametreler her zaman sondan başa doğru tanımlanmalıdır.
    // Yani, bir parametrenin varsayılan değeri varsa, ondan sonra gelen
    // tüm parametrelerin de varsayılan değerleri olmalıdır.
    
    return 0;
}