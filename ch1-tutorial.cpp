#include <iostream>

using std::cin;
using std::cout;

void printHalfSquare() {
    for (int row = 0; row < 5; row++) {
        for (int numHashes = 5; numHashes > row; numHashes--) {
            cout << '#';
        }
        cout << '\n';
    }
}

void printTriangle() {
    for (int row = 1; row < 8; row++) {
        for (int numHashes = 1; numHashes <= 4 - abs(4 - row); numHashes++) {
            cout << '#';
        }
        cout << '\n';
    }
}

// Input must be single digit number.
int doubleAndSumDigits(char digit) {
    int result = (digit - '0') * 2;
    if (result >= 10) {
        result -= 9;
    }
    return result;
}

/*
 * Reads an integer from stdin and validates the Luhn checksum. Checksum is valid
 * when the sum of all digits is a multiple of 10. Every other digit, starting
 * second from the right, is doubled and the digits of the doubled number are summed separately.
 */
void luhnsChecksum() {
    char digit;
    int evenSum = 0, oddSum = 0, position = 1;

    std::cin.get(digit);
    while(digit != '\n') {
        if (position % 2 == 0) {
            oddSum += doubleAndSumDigits(digit);
            evenSum += digit - '0';
        } else {
            oddSum += digit - '0';
            evenSum += doubleAndSumDigits(digit);
        }
        std::cin.get(digit);
        position++;
    }
    
    int checksum;
    if ((position - 1) % 2 == 0) checksum = evenSum;
    else checksum = oddSum;
    if (checksum % 10 == 0) {
        std::cout << "Checksum is divisible by 10. Valid." << '\n';
    } else {
        std::cout << "Checksum is not divisible by 10. Invalid." << '\n';
    }
}

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

// Testing Git
int main() {
    printHalfSquare();
    cout << '\n';
    printTriangle();
    //luhnsChecksum();
    //decodeMessage();
}