/*
Project Euler - Problem 4: Largest Palindrome Product
https://projecteuler.net/problem=4

Problem Tanımı:
Palindromik bir sayı, her iki yönden de okunduğunda aynı olan sayıdır.
İki basamaklı iki sayının çarpımıyla elde edilen en büyük palindrom:
9009 = 91 × 99

Soru:
Üç basamaklı iki sayının çarpımıyla elde edilen en büyük palindrom sayıyı bulunuz.
*/

#include <iostream>
using namespace std;

// Verilen bir tamsayının palindrom olup olmadığını kontrol eden fonksiyon
bool is_palindrome(int n) {
    int temp = n;
    int reversed = 0;
    
    // Sayıyı tersine çevirme (Aritmetik yöntem)
    while (temp > 0) {
        reversed = reversed * 10 + (temp % 10);
        temp /= 10;
    }
    
    return reversed == n;
}

int main() {
    int max_palindrome = 0;
    int factor1 = 0, factor2 = 0;

    // Üç basamaklı sayıları en büyükten (999) en küçüğe (100) doğru tarıyoruz
    for (int i = 999; i >= 100; i--) {
        // Çarpma işleminin değişme özelliğinden ötürü (i * j == j * i),
        // j değerini i'den başlatarak gereksiz tekrarları önlüyoruz.
        for (int j = i; j >= 100; j--) {
            int product = i * j;

            // Optimizasyon: Eğer mevcut çarpım şimdiye kadar bulunan en büyük
            // palindromdan küçük veya eşitse, j azaldıkça sonraki çarpımlar daha da
            // küçüleceğinden içteki döngüyü sonlandırabiliriz.
            if (product <= max_palindrome) {
                break;
            }

            if (is_palindrome(product)) {
                max_palindrome = product;
                factor1 = i;
                factor2 = j;
            }
        }
    }

    cout << "En buyuk palindrom sayi : " << max_palindrome << endl;
    cout << "Carpanlar                : " << factor1 << " x " << factor2 << endl;

    return 0;
}
