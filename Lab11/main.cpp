#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Graf
{
    int n;                   // nr noduri
    vector<int> np;          // numar de predecesori
    vector<vector<int>> adj; // lista adiacenta
};

void sortareTopologicaBFS(Graf &D, vector<int> &L)
{
    queue<int> C;

    for (int u = 0; u < D.n; u++)
    {
        if (D.np[u] == 0)
            C.push(u);
    }

    for (int k = 0; k < D.n; k++)
    {
        if (C.empty())
        {
            cout << "Graful contine cicluri";
            return;
        }
        int u = C.front();
        C.pop();
        L.push_back(u);
        for (int i = 0; i < D.adj[u].size(); i++)
        {
            int v = D.adj[u][i];
            D.np[v]--;
            if (D.np[v] == 0)
                C.push(v);
        }
    }
}

int main()
{
    Graf D;
    int m;
    cin >> D.n >> m;

    D.adj.resize(D.n);
    D.np.resize(D.n, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        D.adj[u].push_back(v);
        D.np[v]++;
    }

    vector<int> L;
    sortareTopologicaBFS(D, L);

    for (int x : L)
        cout << x << " ";

    return 0;

}