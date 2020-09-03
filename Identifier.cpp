#include "Identifier.h"

#include <cstring>

Identifier::Identifier() = default;

bool isLatter(char c) {
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || c == '_';
}

bool isDigit(char c) {
    return '0' <= c && c <= '9';
}

int check(const char *str) {
    if (!isLatter(str[0]))
        return false;

    for (int i = 1; i < strlen(str); i++) {
        if (!isLatter(str[i]) || !isDigit(str[i]))
            return false;
    }

    return true;
}

Identifier::Identifier(const char *str) {
    if (str != nullptr && check(str)) {
        delete[] data;
        data = new char[strlen(str)];
        length = strlen(str);
        memcpy(data, str, length);
    }
}

Identifier::Identifier(const Identifier &other) : String(other) {}

int Identifier::findLast(char c, const char* str) {
    if (str == nullptr) {
        data = new char[0];
        length = 0;
    } else {
        for (int i = strlen(str); i > 0; i--) {
            if (str[i] == c)
                return i;
        }
        return -1;
    }
}

Identifier::~Identifier() = default;