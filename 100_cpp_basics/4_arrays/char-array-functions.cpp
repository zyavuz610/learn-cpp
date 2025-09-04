#include <iostream>
#include <cstring> // C++'ta C stili string fonksiyonları için

using namespace std;

//---
// User-defined string fonksiyonları
//---

// my_strlen: Bir C stil string'in uzunluğunu hesaplar.
size_t my_strlen(const char* str) {
    size_t length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// my_strcpy: Kaynak string'i hedef string'e kopyalar.
// Hedef dizinin yeterli boyutta olması gerekir.
void my_strcpy(char* dest, const char* src) {
    int i = 0;
    while ((dest[i] = src[i]) != '\0') {
        i++;
    }
}

// my_strcmp: İki string'i karşılaştırır.
// Eşitse 0, str1 > str2 ise pozitif, str1 < str2 ise negatif bir değer döndürür.
int my_strcmp(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str1[i] == str2[i]) {
        i++;
    }
    return static_cast<unsigned char>(str1[i]) - static_cast<unsigned char>(str2[i]);
}

//---
// Main fonksiyonu ve kullanım örnekleri
//---

int main() {
    char str1[50] = "Merhaba, Dunya!";
    char str2[50];
    char str3[] = "Merhaba";
    char str4[] = "Merhaba";
    char str5[] = "merhaba";

    // strlen ve my_strlen kullanımı
    cout << "--- strlen ve my_strlen ---" << endl;
    cout << "str1'in uzunlugu (strlen): " << strlen(str1) << endl;
    cout << "str1'in uzunlugu (my_strlen): " << my_strlen(str1) << endl;
    cout << endl;

    // strcpy ve my_strcpy kullanımı
    cout << "--- strcpy ve my_strcpy ---" << endl;
    strcpy(str2, str1);
    cout << "str1'den str2'ye kopyalama (strcpy): " << str2 << endl;

    my_strcpy(str2, "C++ Kodlama");
    cout << "str2'ye yeni kopyalama (my_strcpy): " << str2 << endl;
    cout << endl;

    // strcmp ve my_strcmp kullanımı
    cout << "--- strcmp ve my_strcmp ---" << endl;
    cout << "str3 ve str4 karsilastiriliyor (strcmp): " << strcmp(str3, str4) << endl; // Aynı, 0 döndürür
    cout << "str3 ve str4 karsilastiriliyor (my_strcmp): " << my_strcmp(str3, str4) << endl; // Aynı, 0 döndürür
    cout << "str3 ve str5 karsilastiriliyor (strcmp): " << strcmp(str3, str5) << endl; // Farklı, negatif değer döndürür
    cout << "str3 ve str5 karsilastiriliyor (my_strcmp): " << my_strcmp(str3, str5) << endl; // Farklı, negatif değer döndürür
    cout << endl;
    
    return 0;
}