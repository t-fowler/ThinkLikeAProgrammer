#include <iostream>
#include <string>

namespace TLAP {

using std::cin;
using std::cout;
using std::string;

int baseNToDecimal(string integer, int n) {
    int decimal = 0;
    for (auto digit : integer) {
        decimal = n * decimal + (digit - '0');
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
    std::string binary;
    std::cout << "Input a binary number:\n";
    std::cin >> binary;
    std::cout << TLAP::baseNToDecimal(binary, 2) << '\n';

    return 0;
}