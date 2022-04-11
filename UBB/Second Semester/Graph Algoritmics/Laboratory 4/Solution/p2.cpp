#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define NMAX 100001

struct pair {
    long x, y;
};
long n;
std::vector<long> prufer_encoding;
std::vector<long> rez;

void read_data(const std::string& infile) {
    std::ifstream in(infile);
    in >> n;
    for (auto i = 0; i < n; i++) {
        int x;
        in >> x;
        prufer_encoding.push_back(x);
    }
}

long get_smallest() {
    long frequence[NMAX];
    for (auto i = 0; i <= n; i++) {
        frequence[i] = false;
    }
    for (auto i = 0; i < prufer_encoding.size(); i++) {
        frequence[prufer_encoding[i]] = true;
    }
    for (auto i = 0; i <= n; i++) {
        if (!frequence[i])
            return i;
    }
    return -1;
}

void prufer_decoding(const std::string& outfile) {
    std::vector<pair> r;
    for (auto i = 0; i < n; i++) {
        auto first = prufer_encoding.begin();
        pair e;
        e.x = *first;
        e.y = get_smallest();
        r.push_back(e);
        prufer_encoding.erase(first);
        prufer_encoding.push_back(e.y);
    }
    std::vector<long> rez;
    for (auto i = 0; i < n + 1; i++) {
        rez.push_back(-1);
    }
    for (auto i = 0; i < r.size(); i++) {
        rez[r[i].y] = r[i].x;

    }
    std::ofstream out(outfile);
    out << n + 1 << std::endl;
    for (auto i = 0; i < rez.size(); i++)
        out << rez[i]<< " ";
}


int main() {
    std::string test, infile, outfile;
    std::cout << "Enter test number(1-9): ";
    std::cin >> test;
    infile = test + "-in.txt"; //argv[1]
    outfile = test + "-out.txt"; //argv[2]
    read_data(infile);
    prufer_decoding(outfile);
    return 0;
}