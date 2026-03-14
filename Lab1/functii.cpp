#include "header.h"

void inserare(Nod *&cap,int data)
{
    Nod *p=0;
    p=new Nod;
    if(!cap)
    {
        cap=p;
        cap->pred=0;
        cap->succ=0;
        cap->data=data;
    }
    else
    {
        p->data=data;
        p->succ=cap;
        p->pred=0;
        cap->pred=p;
        cap=p;
    }
}

void inserareK(Nod *&cap,int data,int k)
{
    Nod *p=cap;
    int cnt=0;
    if(k==0)
    {
        inserare(cap,data);
        return;
    }
    while(p)
    {
        if(cnt==k-1)
        {
            Nod *q=new Nod;
            q->data=data;
            q->succ=p->succ;
            q->pred=p;
            p->succ->pred=q;
            p->succ=q;
            return;
        }
        cnt++;
        p=p->succ;
    }
    cout<<"k > dimensiunea listei"<<endl;
    
}

void afisare(Nod *cap)
{
    Nod *p=cap;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->succ;
    }
}