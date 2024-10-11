#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;


int main() {
    int len; cin >> len;
    int temp;
    vector<int> vec;
    for(int i = 0 ; i < len; i++){
        cin >> temp;
        vec.push_back(temp);
    }
    cin >> len;
    vector<int>::iterator it;
    for(int i = 0; i < len ; i++){
        cin >> temp;
        it = lower_bound(vec.begin(),vec.end(),temp);
        //cout << *it << endl;
        if(*(it) == temp){
            cout << "Yes " << (distance(vec.begin(),it)+1) << endl;
            
        }else{
            cout << "No " << (distance(vec.begin(),it)+1) << endl;
        }
    }

    
    return 0;
}

