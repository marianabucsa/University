#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <cstring>
#include <limits.h>
#define NMAX 1001

int graph[NMAX][NMAX];
int n, m;
int source, dest;
int parent[NMAX];

void read_data(const std::string& infile) {
    std::ifstream in(infile);
    in >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, c;
        in >> x >> y >> c;
        graph[x][y] = c;
    }
    in.close();
}

bool bfs(int s, int d) {
    bool visited[NMAX];
    memset(visited, 0, sizeof(visited));
    std::queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 0; i < n; i++) {
            if (!visited[i] && graph[node][i] > 0) {
                q.push(i);
                parent[i] = node;
                visited[i] = true;
            }
        }
    }
    return (visited[d] == true);
}

void ford_fulkerson(const std::string& outfile) {
    source = 0;
    dest = n-1;
    int max_flow = 0;
    while (bfs(source, dest)) {
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
    std::ofstream out(outfile);
    out << max_flow;
    out.close();
}

int main() {
    std::string test, infile, outfile;
    std::cout << "Enter test number(1-10): ";
    std::cin >> test;
    infile = test + "-in.txt"; //argv[1]
    outfile = test + "-out.txt"; //argv[2]
    read_data(infile);
    ford_fulkerson(outfile);
    return 0;
}