#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> s;
    s.insert(10);
    s.insert(5);
    s.insert(10);  // Set'te aynı eleman bir kez daha eklenmez
    for (int x : s) cout << x << " "; // 5 10
    cout << endl;
    cout << "----------------------------" << endl;
    set<string> s2;
    s2.insert("ali");
    s2.insert("veli");
    s2.insert("ali");  // Set'te aynı eleman bir kez daha eklenmez
    for (string x : s2) cout << x << " "; // ali veli
    cout << endl;
    return 0;
}
