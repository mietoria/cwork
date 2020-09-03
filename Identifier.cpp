#include "Identifier.h"

#include <cstring>

Identifier::Identifier() = default;

bool isLatter(char c) {
    if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || c == '_') {
        return true;
    } else {
        return false;
    }
}

bool isDigit(char c) {
    if ('0' <= c && c <= '9') {
        return true;
    } else {
        return false;
    }
}

int proverochka(const char *str) {
    if (!isLatter(str[0]))
        return false;

    for (int i = 1; i < strlen(str); i++) {
        if (!isLatter(str[i]) || !isDigit(str[i]))
            return false;
    }
}

Identifier::Identifier(const char *str) {
    if (str == nullptr || !proverochka(str)) {
        data = new char[0];
        length = 0;
    } else {
        data = new char[strlen(str)];
        length = strlen(str);
        memcpy(data, str, length);
    }
}

Identifier::Identifier(const Identifier &other) : String(other) {}

int Identifier::findLast(char c) {

    return 0;
}

Identifier::~Identifier() = default;