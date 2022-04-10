#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <stdlib.h>
using namespace std;

#define infinit 9999
#define nil 0
//int labirint[10000][10000];
typedef struct {
    int l;
    int c;
}poz;

int matrice_adiacenta_neorientat(int m_adiacenta[50][50],const char nume[20]) {
    ifstream in(nume);
    int n, i, j, x, y;
    in >> n;
    // formam o matrice cu valoarea 0 pe fiecare pozitie
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            m_adiacenta[i][j] = 0;
    // formam matricea de adiacenta
    while (in >> x >> y)
        m_adiacenta[x][y] = m_adiacenta[y][x] = 1;
    in.close();
    return n;
}

int matrice_adiacenta_orientat(int m_adiacenta[50][50], const char nume[20]) {
    ifstream in(nume);
    int n, i, j, x, y;
    in >> n;
    // formam o matrice cu valoarea 0 pe fiecare pozitie
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            m_adiacenta[i][j] = 0;
    // formam matricea de adiacenta
    while (in >> x >> y)
        m_adiacenta[x][y] =  1;
    in.close();
    return n;
}
void moore(int mat[50][50], int start, int l[50], int p[50],int n) {
    int i,v;
    l[start] = 0;
    for (v = 1; v <= n; v++)
        if (v != start)
            l[v] = infinit;
    for (v = 1; v <= n; v++)
        p[v] = 0;
    int coada[50],k,u;
    coada[0] = start;
    i = 1;
    while (coada[0]) {
        u = coada[0];
        for (k = 0; k < i-1; k++)
            coada[k] = coada[k + 1];
        coada[i] = 0;
        i--;
        for (v = 1; v <= n; v++)
            if (mat[u][v] == 1)
                if (l[v] == infinit && p[v] == 0) {
                    p[v] = u;
                    l[v] = l[u] + 1;
                    coada[i] = v;
                    i++;
                }
    }
}

void moore_drum(int l[50], int p[50], int v, int drum[50]) {
    int k; 
    k = l[v];
    drum[k] = v;
    while (k != 0) {
        drum[k - 1] = p[drum[k]];
        k--;
    }
}
void BFS(int mat[50][50], int sursa,int viz[50], int dis[50],int parinte[50],int n) {
    int i,u;
    for (i = 1; i <= n; i++) {
        viz[i] = 0;
        dis[i] = infinit;
        parinte[i] = nil;
    }
    int cul = 1;
    viz[sursa] = cul;
    dis[sursa] = 0;
    parinte[sursa] = nil;
    queue<int>coada;
    coada.push(sursa);
    while (!coada.empty()) {
        u = coada.front();
        coada.pop();
        cul++;
        for (i = 1; i <= n; i++)
            if (mat[u][i] == 1 && viz[i] == 0) {
                viz[i] = cul;
                dis[i] = dis[u] + 1;
                parinte[i] = u;
                coada.push(i);
            }
    }
}


void DFS_VISIT(int mat[50][50],int n, int u, int& time,int dis[50],int viz[50],int parinte[50], int fin[50]) {
    cout << u << " ";
    time += 1;
    dis[u] = time;
    viz[u] = 1;
    for (int i = 1; i <= n; i++)
        if (mat[u][i] == 1 && viz[i] == 0) {
            parinte[i] = u;
            DFS_VISIT(mat,n, i, time, dis, viz, parinte, fin);
        }
    viz[u] = 2;
    time += 1;
    fin[u] = time;
}


void DFS(int mat[50][50],int viz[50],int dis[50],int parinte[50],int fin[50],int n) {
    int i, k = 0;
    for (i = 1; i <= n; i++) {
        viz[i] = 0;
        dis[i] = infinit;
        parinte[i] = -1;
    }
    int time = 0;
    for (i = 1; i <= n; i++)
        if (viz[i] == 0) {
            k++;//numarul componentelor conexe
            cout << endl;
            DFS_VISIT(mat,n, i, time,dis,viz,parinte,fin);
        }
    cout << endl << "Numarul de componente conexe ale graficului : " << k;
}

