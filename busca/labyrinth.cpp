#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main () {

    int height;
    int width;
    
    cin >> height >> width;
    
    char matriz[height][width];

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            cin >> matriz[i][j];
        }
    }

    queue<pair<int, int>> fila;
    vector<vector<bool>> visitado(height, vector<bool>(width, false));
    vector<vector<int>> dist(height, vector<int>(width, -1));
    vector<vector<int>> movimento(height, vector<int>(width, -1));

                    //  down    up
    vector<int> dirR = {1, 0, -1, 0};

                    //    right  left
    vector<int> dirC = {0, 1, 0, -1};

    vector<char> dir = {'D', 'R', 'U', 'L'};

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(matriz[i][j] == 'A'){

                fila.push({i,j});
                dist[i][j] = 0;
                visitado[i][j] = true;

                while(!fila.empty()){
                    auto k = fila.front();
                    fila.pop();

                    int linha = k.first;
                    int coluna = k.second;

                    for(int t = 0; t < 4; t++){
                        int novaLinha = linha + dirR[t];
                        int novaColuna = coluna + dirC[t];

                    if(novaLinha >= 0 && novaLinha < height && novaColuna >= 0 && novaColuna < width){
                        if(matriz[novaLinha][novaColuna] != '#'){

                            if(!visitado[novaLinha][novaColuna]){

                            visitado[novaLinha][novaColuna] = true;

                            dist[novaLinha][novaColuna] = dist[k.first][k.second] + 1;

                            movimento[novaLinha][novaColuna] = dir[t];

                            fila.push({novaLinha, novaColuna});

                            if(matriz[novaLinha][novaColuna] == 'B') {
                                cout << "YES" << endl;
                                cout << dist[novaLinha][novaColuna] << endl;
                                
                                string caminho = "";

                                int atualLinha = novaLinha;
                                int atualColuna = novaColuna;

                                while(matriz[atualLinha][atualColuna] != 'A'){
                                    char m = movimento[atualLinha][atualColuna];
                                    caminho += m;

                                    if(m == 'U'){
                                        atualLinha++;
                                    }
                                    if(m == 'D'){
                                        atualLinha--;
                                    }
                                    if(m == 'R'){
                                        atualColuna--;
                                    }
                                    if(m == 'L'){
                                        atualColuna++;
                                    }
                                }

                                reverse(caminho.begin(), caminho.end());
                                cout << caminho << endl;
                                return 0;

                            }
                        }
                    }
                        
                }
            }

        }

        cout << "NO" << endl;
        return 0;

        }
    }
    }
}

