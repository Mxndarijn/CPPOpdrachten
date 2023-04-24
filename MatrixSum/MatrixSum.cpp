#include <iostream>

using namespace std;

const int SIZE = 4;
const int ROWS = 3;
double sumColumn(const double m[][SIZE], int rowSize, int columnIndex);

int main() {
    double matrix[ROWS][SIZE];


    cout << "Enter a" << ROWS << "-by-" << SIZE << " matrix row by row:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < SIZE; i++) {
        double value = sumColumn(matrix, ROWS, i);
        cout << "Sum of the elements at column " << i << " is " << value << endl;
    }

    return 0;
}

double sumColumn(const double m[][SIZE], int rowSize, int columnIndex) {
    double sum = 0;
    for (int i = 0; i < rowSize; i++) {
        sum += m[i][columnIndex];
    }

    return sum;
}
