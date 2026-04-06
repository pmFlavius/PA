#include <iostream>

using namespace std;

struct Obiect
{
    int greutate;
    int profit;
};

void rucsac1(Obiect o[], int M, int n)
{
    double *solutie = new double[n];
    int C = 0;
    double profit_final=0;
    for (int i = 0; i < n; i++)
    {
        solutie[i] = 0;
    }
    while (C < M)
    {
        int k = -1;
        int maxim_profit = -1;
        for (int i = 0; i < n; i++)
        {
            if (solutie[i] == 0)
            {
                if (o[i].profit > maxim_profit)
                {
                    maxim_profit = o[i].profit;
                    k = i;
                }
            }
        }
        if (k == -1)
            break;

        if (C + o[k].greutate <= M)
        {
            solutie[k] = 1;
            C += o[k].greutate;
            profit_final+=o[k].profit;
        }
        else
        {
            solutie[k] = static_cast<double>(M-C)/o[k].greutate;
            C = M;
            profit_final+=o[k].profit*solutie[k];
        }
    }
    cout<<"Profit final pt rucsac1: "<<profit_final<<endl;
    delete[] solutie;
}

void rucsac2(Obiect o[], int M, int n)
{
    double *solutie = new double[n];
    for (int i = 0; i < n; i++)
    {
        solutie[i] = 0;
    }
    int C=0;
    double profit_final=0;
    while (C < M)
    {
        int k = -1;
        double profit_max = -1;
        for (int i = 0; i < n; i++)
        {
            if (solutie[i] == 0)
            {
                double raport = static_cast<double>(o[i].profit) / o[i].greutate;
                if (raport > profit_max)
                {
                    profit_max = raport;
                    k = i;
                }
            }
        }
        if (k == -1)
            break;
        if (C + o[k].greutate <= M)
        {
            solutie[k] = 1;
            C += o[k].greutate;
            profit_final+=o[k].profit;
        }
        else
        {
            solutie[k]=static_cast<double>(M-C)/o[k].greutate;
            C=M;
            profit_final+=o[k].profit*solutie[k];
        }
    }
    cout<<"Profit final pt rucsac2: "<<profit_final<<endl;
    delete[] solutie;
}

int main()
{
    int n,M;
    cin>>n>>M;
    Obiect *o=new Obiect[n];
    for(int i=0;i<n;i++)
    {
        cin>>o[i].greutate>>o[i].profit;
    }
    rucsac1(o,M,n);
    rucsac2(o,M,n);

}