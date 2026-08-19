#include <iostream>
#include <vector>
using namespace std;

int main () {
    int rows;
    int colunms;
    cin >> rows;

    colunms = rows;

    vector<vector<int>> matriz(rows, vector<int>(colunms, 0));

    for(int i = 0; i < rows; i++){
        for(int j=0; j < colunms; j++){
            cin >> matriz[i][j];
        }
    }

    for(int i = 0; i < rows; i++){
        for(int j=0; j < colunms; j++){
            if(matriz[i][j] == 1){
                cout << j + 1 << " ";
            }
        }
        cout << endl;
    }


    return 0;

}