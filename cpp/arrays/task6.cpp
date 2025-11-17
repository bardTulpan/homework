#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int dataArray[100];
    
    for (int index = 0; index < 100; index++) {
        dataArray[index] = rand() % 5;
    }

    cout << "Initial sequence: ";
    for (int index = 0; index < 100; index++) {
        cout << dataArray[index] << ' ';
    }
    cout << endl;

    int position = 0, zeroStart = 0;
    bool active = true;

    while (active && position < 100) {
        if (dataArray[position] != 0) {
            position++;
            continue;
        }
        
        zeroStart = position;
        
        while (position < 100 && dataArray[position] == 0) {
            position++;
            if (position >= 100) {
                active = false;
                break;
            }
        }
        
        if (active && position < 100) {
            dataArray[zeroStart] = dataArray[position];
            dataArray[position] = 0;
            position = zeroStart;
        }
        
        position++;
    }

    cout << "Modified sequence: ";
    for (int index = 0; index < 100; index++) {
        cout << dataArray[index] << ' ';
    }
    cout << endl;

    return 0;
}
