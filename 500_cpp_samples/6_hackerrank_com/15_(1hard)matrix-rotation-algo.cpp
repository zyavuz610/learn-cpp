#include <bits/stdc++.h>


using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the matrixRotation function below.
void matrixRotation(vector<vector<int>> mat2, int r) {
    int sutun = mat2.size();
    int satir = mat2[0].size();
    int mat[sutun][satir] = {0};
    int matrix[sutun][satir] = {0};
    int f,l1,l2;
for(int j = 0; j < sutun;j++){
        for(int k = 0;k < satir;k++){
             mat[j][k] = mat2[j][k];
        }
     }
     int len;
     f=0;l1=sutun-1;l2=satir-1;
    len = sutun > satir ? satir : sutun;
for(int jx = 0; jx < len/2;jx++){
    int p = r % (((l1+1) - f) * 2 + ((l2+1) - f) * 2 - 4)  ;
   for(int j = 0; j < sutun;j++){
        for(int k = 0;k < satir;k++){
             mat[j][k] = mat2[j][k];
        }
     }

    for(int i = 0; i < p;i++){
        matrix[f+1][f] = mat[f][f];
        matrix[f][l2-1] = mat[f][l2];
        matrix[l1][f+1] = mat[l1][f];
        matrix[l1-1][l2] = mat[l1][l2];
        for(int x = f + 1; x < l2;x++){
            matrix[f][x-1] = mat[f][x];
        }
        for(int x = f+1; x < l1;x++){
            matrix[x+1][f] = mat[x][f];
        }
        for(int x = f + 1; x < l1;x++){
            matrix[x-1][l2] = mat[x][l2];
        }
        for(int x = f+1; x < l2;x++){
            matrix[l1][x+1] = mat[l1][x];
        }
        for(int j = 0; j < sutun;j++){
            for(int k = 0;k < satir;k++){
             mat[j][k] = matrix[j][k];
            }
        }
    }


    f++;l1--;l2--;
    
     
}
    for(int j = 0; j < sutun;j++){
        for(int k = 0;k < satir;k++){
            if(matrix[j][k] == 0) matrix[j][k] = mat2[j][k];
        }
     }
    for(int j = 0; j < sutun;j++){
        for(int k = 0;k < satir;k++){
           cout << matrix[j][k] << " ";
           
        }
        cout << endl;
     }
}

int main()
{
    string mnr_temp;
    getline(cin, mnr_temp);

    vector<string> mnr = split(rtrim(mnr_temp));

    int m = stoi(mnr[0]);

    int n = stoi(mnr[1]);

    int r = stoi(mnr[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

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

