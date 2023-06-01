#pragma once
#include <string>
#include <unordered_map>
#include <queue>

// Node structure for Huffman Tree
struct Node {
    char character;
    int frequency;
    Node* left;
    Node* right;

    Node(char ch, int freq) : character(ch), frequency(freq), left(nullptr), right(nullptr) {}
};

// Comparison function for priority queue
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->frequency > b->frequency;
    }
};

class HuffmanTree {
public:
    HuffmanTree();
    void buildTree(const std::string& text);
    std::string encodeText(const std::string& text);
    std::string decodeText(const std::string& encodedText);
    double calculateStorageGain(const std::string& text);

private:
    Node* root;
    std::unordered_map<char, std::string> huffmanCodes;

    void buildCodeTable(Node* node, std::string code);
};
