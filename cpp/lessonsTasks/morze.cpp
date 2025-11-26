#include <iostream>
#include <cstring> 
#include <limits> 

char decodeMorseChar(const char* code, int len) {
    if (len == 1) {
        if (code[0] == '.') return 'E';
        if (code[0] == '-') return 'T';
    } else if (len == 2) {
        if (code[0] == '.' && code[1] == '.') return 'I';
        if (code[0] == '.' && code[1] == '-') return 'A';
        if (code[0] == '-' && code[1] == '.') return 'N';
        if (code[0] == '-' && code[1] == '-') return 'M';
    } else if (len == 3) {
        if (code[0] == '.' && code[1] == '.' && code[2] == '.') return 'S';
        if (code[0] == '.' && code[1] == '.' && code[2] == '-') return 'U';
        if (code[0] == '.' && code[1] == '-' && code[2] == '.') return 'R';
        if (code[0] == '-' && code[1] == '.' && code[2] == '.') return 'D';
        if (code[0] == '-' && code[1] == '-' && code[2] == '.') return 'G';
        if (code[0] == '-' && code[1] == '-' && code[2] == '-') return 'O';
        if (code[0] == '.' && code[1] == '-' && code[2] == '-') return 'W';
        if (code[0] == '-' && code[1] == '.' && code[2] == '-') return 'K';
    } else if (len == 4) {
        if (code[0] == '.' && code[1] == '.' && code[2] == '.' && code[3] == '.') return 'H';
        if (code[0] == '.' && code[1] == '.' && code[2] == '-' && code[3] == '.') return 'F';
        if (code[0] == '.' && code[1] == '.' && code[2] == '.' && code[3] == '-') return 'V';
        if (code[0] == '.' && code[1] == '-' && code[2] == '.' && code[3] == '.') return 'L';
        if (code[0] == '.' && code[1] == '-' && code[2] == '-' && code[3] == '.') return 'P';
        if (code[0] == '.' && code[1] == '-' && code[2] == '-' && code[3] == '-') return 'J';
        if (code[0] == '-' && code[1] == '.' && code[2] == '.' && code[3] == '.') return 'B';
        if (code[0] == '-' && code[1] == '.' && code[2] == '-' && code[3] == '.') return 'C';
        if (code[0] == '-' && code[1] == '.' && code[2] == '.' && code[3] == '-') return 'X';
        if (code[0] == '-' && code[1] == '.' && code[2] == '-' && code[3] == '-') return 'Y';
        if (code[0] == '-' && code[1] == '-' && code[2] == '.' && code[3] == '.') return 'Z';
        if (code[0] == '-' && code[1] == '-' && code[2] == '.' && code[3] == '-') return 'Q';
    }
    return '\0'; 
}


