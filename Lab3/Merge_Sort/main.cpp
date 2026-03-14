#include <iostream>

using namespace std;

void interclasare(int a[], int p, int q, int m, int temp[])
{
    int i = p;
    int j = m + 1;
    int k = -1;
    while ((i <= m) && (j <= q))
    {
        if (a[i] <= a[j])
        {
            temp[++k] = a[i++];
        }
        else
        {
            temp[++k] = a[j++];
        }
    }
    while (i <= m)
    {
        temp[++k] = a[i++];
    }
    while (j <= q)
    {
        temp[++k] = a[j++];
    }
}

void MergeSort(int a[], int p, int q, int temp[])
{
    if (p < q)
    {
        int m = (p + q) / 2;
        MergeSort(a, p, m, temp);
        MergeSort(a, m + 1, q, temp);
        interclasare(a, p, q, m, temp);
        for (int i = p; i <= q; i++)
        {
            a[i] = temp[i - p];
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    int *temp = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    MergeSort(a, 0, n - 1, temp);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    delete[] a;
    delete[] temp;
}