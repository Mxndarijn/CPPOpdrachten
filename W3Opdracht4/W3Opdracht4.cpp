// W3Opdracht4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

template<typename T>
void intersect(vector<T>& v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

int main()
{
    vector<int> list1;

    cout << "Enter ten integers: ";
    while (list1.size() < 10) {
        int input;
        cin >> input;
        list1.push_back(input);
    }

    intersect<int>(list1);

    cout << "The distinct integers are ";
    for (int i = 0; i < list1.size(); i++) {
        cout << list1[i] << " ";
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
