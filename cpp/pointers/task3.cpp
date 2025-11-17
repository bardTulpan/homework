#include <iostream>
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    const int BUFFER_SIZE = 80;
    char userInput[BUFFER_SIZE];
    int digitCounters[10] = {0};

    cout << "Введите текст для анализа:\n";
    cin.getline(userInput, BUFFER_SIZE, '\n');
    
    for (int position = 0; position < BUFFER_SIZE && userInput[position] != '\0'; position++) {
        char symbol = userInput[position];
        if (symbol >= '0' && symbol <= '9') {
            int digitValue = symbol - '0';
            digitCounters[digitValue]++;
        }
    }

    int mostFrequentDigit = -1;
    int maxFrequency = 0;
    
    for (int digit = 0; digit < 10; digit++) {
        if (digitCounters[digit] > maxFrequency) {
            mostFrequentDigit = digit;
            maxFrequency = digitCounters[digit];
        }
    }

    if (mostFrequentDigit == -1) {
        cout << "В тексте отсутствуют цифры" << endl;
        return 1;
    }
    
    cout << "Наиболее часто встречающаяся цифра: " << mostFrequentDigit << endl;
    cout << "Количество вхождений: " << maxFrequency << endl;

    return 0;
}
