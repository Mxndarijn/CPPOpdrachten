#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream input_file("Exercise3_5.txt");
    ofstream output_file("Exercise3_5.txt", ios_base::app);

    if (!input_file) {
        cout << "Error: file does not exist." << endl;
        return 1;
    }

    int count = 0;
    char c;
    while (input_file.get(c)) {
        ++count;
    }

    output_file << "\nTotal number of characters in file: " << count << endl;

    cout << "Total number of characters in file: " << count << endl;

    return 0;
}