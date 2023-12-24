#include <iostream>

using std::cout;
using std::cin;

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
bool luhnsChecksum() {
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
    
    return (checksum % 10 == 0);
}

int main() {
    if (luhnsChecksum()) {
        std::cout << "Checksum is divisible by 10. Valid." << '\n';
    } else {
        std::cout << "Checksum is not divisible by 10. Invalid." << '\n';
    }
}