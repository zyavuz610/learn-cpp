#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char* argv[]){
    cout    <<"Merhaba " 
            << argc 
            << "\n";
    for(int i=0;i<argc;i++){
        cout<<argv[i]<<endl;
    }
    string str;
    if(argc == 2){
        ifstream infile(argv[1]);
        while( !infile.eof()){
            //infile >> str;
            getline(infile,str);
            cout << str << endl;
        }
        infile.close();
    }
    else if (argc == 3){

    }
    return 0;
} 