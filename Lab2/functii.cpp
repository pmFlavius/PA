#include <iostream>
#include <cmath>
#include "header.h"

void inserare(Nod *&cap, int data)

{
    if (!cap)
    {
        cap = new Nod;
        cap->data = data;
        cap->succ = nullptr;
    }
    else
    {
        Nod *p = new Nod;
        p->data = data;
        p->succ = cap;
        cap = p;
    }
}

void inserareLista(Lista &L, int data)
{
    Nod *p = new Nod;
    p->data = data;
    p->succ = nullptr;
    if (!L.prim)
    {
        L.prim = L.ultim = p;
    }
    else
    {
        L.ultim->succ = p;
        L.ultim = L.ultim->succ;
    }
}

void stergere(Nod *&cap)
{
    if (!cap)
    {
        perror("Lista vida");
    }
    else
    {
        Nod *p = cap;
        cap = cap->succ;
        delete p;
    }
}

void afisare(Nod *cap)
{
    Nod *p = cap;
    while (p)
    {
        std::cout << p->data << " ";
        p = p->succ;
    }
    std::cout << std::endl;
}
void concatenare(Lista &L, Lista &K)
{
    if (!K.prim)
        return;
    if (!L.prim)
    {
        L.prim = K.prim;
        L.ultim = K.ultim;
    }
    else
    {
        L.ultim->succ = K.prim;
        L.ultim = K.ultim;
    }
    K.ultim = K.prim = nullptr;
}
int getCifra(int nr, int k)
{
    int p = 1;
    for (int i = 0; i < k; i++)
        p *= 10;
    return (nr / p) % 10;
}
// m numarul maxim de cifre
// k baza de numeratie
// n numarul de elemente din lista
void RadixSort(Lista &L, int n, int m, int k)
{
    Lista *pachet = new Lista[k];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < k; j++)
        {
            pachet[j] = Lista();
        }
        while (L.prim)
        {
            int w = L.prim->data;
            int cif = getCifra(L.prim->data, i);
            stergere(L.prim);
            inserareLista(pachet[cif], w);
        }
        for (int j = 0; j < k; j++)
        {
            concatenare(L, pachet[j]);
        }
    }
    delete[] pachet;
}
