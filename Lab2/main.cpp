#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    Lista L;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        inserareLista(L,x);
    }
    afisare(L.prim);

    RadixSort(L,n,3,10);

    afisare(L.prim);
    return 0;
}