#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <cstring>
#include <limits.h>
#define NMAX 101

void read_data(int* N, int* C, int* D, int graph[NMAX][NMAX], char *infile) {
    std::ifstream in(infile);
    in >> *N >> *C>> *D;
    for (int i = 0; i < *D; i++) {
        int x, y, c;
        in >> x >> y >> c;
        graph[x][y] = c;
    }
    in.close();
}

bool bfs(int s, int d, int parent [NMAX], int graph[NMAX][NMAX], int N) {
    bool visited[NMAX];
    memset(visited, 0, sizeof(visited));
    std::queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 0; i < N; i++) {
            if (!visited[i] && graph[node][i] > 0) {
                q.push(i);
                parent[i] = node;
                visited[i] = true;
            }
        }
    }
    return (visited[d] == true);
}

int ford_fulkerson(int source, int dest ,int N, int graph[NMAX][NMAX],int parent[NMAX]) {
    int max_flow = 0;
    while (bfs(source, dest, parent, graph, N)) {
        int path_flow = INT_MAX;
        for (int i = dest; i != source; i = parent[i]) {
            int u = parent[i];
            path_flow = std::min(path_flow, graph[u][i]);
        }

        for (int i = dest; i != source; i = parent[i]) {
            int u = parent[i];
            graph[u][i] -= path_flow;
            graph[i][u] += path_flow;
        }

        max_flow += path_flow;
    }
    return max_flow;
}

int main(int argc, char *argv[]) {
    char infile[20], outfile[20];
    strcpy(infile, argv[1]);
    strcpy(outfile, argv[2]);
    int graph[NMAX][NMAX];
    int N, C, D;
    int parent[NMAX];
    read_data(&N, &C, &D, graph, infile);
    std::vector<int> v;
    for(int i=0; i<C;i++)
        v.push_back(ford_fulkerson(i, N-1, N, graph, parent));
    int s = 0;
    for (auto i : v)
        s += i;
    std::ofstream out(outfile);
    out << s << std::endl;
    for (auto i : v)
        out << i << " ";
    return 0;
}