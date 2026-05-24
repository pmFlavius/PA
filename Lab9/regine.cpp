#include <iostream>
#include <cstring>

using namespace std;

bool valid(int linie, int coloana, int sol[])
{
    for (int i = 0; i < linie; i++)
    {
        if (sol[i] == coloana || abs(sol[i] - coloana) == abs(i - linie))
            return 0;
    }
    return 1;
}

void afisare(int n, int sol[])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (sol[i] == j)
                cout << "Q";
            else
                cout << ".";
        }
        cout << endl;
    }
    cout << endl;
}

void regine(int linie, int n, int sol[])
{
    if (linie == n)
    {
        afisare(n, sol);
        return;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (valid(linie, i, sol))
            {
                sol[linie] = i;
                regine(linie + 1, n, sol);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int *sol = new int[n];
    memset(sol, 0, n * sizeof(int));
    regine(0, n, sol);
    return 0;
}