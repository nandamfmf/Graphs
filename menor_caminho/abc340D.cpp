#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){

    int stages;
    cin >> stages;
                      // peso, destino
    vector<vector<pair<long long, int>>> adj(stages + 1);

    for(int i = 1; i <= stages - 1; i++){

            long long a, b, c;
            cin >> a >> b >> c;

            adj[i].push_back({a, i+1});
            adj[i].push_back({b, c});

    }

    vector<long long> dist(stages + 1, 1e18);
    vector<bool> visitado(stages + 1, false);

    dist[1] = 0;

    priority_queue<pair<long long, int>> pq;
    pq.push({0, 1});

    while(!pq.empty()){
        int a = pq.top().second;
        pq.pop();

        if(visitado[a]) continue;

        visitado[a] = true;

        for(auto i : adj[a]){
            int vertice = i.second;
            int peso = i.first;

            if(dist[a] + peso < dist[vertice]){
                dist[vertice] = dist[a] + peso;
                pq.push({-dist[vertice], vertice});
            }
        }
    }

    cout << dist[stages] << endl;
    
    return 0;
}