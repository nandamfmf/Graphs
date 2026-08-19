#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main () {

    int n = 5;

    // Cada elemento tem um vector associado a ele 
    vector<vector<int>> adj = {
        {1, 2},    // 0
        {0, 3, 4}, // 1
        {0},       // 2
        {1},       // 3
        {1}        // 4
    };

    stack<int> pilha;
    vector<bool> visitado(n, false);

    pilha.push(0);
    visitado[0] = true;

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
}