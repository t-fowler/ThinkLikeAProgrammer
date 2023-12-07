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

// Testing Git
int main() {
    /*
    printHalfSquare();
    cout << '\n';
    printTriangle();
    */
    luhnsChecksum();
}