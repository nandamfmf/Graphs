#include <iostream>
#include <vector>
#include <stack>
using namespace std;

enum color{
    SEMCOR = -1,
    VERDE = 0,
    AZUL = 1
};

int main () {

    int n;
    while(cin >> n && n != 0){

        vector<color> cores(n + 1, SEMCOR);
        vector<vector<int>> adj(n + 1);

        bool bicolored = true;

        int edges;
        cin >> edges;

        for (int i = 0; i < edges; i++){
            int A, B;
            cin >> A >> B;

            adj[A].push_back(B);
            adj[B].push_back(A);

        }

        stack<int> pilha;
        cores[0] = VERDE;

        pilha.push(0);

        while(!pilha.empty() && bicolored){
            int k = pilha.top();
            pilha.pop();

            for(auto i : adj[k]){

                if(cores[i] == SEMCOR){
                    if(cores[k] == VERDE){
                        cores[i] = AZUL;
                    }
                    else{
                        cores[i] = VERDE;
                    }

                    pilha.push(i);
                }

                if(cores[i] == cores[k]){
                    bicolored = false;
                    break;
                }
            }
        }

        if(!bicolored){
            cout << "NOT BICOLORABLE." << endl;
        }
        else{
            cout << "BICOLORABLE." << endl;
        }
    }


}