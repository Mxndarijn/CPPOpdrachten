// W3Opdracht3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
vector<T> intersect(const vector<T>& v1, const vector<T>& v2) {
    vector<T> elements;

    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v2.size(); j++) {
            if (v1[i] == v2[j]) {
                elements.push_back(v1[i]);
            }
        }
    }

    return elements;
}

int main()
{
    const vector<int> list1 = { 10,11,12,13,14 };

    const vector<int> list2 = { 20,11,12,24 };


    vector<int> intersected = intersect<int>(list1, list2);

    for (int i = 0; i < intersected.size(); i++) {
        cout << "Value: " << intersected[i] << endl;
    }
    std::cout << "Hello World!\n";
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
