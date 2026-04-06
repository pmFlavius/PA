#pragma once

const int DIM_MAX = 100;

void insertheap(int heap[],int &n,int val);
int removeheap(int heap[],int &n);
void creareLEP(int x[],int n);
void inordine(int heap[],int n,int i);
void postordine(int heap[],int n,int i);
