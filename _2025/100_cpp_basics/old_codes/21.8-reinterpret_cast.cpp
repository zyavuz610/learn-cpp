// reinterpret_cast, iki tür arasında bit seviyesinde bir dönüşüm sağlar. Genellikle veri tiplerinin bellekteki gösterimlerini değiştirmek için kullanılır. Ancak bu tür dönüşümler risklidir ve dikkatli kullanılmalıdır.

#include <iostream>

int main() {
    int num = 65;
    char* ch = reinterpret_cast<char*>(&num);  // reinterpret_cast ile int'i char*'a dönüştür

    std::cout << "reinterpret_cast ile int'in ilk baytı: " << *ch << std::endl;  // 'A' harfi (ASCII 65)
    return 0;
}
