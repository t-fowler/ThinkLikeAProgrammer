#include <iostream>
#include <string>

// 3-3, 3-4
namespace TLAP {

const char cipher[26] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
                            'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l',
                                'z', 'x', 'c', 'v', 'b', 'n', 'm'};

void encodeStream(std::istream& in_stream, std::ostream& out_stream) {
    char letter;

    in_stream >> std::noskipws >> letter;
    while (letter != '\n') {
        if (letter >= 'a' && letter <= 'z') {
            out_stream << cipher[letter - 'a'];
        } 
        else if (letter >= 'A' && letter <= 'Z') {
            out_stream << static_cast<char>(cipher[letter - 'A'] - 32);
        }
        else {
            out_stream << letter;
        }
        in_stream >> letter;
    }
    out_stream << '\n';

}

void decodeStream(std::istream& in_stream, std::ostream& out_stream) {
    char letter;

    in_stream >> std::noskipws >> letter;
    while (letter != '\n') {
        if (letter >= 'a' && letter <= 'z') {
            char idx = 0;
            while (cipher[idx] != letter) {
                idx++;
            }
            out_stream << static_cast<char>(idx + 'a');
        }
        else if (letter >= 'A' && letter <= 'Z') {
            int idx = 0;
            while (cipher[idx] != (letter + 32)) {
                idx++;
            }
            out_stream << static_cast<char>(idx + 'A');
        }
        else {
            out_stream << letter;
        }
        in_stream >> letter;
    }
    out_stream << '\n';

}

} // namespace TLAP

int main(int argc, char* argv[]) {
    const std::string usage = "usage: 'command -e' for encode and 'command -d' for decode.\n";

    if (argv[1][0] != '-') {
        std::cout << usage;
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