#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;
    cout<<"n= ";
    cin>>n;
    char **c=new char*[n];
    for(int i=0;i<n;i++)
    {
        c[i]=new char[n];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>c[i][j];
        }
    }
    cout<<endl;



    for(int i=0;i<n/2;i++)
    {
        for(int j=i;j<n-i-1;j++)
        {
            char temp=c[i][j];
            c[i][j] = c[n-1-j][i];
            c[n-1-j][i] = c[n-1-i][n-1-j];
            c[n-1-i][n-1-j] = c[j][n-1-i];
            c[j][n-1-i] = temp;
        }
    }

    //sau mai pe inteles reverse+transpusa

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++)
    {
        delete[] c[i];
    }
    return 0;
}