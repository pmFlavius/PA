#pragma once

#include <iostream>

using namespace std;

struct Nod
{
    int data;
    Nod *succ;
    Nod *pred;
};

void inserare(Nod *&cap,int data);
void inserareK(Nod *&cap,int data,int k);
void afisare(Nod *cap);
