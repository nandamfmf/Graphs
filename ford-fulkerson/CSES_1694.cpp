#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

/*
Problema: CSES 1694 - Download Speed
Aluna: Maria Fernanda Magalhães Freitas
*/

using namespace std;

int capacidade[505][505]; 
vector<int> adj[505]; 

int bfs(int origem, int destino, vector<int>& pai, int n) {
    fill(pai.begin(), pai.end(), -1);

    queue<int> fila;
    fila.push(origem);

    pai[origem] = origem;

    while (!fila.empty()) {
        int u = fila.front();
        fila.pop();

        for (int v : adj[u]) {
            if (pai[v] == -1 && capacidade[u][v] > 0) {
                pai[v] = u;

                if (v == destino) { 
                    return 1;
                }

                fila.push(v);
            }
        }
    }

    return 0;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back(b);
        adj[b].push_back(a);

        capacidade[a][b] += c;
    }

    int fluxoMaximo = 0;
    vector<int> pai(n + 1);

    while (bfs(1, n, pai, n)) { 
        int fluxo = 1000000000;

        int v = n;

        while (v != 1) {
            int u = pai[v];

            fluxo = min(fluxo, capacidade[u][v]);

            v = u;
        }

        v = n;

        while (v != 1) {
            int u = pai[v];

            capacidade[u][v] -= fluxo;
            capacidade[v][u] += fluxo;

            v = u;
        }

        fluxoMaximo += fluxo;
    }

    cout << fluxoMaximo << '\n';

    return 0;
}