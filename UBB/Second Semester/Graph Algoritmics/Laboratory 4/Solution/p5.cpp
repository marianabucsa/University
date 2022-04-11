#include <fstream>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#define NMAX 100001

class Node{
public:
    int x;
    int y;
    int cost;
    Node(int x, int y, int cost){
        this->x = x;
        this->y = y;
        this->cost = cost;
    }
};
std::vector<int> answer;
std::vector<Node*> muchii;
std::vector<std::pair<int, int>> rez;
int father[NMAX];
int n, m;
int cost_sol = 0;

void read_data(const std::string infile){
    std::ifstream in(infile);
    in>>n>>m;
    for(int i = 0; i<m; i++){
        int x, y, cost;
        in >> x>> y>> cost;
        muchii.push_back(new Node(x,y,cost));
    }
    in.close();
}

int find_(int x){
    if(father[x] == x) return x;
    father[x] = find_(father[x]);
    return father[x];
}

void unite(int x, int y){
    father[find_(y)] = find_(x);
}

void solve(){
    sort(muchii.begin(), muchii.end(), [&](Node* i, Node* j){
        return i->cost < j->cost;
    });

    for(int i = 0; i < n; i++){
        father[i] = i;
    }
    for(int i = 0; i<m; i++){
        if(find_(muchii[i]->x) != find_(muchii[i]->y)){
            cost_sol += muchii[i]->cost;
            answer.push_back(i);
            unite(muchii[i]->x,muchii[i]->y);
        }
    }
}

void write(const std::string& outfile){
    std::ofstream out(outfile);
    out<<cost_sol<<std::endl;
    out<<answer.size()<<std::endl;
    for(int i = 0; i<answer.size(); i++){
        rez.push_back(std::make_pair(muchii[answer[i]]->x,muchii[answer[i]]->y));
    }
    std::sort(rez.begin(), rez.end(), [&](std::pair<int,int> i, std::pair<int,int> j){
        if(i.first == j.first)
            return i.second < j.second;
        return i.first < j.first;
    });
    for(auto i : rez){
        out<< i.first<<" "<<i.second<<std::endl;
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
    solve();
    write(outfile);
    return 0;
}