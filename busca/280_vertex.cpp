#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main () {
    
    int n;
    
    while (cin >> n && n != 0) {
    
    vector<vector<int>> adj(n + 1);

    int v;
    int i;

    while(cin >> v && v != 0){

        while(cin >> i && i != 0){

            adj[v].push_back(i);
        }
    }

    int qntd;
    cin >> qntd;

    vector<int> vertices_partida(qntd);
    
    for (int i = 0; i < qntd; i++) {
        cin >> vertices_partida[i];
    }

    for(int i = 0; i < vertices_partida.size(); i++){

        stack<int> pilha;
        vector<bool> visitado(n + 1, false);

        pilha.push(vertices_partida[i]);

        while(!pilha.empty()){

            int k = pilha.top();
            pilha.pop();

            for(auto i : adj[k]){
                if(!visitado[i]){
                    visitado[i] = true;
                    pilha.push(i);
                }
            }
        }

        int quantidade = 0;

        for (int i = 1; i <= n; i++) {
            if (!visitado[i]) {
                quantidade++;
            }
        }

        cout << quantidade;

        for (int i = 1; i <= n; i++) {
            if (!visitado[i]) {
                cout << " " << i;
            }
        }

        cout << '\n';
}
}
}