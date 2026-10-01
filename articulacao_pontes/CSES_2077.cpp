/*
Tarefa CSES_2077 - Articulação de Pontes
Aluna: Maria Fernanda Magalhães Freitas
*/

#include <iostream>
#include <vector>
using namespace std;

int tin[100005];
int low[100005];
vector<bool> visitado(100005, false);
vector<bool> articulacao(100005, false);

int timer = 0;

void dfs(int raiz, int pai, vector<vector<int>>& adj){

    visitado[raiz] = true;
    tin[raiz] = low[raiz] = timer++;
    int num_filhos = 0;

    for(int vizinho : adj[raiz]){

        if(vizinho == pai) continue;

        if(visitado[vizinho]){
            low[raiz] = min(low[raiz], tin[vizinho]);
        }
        else{

            dfs(vizinho, raiz, adj);
            low[raiz] = min(low[raiz], low[vizinho]);

            if(pai != -1 && low[vizinho] >= tin [raiz]){
                articulacao[raiz] = true;
            }

            num_filhos++;
        }
        
    }

    if(pai == -1 && num_filhos > 1){
        articulacao[raiz] = true;
    }


}

int main () {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for(int i = 1; i <= m; i ++){
        
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1, adj);

    int count = 0;
    vector<int> lista_cidades;

    for(int i = 1; i <= n; i++){
        if(articulacao[i]){
            count++;
            lista_cidades.push_back(i);
        }
    }

    cout << count << endl;

    for(int cidade : lista_cidades){
        cout << cidade << " ";
    }
    cout << endl;

}