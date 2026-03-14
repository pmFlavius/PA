#pragma once

#include <algorithm>

using namespace std;

void compara_si_schimba(int &a,int &b,bool s)
{
    //s=0 crescator
    //s=1 descrescator
    if(s==0)
    {
        if(b<a)
            swap(a,b);
    }
    else
    {
        if(a<b)
            swap(a,b);
    }
    return;
}

void sortare_secventa_bitona(int a[],int i,int d,bool s)
{
    if(d==2)
    {
        compara_si_schimba(a[i],a[i+1],s);
        return;
    }
    for(int j=0;j<d/2;j++)
    {
        compara_si_schimba(a[i+j],a[i+j+d/2],s);
    }
    sortare_secventa_bitona(a,i,d/2,s);
    sortare_secventa_bitona(a,i+d/2,d/2,s);
}


void BatcherSort(int a[],int i,int d,bool s)
{
    if(d==2)
    {
        compara_si_schimba(a[i],a[i+1],s);
    }
    else
    {
        BatcherSort(a,i,d/2,0);
        BatcherSort(a,i+d/2,d/2,1);
        sortare_secventa_bitona(a,i,d,s);
    }
}


