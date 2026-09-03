#include <iostream>
#include <vector>
using namespace std;

int main(){

    long long inf = 1e18;

    // cities, roads, queries
    int n, m, q;

    cin >> n >> m >> q;

    vector<vector<long long>> matriz_dist(n+1, vector<long long>(n+1, inf));

    for(int i = 1; i <= n; i ++){
        matriz_dist[i][i] = 0;
    }

    for(int i = 0; i < m; i++){

        int a, b, c;
        cin >> a >> b >> c;

        if(c < matriz_dist[a][b]){
            matriz_dist[a][b] = c;
            matriz_dist[b][a] = c;
        }

    }

    // Floyd-Warshall para encontrar o menor caminho:
    for(int k = 1; k <= n; k++){ // Intermediário
        for(int i = 1; i <= n; i ++) { // Origem
            for(int j = 1; j <= n; j++){ // Destino

                if(matriz_dist[i][k] != inf && matriz_dist[k][j] != inf){
                
                if(matriz_dist[i][k] + matriz_dist[k][j] < matriz_dist[i][j]){
                    matriz_dist[i][j] = matriz_dist[i][k] + matriz_dist[k][j];
                }

            }

            }
        }

    }

    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        if(matriz_dist[a][b] != inf){
            cout << matriz_dist[a][b] << endl;
        } else {
            cout << -1 << endl;
        }
    }

}


