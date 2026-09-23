# Project Euler Çözümleri (C++)

Bu dizin, [Project Euler](https://projecteuler.net/) platformunda yer alan matematiksel ve algoritmik problemlerin C++ dili ile geliştirilmiş çözümlerini içermektedir.

---

## 📌 Project Euler Nedir?
[Project Euler](https://projecteuler.net/), matematik ve bilgisayar programlama becerilerini birleştiren bir dizi zorlayıcı problemden oluşan popüler bir platformdur. Problemler basit döngülerden ileri seviye sayı teorisi, kombinatorik ve dinamik programlamaya kadar geniş bir yelpazeyi kapsar. Problemleri çözmek genellikle hem algoritmik düşünme hem de matematiksel analiz gerektirir.

---

## 📂 Çözülen Problemler Listesi

| No | Problem Başlığı | C++ Kaynak Kodu | Açıklama / Temel Konsept | Project Euler Linki |
|:--:|:----------------|:---------------|:-------------------------|:-------------------:|
| **1** | Multiples of 3 or 5 | [001-multiples of 3 or 5.cpp](001-multiples%20of%203%20or%205.cpp) | 1000'den küçük 3 veya 5'in katı olan sayıların toplamı (Döngüler, Mod Operatörü) | [Problem 1](https://projecteuler.net/problem=1) |
| **2** | Even Fibonacci Numbers | [002_sum_of_even_fibonacci.cpp](002_sum_of_even_fibonacci.cpp) | 4 milyonu aşmayan çift Fibonacci sayılarının toplamı (Fibonacci Dizisi, Koşullu Döngü) | [Problem 2](https://projecteuler.net/problem=2) |
| **3** | Largest Prime Factor | [003_largest_prime_factor.cpp](003_largest_prime_factor.cpp) | 600851475143 sayısının en büyük asal çarpanı (Asallık Kontrolü, Çarpanlara Ayırma) | [Problem 3](https://projecteuler.net/problem=3) |
| **4** | Largest Palindrome Product | [004_palindrome.cpp](004_palindrome.cpp) | 3 basamaklı iki sayının çarpımıyla elde edilen en büyük palindrom sayı (Palindrom Kontrolü, Arama Optimizasyonu) | [Problem 4](https://projecteuler.net/problem=4) |

---

## 🔍 Problem Detayları ve Çözüm Yaklaşımları

### 1. [Problem 1: Multiples of 3 or 5](001-multiples%20of%203%20or%205.cpp)
* **Problem Tanımı:** 10'dan küçük 3 veya 5'in katı olan doğal sayılar 3, 5, 6 ve 9'dur. Bunların toplamı 23'tür. 1000'den küçük 3 veya 5'in katı olan tüm doğal sayıların toplamını bulunuz.
* **Çözüm Yaklaşımı:**
  * `for` döngüsü ile 1'den 999'a kadar olan sayılar taranır.
  * Modülüs (`%`) operatörü ile sayının 3 veya 5'e bölünüp bölünmediği (`index % 3 == 0 || index % 5 == 0`) kontrol edilir ve toplama eklenir.
  * *Alternatif Yaklaşım:* Aritmetik dizi toplam formülü ($S_n = \frac{n(n+1)}{2}$) ve Dahil Etme-Hariç Tutma İlkesi (Inclusion-Exclusion Principle) kullanılarak $O(1)$ zaman karmaşıklığında da çözülebilir.

### 2. [Problem 2: Even Fibonacci Numbers](002_sum_of_even_fibonacci.cpp)
* **Problem Tanımı:** Fibonacci dizisindeki her yeni terim, önceki iki terimin toplanmasıyla oluşturulur ($1, 2, 3, 5, 8, 13, 21, 34, 55, 89, \dots$). Değeri 4 milyonu (4.000.000) aşmayan çift terimlerin toplamını bulunuz.
* **Çözüm Yaklaşımı:**
  * İki değişken (`a = 0`, `b = 1`) ile Fibonacci serisi terim terim üretilir.
  * `do-while` döngüsü içerisinde sıradaki terim hesaplanır ve çift olanlar (`b % 2 == 0`) `answer` toplam değişkenine eklenir.
  * Değer 4 milyonu aştığında döngü sonlandırılır.

### 3. [Problem 3: Largest Prime Factor](003_largest_prime_factor.cpp)
* **Problem Tanımı:** 13195 sayısının asal çarpanları 5, 7, 13 ve 29'dur. $600851475143$ sayısının en büyük asal çarpanını bulunuz.
* **Çözüm Yaklaşımı:**
  * Çok büyük bir tamsayı ile çalışıldığı için uygun veri türü (`long double` / `long long`) kullanılır.
  * Sayı 2'den başlayarak küçük asal bölenlerine bölünerek basamak basamak küçültülür.
  * Tam bölünme kalmadığında elde edilen en son bölen, sayının en büyük asal çarpanını verir.

### 4. [Problem 4: Largest Palindrome Product](004_palindrome.cpp)
* **Problem Tanımı:** İki basamaklı iki sayının çarpımıyla elde edilen en büyük palindromik sayı $9009 = 91 \times 99$'dur. Üç basamaklı iki sayının çarpımıyla elde edilen en büyük palindromu bulunuz.
* **Çözüm Yaklaşımı:**
  * Sayının tersi aritmetik yöntemle (mod 10 ve bölme) elde edilerek `is_palindrome` fonksiyonu ile doğrulanır.
  * İç içe iki döngü ile 999'dan 100'e geriye doğru tarama yapılır.
  * $i \times j \le \text{max\_palindrome}$ olduğu anda iç döngü sonlandırılarak (erken kesme/pruning) arama uzayı büyük ölçüde optimize edilir.

---

## 🛠️ Nasıl Derlenir ve Çalıştırılır?

Herhangi bir C++ derleyicisi (örneğin MinGW `g++`) ile terminal üzerinden derleyip çalıştırabilirsiniz:

```bash
# Problem 1:
g++ "001-multiples of 3 or 5.cpp" -o problem1
./problem1

# Problem 2:
g++ 002_sum_of_even_fibonacci.cpp -o problem2
./problem2

# Problem 3:
g++ 003_largest_prime_factor.cpp -o problem3
./problem3

# Problem 4:
g++ 004_palindrome.cpp -o problem4
./problem4
```
