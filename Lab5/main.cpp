#include <iostream>
#include "functii.h"
using namespace std;

int main()
{
    int n;
    cin>>n;
    int *x=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }
    creareLEP(x,n);
    delete[] x;
    return 0;
}