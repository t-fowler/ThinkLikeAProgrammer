#include <cmath>
#include <iostream>
#include <string>

namespace TLAP {

using namespace std;

int charToDigit(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }

    else if (c >= 'A' && c <= 'Z') {
        return c - '0' - 7;
    }

    else if (c >= 'a' && c <= 'z') {
        return c -'0' - 39;
    }
    
    else {
        return -1;
    }
}

char digitToChar(int digit) {
    if (digit > 9) {
        return digit + '0' + 7;
    }

    return digit + '0';
}

int baseNToDecimal(string integerString, int n) {
    int decimal = 0;
    for (auto digit : integerString) {
        decimal = n * decimal + charToDigit(digit);
    }
    return decimal;
}

string decimalToBaseN(int decimal, int n) {
    string integerString = "";
    // divide the largest power of n into decimal
    // grab the remainder to continue the process.
    do {
        int largestPower = pow(n, floor(log(decimal) / log(n)));
        int digit = decimal / largestPower;
        integerString += digitToChar(digit);
        decimal = decimal % largestPower;
    } while (decimal >= n);

    return integerString;
}

string changeBase(string integer, int originalBase, int newBase) {
    int remainder;

    return "TODO";
}


} // namespace TLAP


int main() {
    std::string integerString;
    int base = 0;
    int decimal;

    std::cout << "Input an integer in any base <= 35:\n";
    std::cin >> integerString;
    std::cout << "What is the base?\n";
    std::cin >> base;

    if (base < 1) {
        std::cout << "invalid base\n.";
        return 1;
    }

    std::cout << TLAP::baseNToDecimal(integerString, base) << '\n';

    std::cout << "Input a decimal integer:\n";
    std::cin >> decimal;
    std::cout << "What base would you like to convert to?\n";
    std::cin >> base;

    std::cout << TLAP::decimalToBaseN(decimal, base) << std::endl;

    return 0;
}