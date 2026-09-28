#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int N, M;

bool ehValido(int n, int m)
{
    return n >= 0 and n < N and m >= 0 and m < M;
}

int main()
{

    cout << "Digite as dimensões da matriz (N x M): ";
    cin >> N >> M;

    vector<vector<char>> mapa(N, vector<char>(M, '.'));

    cout << "Digite seu mapa linha por linha\n";

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> mapa[i][j];
        }
    }

    vector<vector<bool>> ehOceano(N, vector<bool>(M, false));
    queue<pair<int, int>> qOceano;

    // adiciona tds as celulas da borda na matriz de oceano
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if ((i == 0 or i == N - 1 or j == 0 or j == M - 1) and mapa[i][j] == '.')
            {
                ehOceano[i][j] = true;
                qOceano.push({i, j});
            }
        }
    }

    while (!qOceano.empty())
    {
        auto [r, c] = qOceano.front();
        qOceano.pop();

        for (int k = 0; k < 4; k++)
        {
            int nr = r + dx[k];
            int nc = c + dy[k];

            if (ehValido(nr, nc) && mapa[nr][nc] == '.' && !ehOceano[nr][nc])
            {
                ehOceano[nr][nc] = true;
                qOceano.push({nr, nc});
            }
        }
    }

    vector<vector<bool>> visitado(N, vector<bool>(M, false));
    int ilhasComLago = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (mapa[i][j] == '#' and !visitado[i][j])
            {
                bool temLago = false;

                queue<pair<int, int>> qIlha;
                qIlha.push({i, j});
                visitado[i][j] = true;

                while (!qIlha.empty())
                {
                    auto [r, c] = qIlha.front();
                    qIlha.pop();

                    for (int k = 0; k < 4; k++)
                    {
                        int nr = r + dx[k];
                        int nc = c + dy[k];

                        if (ehValido(nr, nc))
                        {
                            if (mapa[nr][nc] == '#' and !visitado[nr][nc])
                            {
                                visitado[nr][nc] = true;
                                qIlha.push({nr, nc});
                            }

                            else if (mapa[nr][nc] == '.' and !ehOceano[nr][nc])
                            {
                                temLago = true;
                            }
                        }
                    }
                }
                if (temLago)
                {
                    ilhasComLago++;
                }
            }
        }
    }

    cout << "\nQuantidade de ilhas com lago: " << ilhasComLago << "\n";

    return 0;
}