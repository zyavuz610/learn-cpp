#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> st;
    st.push(10);  // Yığına 10 ekle
    st.push(20);  // Yığına 20 ekle
    cout << st.top() << endl; // 20
    st.pop();  // Yığından 20'yi çıkar
    cout << st.top() << endl; // 10
    //cout <<"pop:" << st.pop() << endl; // 10
    cout << "----------------------------" << endl;
    stack<string> st2;
    st2.push("ali");
    st2.push("veli");
    cout << st2.top() << endl;
    st2.pop();
    cout << st2.top() << endl;
    return 0;
}
