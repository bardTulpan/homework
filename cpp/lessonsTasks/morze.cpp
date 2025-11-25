#include <iostream>

void textToMorse(const char* text, char* result) {
    int pos = 0;
    
    for (int i = 0; text[i] != '\0'; i++) {
        if (i > 0 && pos > 0 && text[i] != ' ' && text[i-1] != ' ') {
            result[pos] = ' ';
            pos++;
        }
        
        switch(text[i]) {
            case 'A': 
                result[pos++] = '.'; 
                result[pos++] = '-';
                break;
            case 'B':
                result[pos++] = '-';
                result[pos++] = '.';
                result[pos++] = '.';
                result[pos++] = '.';
                break;
            case 'C':
                result[pos++] = '-';
                result[pos++] = '.';
                result[pos++] = '-';
                result[pos++] = '.';
                break;
            case 'D':
                result[pos++] = '-';
                result[pos++] = '.';
                result[pos++] = '.';
                break;
            case 'E':
                result[pos++] = '.';
                break;
            case 'F':
                result[pos++] = '.';
                result[pos++] = '.';
                result[pos++] = '-';
                result[pos++] = '.';
                break;
            case 'G':
                result[pos++] = '-';
                result[pos++] = '-';
                result[pos++] = '.';
                break;
            case 'H':
                result[pos++] = '.';
                result[pos++] = '.';
                result[pos++] = '.';
                result[pos++] = '.';
                break;
            case 'I':
                result[pos++] = '.';
                result[pos++] = '.';
                break;
            case 'J':
                result[pos++] = '.';
                result[pos++] = '-';
                result[pos++] = '-';
                result[pos++] = '-';
                break;
            case 'K':
                result[pos++] = '-';
                result[pos++] = '.';
                result[pos++] = '-';
                break;
            case 'L':
                result[pos++] = '.';
                result[pos++] = '-';
                result[pos++] = '.';
                result[pos++] = '.';
                break;
            case 'M':
                result[pos++] = '-';
                result[pos++] = '-';
                break;
            case 'N':
                result[pos++] = '-';
                result[pos++] = '.';
                break;
            case 'O':
                result[pos++] = '-';
                result[pos++] = '-';
                result[pos++] = '-';
                break;
            case 'P':
                result[pos++] = '.';
                result[pos++] = '-';
                result[pos++] = '-';
                result[pos++] = '.';
                break;
            case 'Q':
                result[pos++] = '-';
                result[pos++] = '-';
                result[pos++] = '.';
                result[pos++] = '-';
                break;
            case 'R':
                result[pos++] = '.';
                result[pos++] = '-';
                result[pos++] = '.';
                break;
            case 'S':
                result[pos++] = '.';
                result[pos++] = '.';
                result[pos++] = '.';
                break;
            case 'T':
                result[pos++] = '-';
                break;
            case 'U':
                result[pos++] = '.';
                result[pos++] = '.';
                result[pos++] = '-';
                break;
            case 'V':
                result[pos++] = '.';
                result[pos++] = '.';
                result[pos++] = '.';
                result[pos++] = '-';
                break;
            case 'W':
                result[pos++] = '.';
                result[pos++] = '-';
                result[pos++] = '-';
                break;
            case 'X':
                result[pos++] = '-';
                result[pos++] = '.';
                result[pos++] = '.';
                result[pos++] = '-';
                break;
            case 'Y':
                result[pos++] = '-';
                result[pos++] = '.';
                result[pos++] = '-';
                result[pos++] = '-';
                break;
            case 'Z':
                result[pos++] = '-';
                result[pos++] = '-';
                result[pos++] = '.';
                result[pos++] = '.';
                break;
            case ' ':
                if (pos > 0) {
                    result[pos++] = ' ';
                    result[pos++] = ' ';
                }
                break;
            default:
                break;
        }
    }
    
    result[pos] = '\0';
}

