#include <bits/stdc++.h>

using namespace std;

// Complete the kaprekarNumbers function below.
void kaprekarNumbers(int p, int q) {
    long long sq;
    string s;
    string leftpart;
    string rightpart;
    bool control = false;
    long leftpartbutint = 0;
    long rightpartbutint = 0;
    while(p != q+1){
        sq = pow(p,2);
        s = to_string(sq);
        int len = s.size();
        for(int i = 1; i < 2;i++){
            leftpart = s.substr(0,len/2);
            rightpart = s.substr(len/2);
            try{
                leftpartbutint = stol(leftpart);
            }catch(exception e){}
            try{
                rightpartbutint = stol(rightpart);
            }catch(exception e){}
            
            if(leftpartbutint + rightpartbutint == p) {
                cout << p << " ";
                control = true;
                break;
            }
        }
        p++;
    }
    if(!control) cout << "INVALID RANGE";
}

int main()
{
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    kaprekarNumbers(p, q);

    return 0;
}

