#include <string>

#include "SubstitutionCipher.hpp"

// 3-3, 3-4
namespace TLAP {

const char CIPHER[26] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
                            'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l',
                                'z', 'x', 'c', 'v', 'b', 'n', 'm'};

void encodeStream(std::istream& in_stream, std::ostream& out_stream) {
    char plaintext;

    in_stream >> std::noskipws >> plaintext;
    while (plaintext != '\n') {
        out_stream << encodeCharacter(plaintext);
        in_stream >> plaintext;
    }
    out_stream << '\n';
}

char encodeCharacter(char plaintext) {
    if (plaintext >= 'a' && plaintext <= 'z') {
        return CIPHER[plaintext - 'a'];
    }
    else if (plaintext >= 'A' && plaintext <= 'Z') {
        return CIPHER[plaintext - 'A'] - 32;
    }
    else {
        return plaintext;
    }
}

void decodeStream(std::istream& in_stream, std::ostream& out_stream) {
    char encoded_char;

    in_stream >> std::noskipws >> encoded_char;
    while (encoded_char != '\n') {
        out_stream << decodeCharacter(encoded_char);
        in_stream >> encoded_char;
    }
    out_stream << '\n';

}

char decodeCharacter(char encoded) {
    char idx = 0;

    if (encoded >= 'a' && encoded <= 'z') {
        while (CIPHER[idx] != encoded) {
            idx++;
        }
        return idx + 'a';
    }
    else if (encoded >= 'A' && encoded <= 'Z') {
        while (CIPHER[idx] != (encoded + 32)) {
            idx++;
        }
        return idx + 'A';
    }
    else {
        return encoded;
    }
}

} // namespace TLAP

int main(int argc, char* argv[]) {
    const std::string usage = "usage: 'command -e' for encode and 'command -d' for decode.\n";

    if (argc < 2 || argv[1][0] != '-') {
        std::cout << usage;
        return 1;
    }

    if (argv[1][1] == 'e') {
        // std::cout << "Provide your plaintext message.\n";
        TLAP::encodeStream(std::cin, std::cout);
    }
    else if (argv[1][1] == 'd') {
        TLAP::decodeStream(std::cin, std::cout);
    }
    else {
        std::cout << usage;
    }
}