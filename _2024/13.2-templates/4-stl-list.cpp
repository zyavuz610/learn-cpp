#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> l;
    list<string> l2;
    l.push_back(10); // Listenin sonuna ekle
    l.push_front(5); // Listenin başına ekle
    l.push_back(20); // Listenin sonuna ekle
    for (int x : l) cout << x << " "; // 5 10
    cout << endl;
    l.pop_back(); // Listenin son elemanını sil
    for (int x : l) cout << x << " "; // 5
    cout << endl;
    cout<<"----------------------------"<<endl;
    l2.push_back("ali");
    l2.push_front("veli");
    l2.push_back("deli");
    for (string x : l2) cout << x << " ";
    cout << endl;
    l2.pop_back();
    for (string x : l2) cout << x << " ";
    cout << endl;
    return 0;
}
