/*
QUESTÃO 2: Dados um grafo e dois vértices s e t, proponha um algoritmo que determine se existe um caminho de s até t
contendo um número par de arestas.
Observe que não basta verificar se existe qualquer caminho entre s e t.
Descreva como o problema pode ser modelado como um novo grafo e indique qual algoritmo de busca pode
ser utilizado.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(){

    int vertices, arestas;
    cin >> vertices >> arestas;

    vector<vector<int>> adj(vertices);

    for(int i = 0; i < arestas; i++){
        
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<vector<bool>> visitado(vertices, vector<bool>(2, false));
    queue<pair<int,int>> fila;

    int vertice_s, vertice_t;
    cin >> vertice_s >> vertice_t;

    visitado[vertice_s][0] = true;
    fila.push({vertice_s, 0});

    while(!fila.empty()){
            
        int k = fila.front().first;
        int paridade = fila.front().second;
        fila.pop();

            for(auto i : adj[k]){

                int novaparidade = (paridade + 1) % 2;

                if(!visitado[i][novaparidade]){

                    visitado[i][novaparidade] = true;
                    fila.push({i, novaparidade});

            }
        }
    }

    if(visitado[vertice_t][0]){
        cout << "SIM" << endl;
    }
    else{
        cout << "NAO" << endl;
    }

    return 0;
}