// W2Opdracht4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>

using namespace std;

bool containsLetter(list<char> list, char var) {
    return (find(list.begin(), list.end(), var) != list.end());
}

void printWord(string word, list<char> list) {
    for (char c : word) {
        if (containsLetter(list, c)) {
            cout << c;
        }
        else {
            cout << "*";
        }
   }
}

bool isCharInWord(string word, char c) {
    return word.find(c) != string::npos;
}


int main()
{
    vector<std::string> words = { "write", "that", "school", "guus", "richard", "widm", "xander", "owen"};

    bool guessed = false;
    int misses = 0;
    list<char> list = {};

    string word = words[rand() % words.size()];
    while (!guessed) {
        cout << "(Guess)Enter a letter in the word ";
        printWord(word, list);

        cout << " >";
        char checkLetter;
        cin >> checkLetter;


        if (!containsLetter(list, checkLetter)) {
            if (!isCharInWord(word, checkLetter)) {
                misses++;
            }
            list.push_back(checkLetter);
        }

        bool correct = true;
        for (char c : word) {
            if (!containsLetter(list, c)) {
                correct = false;
            }
        }

        if (correct) {
            cout << "The word is " << word << ". You missed " << misses << " times";
            guessed = true;
        }

    }
}

