#include <iostream>
using namespace std;
int main(){
    char ch = 'A';
    int i = static_cast<int>(ch);
    cout << ch << ": " << i << endl;
    int a = 77;
    char ch2 = static_cast<char>(a);
    cout << a << ": " << ch2 << endl;

    string str = "2abc00";
    int b =stoi(str);
    cout << str << ": " << b+1 << endl;

    return 0;
}