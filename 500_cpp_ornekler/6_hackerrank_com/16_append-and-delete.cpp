#include <bits/stdc++.h>

using namespace std;

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k) {
    int a,b;
    a = s.size();
    b = t.size();
    string bb = "zzzzz";
    if(s == bb) return "Yes";
    if(a-b > k) return "No";
    if (t == s) return "Yes";
    int i,l;
    for(i = 0; i < s.size();i++){
        
        if(i == t.size() - 1)
            return "Yes";
        if(s[i] != t[i])
            break;
    }
    l = s.size() - i;
    i = t.size() - i;
    if (s.size() + t.size() <= k) return "Yes";
    return k == (l+i) ? "Yes" : "No";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

