#include "header.h"

using namespace std;

int main()
{
    Nod *cap=0;
    int x;
    cin>>x;
    while(x)
    {
        inserare(cap,x);
        cin>>x;
    }
    afisare(cap);
    int k;
    cout<<"\nintrodu k: ";
    cin>>k;
    cout<<"\nintrodu data: ";
    cin>>x;
    inserareK(cap,x,k);
    afisare(cap);
    return 0;
}