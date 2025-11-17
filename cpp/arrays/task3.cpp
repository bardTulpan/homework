//нашёл set в c++
#include <iostream>
#include <set>

using namespace std;

bool hasUniqueDigits(int number) {
    set<int> digits;
    while (number > 0) {
        int digit = number % 10;
        if (digits.count(digit)) return false;
        digits.insert(digit);
        number /= 10;
    }
    return true;
}

int main() {
    for (int value = 1000; value <= 9999; value++) {
        if (hasUniqueDigits(value)) {
            cout << value << endl;
        }
    }
    return 0;
}
