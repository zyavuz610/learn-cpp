#include <iostream>

int main() {
    int sayi;
    int toplam = 0;

    // while(true) sonsuz döngü başlatır.
    // Döngüden çıkış koşulu "break" ile kontrol edilir.
    while (true) {
        std::cout << "Toplama eklemek istediginiz sayiyi girin (Cikis icin 0): ";
        std::cin >> sayi;

        // Kullanıcı 0 girerse döngüden çıkılır.
        if (sayi == 0) {
            break;
        }

        // Girilen sayı toplama eklenir.
        toplam += sayi;
        std::cout << "\nToplam: " << toplam << std::endl;
    }

    std::cout << "Program sonlandirildi." << std::endl;

    return 0;
}