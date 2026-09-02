#include <iostream>
#include <vector>
using namespace std;

int main () {

    int n = 20;
    long long INF = 1e18;

    vector<vector<pair<int,int>>> adj(n);
    vector<int> parent(n, -1);
    vector<long long> dist(n, INF);

    dist[1] = 0;

    for(int i = 1; i <= n-1; i++){ // Relaxar n-1 vezes
        for(int j = 0; j < n; j++){ // Cada nó percorrido
            for ( auto k : adj[j]){
                int vertice = k.first;
                int peso = k.second;

                if(dist[j] + peso < dist[vertice]){
                    dist[vertice] = dist[j] + peso;
                    parent[vertice] = j;
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
       for(auto k : adj[i]) {

        int vertice = k.first;
        int peso = k.second;

        if(dist[i] + peso < dist[vertice]) {

            cout << "Ciclo negativo" << endl;

        }
    }
}

}