// Opdracht2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    string s;
    cout << "Enter a genome string: ";
    cin >> s;


    int i = 0;
    while (i < s.length()) {
        //Find start index or stop
        int startIndex = s.find("ATG", i);
        if (startIndex == string::npos) {
            break;
        }
        // add 3 (AGT is 3 chars)
        startIndex += 3;

        //Find stop index or stop
        string list[] = {
            "TAG",
            "TTA",
            "TGA"
        };
        int endIndex = s.find(list[0], startIndex);
        for (string end : list) {
            int en = s.find(end, startIndex);
            if (en < endIndex && en != string::npos) {
                endIndex = en;
            }
        }
        // Add one
        endIndex += 1;
        if (endIndex == string::npos) {
            cout << "Could not find end index";
            break;
        }

        //get gene
        int length = endIndex - (startIndex);
        string gene = s.substr(startIndex, length);

        //check length
        if (length % 3 != 0) {
            cout << "Not a multiple of 3: " << gene << endl;
        }
        else {
            cout << "Start: " << startIndex << " End: " << endIndex << endl;
            cout << gene << endl;
        }

        //add value to i
        i = endIndex + 3;



    }
    
}
