#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

bool isPrime(long long n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream file("e2mil.txt");
    string all_text;
    getline(file, all_text, '\0');
    file.close();
    
    string digits;
    for (char c : all_text) {
        if (c >= '0' && c <= '9') {
            digits += c;
        }
    }
    
    if (!digits.empty() && digits[0] == '2') {
        digits = digits.substr(1);
    }
    
    for (int i = 0; i + 10 <= digits.size(); i++) {
        string window = digits.substr(i, 10);
        
        if (window[0] == '0') {
            continue;
        }
        
        long long num = stoll(window);
        
        if (isPrime(num)) {
            cout << "Число: " << window << "\n";
            cout << "Позиция: " << i << " (отсчет с 0)\n";
            return 0;  
        }
        
    }
        return 0;
}
