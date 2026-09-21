#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> bfs(int linhaorigem, int colunaorigem, int linhas, int colunas,vector<vector<char>>& matriz){

    vector<vector<bool>> visitado(linhas, vector<bool>(colunas, false));
    vector<vector<int>> distancia(linhas, vector<int>(colunas, 999999999));

    queue<pair<int,int>> pilha; 

    pilha.push({linhaorigem, colunaorigem});
    visitado[linhaorigem][colunaorigem] = true;
    distancia[linhaorigem][colunaorigem] = 0;

    while(!pilha.empty()){
        int l = pilha.front().first;
        int c = pilha.front().second;

        pilha.pop();

        const int dlinha[] = {-1, 0, 1, 0};
        const int dcoluna[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; ++i){
            int novaLinha = l + dlinha[i];
            int novaColuna = c + dcoluna[i];

            if(matriz[novaLinha][novaColuna] == 'P' && novaLinha >= 0 && novaLinha < linhas && novaColuna >= 0 && novaColuna < colunas &&
               distancia[novaLinha][novaColuna] > distancia[l][c] + 1) {

                visitado[novaLinha][novaColuna] = true;
                distancia[novaLinha][novaColuna] = distancia[l][c] + 1;
                pilha.push({novaLinha, novaColuna});

            } else if(matriz[novaLinha][novaColuna] != 'P' && matriz[novaLinha][novaColuna] != '#' && 
                    novaLinha >= 0 && novaLinha < linhas && novaColuna >= 0 && novaColuna < colunas &&
                    distancia[novaLinha][novaColuna] > distancia[l][c] + 1) {

                visitado[novaLinha][novaColuna] = true;
                distancia[novaLinha][novaColuna] = distancia[l][c];
                pilha.push({novaLinha, novaColuna});

            }
        }

    }

    return distancia;
}


int main () {
    int linhas, colunas;
    cin >> linhas >> colunas;

    int linhaA, colunaA, linhaB, colunaB;

    vector<vector<char>> matriz(linhas, vector<char>(colunas));

    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            cin >> matriz[i][j];

            if(matriz[i][j] == 'A'){
                linhaA = i;
                colunaA = j;
            }

            if(matriz[i][j] == 'B'){
                linhaB = i;
                colunaB = j;
        }
    }
}

    vector<vector<int>> componentes_conexas;
    vector<vector<int>> portas;

    auto distancias = bfs(linhaA, colunaA, linhas, colunas, matriz);

    
}