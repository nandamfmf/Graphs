#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

int main () {

    int n;

    int caso = 1;

    while(cin >> n && n != 0){

        map<int, vector<int>> adj;
        map<int, bool> existe;

        for(int i = 0; i < n; i++){
            int A, B;
            cin >> A >> B;

            adj[A].push_back(B);
            adj[B].push_back(A);

            existe[A] = true;
            existe[B] = true;

        }

        int node, ttl;

        while(cin >> node >> ttl){
        
            if(node == 0 && ttl == 0){
                break;
            }

            queue<int> fila;
            map<int, bool> visitado;
            map<int, int> dist;

            fila.push(node);
            visitado[node] = true;
            dist[node] = 0;

            while(!fila.empty()){

            int k = fila.front();
            fila.pop();

            for(auto viz : adj[k]){

                if(!visitado[viz]){
                    visitado[viz] = true;
                    dist[viz] = dist[k] + 1;
                    fila.push(viz);
                }
            }
        }

        int count = 0;
        
        for(auto elemento : existe){

            int v = elemento.first;

            if(!visitado[v] || ttl < dist[v]){
                count++;
            }

        }

        cout << "Case " << caso << ": " << count << " nodes not reachable from node " << node << " with TTL = " << ttl << "." << endl;
        caso++;
    }

    }
}



