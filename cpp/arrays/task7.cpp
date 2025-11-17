#include <iostream>
#include <climits>
#include <cstdlib>

using namespace std;

int main() {
    int rows, cols;
    cout << "Input matrix dimensions: ";
    cin >> rows >> cols;
    
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
    
    int* rowMinimums = new int[rows];
    int* columnMaximums = new int[cols];
    
    for (int i = 0; i < rows; i++) {
        int currentMin = INT_MAX;
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] < currentMin) {
                currentMin = matrix[i][j];
            }
        }
        rowMinimums[i] = currentMin;
    }
    
    for (int j = 0; j < cols; j++) {
        int currentMax = INT_MIN;
        for (int i = 0; i < rows; i++) {
            if (matrix[i][j] > currentMax) {
                currentMax = matrix[i][j];
            }
        }
        columnMaximums[j] = currentMax;
    }
    
    cout << "Matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    
    bool foundSaddle = false;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == rowMinimums[i] && matrix[i][j] == columnMaximums[j]) {
                foundSaddle = true;
                cout << "Found saddle point at row " << i + 1 << ", column " << j + 1 << endl;
            }
        }
    }
    
    if (!foundSaddle) {
        cout << "No saddle points found" << endl;
    }
    
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] rowMinimums;
    delete[] columnMaximums;
    
    return 0;
}
