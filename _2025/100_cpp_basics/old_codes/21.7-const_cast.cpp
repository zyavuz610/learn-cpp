// const_cast, const veya volatile niteliklerini türlerden kaldırmak veya eklemek için kullanılır. Ancak const olan bir veriyi değiştirilebilir hale getirip değiştirmek, tanımsız davranışa yol açabilir.

#include <iostream>

void printValue(const int* val) {
    int* modifiableVal = const_cast<int*>(val);  // const_cast kullanarak const'u kaldır
    *modifiableVal = 42;  // Değeri değiştirme
}

int main() {
    int x = 10;
    const int* ptr = &x;
    printValue(ptr);  // x'in değeri değiştirilecek
    std::cout << "Yeni değer: " << x << std::endl;  // Yeni değeri yazdır
    return 0;
}
