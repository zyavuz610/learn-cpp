#include <iostream>
#include <chrono>

int Max(int a, int b) {
    return (a > b) ? a : b;
}

inline int Max2(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    const long long int iterations = 1000000000*2;
    int a = 42, b = 84;
    int result = 0;

    // Normal fonksiyon için zaman ölçümü
    auto start1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        result = Max(a, b);
    }
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration1 = end1 - start1;
    std::cout << "Max fonksiyonunun calisma suresi: " << duration1.count() << " saniye" << std::endl;

    // Inline fonksiyon için zaman ölçümü
    auto start2 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        result = Max2(a, b);
    }
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration2 = end2 - start2;
    std::cout << "Max2 (inline) fonksiyonunun calisma suresi: " << duration2.count() << " saniye" << std::endl;

    return 0;
}
