#include "Identifier.h"

#include <cstring>
#include <math.h>
#include <algorithm>

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
        if (!isLatter(str[i]) || isDigit(str[i]))
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


int Identifier::findLast(char c) const {
    for (int i = length - 1; i >= 0; i--) {
        if (data[i] == c) {
            return i;
        }
    }
    return -1;
}

Identifier& Identifier::operator=(const Identifier &other) {
    if (this != &other) {
        if (length != other.length) {
            delete[] data;
            data = new char[other.length];
            length = other.length;
        }
        memcpy(data, other.data, length);
    }

    return *this;
}

bool Identifier::operator>(const Identifier other) {
    int len = std::min(length, other.length);

    bool a;

    for (int i = 0; i < len; i++){
        if(data[i] <= other.data[i]){
            return false;
        }
        else
            a = true;
    }
    return a;
}

Identifier::~Identifier() = default;