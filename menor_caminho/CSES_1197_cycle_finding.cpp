#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<long long> dist(n+1, 0); // Em vez de inicializar com infinito, 
    // inicializamos todos os vértices com 0 para detectar ciclos negativos partindo de qualquer vértice, não apenas do primeiro.
    vector<int> parent(n+1, -1);
    vector<int> vertices_ciclo;

    for(int i = 0; i < m; i ++){

            int a, b, c;
            cin >> a >> b >> c;

            adj[a].push_back({b, c});
    }

    bool temCicloNegativo = false;

    for(int i = 1; i <= n-1; i++){ // Relaxar arestas n-1 vezes

        for(int k = 1; k <= n; k++){ // Nós

        for(auto j : adj[k]){
            int vertice = j.first;
            int peso = j.second;

            if(dist[k] + peso < dist[vertice]){
                dist[vertice] = dist[k] + peso;
                parent[vertice] = k;
            }

        }
    }
    }

    int ciclo_inicio = -1;

    for(int i = 1; i <= n; i++){

        for(auto j : adj[i]){
            int vertice = j.first;
            int peso = j.second;

            if(dist[i] + peso < dist[vertice]){
                temCicloNegativo = true;
                ciclo_inicio = vertice;
                parent[vertice] = i;
                break;
            }
        }
    }

    int atual = ciclo_inicio;
    
    if(ciclo_inicio != -1){

        for(int i = 0; i < n; i++){ // Para garantir que estamos dentro do ciclo, percorremos n vezes.
            atual = parent[atual];
        }

        int inicio = atual;
        vertices_ciclo.push_back(inicio);

        atual = parent[inicio];

        while(atual != inicio){
            vertices_ciclo.push_back(atual);
            atual = parent[atual];
        }

        vertices_ciclo.push_back(inicio); // Adiciona o vértice inicial novamente para fechar o ciclo

        reverse(vertices_ciclo.begin(), vertices_ciclo.end());

    }

    if(temCicloNegativo){

        cout << "YES" << endl;

        for(int i = 0; i < vertices_ciclo.size(); i++){
            cout << vertices_ciclo[i] << " ";
        }
        cout << endl;
    } 

    else {
        cout << "NO" << endl;
    }


}