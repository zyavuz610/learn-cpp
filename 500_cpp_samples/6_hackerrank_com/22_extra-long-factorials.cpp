#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) {
vector<int> d;
    d.push_back(1);
    
    for (int i = 2; i <= n; ++i) {
        for (auto it = d.begin(); it != d.end(); ++it)
            *it *= i;
        
        for (size_t j = 0; j < d.size(); ++j) {
            if (d[j] < 10)
                continue;

            if (j == d.size() - 1)
                d.push_back(0);
            
            d[j + 1] += d[j] / 10;
            d[j] %= 10;
        }
    }
    reverse(d.begin(),d.end());
    for (auto it = d.begin(); it != d.end(); ++it)
        cout << *it;

}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}

