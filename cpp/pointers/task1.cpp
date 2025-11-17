#include <iostream>
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    const int MAX_SIZE = 80;
    char inputString[MAX_SIZE];
    char resultString[MAX_SIZE];

    cout << "Введите строку для обработки:\n";
    cin.getline(inputString, MAX_SIZE, '\n');
    
    int readPos = 0;
    int writePos = 0;
    bool previousWasSpace = false;
    
    while (inputString[readPos] == ' ') {
        readPos++;
    }
    
    while (readPos < MAX_SIZE && inputString[readPos] != '\0') {
        char currentCharacter = inputString[readPos];
        
        if (currentCharacter == ' ') {
            if (!previousWasSpace) {
                resultString[writePos] = currentCharacter;
                writePos++;
                previousWasSpace = true;
            }
        } else {
            resultString[writePos] = currentCharacter;
            writePos++;
            previousWasSpace = false;
        }
        
        readPos++;
    }
    
    if (writePos > 0 && resultString[writePos - 1] == ' ') {
        writePos--;
    }
    
    resultString[writePos] = '\0';
    
    cout << "Результат: " << resultString << "|" << endl;

    return 0;
}
