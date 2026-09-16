/*
QUESTÃO 1: Dado um grafo não direcionado, proponha um algoritmo que identifique todas as suas componentes conexas.
Para cada componente, o algoritmo deve informar:
• os vértices que pertencem à componente;
• o número de vértices da componente.
As componentes devem ser apresentadas em ordem decrescente de tamanho.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
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

    vector<bool> visitado(vertices, false);
    vector<vector<int>> componentes;

    for(int p = 0; p < vertices; p++){

        if(!visitado[p]){
        
        vector<int> componente;
        stack<int> pilha;

        visitado[p] = true;
        pilha.push(p);

        while(!pilha.empty()){
            
            int k = pilha.top();
            pilha.pop();
            componente.push_back(k);

            for(auto i : adj[k]){
                if(!visitado[i]){

                    visitado[i] = true;
                    pilha.push(i);

                }
            }

        }

        componentes.push_back(componente);

    }

    while(!componentes.empty()){

        int maior = 0;

        for(int i = 1; i < componentes.size(); i++){

            if(componentes[i].size() > componentes[maior].size()){
                maior = i;
            }
        }

        cout << "Componente: ";

        for(auto vertice : componentes[maior]){
            cout << vertice << " ";
        }

        cout << endl;
        cout << "Quantidade: " << componentes[maior].size() << endl;

        componentes.erase(componentes.begin() + maior);
    }
}
}