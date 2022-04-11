#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define NMAX 100001

long n;
std::vector<long> G[NMAX];
std::vector<long> rez;

void read_data(const std::string& infile){
    std::ifstream in(infile);
    in>>n;
    for(auto i=0;i<n;i++){
        int x;
        in>>x;
        G[i].push_back(x);
        G[x].push_back(i);
    }
}
int get_parent(int node){
    for(auto i=0;i<n;i++){
        for(auto j=0; j<G[i].size();j++){
            if(G[i][j] == node){
                return i;
            }
        }
    }
}

void erase_from_nodes(int node){
    for(auto i=0;i<=n;i++){
        if(find(G[i].begin(),G[i].end(),node) != G[i].end())
            G[i].erase(find(G[i].begin(), G[i].end(), node));
    }
}

long get_min_leaf_parent(){
    auto min_leaf=n+1;
    for(auto i=0;i<n;i++)
        if(G[i].size()==1 && min_leaf>i){
            min_leaf = get_parent(i);
            G[i].erase(G[i].begin());
            erase_from_nodes(i);
            break;
        }
    return min_leaf;
}

void prufer_encoding(const std::string& outfile){
    while(rez.size()<n){
        auto p=get_min_leaf_parent();
        rez.push_back(p);
    }
    std::ofstream out(outfile);
    out<<n-1<<std::endl;
    for(auto i=0;i<n-1;i++)
        out<<rez[i]<<" ";
}


int main() {
    std::string test, infile, outfile;
    std::cout << "Enter test number(1-9): ";
    std::cin >> test;
    infile = test + "-in.txt"; //argv[1]
    outfile = test + "-out.txt"; //argv[2]
    read_data(infile);
    prufer_encoding(outfile);
    return 0;
}
