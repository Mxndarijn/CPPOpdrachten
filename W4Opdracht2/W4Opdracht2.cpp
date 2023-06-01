#include <iostream>
#include "Nodes.h"
#include <iostream>
#include <queue>
#include <map>
#include <iterator>
#include <algorithm>
#include <fstream>


constexpr const int UniqueSymbols = 1 << CHAR_BIT;
constexpr const char* SampleString = "best wel veel eeeeeees";

using HuffCode = std::vector<bool>;
using HuffCodeMap = std::map<char, HuffCode>;


struct NodeCmp {
	bool operator()(std::shared_ptr<const INode> lhs, std::shared_ptr<const INode> rhs) const {
		return lhs->frequency > rhs->frequency;
	}
};

std::shared_ptr<INode> BuildTree(const int(&frequencies)[UniqueSymbols]) {

	auto cmp = [](std::shared_ptr<const INode> lhs, std::shared_ptr<const INode> rhs) {
		return lhs->frequency > rhs->frequency;
	};

	std::priority_queue<std::shared_ptr<INode>, std::vector<std::shared_ptr<INode>>, NodeCmp> trees;
	//std::priority_queue<std::shared_ptr<INode>, std::vector<std::shared_ptr<INode>>, decltype(cmp)> trees(cmp);

	for (int i = 0; i < UniqueSymbols; ++i) {
		if (frequencies[i] != 0)
			trees.push(std::shared_ptr<INode>(new LeafNode(frequencies[i], (char)i)));
	}


	std::cout << "\n Only leaf nodes:\n";
	std::priority_queue<std::shared_ptr<INode>, std::vector<std::shared_ptr<INode>>, NodeCmp> trees2{ trees };
	while (!trees2.empty()) {
		trees2.top()->printNode();
		trees2.pop();
		std::cout << " ";
	}
	std::cout << '\n';


	std::cout << "\n Connected nodes:\n";
	while (trees.size() > 1) {
		std::shared_ptr<INode> childR = trees.top();
		trees.pop();

		std::shared_ptr<INode> childL = trees.top();
		trees.pop();

		std::shared_ptr<INode> parent = std::shared_ptr<INode>(new InternalNode(childR, childL));
		trees.push(parent);


		std::priority_queue<std::shared_ptr<INode>, std::vector<std::shared_ptr<INode>>, NodeCmp> trees3{ trees };
		while (!trees3.empty()) {
			trees3.top()->printNode();
			trees3.pop();
			std::cout << " ";
		}
		std::cout << '\n';

	}
	return trees.top();
}

void GenerateCodes(const std::shared_ptr<INode> node, const HuffCode& prefix, HuffCodeMap& outCodes) {
	if (auto lf = std::dynamic_pointer_cast<const LeafNode>(node)) {
		outCodes[lf->symbol] = prefix;
	}
	else if (auto in = std::dynamic_pointer_cast<const InternalNode>(node)) {
		HuffCode leftPrefix = prefix;
		leftPrefix.push_back(false);
		GenerateCodes(in->left, leftPrefix, outCodes);

		HuffCode rightPrefix = prefix;
		rightPrefix.push_back(true);
		GenerateCodes(in->right, rightPrefix, outCodes);
	}
}

std::string decodeText(const std::shared_ptr<INode> node, const std::string& encodedText) {
	std::string decodedText;
	std::shared_ptr<INode> current = node;

	for (char bit : encodedText) {
		if (bit == '0') {
			if (auto internalNode = std::dynamic_pointer_cast<const InternalNode>(current)) {
				current = internalNode->left;
			}
		}
		else if (bit == '1') {
			if (auto internalNode = std::dynamic_pointer_cast<const InternalNode>(current)) {
				current = internalNode->right;
			}
		}

		if (auto leafNode = std::dynamic_pointer_cast<const LeafNode>(current)) {
			decodedText += leafNode->symbol;
			current = node;
		}
	}

	return decodedText;
}

