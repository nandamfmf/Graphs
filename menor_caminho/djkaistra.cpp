#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){

    int n = 20;

    vector<vector<pair<int,int>>> adj;
    vector<long long> dist(n, 1e18);
    vector<int> parent(n, -1);
    vector<bool> visitado(n, false);
    priority_queue<pair<int,int>> pq;

    dist[1] = 0;
        // peso, vértice
    pq.push({0, 1});

    while(!pq.empty()){
        int k = pq.top().second;
        pq.pop();

        if(visitado[k]) continue;

        visitado[k] = true;

        for(auto i : adj[k]){
            int vertice = i.second;
            int peso = i.first;

            if(dist[k] + peso < dist[vertice]){
                dist[vertice] = dist[k] + peso;
                parent[vertice] = k;
                pq.push({-dist[vertice], vertice});
            }
        }
    }


}