void morseToText(const char* morse, char* text) {
    int text_pos = 0;
    int i = 0;
    
    while (morse[i] != '\0') {
        if (morse[i] == ' ') {
            i++;
            continue;
        }
        
        if (morse[i] == '.' && morse[i+1] == '-') {
            text[text_pos++] = 'A';
            i += 2;
        }
        else if (morse[i] == '-' && morse[i+1] == '.' && morse[i+2] == '.' && morse[i+3] == '.') {
            text[text_pos++] = 'B';
            i += 4;
        }
        else if (morse[i] == '-' && morse[i+1] == '.' && morse[i+2] == '-' && morse[i+3] == '.') {
            text[text_pos++] = 'C';
            i += 4;
        }
        else if (morse[i] == '-' && morse[i+1] == '.' && morse[i+2] == '.') {
            text[text_pos++] = 'D';
            i += 3;
        }
        else if (morse[i] == '.') {
            text[text_pos++] = 'E';
            i += 1;
        }
        else if (morse[i] == '.' && morse[i+1] == '.' && morse[i+2] == '-' && morse[i+3] == '.') {
            text[text_pos++] = 'F';
            i += 4;
        }
        else if (morse[i] == '-' && morse[i+1] == '-' && morse[i+2] == '.') {
            text[text_pos++] = 'G';
            i += 3;
        }
        else if (morse[i] == '.' && morse[i+1] == '.' && morse[i+2] == '.' && morse[i+3] == '.') {
            text[text_pos++] = 'H';
            i += 4;
        }
        else if (morse[i] == '.' && morse[i+1] == '.') {
            text[text_pos++] = 'I';
            i += 2;
        }
        else if (morse[i] == '.' && morse[i+1] == '-' && morse[i+2] == '-' && morse[i+3] == '-') {
            text[text_pos++] = 'J';
            i += 4;
        }
        else if (morse[i] == '-' && morse[i+1] == '.' && morse[i+2] == '-') {
            text[text_pos++] = 'K';
            i += 3;
        }
        else if (morse[i] == '.' && morse[i+1] == '-' && morse[i+2] == '.' && morse[i+3] == '.') {
            text[text_pos++] = 'L';
            i += 4;
        }
        else if (morse[i] == '-' && morse[i+1] == '-') {
            text[text_pos++] = 'M';
            i += 2;
        }
        else if (morse[i] == '-' && morse[i+1] == '.') {
            text[text_pos++] = 'N';
            i += 2;
        }
        else if (morse[i] == '-' && morse[i+1] == '-' && morse[i+2] == '-') {
            text[text_pos++] = 'O';
            i += 3;
        }
        else if (morse[i] == '.' && morse[i+1] == '-' && morse[i+2] == '-' && morse[i+3] == '.') {
            text[text_pos++] = 'P';
            i += 4;
        }
        else if (morse[i] == '-' && morse[i+1] == '-' && morse[i+2] == '.' && morse[i+3] == '-') {
            text[text_pos++] = 'Q';
            i += 4;
        }
        else if (morse[i] == '.' && morse[i+1] == '-' && morse[i+2] == '.') {
            text[text_pos++] = 'R';
            i += 3;
        }
        else if (morse[i] == '.' && morse[i+1] == '.' && morse[i+2] == '.') {
            text[text_pos++] = 'S';
            i += 3;
        }
        else if (morse[i] == '-') {
            text[text_pos++] = 'T';
            i += 1;
        }
        else if (morse[i] == '.' && morse[i+1] == '.' && morse[i+2] == '-') {
            text[text_pos++] = 'U';
            i += 3;
        }
        else if (morse[i] == '.' && morse[i+1] == '.' && morse[i+2] == '.' && morse[i+3] == '-') {
            text[text_pos++] = 'V';
            i += 4;
        }
        else if (morse[i] == '.' && morse[i+1] == '-' && morse[i+2] == '-') {
            text[text_pos++] = 'W';
            i += 3;
        }
        else if (morse[i] == '-' && morse[i+1] == '.' && morse[i+2] == '.' && morse[i+3] == '-') {
            text[text_pos++] = 'X';
            i += 4;
        }
        else if (morse[i] == '-' && morse[i+1] == '.' && morse[i+2] == '-' && morse[i+3] == '-') {
            text[text_pos++] = 'Y';
            i += 4;
        }
        else if (morse[i] == '-' && morse[i+1] == '-' && morse[i+2] == '.' && morse[i+3] == '.') {
            text[text_pos++] = 'Z';
            i += 4;
        }
        else {
            i++;
        }
        
        if (morse[i] == ' ') {
            i++;
        }
    }
    
    text[text_pos] = '\0';
}

int main() {
    const int maximumLengthText = 100;
    const int maximumLengthResult = 500;
    char input[maximumLengthText];
    char output[maximumLengthResult];
    int choice;
    
    std::cout << "Выберите режим работы:\n";
    std::cout << "1 - Текст в азбуку Морзе\n";
    std::cout << "2 - Азбука Морзе в текст\n";
    std::cout << "Ваш выбор: ";
    std::cin >> choice;
    std::cin.ignore(); // Очищаем буфер после ввода числа
    
    if (choice == 1) {
        std::cout << "Введите текст (только заглавные буквы): ";
        std::cin.getline(input, maximumLengthText);
        textToMorse(input, output);
        std::cout << "Азбука Морзе: " << output << std::endl;
    }
    else if (choice == 2) {
        std::cout << "Введите код Морзе: ";
        std::cin.getline(input, maximumLengthText);
        morseToText(input, output);
        std::cout << "Текст: " << output << std::endl;
    }
    else {
        std::cout << "Неверный выбор!" << std::endl;
    }
    
    return 0;
}