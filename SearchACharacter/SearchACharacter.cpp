#include <iostream>
#include <string>

using namespace std;
bool search(string& s, char& key);


int main() {
    string s;
    char key;

    cout << "Enter a string: ";
    getline(cin, s);

    cout << "Enter a character to search for: ";
    cin >> key;

    if (search(s, key)) {
        cout << "The character " << key << " was found in the string." << endl;
    }
    else {
        cout << "The character " << key << " was not found in the string." << endl;
    }

    return 0;
}

bool search(string& s, char& key) {
    for (char c : s) {
        if (c == key) {
            return true;
        }
    }
    return false;
}