#pragma once
#include <string>

class HuffmanEncoder {
public:
    static void encodeFile(const std::string& inputPath, const std::string& outputPath);
    static void decodeFile(const std::string& inputPath, const std::string& outputPath);
    static std::string readFile(const std::string& filePath);
    static void writeFile(const std::string& filePath, const std::string& content);
};