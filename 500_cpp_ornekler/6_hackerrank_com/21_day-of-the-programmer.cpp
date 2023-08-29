#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the dayOfProgrammer function below.
string dayOfProgrammer(int year) {
    int feb = 28;
    if (year % 4 == 0) feb = 29;
    if (year > 1918 && year % 100 == 0) feb = 28;
    if (year > 1918 && year % 400 == 0) feb = 29;
   
    int i,total = 0;
    int tm;
    for(i = 0; total < 256;i++){
        tm = total;
        if ( i == 1){
            total += feb;
            continue;
        }
        if ( i == 7){
            total += 31;
            continue;
        }
        total += i % 2 == 0 ? 31 : 30;
    }
    string a;
    if(year == 1918) tm = 230;
    if (i < 10)
    a = to_string(256 - tm) + ".0" + to_string(i) + "." + to_string(year);
    else
    a = to_string(256 - tm) + "." + to_string(i) + "." + to_string(year);
    
    return a;
 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

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

