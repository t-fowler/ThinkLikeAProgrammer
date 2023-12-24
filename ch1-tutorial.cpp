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

// Testing Git
int main() {
    printHalfSquare();
    cout << '\n';
    printTriangle();
}