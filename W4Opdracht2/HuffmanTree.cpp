#include "HuffmanTree.h"

HuffmanTree::HuffmanTree() : root(nullptr) {}

void HuffmanTree::buildTree(const std::string& text) {
    // Calculate character frequencies
    std::unordered_map<char, int> freqMap;
    for (char ch : text) {
        freqMap[ch]++;
    }

    // Create nodes for each character and add them to a priority queue
    std::priority_queue<Node*, std::vector<Node*>, Compare> pq;
    for (auto& entry : freqMap) {
        Node* node = new Node(entry.first, entry.second);
        pq.push(node);
    }

    // Build Huffman Tree
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        int sumFreq = left->frequency + right->frequency;
        Node* parent = new Node('\0', sumFreq);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    root = pq.top();
    pq.pop();

    // Build the Huffman code table
    buildCodeTable(root, "");
}

void HuffmanTree::buildCodeTable(Node* node, std::string code) {
    if (node == nullptr) {
        return;
    }

    if (node->character != '\0') {
        huffmanCodes[node->character] = code;
    }

    buildCodeTable(node->left, code + "0");
    buildCodeTable(node->right, code + "1");
}

std::string HuffmanTree::encodeText(const std::string& text) {
    std::string encodedText;
    for (char ch : text) {
        encodedText += huffmanCodes[ch];
    }
    return encodedText;
}

std::string HuffmanTree::decodeText(const std::string& encodedText) {
    std::string decodedText;
    Node* current = root;
    for (char bit : encodedText) {
        if (bit == '0') {
            current = current->left;
        }
        else {
            current = current->right;
        }

        if (current->character != '\0') {
            decodedText += current->character;
            current = root;
        }
    }
    return decodedText;
}

double HuffmanTree::calculateStorageGain(const std::string& text) {
    double originalSize = 0;
    double encodedSize = 0;

    for (char ch : text) {
        originalSize += 8; // Assuming each character occupies 8 bits

        auto it = huffmanCodes.find(ch);
        if (it != huffmanCodes.end()) {
            encodedSize += (it->second.length() * it->second.length());
        }
    }

    return (originalSize - encodedSize) / originalSize;
}