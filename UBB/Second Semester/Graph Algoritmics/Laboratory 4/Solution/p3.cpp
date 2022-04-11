#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#define MAX_CHAR 255

class Node {
public:
    char caracter;
    int freq;
    Node* left, * right;
    char ascii;
    Node(char caracter, int freq) {
        this->left = this->right = nullptr;
        this->caracter = caracter;
        this->freq = freq;
        this->ascii= caracter;
    }
};

class Comparator {
public:
    bool operator()(const Node* a, const Node* b) {
        if (a->freq == b->freq)
            return int(a->ascii) > int(b->ascii);
        return a->freq > b->freq;
    }
};

std::string str;
int freq[MAX_CHAR];
std::priority_queue< Node*, std::vector<Node*>, Comparator> p_queue;
std::vector<std::pair<char, std::string>> v;


void read_data(const std::string& infile) {
    std::ifstream in(infile);
    std::string read;
    while (!in.eof()) {
        std::getline(in, read);
        str += read;
    }
    in.close();
}

void find_freq() {
    for (const auto& elem : str) {
        freq[int(elem)] ++;
    }
}

void generate_code(const std::string& outfile, Node* root, std::string s) {
    if (!root) {
        return;
    }
    if (root->caracter != '$') {
        v.push_back(std::make_pair(root->caracter, s));
    }
    generate_code(outfile, root->left, s + '0');
    generate_code(outfile, root->right, s + '1');
}

std::string find(char caracter) {
    for (const auto& i : v)
        if (i.first == caracter)
            return i.second;
    return "";
}

void huffman_encoding(const std::string& outfile) {
    find_freq();
    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            p_queue.push(new Node(char(i), freq[i]));
        }
    }
    std::ofstream out(outfile);
    out << p_queue.size() << std::endl;
    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            out << char(i) << " " << freq[i] << std::endl;
        }
    }
    out.close();
    while (p_queue.size() != 1) {
        auto left = p_queue.top();
        p_queue.pop();

        auto right = p_queue.top();
        p_queue.pop();

        auto nod = new Node('$', left->freq + right->freq);
        nod->left = left;
        nod->right = right;
        nod->ascii =std::min(left->ascii, right->ascii);
        p_queue.push(nod);
    }
    generate_code(outfile, p_queue.top(), "");
    std::ofstream out2;
    out2.open(outfile, std::ios_base::app);
    for (auto i = 0; i < str.size(); i++) {
        std::string code = find(str[i]);
        out2 << code;
    }
    out2 << std::endl;
    out2.close();
}

int main() {
    std::string test, infile, outfile;
    std::cout << "Enter test number(1-5): ";
    std::cin >> test;
    infile = test + "-in.txt"; //argv[1]
    outfile = test + "-out.txt"; //argv[2]
    read_data(infile);
    huffman_encoding(outfile);
    return 0;
}