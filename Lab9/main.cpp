#include <iostream>

using namespace std;

void submultimiOpt(int s, int k, int r, bool x[], int w[], int n, int M)
{
    if (k >= n)
        return;
    x[k] = 1;
    if (s + w[k] == M)
    {
        for (int i = 0; i <= k; i++)
        {
            cout << x[i] << " ";
        }
        cout << endl;
    }
    else if (k + 1 < n && s + w[k] + w[k + 1] <= M)
    {
        submultimiOpt(s + w[k], k + 1, r - w[k], x, w, n, M);
    }
    if (k + 1 < n && (s + r - w[k] >= M) && s + w[k + 1] <= M)
    {
        x[k] = 0;
        submultimiOpt(s, k + 1, r - w[k], x, w, n, M);
    }
}

int main()
{
    int n, M;
    cin >> n >> M;
    int *w = new int[n];
    bool *sol = new bool[n];
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
        sol[i] = 0;
        r += w[i];
    }
    submultimiOpt(0, 0, r, sol, w, n, M);
    delete[] w;
    delete[] sol;
    return 0;
}