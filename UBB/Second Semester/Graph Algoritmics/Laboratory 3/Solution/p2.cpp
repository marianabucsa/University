#include <cstdio>
#include <vector>
#include <queue>
#include <fstream>
#include <string>
#include <iostream>
#define INF 1e9
#define NMAX 500

using namespace std;

class node {
public:
    int y, cost;
    node(int y, int cost) {
        this->y = y;
        this->cost = cost;
    }
    bool operator <(const node& other) const {
        return this->cost < other.cost;
    }
};

vector<node>G[NMAX];
priority_queue<node>prior_q;
queue<int>q;
int dist[NMAX][NMAX];
int nr_v, nr_a;
int h[NMAX];
bool negative = false;

void read_data(std::string infile){
    ifstream in(infile);
    in >> nr_v >> nr_a;
    for (int i = 1; i <= nr_a; i++) {
        int x, y, cost;
        in >> x >> y >> cost;
        G[x].push_back(node(y, cost));
    }
    in.close();
}


void bellman_ford(int start){
    int cnt_cycle[1001];
    for(int i = 0; i<=nr_v; i++){
        h[i] = INF;
        cnt_cycle[i] = 0;
    }
    h[start] = 0;
    q.push(start);
    vector<node>::iterator it;
    while(!q.empty()){
        int nod = q.front();
        q.pop();
        for(it = G[nod].begin(); it != G[nod].end(); it++){
            if(h[nod] + it -> cost < h[it -> y]){
                h[it -> y] = h[nod] + it -> cost;
                if(cnt_cycle[it -> y] > nr_v){
                    negative = true;
                    return;
                }
                else{
                    q.push(it -> y);
                    cnt_cycle[it->y] ++;
                }
            }
        }
    }

}

void empty_q(priority_queue<node>q){
    while(!q.empty()){
        q.pop();
    }
}


void dijkstra(int start){
    //empty_q(prior_q);
    for(int i = 0; i<nr_v; i++){
        dist[start][i] = INF;
    }
    dist[start][start] = 0;
    prior_q.push(node(start, dist[start][start]));
    vector<node>::iterator it;
    while(!prior_q.empty()){
        node fr = prior_q.top();
        int nod = fr.y;
        int cost = fr.cost;
        prior_q.pop();
        //if(dist[start][nod] != cost){
          //  continue;
        //}
        for(it = G[nod].begin(); it != G[nod].end(); it++){
            if(dist[start][nod] + it -> cost < dist[start][it -> y]){
                dist[start][it -> y] = dist[start][nod] + it -> cost;
                prior_q.push(node(it->y, dist[start][it->y]));
            }
        }
    }
}

void add_node_reweight(){
    for(int i = 1; i<=nr_v; i++){
        G[nr_v+1].push_back(node(i, 0));
    }
}

void johnsons_alg(std::string outfile){
    add_node_reweight();
    bellman_ford(0 );
    ofstream out(outfile);
    if(negative == true){
        printf("Graful are un circuit negativ!\n");
        out<<"-1";
        return;
    }
    for(int i = 0; i<nr_v; i++){
        for(int j = 0; j<G[i].size(); j++){
            node nod = G[i][j];
            if(nod.cost!=INF)
                nod.cost = nod.cost + h[i] - h[nod.y];
            G[i][j] = nod;
            out<< i<<" "<<nod.y<< " "<< nod.cost<<"\n";
        }
    }
    for(int i = 0; i<nr_v; i++){
        dijkstra(i);
    }
    for(int i = 0; i<nr_v; i++){
        for(int j = 0; j<nr_v; j++){
            if(dist[i][j] != INF){
                dist[i][j] = dist[i][j] + h[j] - h[i];
                out<< dist[i][j]<<" ";
            }
            else{
                out<<"INF ";
            }
        }
        out<<"\n";
    }
    out.close();
}


int main(){
    std::string test, infile, outfile;
    std::cout << "Enter test number(1-10): ";
    std::cin >> test;
    infile = test + "-in.txt"; //argv[1]
    outfile = test + "-out.txt"; //argv[2]
    read_data(infile);
    johnsons_alg(outfile);
    return 0;
}