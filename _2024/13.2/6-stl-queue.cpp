#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;
    q.push(10);  // Kuyruğa 10 ekle
    q.push(20);  // Kuyruğa 20 ekle
    cout << q.front() << endl; // 10
    q.pop();  // Kuyruğun başındaki elemanı çıkar
    cout << q.front() << endl; // 20
    return 0;
}
