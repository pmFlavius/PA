#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;

int DIM = 3;                     // Dimensiunea tablei
const string GOAL = "ABCEHFLGD"; // Configuratia finala Cf
vector<vector<int>> adj = {
    {1, 3},    // o piesa aflata in pozitia 0 se poate deplasa in pozitiile 1 si 3 (dreapta si jos)
    {0, 2, 4}, // o piesa aflata in pozitia 1 se poate deplasa in pozitiile 0, 2 si 4 (stanga, dreapta si jos)
    {1, 5},
    {0, 4, 6},
    {1, 3, 5, 7},
    {2, 4, 8},
    {3, 7},
    {4, 6, 8},
    {5, 7}}; // lista de adiacenta care reprezinta vecinii posibili ai fiecarei pozitii

struct Node
{                        // structura nodului pentru heap
    int level;           // nivelul in arbore
    int cStar;             // c*: nivel + g*(v)
    string config;       // configuratia curenta
    vector<string> path; // drumul parcurs pana la aceasta configuratie

    bool operator>(const Node &other) const
    {
        return cStar > other.cStar; // conditia necesara pentru coada cu prioritati
    }
};

// Functia pozC care returneaza pozitia caracterului X in configuratia C
int pozC(const string C, char X) {
    return C.find(X);
}

// Numara piesele Y care apar dupa piesa X in configuratia C,
// dar care ar trebui sa apara inaintea lui X in configuratia finala (GOAL)
int lessC(const string C, char X) {
    int cnt = 0;
    int pos = pozC(C,X);
    for(int i = pos+1;i<C.size();i++){
        if(C[i] < X && C[i] != 'L') {
            cnt++;
        }
    }
    return cnt;
}

// Functia lC care determina paritatea pozitiei libere (L) pe tabla
int lC(const string C) {
    int pos = pozC(C,'L');
    return pos % 2;
}

// Functia isSolvable care decide daca configuratia initiala C poate fi rezolvata
bool isSolvable(const string C) {
    
}

// Functia gStar care calculeaza cate piese sunt in pozitie gresita fata de configuratia finala Cf
int gStar(const string C) {
    int cnt=0;
    for(int i=0;i<C.size();i++){
        if(C[i] != GOAL[i] && C[i] != 'L') {
            cnt++;
        }
    }
    return cnt;
}

// Functia generateChildren care genereaza toate configuratiile posibile prin mutarea lui L
// Aici se foloseste lista de adiacenta pentru a gasi vecinii posibili lui L
vector<string> generateChildren(const string C) {
    vector<string> copii;
    int pos = pozC(C,'L');
    for(int i=0;i<adj[pos].size();i++){
        int newPos = adj[pos][i];
        string newConfig = C;
        swap(newConfig[pos], newConfig[newPos]);
        copii.push_back(newConfig);
    }
    return copii;
}

// Functia perspico care implementeaza algoritmul Perspico
void perspico(const string radacina)
{
    // Verificam daca configuratia initiala are solutie
    // Creare min heap
    priority_queue<Node, vector<Node>, greater<Node>> A;
    unordered_set<string> visited; //pentru a nu se repeta aceleasi configuratii 
    // Adaugam nodul de start in heap
    A.push({0, gStar(radacina), radacina, {radacina}});
    visited.insert(radacina);
    while (!A.empty())
    {
        // Extragem nodul cu costul minim
        Node min = A.top();
        A.pop();
        // Verificam daca am ajuns la solutia finala si afisam drumul parcurs pana la aceasta configuratie
        if(min.config == GOAL) {
            cout << "Drumul parcurs: " << endl;
            for(int i=0;i<min.path.size();i++){
                cout<<min.path[i]<<endl;
            }
            return;
        }
        // Generam copii pentru nodul curent
        vector<string>copii = generateChildren(min.config);
        // Adaugam fiecare copil in heap
        cout<<"Copii: " << endl;
        for(int i=0;i<copii.size();i++){
            if(visited.find(copii[i]) != visited.end()) {
                continue; // daca configuratia a fost deja vizitata, o sarim
            }
            cout<<copii[i]<<endl;
            string configCopil = copii[i];
            int g = gStar(configCopil);
            int cStar = min.level + 1 + g;
            vector<string> pathCopil = min.path;
            pathCopil.push_back(configCopil);
            A.push({min.level + 1, cStar, configCopil, pathCopil});
            visited.insert(copii[i]);
        }
        cout<<endl;
        
    }
}

int main()
{
    string configuratieInitiala = "ABCEFLGHD"; // configuratia initiala
    perspico(configuratieInitiala);
    return 0;
}