void citire_labirint(int** labirint,int &n,int &m, poz &start,poz &finish) {
    int i,j;
    ifstream in("labirint.txt");
    i = 0;
    string line;
    while (getline(in, line)) {
        for (j = 0; j < line.length(); j++) {
            if (line[j] == '1')
                labirint[i][j] = 1;
            if (line[j] == ' ')
                labirint[i][j] = 0;
            if (line[j] == 'S') {
                labirint[i][j] = 2;
                start.l = i;
                start.c = j;
            }
            if (line[j] == 'F') {
                labirint[i][j] = 2;
                finish.l = i;
                finish.c = j;
            }
        }
        i++;
    }
    n = i;
    m = line.length();
}
/*
void lab_dfs(int** labirint, poz start, poz finish, int m, int n, poz rez[100], int viz[500][500], int k) {
    int i, j; 
    rez[k] = start;
    viz[start.l][start.c] = 1;
    if (start.l = finish.l && start.c = finish.c)
        return;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if (valid(labirint, viz, i, j)) {
                viz[i][j] = 1;
                poz d = { i,j };
                lab_dfs(labirint,d,finish,m,n,rez,viz,k+1)
            }
}
*/
int main() {

    // ex 1 Moore

    int mat[50][50], n, l[50], p[50], drum[50], u, v;
    n = matrice_adiacenta_orientat(mat, "graf.txt");
    cout << "Introduceti nodul:";
    cin >> u;
    cout << endl;
    moore(mat, u, l, p, n);
    for (v = 1; v <= n; v++)
        if (l[v] != infinit) {

            moore_drum(l, p, v, drum);
            for (int i = 0; i <= l[v]; i++)
                cout << drum[i] << "  ";
            cout << endl;
        }
        else
            cout << "Nu exista drum intre " << u << " si " << v << endl;
    cout << endl << endl;

    // ex 2 Inchidere tranzitiva

    n = matrice_adiacenta_orientat(mat, "inchidere_tranzitiva.txt");
    int mat_tranzitiva[50][50];
    int i, j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            mat_tranzitiva[i][j] = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) {
            moore(mat, i, l, p, n);
            if (l[j] != infinit) {
                mat_tranzitiva[i][j] = 1;
            }
            mat_tranzitiva[i][i] = 1;
        }
    cout << "Matricea tranzitiva :" << endl;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            cout << mat_tranzitiva[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    // ex 4 BFS
    n = matrice_adiacenta_orientat(mat, "BFS.txt");
    int viz[50], dis[50], parinte[50],cul=0;
    cout << "Varful sursa BFS: ";
    cin >> v;
    BFS(mat, v, viz, dis, parinte,n);
    cout << "Parcurgere BFS :" << endl;
    for(i=1;i<=n;i++)
        for (j = 1; j <= n; j++)
            if (viz[j] == i )
                cout << j << " ";
    cout << endl;
    for (i = 1; i <= n; i++)
        cout << "Distanta de la " << v << " la " << i << " este " << dis[i] << endl;
    cout << endl << endl;

    // ex 5 DFS
    n = matrice_adiacenta_neorientat(mat, "DFS.txt");
    int  fin[50];
    cout << "Rezultat DFS" << endl;
    DFS(mat, viz, dis, parinte,fin, n);
    cout << endl << endl;

     
    //ex 3 Labirint
    int** labirint;
    int m;
    poz start, finish,rez[100];
    labirint = (int**)malloc(5000 * sizeof(int*));
    for (i = 0; i < 5000; i++)
        labirint[i] = (int*)malloc(5000 * sizeof(int));
    citire_labirint(labirint,n,m,start,finish);
    //lab_dfs(labirint,start,finish,m,n,rez,vis,k)
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (labirint[i][j] == 1)
                printf("\x1B[31m%d\033[0m ", labirint[i][j]);
            if (labirint[i][j] == 2)
                printf("\x1B[33m%d\033[0m ", labirint[i][j]);
            if (labirint[i][j] == 0)
                printf("%d ", labirint[i][j]);
        }
        cout << endl;
    }
    for (i = 0; i < 5000; i++)
        free(labirint[i]);
    free(labirint);
    return 0;
}