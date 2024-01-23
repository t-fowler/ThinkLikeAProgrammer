#include <iostream>
#include <string>

namespace TLAP {

using std::cin;
using std::cout;
using std::string;

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

int baseNToDecimal(string integer, int n) {
    int decimal = 0;
    for (auto digit : integer) {
        decimal = n * decimal + charToDigit(digit);
    }
    return decimal;
}

string changeBase(string integer, int originalBase, int newBase) {
    int remainder;

    return "TODO";
}


} // namespace TLAP

/*
 * 
 */
int main() {
    std::string integerString;
    int base = 0;

    std::cout << "Input a binary number:\n";
    std::cin >> integerString;
    std::cout << "What is the base?\n";
    std::cin >> base;

    if (base < 1) {
        std::cout << "invalid base\n.";
        return 1;
    }

    std::cout << TLAP::baseNToDecimal(integerString, base) << '\n';

    return 0;
}