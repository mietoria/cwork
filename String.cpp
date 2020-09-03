#include <cstring>

#include "String.h"

String::String() : data(new char[0]), length(0) {}

String::String(const char *str) {
    if (str == nullptr) {
        data = new char[0];
        length = 0;
    } else {
        data = new char[strlen(str)];
        length = strlen(str);
        memcpy(data, str, length);
    }
}

String::String(char a) : data(new char[1]), length(1) {
    data[0] = a;
}

String::String(const String &other) : data(new char[other.length]), length(other.length) {
    memcpy(data, other.data, length);
}

String::~String() {
    delete[] data;
}

char String::operator[](int index) const {
    return data[index];
}
