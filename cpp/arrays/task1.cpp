#include <iostream>
using namespace std;

int main() {
    int binaryDigits[] = {1, 1, 1, 0, 1, 1, 1, 1};
    int arraySize = sizeof(binaryDigits) / sizeof(binaryDigits[0]);
    int lastPosition = arraySize - 1;
    
    if (binaryDigits[lastPosition] == 0) {
        binaryDigits[lastPosition] = 1;
        for (int index = 0; index < arraySize; index++) {
            cout << binaryDigits[index];
        }
        cout << endl;
        return 0;
    }
    
    int currentPosition = lastPosition;
    while (currentPosition >= 0) {
        if (binaryDigits[currentPosition] == 1) {
            binaryDigits[currentPosition] = 0;
            currentPosition--;
        } else {
            binaryDigits[currentPosition] = 1;
            for (int index = 0; index < arraySize; index++) {
                cout << binaryDigits[index];
            }
            cout << endl;
            return 0;
        }
    }
    
    return 0;
}
