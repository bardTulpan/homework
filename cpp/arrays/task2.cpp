#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
    int size, counter = 0, l = 0, r = 0, t = 0, b = 0;
    cout << "Input matrix dimension: ";
    cin >> size;
    
    int* numbers = new int[size * size];
    int** matrix = new int*[size];
    
    for (int row = 0; row < size; row++) 
        matrix[row] = new int[size];
    
    for (int i = 0; i < size * size; i++) {
        numbers[i] = rand() % 100;
    }

    sort(numbers, numbers + size * size);
    
    while (counter < size * size) {
        for (int col = l; col < size - r && counter < size * size; col++) {
            matrix[t][col] = numbers[counter++];
        }
        t++;
        
        for (int row = t; row < size - b && counter < size * size; row++) {
            matrix[row][size - r - 1] = numbers[counter++];
        }
        r++;
        
        for (int col = size - r - 1; col >= l && counter < size * size; col--) {
            matrix[size - b - 1][col] = numbers[counter++];
        }
        b++;
        
        for (int row = size - b - 1; row >= t && counter < size * size; row--) {
            matrix[row][l] = numbers[counter++];
        }
        l++;
    }
    
    cout << "Spiral arrangement:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << '\t';
        }
        cout << endl;
    }

    for (int i = 0; i < size; i++)
        delete[] matrix[i];
    delete[] matrix;
    delete[] numbers;
    
    return 0;
}
