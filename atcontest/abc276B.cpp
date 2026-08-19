#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int cities, roads;
    cin >> cities >> roads;

    // vector onde cada elemento tem um vector associado. Cada cidade vai estar ligada a outras.
    vector<vector<int>> lista(cities + 1);

    for(int i=0; i < roads; i++){
        int A, B;
        cin >> A >> B;

        lista[A].push_back(B);
        lista[B].push_back(A);
    }

    for(int i = 1; i < cities + 1; i++){

        sort(lista[i].begin(), lista[i].end());

        cout << lista[i].size();

        for(int j=0; j<lista[i].size(); j++){
            cout << " " << lista[i][j];
        }

        cout << endl;
        
    }
    

    return 0;

}