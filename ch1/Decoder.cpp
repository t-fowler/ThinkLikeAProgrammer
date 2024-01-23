#include <iostream>

using std::cin;
using std::cout;

char decodeUppercase(int number) {
    return number + 'A' - 1;
}

char decodeLowercase(int number) {
    return number + 'a' - 1;
}

char decodePunctuation(int number) {
    switch (number) {
        case 1: return '!'; break;
        case 2: return '?'; break;
        case 3: return ','; break;
        case 4: return '.'; break;
        case 5: return ' '; break;
        case 6: return ';'; break;
        case 7: return '"'; break;
        case 8: return '\''; break;
        default: return 0; break;
    }
}

//
void decodeMessage() {
    char digitChar;
    enum decodingMode {
        UPPERCASE,
        LOWERCASE,
        PUNCTUATION
    } mode = UPPERCASE;
    // read a line one char at a time.
    // convert input into an integer
    do {
        digitChar = cin.get();
        int number = 0;
        while (digitChar != ',' && digitChar != 10) {
            number = (number * 10) + (digitChar - '0');
            digitChar = cin.get();
        }
        switch (mode) {
            case UPPERCASE:
                number = number % 27;
                if (number == 0) {
                    mode = LOWERCASE;
                    continue;
                }
                cout << decodeUppercase(number);
                break;
            case LOWERCASE:
                number = number % 27;
                if (number == 0) {
                    mode = PUNCTUATION;
                    continue;
                }
                cout << decodeLowercase(number);
                break;
            case PUNCTUATION:
                number = number % 9;
                if (number == 0) {
                    mode = UPPERCASE;
                    continue;
                }
                cout << decodePunctuation(number);
                break;
        }
    } while (digitChar != 10);
    cout << '\n';
}

int main() {
    decodeMessage();
}