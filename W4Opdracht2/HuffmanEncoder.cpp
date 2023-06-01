#include "HuffmanEncoder.h"
#include "HuffmanTree.h"
#include <fstream>
#include <iterator>
#include <iostream>

void HuffmanEncoder::encodeFile(const std::string& inputPath, const std::string& outputPath) {
    std::string inputText = readFile(inputPath);

    HuffmanTree tree;
    tree.buildTree(inputText);
    std::string encodedText = tree.encodeText(inputText);

    writeFile(outputPath, encodedText);
}

void HuffmanEncoder::decodeFile(const std::string& inputPath, const std::string& outputPath) {
    std::string encodedText = readFile(inputPath);

    HuffmanTree tree;
    tree.buildTree(encodedText);
    std::string decodedText = tree.decodeText(encodedText);

    writeFile(outputPath, decodedText);
}

std::string HuffmanEncoder::readFile(const std::string& filePath) {
    std::ifstream inputFile(filePath, std::ios::binary);
    if (!inputFile) {
        std::cout << "Error opening input file: " << filePath << std::endl;
        exit(1);
    }

    std::string content;
    inputFile >> std::noskipws;
    std::copy(std::istream_iterator<char>(inputFile), std::istream_iterator<char>(), std::back_inserter(content));

    inputFile.close();
    return content;
}

void HuffmanEncoder::writeFile(const std::string& filePath, const std::string& content) {
    std::ofstream outputFile(filePath, std::ios::binary);
    if (!outputFile) {
        std::cout << "Error opening output file: " << filePath << std::endl;
        exit(1);
    }

    std::copy(content.begin(), content.end(), std::ostream_iterator<char>(outputFile));

    outputFile.close();
}