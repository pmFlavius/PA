#include <iostream>

using namespace std;

void partitioneaza(int a[], int p, int q, int &k)
{
    int x = a[p];
    int i = p + 1;
    int j = q;
    while (i <= j)
    {
        if (a[i] <= x && i <= q)
            i++;
        if (a[j] >= x && j >= p)
            j--;
        if (i < j)
        {
            if (a[i] > x && x > a[j])
            {
                swap(a[i], a[j]);
                i++;
                j--;
            }
        }
    }
    k = i - 1;
    a[p] = a[k];
    a[k] = x;
}

void quicksort1(int a[], int p, int q)
{
    if (p < q)
    {
        int k;
        partitioneaza(a, p, q, k);
        quicksort1(a, p, k - 1);
        quicksort1(a, k + 1, q);
    }
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    quicksort1(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    delete[] a;
    return 0;
}