#include <vector>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(){
    
    int n = 5;

    vector<vector<int>> adj = {
        {1, 2},    // 0
        {0, 3, 4}, // 1
        {0},       // 2
        {1},       // 3
        {1}        // 4
    };

    queue<int> fila;
    vector<bool> visitado(n, false);
    vector<int> dist(n);
    vector<int> pred(n);

    fila.push(0);
    visitado[0] = true;
    dist[0] = 0;
    pred[0] = 0;

    while(!fila.empty()){
        int k = fila.front();
        fila.pop();

        for(auto i : adj[k]){

            if(!visitado[i]){
                visitado[i] = true;
                dist[i] = dist[k] + 1;
                pred[i] = k;
                fila.push(i);
            }
        }
    }

}