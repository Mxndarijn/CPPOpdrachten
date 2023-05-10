#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream input_file("Exercise3_7.txt");

    if (!input_file) {
        cout << "Error: input file not found.\n";
        return 1;
    }

    int num;
    int sum = 0;
    int product = 1;
    int count = 0;

    string line;
    while (getline(input_file, line)) {
        num = stoi(line);
        sum += num;
        product *= num;
        ++count;
    }

    if (count != 6) {
        cout << "Error: input file should contain exactly six integers.\n";
        return 1;
    }

    double average = static_cast<double>(sum) / count;

    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Product: " << product << endl;

    return 0;
}
