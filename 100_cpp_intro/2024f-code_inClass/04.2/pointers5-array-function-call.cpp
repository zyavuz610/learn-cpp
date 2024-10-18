#include <iostream>
using namespace std;

int len(char *a){
    int i=0;
    while(a[i] != '\0') i++;
    return i;
}

int main(){
    char a[] = "zafer";
    cout<<a<<":"<<len(a)<<endl;
    return 0;
}