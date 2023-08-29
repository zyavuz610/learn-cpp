/*
c++ dilinde iteratorlar, STL (Standard Template Library) kütüphanesinin bir parçasıdır.
STL kütüphanesi, C++ dilinin standart kütüphanesidir.
 "iterator", veri yapılarındaki (örneğin, diziler, vektörler, listeler vb.) öğeleri sırayla dolaşmanızı ve erişmenizi sağlayan bir araçtır. 
 Iteratorler, veri yapısının içindeki öğeleri gösteren ve üzerinde işlem yapmanıza olanak tanıyan nesnelerdir. 
 Bu sayede veri yapısındaki elemanlara kolayca erişebilir, değiştirebilir veya silebilirsiniz.

 std::vector, std::list, std::set, std::map gibi veri yapılarının her biri için ayrı iterator türleri bulunmaktadır.

 örneğin;
 #include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    // Iterator kullanarak vektörü dolaşma
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " "; // *it ile iteratorun gösterdiği değeri alırız
    }
    
    return 0;
}


*/
*/