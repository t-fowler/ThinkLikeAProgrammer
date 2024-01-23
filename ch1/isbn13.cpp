#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

// 2-5
bool validateISBN13(string isbn) {
    int checksum = 0;
    for (int i = 0; i < 13; i++) {
        int digit = isbn[i] - '0';
        if (i%2 == 1) digit *= 3;
        checksum += digit;
    }
    return (checksum % 10) == 0;
}

int generateISBN13(string isbn) {
    int checksum = 0;
    for (int i = 0; i < 12; i++) {
        int digit = isbn[i] - '0';
        if (i%2 == 1) digit *= 3;
        checksum += digit;
    }
    return 10 - (checksum % 10);
}

int main() {
    cout << "Input an ISBN-13 identifier:\n";
    string isbn;
    cin >> isbn;
    if (validateISBN13(isbn)) {
        cout << "The ISBN is valid.\n";
    } else {
        cout << "The ISBN is not valid.\n";
    }

    cout << "Input an ISBN-13 with no check digit:\n";
    cin >> isbn;
    cout << isbn << generateISBN13(isbn) << '\n';
}