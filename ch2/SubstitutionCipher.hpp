#ifndef SUBSTITUTION_CIPHER_H
#define SUBSTITUTION_CIPHER_H

#include <iostream>

namespace TLAP {

void encodeStream(std::istream&, std::ostream&);
char encodeCharacter(char);

void decodeStream(std::istream&, std::ostream&);
char decodeCharacter(char);

} // namespace TLAP

#endif