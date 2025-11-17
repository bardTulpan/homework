//прочитал про srand в с++, решил использовать в задачи
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    
    int numbers[100];
    
    for (int i = 0; i < 100; i++) {
        int randomValue = rand() % 100;
        numbers[i] = (randomValue % 2 == 0) ? 0 : randomValue;
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    int longestSequence = 0;
    int currentSequence = 0;
    
    for (int i = 0; i < 100; i++) {
        if (numbers[i] == 0) {
            currentSequence++;
            if (currentSequence > longestSequence) {
                longestSequence = currentSequence;
            }
        } else {
            currentSequence = 0;
        }
    }
    
    cout << "Longest zero sequence: " << longestSequence << endl;
    
    return 0;
}
