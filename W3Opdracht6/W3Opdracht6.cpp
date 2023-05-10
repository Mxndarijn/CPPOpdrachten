#include <iostream>
#include <fstream>

using namespace std;

int main() {
    cout << "Enter filename: ";
    string fileName;
    cin >> fileName;

    ifstream input_file(fileName);
    ofstream output_file(fileName, ios_base::app);

    if (!input_file) {
        cout << "Error: file does not exist." << endl;
        return 1;
    }

    int count = 0;
    char c;
    while (input_file.get(c)) {
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
            ++count;
        }
    }

    cout << "Total number of vowels in file: " << count << endl;

    return 0;
}