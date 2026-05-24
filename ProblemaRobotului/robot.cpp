#include <iostream>
#include <queue>
#include <utility>

using namespace std;

char a[1000][1000];
int distanta[1000][1000];
int main()
{
    queue<pair<int, int>> q;
    int n, m, starti, startj;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'S')
                starti = i, startj = j;
        }
    }

    int vx[4] = {-1, 0, 1, 0};
    int vy[4] = {0, 1, 0, -1};
    q.push(make_pair(starti, startj));
    a[starti][startj] = '#';
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        for (int k = 0; k < 4; k++)
        {
            int iv = i + vx[k];
            int jv = j + vy[k];
            if (iv >= 0 && iv < n && jv >= 0 && jv < m && a[iv][jv]!='#')
            {
                if (a[iv][jv] == '.')
                {
                    a[iv][jv] = '#';
                    q.push(make_pair(iv, jv));
                    distanta[iv][jv] = distanta[i][j] + 1;
                }
                if (a[iv][jv] == 'D')
                {
                    cout << distanta[i][j] + 1;
                    return 0;
                }
            }
        }
        q.pop();
    }

    return 0;
}