double calculateStorageGain(const std::string& originalText, const std::string& encodedText) {
	double originalLength = originalText.length() * CHAR_BIT;
	double encodedLength = encodedText.length();
	double storageGain = (1 - encodedLength / originalLength) * 100;

	return storageGain;
}


void encodeFile(const std::string& inputFile, const std::string& outputFile, const HuffCodeMap& codes) {
	std::ifstream input(inputFile, std::ios::binary);
	std::ofstream output(outputFile, std::ios::binary);

	char ch;
	while (input.get(ch)) {
		const HuffCode& code = codes.at(ch);
		for (bool bit : code) {
			output.put(bit ? '1' : '0');
		}
	}

	input.close();
	output.close();
}

void decodeFile(const std::shared_ptr<INode> root, const std::string& inputFile, const std::string& outputFile) {
	std::ifstream input(inputFile, std::ios::binary);
	std::ofstream output(outputFile, std::ios::binary);

	std::string encodedText((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());
	std::string decodedText = decodeText(root, encodedText);

	output << decodedText;

	input.close();
	output.close();
}

void testHuffmanCoding() {
	// Build frequency table
	int frequencies[UniqueSymbols] = { 0 };
	const char* ptr = SampleString;
	while (*ptr != '\0')
		++frequencies[*ptr++];

	auto root = BuildTree(frequencies);

	HuffCodeMap codes;
	GenerateCodes(root, HuffCode(), codes);

	// Encode and decode a sample text
	std::string originalText = SampleString;
	std::string encodedText;
	for (char ch : originalText) {
		const HuffCode& code = codes[ch];
		for (bool bit : code) {
			encodedText += (bit ? '1' : '0');
		}
	}

	std::cout << "Original text: " << originalText << std::endl;
	std::cout << "Encoded text: " << encodedText << std::endl;

	std::string decodedText = decodeText(root, encodedText);
	std::cout << "Decoded text: " << decodedText << std::endl;

	double storageGain = calculateStorageGain(originalText, encodedText);
	std::cout << "Storage gain: " << storageGain << "%" << std::endl;

	// Test file I/O operations
	std::string inputFile = "C:\\Users\\Merij\\Downloads\\huffman\\input.txt";
	std::string encodedFile = "C:\\Users\\Merij\\Downloads\\huffman\\encoded.txt";
	std::string decodedFile = "C:\\Users\\Merij\\Downloads\\huffman\\decoded.txt";

	// Write the original text to the input file
	std::ofstream input(inputFile);
	input << originalText;
	input.close();

	// Encode the input file and write the encoded text to the encoded file
	encodeFile(inputFile, encodedFile, codes);

	// Decode the encoded file and write the decoded text to the output file
	decodeFile(root, encodedFile, decodedFile);

	// Read the decoded text from the output file
	std::ifstream output(decodedFile);
	std::string fileDecodedText((std::istreambuf_iterator<char>(output)), std::istreambuf_iterator<char>());
	output.close();

	std::cout << "Decoded text from file: " << fileDecodedText << std::endl;
}

int main() {
	// Build frequency table
	int frequencies[UniqueSymbols] = { 0 };
	const char* ptr = SampleString;
	while (*ptr != '\0')
		++frequencies[*ptr++];

	for (int i = 0; i < UniqueSymbols; i++) {
		if (frequencies[i] != 0)
			std::cout << static_cast<char>(i) << " : " << frequencies[i] << std::endl;
	}
	std::cout << std::endl;


	auto root = BuildTree(frequencies);

	HuffCodeMap codes;
	GenerateCodes(root, HuffCode(), codes);

	for (auto& code : codes) {
		std::cout << code.first << " ";
		std::copy(code.second.begin(), code.second.end(),
			std::ostream_iterator<bool>(std::cout));
		std::cout << '\n';
	}

	testHuffmanCoding();

	return 0;
}