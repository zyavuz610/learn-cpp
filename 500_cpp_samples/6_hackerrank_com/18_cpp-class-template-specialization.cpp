#include <iostream>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;
template <typename T>
struct Traits{
    static std::string name(int i){
        switch(i){
            case 0:
                return typeid(T) == typeid(Fruit) ? "apple" : "red";
                break;
            case 1:
                return typeid(T) == typeid(Fruit) ? "orange" : "green";
                break;
            case 2:
                return typeid(T) == typeid(Fruit) ? "pear" : "orange";
                break;
            default:
                return "unknown";
        }
    }
};
// Define specializations for the Traits class template here.


int main()
{
	int t = 0; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}

