#include <iostream>
#include <chrono>
#include <random>
#include "functii.h"
using namespace std;

int main()
{
    //n trebuie sa fie putere a lui 2 (65536)
    //5452.49 ms cand vectorul e aleator generat
    //5390.19 ms cand vectorul e sortat crescator deja
    //5043.23 ms cand vectorul e sortat descrescator deja !!!!
    auto start = std::chrono::high_resolution_clock::now();

    int n;
    cin >> n;
    int v[100005];
    for (int i = 0; i < n; i++)
    {
        v[i]=n-i;
    }
    BatcherSort(v, 0, n, 0);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout<<endl<<endl<<endl;
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = end - start;

    auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(duration);
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
    float ms_fractional = static_cast<float>(microseconds.count()) / 1000.0f;

    cout << "Duration = "
         << microseconds.count() << " µs ("
         << ms_fractional << " ms)"
         << std::endl;

    return 0;
}