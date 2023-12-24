#include <iostream>

using std::cin;
using std::cout;

int binaryToDecimal(string binary) {
    int decimal = 0;
    for (int i = 0; i < binary.length() ; i++) {
        decimal = 2 * decimal + (binary[i] - '0');
    }
    return decimal;
}

int main() {
    string binary;
    cout << "Input a binary number:\n";
    cin >> binary;
    cout << binaryToDecimal(binary) << '\n';
}