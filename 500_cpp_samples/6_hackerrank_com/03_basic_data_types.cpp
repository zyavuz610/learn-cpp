/*
Sample Input

    3 12345678912345 a 334.23 14049.30493

Sample Output

    3
    12345678912345
    a
    334.230
    14049.304930000
*/
//------------------------------------------------------------------------------
#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main() {
    int i;
    long int l;
    char c;
    float f;
    double d;
    cin>>i>>l>>c>>f>>d;
    cout<<i<<endl;
    cout<<l<<endl;
    cout<<c<<endl;
    cout<<fixed<<setprecision(3)<<f<<endl;
    cout<<d<<endl;
    return 0;
}