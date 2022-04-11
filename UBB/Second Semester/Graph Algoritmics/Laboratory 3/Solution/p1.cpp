#include <cstdio>
#include <deque>
#include <climits>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#define NMAX 50001
#define INF INT_MAX

using namespace std;

class node {
public:
    int y, cost;
    node(int y, int cost) {
        this->y = y;
        this->cost = cost;
    }
};

vector <node> G[NMAX];
deque <int> Q;
bool negative = false;
int nr_v, nr_a, sursa, dist[NMAX];

void read_data(const std::string infile) {
    ifstream in(infile);
    in >> nr_v >> nr_a >> sursa;
    for (int i = 1; i <= nr_a; i++) {
        int x, y, cost;
        in >> x >> y >> cost;
        G[x].push_back(node(y, cost));
    }
    in.close();
}


void bellman(int nr_v, int start, deque <int> Q, vector<node> G[NMAX], int dist[], bool& negative) {
    int cnt_cycle[10001];

    for (int i = 0; i < nr_v; i++) {\
        dist[i] = INF;
        cnt_cycle[i] = 0;
    }
    Q.push_back(start);
    vector<node> ::iterator it;
    dist[start] = 0;
    while (!Q.empty()) {
        int node = Q.front();
        Q.pop_front();
        for (it = G[node].begin(); it != G[node].end(); it++) {
            if (dist[node] + it->cost < dist[it->y]) {
                dist[it->y] = dist[node] + it->cost;
                if (cnt_cycle[it->y] > nr_v) {
                    negative = true;
                    return;
                }
                else {
                    Q.push_back(it->y);
                    cnt_cycle[it->y] ++;
                }
            }
        }
    }
}


int main() {
    std::string test, infile, outfile;
    std::cout << "Enter test number(1-7): ";
    std::cin >> test;
    infile = test + "-in.txt"; //argv[1]
    outfile = test + "-out.txt"; //argv[2]
    read_data(infile);
    bellman(nr_v, sursa, Q, G, dist, negative);
    if(negative == true) {
        printf("Ciclu negativ!");
    }else {
        ofstream out(outfile);
        for (int i = 0; i < nr_v; i++) {
            if (dist[i] == INF)
                out << "INF ";
            else
                out << dist[i] << " ";
        }
        out.close();
    }
    return 0;
}