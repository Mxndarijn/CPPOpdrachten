// W2Opdracht5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    int numRows;
    cout << "Enter the number of rows for the matrix: ";
    cin >> numRows;
    cout << "Enter the matrix row by row:" << endl;

    int matrix[100][100];
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numRows; j++) {
            cin >> matrix[i][j];
       }
    }

    int x = 0;
    int y = 0;
    int maxSize = 0;

    for (int matrixSize = 1; matrixSize < numRows; matrixSize++) {
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numRows; j++) {
                bool correct = true;

                for (int matrixLocationX = 0; matrixLocationX < matrixSize; matrixLocationX++) {
                    for (int matrixLocationY = 0; matrixLocationY < matrixSize; matrixLocationY++) {
                        if(matrix[i + matrixLocationX][j + matrixLocationY] != 1) {
                            correct = false;
                        }
                    }
                }
                if (correct) {
                    x = j;
                    y = i;
                    maxSize = matrixSize;
                }
            }
        }
    }

    cout << "The maximum square submatrix is at (" << x << ", " << y << ") with size " << maxSize;
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
