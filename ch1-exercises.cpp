#include <iostream>

using std::cin;
using std::cout;

// 2-1.
void printUpsidedownTriangle() {
    for (int row = 1; row <= 4; row++) {
        for (int space = 1; space < row; space++) {
            cout << ' ';
        }
        for (int hashNum = 1; hashNum <= 8 - 2 * (row - 1); hashNum++) {
            cout << '#';
        }
        cout << '\n';
    }
}

// 2-2
/*
1   3   3
2   2   2
3   1   1
4   0   0
5   0   1
6   1   2
7   2   3
8   3   4
*/
void printDiamond() {
    for (int row = 1; row <= 4; row++) {
        for (int space = 1; space <= 4 - row; space++) {
            cout << ' ';
        }
        for (int hashNum = 1; hashNum <= 2 * row; hashNum++) {
            cout << '#';
        }
        cout << '\n';
    }
    printUpsidedownTriangle();
}

// 2-3
void printX() {
    for (int row = 1; row <= 4; row++) {
        for (int space = 1; space <= row - 1; space++) {
            cout << ' ';
        }
        for (int hashNum = 1; hashNum <= row; hashNum++) {
            cout << '#';
        }
        for (int space = 1; space <= 14 - 2 * (2 * row - 1); space++) {
            cout << ' ';
        }
        for (int hashNum = 1; hashNum <= row; hashNum++) {
            cout << '#';
        }
        cout << '\n';
    }
    for (int row = 4; row >= 1; row--) {
        for (int space = 1; space <= row - 1; space++) {
            cout << ' ';
        }
        for (int hashNum = 1; hashNum <= row; hashNum++) {
            cout << '#';
        }
        for (int space = 1; space <= 14 - 2 * (2 * row - 1); space++) {
            cout << ' ';
        }
        for (int hashNum = 1; hashNum <= row; hashNum++) {
            cout << '#';
        }
        cout << '\n';
    }
}

// 2-5
bool validateISBN13() {

}

bool generateISBN13() {
    
}

int main() {
    printUpsidedownTriangle();
    cout << '\n';
    printDiamond();
    cout << '\n';
    printX();
}