void textToMorse(const char* text, char* result) {
    int pos = 0;
    
    for (int i = 0; text[i] != '\0'; i++) {
        if (i > 0 && text[i] != ' ' && text[i-1] != ' ') {
            if (pos > 0 && result[pos-1] != ' ') {
                 result[pos++] = ' ';
            }
        }
        
        switch(text[i]) {
            case 'A': result[pos++] = '.'; result[pos++] = '-'; break;
            case 'B': result[pos++] = '-'; result[pos++] = '.'; result[pos++] = '.'; result[pos++] = '.'; break;
            case 'C': result[pos++] = '-'; result[pos++] = '.'; result[pos++] = '-'; result[pos++] = '.'; break;
            case 'D': result[pos++] = '-'; result[pos++] = '.'; result[pos++] = '.'; break;
            case 'E': result[pos++] = '.'; break;
            case 'F': result[pos++] = '.'; result[pos++] = '.'; result[pos++] = '-'; result[pos++] = '.'; break;
            case 'G': result[pos++] = '-'; result[pos++] = '-'; result[pos++] = '.'; break;
            case 'H': result[pos++] = '.'; result[pos++] = '.'; result[pos++] = '.'; result[pos++] = '.'; break;
            case 'I': result[pos++] = '.'; result[pos++] = '.'; break;
            case 'J': result[pos++] = '.'; result[pos++] = '-'; result[pos++] = '-'; result[pos++] = '-'; break;
            case 'K': result[pos++] = '-'; result[pos++] = '.'; result[pos++] = '-'; break;
            case 'L': result[pos++] = '.'; result[pos++] = '-'; result[pos++] = '.'; result[pos++] = '.'; break;
            case 'M': result[pos++] = '-'; result[pos++] = '-'; break;
            case 'N': result[pos++] = '-'; result[pos++] = '.'; break;
            case 'O': result[pos++] = '-'; result[pos++] = '-'; result[pos++] = '-'; break;
            case 'P': result[pos++] = '.'; result[pos++] = '-'; result[pos++] = '-'; result[pos++] = '.'; break;
            case 'Q': result[pos++] = '-'; result[pos++] = '-'; result[pos++] = '.'; result[pos++] = '-'; break;
            case 'R': result[pos++] = '.'; result[pos++] = '-'; result[pos++] = '.'; break;
            case 'S': result[pos++] = '.'; result[pos++] = '.'; result[pos++] = '.'; break;
            case 'T': result[pos++] = '-'; break;
            case 'U': result[pos++] = '.'; result[pos++] = '.'; result[pos++] = '-'; break;
            case 'V': result[pos++] = '.'; result[pos++] = '.'; result[pos++] = '.'; result[pos++] = '-'; break;
            case 'W': result[pos++] = '.'; result[pos++] = '-'; result[pos++] = '-'; break;
            case 'X': result[pos++] = '-'; result[pos++] = '.'; result[pos++] = '.'; result[pos++] = '-'; break;
            case 'Y': result[pos++] = '-'; result[pos++] = '.'; result[pos++] = '-'; result[pos++] = '-'; break;
            case 'Z': result[pos++] = '-'; result[pos++] = '-'; result[pos++] = '.'; result[pos++] = '.'; break;
            
            case ' ':
                if (pos > 0) {
                    if (result[pos-1] == ' ') {
                        pos--;
                    }
                    result[pos++] = ' ';
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
    int morse_pos = 0;
    
    char current_code[5]; 
    int current_code_len = 0;
    
    while (morse[morse_pos] != '\0') {
        
        if (morse[morse_pos] == '.' || morse[morse_pos] == '-') {
            if (current_code_len < 4) {
                current_code[current_code_len++] = morse[morse_pos];
            }
            morse_pos++;
            continue;
        }
        
        if (morse[morse_pos] == ' ') {
            if (current_code_len > 0) {
                current_code[current_code_len] = '\0';
                char decoded_char = decodeMorseChar(current_code, current_code_len);
                if (decoded_char != '\0') {
                    text[text_pos++] = decoded_char;
                }
                current_code_len = 0;
            }
            
            if (morse[morse_pos + 1] == ' ' && morse[morse_pos + 2] == ' ') {
                text[text_pos++] = ' ';
                morse_pos += 3;
            } else {
                morse_pos++;
            }
            
            while (morse[morse_pos] == ' ') {
                morse_pos++;
            }
            continue;
        }
        
        morse_pos++;
    }
    
    if (current_code_len > 0) {
        current_code[current_code_len] = '\0';
        char decoded_char = decodeMorseChar(current_code, current_code_len);
        if (decoded_char != '\0') {
            text[text_pos++] = decoded_char;
        }
    }
    
    text[text_pos] = '\0';
}

int main() {
    const int maximumLengthText = 100;
    const int maximumLengthResult = 500;
    char input[maximumLengthResult];
    char output[maximumLengthResult];
    int choice;
    
    std::cout << "Выберите режим работы:\n";
    std::cout << "1 - Текст в азбуку Морзе\n";
    std::cout << "2 - Азбука Морзе в текст\n";
    std::cout << "Ваш выбор: ";
    if (!(std::cin >> choice)) {
        std::cerr << "Ошибка ввода числа!" << std::endl;
        return 1;
    }
    // Очистка буфера после ввода числа
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if (choice == 1) {
        std::cout << "Введите текст (только заглавные буквы и пробелы): ";
        std::cin.getline(input, maximumLengthText);
        textToMorse(input, output);
        std::cout << "Азбука Морзе: " << output << std::endl;
    }
    else if (choice == 2) {
        std::cout << "Введите код Морзе (разделяйте символы ОДНИМ пробелом, слова - ТРЕМЯ): ";
        std::cin.getline(input, maximumLengthResult);
        morseToText(input, output);
        std::cout << "Текст: " << output << std::endl;
    }
    else {
        std::cout << "Неверный выбор!" << std::endl;
    }
    
    return 0;
}
