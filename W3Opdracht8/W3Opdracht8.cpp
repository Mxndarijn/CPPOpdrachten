#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ifstream input_file("Exercise3_8.txt");

    if (!input_file) {
        cout << "Error: input file not found.\n";
        return 1;
    }

    vector<int> nums;
    string line;

    while (getline(input_file, line)) {
        nums.push_back(stoi(line));
    }

    sort(nums.begin(), nums.end(), greater<int>());

    input_file.close();

    ofstream output_file("Exercise3_8.txt");

    if (!output_file) {
        cout << "Error: output file could not be opened.\n";
        return 1;
    }

    for (int i = 0; i < nums.size(); ++i) {
        output_file << nums[i] << "\n";
    }

    output_file.close();

    return 0;
}
