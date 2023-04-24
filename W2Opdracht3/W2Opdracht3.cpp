// W2Opdracht3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

bool isPalindrome(const string& s);

int main()
{
    string value;
    cout << "Enter a string: ";
    cin >> value;

    if (isPalindrome(value)) {
        cout << value << " is a palindrome" << endl;
    }
    else {
        cout << value << " is not a palindrome" << endl;
    }

}

bool isPalindrome(const string& s) {
    for (int i = 0; i < s.size() / 2; i++) {
        if (tolower(s[i]) == tolower(s[s.size() - 1 - i])) {
            continue;
        }
        else {
            return false;
        }
    }
    return true;

}

