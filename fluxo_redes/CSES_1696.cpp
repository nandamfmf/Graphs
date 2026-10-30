#include <iostream>
#include <vector>

/*
Problema: CSES 1694 - School Dance
Aluna: Maria Fernanda Magalhães Freitas
*/

using namespace std;

int n, m, k;

vector<vector<int>> adj;

vector<int> match;
vector<bool> visitado;

bool dfs(int menino) {

    for (int menina : adj[menino]) {

        if (visitado[menina])
            continue;

        visitado[menina] = true;

        if (match[menina] == 0 || dfs(match[menina])) {

            match[menina] = menino;

            return true;
        }
    }

    return false;
}

int main() {

    cin >> n >> m >> k;

    adj.resize(n + 1);

    match.resize(m + 1, 0);

    for (int i = 0; i < k; i++) {

        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
    }

    int resposta = 0;

    for (int menino = 1; menino <= n; menino++) {

        visitado.assign(m + 1, false);

        if (dfs(menino)) {
            resposta++;
        }
    }

    cout << resposta << "\n";

    for (int menina = 1; menina <= m; menina++) {

        if (match[menina] != 0) {

            cout << match[menina] << " " << menina << "\n";
        }
    }

    return 0;
}