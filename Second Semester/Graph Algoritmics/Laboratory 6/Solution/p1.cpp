#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string.h>

#define NMAX 100

typedef struct {
    int indice;
    int grad;
}Nod;

bool cmp_f(Nod x, Nod y) {
    return x.grad > y.grad;
}

bool colorat(int* rez, int n) {
    for (int i = 0; i < n; i++)
        if (rez[i] == -1)
            return false;
    return true;
}

bool adiacent(int x, int y, std::vector<int> G[NMAX]) {
    for (auto v : G[x])
        if (v == y)
            return true;
    return false;
}

bool remove_f(Nod nd) {
    return nd.grad == -1;
}

void read_data(char* infile, std::vector<int> G[NMAX], int* n, int* m) {
    std::ifstream in(infile);
    in >> *n >> *m;
    // salvam sub forma unei liste de adiacenta
    for (int i = 0; i < *m; i++) {
        int x, y;
        in >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    in.close();
}

void colorare(int n, int m, std::vector<int>* G, char* outfile) {
    //  algoritmul welsh_powell

    // rezultatul colorarii va fi stocat in rez
    int rez[100];
    for (int i = 0; i < n; i++)
        rez[i] = -1;

    // sortam varfurile descrescator dupa grad
    std::vector<Nod> varfuri;
    for (int i = 0; i < n; i++) {
        Nod n;
        n.indice = i;
        n.grad = G[i].size();
        varfuri.push_back(n);
    }
    std::sort(varfuri.begin(), varfuri.end(), cmp_f);

    int k, curent = 0, culoare = 0;

    while (!colorat(rez, n)) {
        /*
         * cat timp nu am ajuns la un rezultat adaugam culoarea curenta la toate varfurile
         * care nu sunt adiacenta cu varful curent
         */
        curent = 0;
        while (rez[varfuri[curent].indice] != -1 && curent<varfuri.size())
            curent++;
        rez[varfuri[curent].indice] = culoare;
        varfuri[curent].grad = -1;
        k = curent + 1;
        while (k < varfuri.size()) {
            bool ok = true;
            for (int i = 0; i < varfuri.size(); i++) {
                if (rez[varfuri[i].indice]==culoare && adiacent(varfuri[k].indice, varfuri[i].indice, G))
                    ok = false;
            }
            if (ok) {
                rez[varfuri[k].indice] = culoare;
                varfuri[k].grad = -1;
            }
            k++;
        }
        culoare++;
        remove_if(varfuri.begin(), varfuri.end(), remove_f);
    }
    std::ofstream out(outfile);
    out << culoare << std::endl;
    for (int i = 0; i < n; i++)
        out << rez[i] << " ";
}

int main(int argc, char* argv[]) {
    char infile[20], outfile[20];
    strcpy(infile,argv[1]);
    strcpy(outfile,argv[2]);

    std::vector<int> G[NMAX];
    int n, m;
    read_data(infile, G, &n, &m);
    colorare(n, m, G, outfile);
    return 0;
}