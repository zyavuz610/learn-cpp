#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
    // --- VECTOR ÖRNEĞİ ---
    vector<string> isimler;
    isimler.push_back("Ali");
    isimler.push_back("Ayse");
    isimler.push_back("Mehmet");

    cout << "Vector'un 2. elemani: " << isimler[1] << endl; // Erişim hızı O(1)

    // --- MAP ÖRNEĞİ ---
    // Plaka kodlarını (int) Şehir isimlerine (string) bağlayalım
    map<int, string> plakalar;
    
    plakalar[6] = "Ankara";
    plakalar[34] = "Istanbul";
    plakalar[35] = "Izmir";

    // Map elemanları Key değerine göre otomatik sıralanır (6, 34, 35)
    cout << "\n--- Map Icerigi ---" << endl;
    for (auto it = plakalar.begin(); it != plakalar.end(); ++it) {
        // it->first : Key (Anahtar)
        // it->second: Value (Değer)
        cout << "Plaka: " << it->first << " - Sehir: " << it->second << endl;
    }

    // Map'te arama yapmak
    if (plakalar.find(34) != plakalar.end()) {
        cout << "\n34 plakali sehir bulundu: " << plakalar[34] << endl;
    }

    return 0;
}