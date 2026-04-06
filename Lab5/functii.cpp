#include <iostream>
#include "functii.h"

using namespace std;

void insertheap(int heap[], int &n, int val)
{
    heap[++n] = val;
    int fiu = n;
    int parinte = n / 2;
    while (parinte >= 1)
    {
        if (heap[parinte] > heap[fiu])
        {
            swap(heap[parinte], heap[fiu]);
            fiu = parinte;
            parinte = parinte / 2;
        }
        else
            parinte = 0;
    }
}

int removeheap(int heap[], int &n)
{
    if (n == 0)
    {
        cout << "Nu s elemente in heap";
        exit(0);
    }
    int minim = heap[1];
    heap[1] = heap[n];
    n--;
    int parinte = 1;
    int fiu = 2;
    while (fiu <= n)
    {
        int fiustanga = parinte * 2;
        int fiudreapta = parinte * 2 + 1;
        if (fiudreapta <= n && heap[fiustanga] > heap[fiudreapta])
        {
            fiu = fiudreapta;
        }
        else
        {
            fiu = fiustanga;
        }
        if (heap[parinte] > heap[fiu])
        {
            swap(heap[parinte], heap[fiu]);
            parinte = fiu;
            fiu = fiu * 2;
        }
        else
            fiu = n + 1;
    }
    return minim;
}

void creareLEP(int x[], int n)
{
    int heap[DIM_MAX];
    int hsize = 0;
    for (int i = 0; i < n; i++)
    {
        insertheap(heap, hsize, x[i]);
    }
    while (hsize > 1)
    {
        cout << "Iteratie:\n";
        postordine(heap, hsize, 1);
        int t1 = removeheap(heap, hsize);
        int t2 = removeheap(heap, hsize);

        int suma = t1 + t2;
        cout << endl << t1 << " + " << t2 << " = " << suma << endl;

        insertheap(heap, hsize, suma);
    }
    cout << "Cost minim: " << heap[1];
}

void inordine(int heap[], int n, int i)
{
    if (i > n)
    {
        return;
    }
    inordine(heap, n, 2 * i);
    cout << heap[i] << " ";
    inordine(heap, n, 2 * i + 1);
}

void postordine(int heap[], int n, int i)
{
    if (i > n)
    {
        return;
    }
    postordine(heap, n, 2 * i);
    postordine(heap, n, 2 * i + 1);
    cout << heap[i] << " ";
}