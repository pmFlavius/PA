#include <iostream>
#include <vector>
using namespace std;

#define INF __INT32_MAX__

void Floyd_Warshall(vector<vector<int>> &L, vector<vector<int>> &P, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && L[i][j] != INF)
                P[i][j] = i;
            else
                P[i][j] = -1;
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                int temp = 0;
                if (L[i][k] == INF || L[k][j] == INF)
                {
                    temp = INF;
                }
                else
                    temp = L[i][k] + L[k][j];

                if (temp < L[i][j])
                    L[i][j] = temp, P[i][j] = P[k][j];

                if (i == j && L[i][j] < 0)
                {
                    cout << "Digraful are circuite negative";
                    return;
                }
            }
        }
    }
}

void afisaremat(vector<vector<int>> M, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (M[i][j] == INF)
                cout << "INF ";
            else
                cout << M[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main()
{
    int n = 5;
    vector<vector<int>> L =
        {
            {0, 6, INF, 1, INF},
            {INF, 0, 5, INF, 4},
            {INF, INF, 0, INF, 5},
            {INF, 2, INF, 0, 1},
            {INF, 2, INF, INF, 0}};

    vector<vector<int>> P(n, vector<int>(n));
    afisaremat(L, n);
    Floyd_Warshall(L, P, n);

    afisaremat(L, n);
    afisaremat(P, n);
}