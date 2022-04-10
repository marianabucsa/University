#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>

class Node {
public:
    char caracter;
    int freq;
    Node* left, * right;
    Node(char caracter, int freq) {
        this->left = this->right = nullptr;
        this->caracter = caracter;
        this->freq = freq;
    }
};

class Comparator {
public:
    bool operator()(const Node* a, const Node* b) {
        if (a->freq == b->freq)
            return int(a->caracter) > int(b->caracter);
        return a->freq > b->freq;
    }
};

std::string str;
std::priority_queue< Node*, std::vector<Node*>, Comparator> p_queue;


void read_data(const std::string& infile) {
    std::ifstream in(infile);
    int n;
    in >> n;
    in.get();
    for (int i = 0; i < n; i++) {
        char caracter;
        int freq;
        in.get(caracter);
        in >> freq;
        in.get();
        p_queue.push(new Node(caracter, freq));
    }
    std::string read;
    while (!in.eof()) {
        std::getline(in, read);
        str += read;
    }
    in.close();
}

void huffman_decoding(const std::string& outfile) {
    while (p_queue.size() != 1) {
        auto left = p_queue.top();
        p_queue.pop();

        auto right = p_queue.top();
        p_queue.pop();

        auto nod = new Node('$', left->freq + right->freq);
        nod->left = left;
        nod->right = right;
        p_queue.push(nod);
    }
    std::string rez;
    Node* nod = p_queue.top();
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '0')
            nod = nod->left;
        else
            nod = nod->right;
        if (nod->left == nullptr && nod->right == nullptr) {
            rez += nod->caracter;
            nod = p_queue.top();
        }
    }
    std::ofstream out(outfile);
    out << rez;
    out.close();
}

int main() {
    std::string test, infile, outfile;
    std::cout << "Enter test number(1-5): ";
    std::cin >> test;
    infile = test + "-in.txt"; //argv[1]
    outfile = test + "-out.txt"; //argv[2]
    read_data(infile);
    huffman_decoding(outfile);
    return 0;
}
