#include <bits/stdc++.h>
#include <vector>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'pickingNumbers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int pickingNumbers(vector<int> b) {
    vector<int> a = b;
    int maxlen = 0,len = 0;
    int mostrepeated = 0;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i = 0;i < a.size() - 1;){
        if (a[i] == a[i+1])
            a.erase(a.begin()+i+1);
        else
            ++i;
    }
    auto maxi = [&len,&b] (int n){
        for (int i = 0; i < b.size(); i++){
            if ( n == b [i])
                len++;
        }
    };
    for (int i = 0;i < a.size() - 1;){
        if (abs(a[i] - a[i+1]) == 1){
            maxi(a[i]);
            maxi(a[i+1]);

            if (len > maxlen) maxlen = len;
            len = 0;
            i++;
        }
        else 
            i++;
            
    }
    for (int i = 0; i < b.size(); i++){
        len = 0;
        for (int j = 0; j < b.size(); j++){
            if ( a[i] == b [j])
                len++;
            }
        if (len > mostrepeated) mostrepeated = len;
        }
    if (mostrepeated < maxlen)
        return maxlen;
    else
        return mostrepeated;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = pickingNumbers(a);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

