#include <iostream>
#include <cstring>

using namespace std;
void count(const char s[], int counts[]);

int main() {
    int counts[26];
    char s[100];

    cout << "Enter a string: ";
    cin.getline(s, 100);

    count(s, counts);

    for (int i = 0; i < 26; i++) {
        if (counts[i] > 0) {
            char charIndex = 'a' + i;
            cout << charIndex << ": " << counts[i] << " times\n";
        }
    }
    return 0;
}

void count(const char s[], int counts[]) {
    for (int i = 0; i < 26; i++) {
        counts[i] = 0;
    }

    for (int i = 0; i < strlen(s); i++) {
        char c = tolower(s[i]);
        if (c >= 'a' && c <= 'z') {
            int charIndex = c - 'a';
            counts[charIndex]++;
        }
    }
}
