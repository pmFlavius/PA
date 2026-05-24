#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void Dijkstra(vector<vector<int>> &L,int start,vector<int> &D,vector<int> &P,int n)
{
    vector<bool> visited(n,false); //initializeaza tot vectorul cu 0 uri 
    //construirea vectorilor D si P
    //D - distante, P - predecesiri
    for(int i=0;i<n;i++)
    {
        D[i]=L[start][i];
        if(D[i]==INT_MAX)
            P[i]=-1;
        else
            P[i]=start;
    }

    visited[start]=true;
    
    for(int i=0;i<n-1;i++)
    {
        int min = INT_MAX;
        int k =-1;
        for(int j=0;j<n;j++)
        {
            if(!visited[j] && D[j]<min)
            {
                min = D[j];
                k = j;
            }
        }
        if(k==-1)
            break;

        visited[k]=true;
        for(int j=0;j<n;j++)
        {
            if(!visited[j] && L[k][j]!=INT_MAX && D[k]!=INT_MAX && D[j] > D[k] + L[k][j])
            {
                D[j] = D[k] + L[k][j];
                P[j] = k;
            }
        }

    }
}

int main()
{
    int n = 4;

    vector<vector<int>> L =
    {
        {0, 2, 3, INT_MAX},
        {INT_MAX, 0, INT_MAX, 4},
        {INT_MAX, INT_MAX, INT_MAX, 1},
        {INT_MAX, INT_MAX, INT_MAX, 0}
    };

    vector<int> D(n);
    vector<int> P(n);

    int start;
    cin>>start;
    Dijkstra(L,start,D,P,n);

    cout<<"D:\n";
    for(int i=start;i<n;i++)
        cout<<D[i]<<" ";

    cout<<"\nP:\n";
    for(int i=start;i<n;i++)
        cout<<P[i]<<" ";

    cout<<endl;
    for(int i=n-1;i>=start;i--)
    {
        if(P[i]!=-1)
            cout<<i<<" ";
        if(P[i]==start)
        {
            cout<<start<<" ";
            break;
        }
    }

    return 0;
}
