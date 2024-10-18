#include <iostream>
using namespace std;

int len(char *a){
    int i=0;
    while(a[i] != '\0') i++;
    return i;
}
int sum(int *a,int n){
    int s=0;
    for(int i=0;i<n;i++){
        s += a[i];
    }
    return s;
}
void upper(char *a){
    while(*a != '\0'){
        if(*a >= 'a' && *a <= 'z')
           *a -= ('a' - 'A'); 
         a++;
    }
}

int main(){
    char a[] = "zafer";
    cout<<a<<":"<<len(a)<<endl;
    upper(a);
    cout<<a<<":"<<len(a)<<endl;
    return 0;
}