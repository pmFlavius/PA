#pragma once

struct Nod
{
    int data;
    Nod *succ;
};

struct Lista
{
    Nod *prim;
    Nod *ultim;
    Lista()
    {
        prim=nullptr;
        ultim=nullptr;
    }
};

int getCifra(int nr,int k);
void inserare(Nod *&cap,int data);
void inserareLista(Lista &L,int data);
void stergere(Nod *&cap);
void afisare(Nod *cap);
void concatenare(Lista &L, Lista &K);

void RadixSort(Lista &L,int n,int m,int k);