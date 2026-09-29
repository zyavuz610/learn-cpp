# Nesne Tabanlı Programlama — Telafi Çalışması
## Hafta 1-3: Project Euler Problem 1, 2, 3

**Öğrenci:** Dersi alan öğrenciler
**Kapsam:** Bu ödev, dönem boyunca yüz yüze katılım sağlanmayan ders içi çalışmaların (ödev/etkinlik) yerine geçen telafi çalışmasının ilk 3 haftalık parçasıdır. Sınav yerine geçmez.

---

### Yapılacaklar

Project Euler sitesindeki aşağıdaki üç problemi çözünüz:

- **Problem 1** — Multiples of 3 or 5
- **Problem 2** — Even Fibonacci Numbers
- **Problem 3** — Largest Prime Factor

Her problem için **ayrı bir C++ dosyası** hazırlayın. Her dosya, o problemi çözen **tek bir sınıf** ve o sınıfı kullanan bir **main fonksiyonu** içermelidir. Kodların tamamı **tek dosyada** olacaktır (ayrı .h/.cpp dosyalarına bölünmeyecek).

Sınıf isimlendirmesi problem numarasına göre yapılacaktır:

| Problem | Dosya adı | Sınıf adı |
|---|---|---|
| 1 | `Problem1.cpp` | `Problem1Solver` |
| 2 | `Problem2.cpp` | `Problem2Solver` |
| 3 | `Problem3.cpp` | `Problem3Solver` |

---

### Sınıf Tasarım Kuralları

1. Problemin girdisi (örneğin Problem 1'deki limit değeri, Problem 2'deki üst sınır) **private bir üye değişken** olarak tutulmalı, sınıfın **kurucusu (constructor)** ile dışarıdan verilmelidir. Sabit değer olarak kodun içine gömülmemelidir.
2. Sınıfın çözümü hesaplayan **public bir metodu** olmalı (örn. `solve()`), bu metot sonucu döndürmelidir; ekrana yazdırma işini yapmamalıdır.
3. Hesaplama sırasında kullanılan yardımcı işlemler (örn. asal kontrolü, Fibonacci üretimi) sınıfın **private metotları** olarak yazılmalıdır; `main` içine veya sınıf dışına serbest fonksiyon olarak yazılmamalıdır.
4. `main` fonksiyonu yalnızca şunları yapmalıdır: sınıftan bir nesne oluşturmak, `solve()` metodunu çağırmak, sonucu ekrana yazdırmak. Problemin çözüm mantığı `main` içinde olmamalıdır.

### Örnek İskelet (Problem 1 için, doldurulacak)

```cpp
#include <iostream>

class Problem1Solver {
private:
    int limit_;
    // gerekirse başka private yardımcı metotlar buraya

public:
    explicit Problem1Solver(int limit) : limit_(limit) {}

    long long solve() {
        // TODO: 3 veya 5'in katı olan sayıların toplamını hesapla
    }
};

int main() {
    Problem1Solver solver(1000);
    std::cout << "Sonuc: " << solver.solve() << std::endl;
    return 0;
}
```

Problem 2 ve Problem 3 için aynı mantıkla, kendi girdilerine uygun kurucu parametreleriyle `Problem2Solver` ve `Problem3Solver` sınıflarını siz tasarlayacaksınız.

---

### Teslim Şekli

- Bir GitHub deposu açın (özel/private olabilir, bana erişim veriniz) veya mevcut deponuzu kullanın.
- Depoda `hafta1-3/` gibi bir klasör altında üç dosyayı da bulundurun.
- Her problem ayrı bir commit ile eklenmeli; commit mesajı problemi kısaca belirtmeli (örn. "Problem 1 solved").
- Kodlar `g++ -std=c++17 -Wall -Wextra` ile uyarısız derlenmelidir.
- README dosyasına her problem için beklenen çıktıyı (örnek: "Problem 1 -> 233168") not düşünüz.

### Teslim Tarihi

Ekim ayı sonu

### Değerlendirme Kriterleri

| Kriter | Açıklama |
|---|---|
| Doğru sonuç | Her üç problem için doğru sayısal sonuç |
| Sınıf tasarımı | Private/public ayrımı doğru, kurucu ile parametre alma, hesaplama mantığının sınıf içinde kapsüllenmesi |
| main sadeliği | main içinde yalnızca nesne oluşturma ve sonucu yazdırma |
| Kod kalitesi | Anlamlı isimlendirme, uyarısız derleme, gereksiz global/serbest fonksiyon olmaması |
| Commit düzeni | Üç ayrı, açıklayıcı commit |

Bu üç problem, ileride ekleyeceğimiz test sınıfları ve soyut `Solver` arayüzünün temelini oluşturacağı için, sınıf tasarımına özellikle dikkat ediniz.

Başarılar dilerim.
