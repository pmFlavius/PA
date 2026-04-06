#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pair {
    int X; // greutate
    int Y; // profit
};

bool compara(Pair a, Pair b) {
    if (a.X == b.X)
        return a.Y > b.Y; // profit mai mare primul
    return a.X < b.X;     // greutate mai mica prima
}


// interclasare + eliminare solutii dominate
vector<Pair> interclGrafice(vector<Pair>& A, vector<Pair>& B) {
    vector<Pair> C;

    // copiem A
    for (int i = 0; i < A.size(); i++) {
        C.push_back(A[i]);
    }

    // copiem B
    for (int i = 0; i < B.size(); i++) {
        C.push_back(B[i]);
    }

    // sortam dupa greutate crescator, profit descrescator
    sort(C.begin(), C.end(), compara);

    vector<Pair> rez;
    int maxProfit = -1;

    // pastram doar punctele eficiente
    for (int i = 0; i < C.size(); i++) {
        if (C[i].Y > maxProfit) {
            rez.push_back(C[i]);
            maxProfit = C[i].Y;
        }
    }

    return rez;
}

void rucsac(int M, int n, vector<int>& w, vector<int>& p, vector<int>& x) {
    vector<vector<Pair>> S(n + 1);
    vector<Pair> T;

    // cazul initial
    S[0].push_back({0, 0});

    for (int i = 0; i < n; i++) {
        T.clear();

        // construim T (adaugam obiectul i)
        for (int j = 0; j < S[i].size(); j++) {
            Pair pr = S[i][j];
            Pair nou;
            nou.X = pr.X + w[i];
            nou.Y = pr.Y + p[i];
            T.push_back(nou);
        }

        // unim S[i] si T
        S[i + 1] = interclGrafice(S[i], T);
    }

    // cautam cea mai buna solutie cu greutate <= M
    int Xj = 0, Yj = 0;

    for (int i = 0; i < S[n].size(); i++) {
        if (S[n][i].X <= M && S[n][i].Y > Yj) {
            Xj = S[n][i].X;
            Yj = S[n][i].Y;
        }
    }

    int profitmaxim = Yj;

    // reconstruim solutia
    for (int i = n - 1; i >= 0; i--) {
        bool gasit = false;

        for (int j = 0; j < S[i].size(); j++) {
            if (S[i][j].X == Xj && S[i][j].Y == Yj) {
                gasit = true;
                break;
            }
        }

        if (gasit) {
            x[i] = 0;
        } else {
            x[i] = 1;
            Xj = Xj - w[i];
            Yj = Yj - p[i];
        }
    }

    // afisare
    cout << "Profit maxim: " << profitmaxim << endl;

    cout << "Obiecte alese: ";
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

int main() {
    int n = 4, M = 7;

    vector<int> w = {1, 3, 4, 5};
    vector<int> p = {1, 4, 5, 7};
    vector<int> x(n, 0);

    rucsac(M, n, w, p, x);

    return 0;
}