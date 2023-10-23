#include <bits/stdc++.h>
using namespace std;

int min_cut(vector<vector<int>> &g, int N)
{
    int Iterations = N - 2, count = 0;
    vector<vector<int>> g1(N, vector<int>(N));

    while (N > 2)
    {
        int u = 0, v = 0;
        cout << "\n -- enter edge(u,v) to be removed\n";
        cin >> u;
        cin >> v;

        for (int i = 0; i < N - 1; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                count = 0;

                if (i == u && j == v)
                    g1[i][j] = g1[j][i] = 0;

                else if (i == u || i == v)
                {
                    if (g[u][j] > 0)
                        count += g[u][j];

                    if (g[v][j] > 0)
                        count += g[v][j];

                    g1[u][j] = g1[v][j] = count;
                }

                else if (j == u || j == v)
                {
                    if (g[u][i] > 0)
                        count += g[u][i];

                    if (g[v][i] > 0)
                        count += g[v][i];

                    g1[i][u] = g1[i][v] = count;
                }

                else
                    g1[i][j] = g[i][j];
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i >= j)
                    g1[i][j] = g1[j][i];
            }
        }

        int row = 0, col = 0;
        vector<vector<int>> g2(N -1, vector<int>(N -1));
        for (int i = 0; i < N; i++)
        {
            if (i == v) continue;
            col = 0;
            for (int j = 0; j < N; j++)
            {
                if (j == v) continue;

                g2[row][col] = g1[i][j];
                col++;
            }
            row++;
        }

        for(int i = 0; i < N -1; i++)
        {
            for(int j = 0; j < N -1; j++)
            {
                g[i][j] = g2[i][j];
            }
        }
        N--;
    }

    return g[0][1];
}

int main()
{
    int N = 4;
    vector<vector<int>> g = {{0, 1, 1, 1}, {1, 0, 0, 1}, {1, 0, 0, 1}, {1, 1, 1, 0}};

    int count = min_cut(g, N);
    std::cout << "min cut value : " << count;
}