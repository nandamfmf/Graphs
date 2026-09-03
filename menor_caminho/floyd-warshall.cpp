
// O(n³), usa matriz e intermediarios do tipo i -> k -> j.
#include <iostream>
#include <vector>
using namespace std;

int main () {
    int l, c;
    cin >> l >> c;

    vector<vector<int>> matriz(l, vector<int>(c));

    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            cin >> matriz[i][j];
        }
    }

    vector<vector<int>> dist = matriz;

    for(int k = 0; k < l; k++){ // Nó intermediário
        for(int i = 0; i < l; i++){ // Nó de origem
            for(int j = 0; j < l; j++) // Nó de destino
            
            if(dist[i][k] + dist[k][j] < dist[i][j]){
                dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    bool temCicloNegativo = false;

    for(int i = 0; i < l; i++){
        if(dist[i][i] < 0){ // Se a distância de um nó até ele mesmo for negativa, então há um ciclo negativo.
            temCicloNegativo = true;
        }
    }




}

