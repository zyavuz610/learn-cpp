#include <iostream>
#include <map>

using namespace std;

int main() {
    map<int, string> m;
    m[1] = "One";
    m[2] = "Two";
    for (const auto& pair : m) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << "----------------------------" << endl;
    map<string, int> m2;
    m2["ali"] = 1985;
    m2["veli"] = 1986;
    for (const auto& pair : m2) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << "----------------------------" << endl;
    cout << "birth-of-ali:"<<m2["ali"] << endl;
    return 0;
}
