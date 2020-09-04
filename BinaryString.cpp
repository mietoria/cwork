#include "BinaryString.h"
#include <cstring>
#include <string>
#include "math.h"

BinaryString::BinaryString() = default;


BinaryString::~BinaryString() = default;


bool isBinary(const char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != '0' && str[i] != '1')
            return false;
    }
    return true;
}

BinaryString::BinaryString(const char *str) {
    if (isBinary(str)) {
        delete[] data;
        data = new char[strlen(str)];
        length = strlen(str);
        memcpy(data, str, length);
    }
}

BinaryString::BinaryString(const BinaryString &other) : String(other) {}

int BinaryString::getSign() {
    return data[0] == '1' ? -1 : 1;
}

BinaryString &BinaryString::operator=(const BinaryString &other) {
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

BinaryString BinaryString::addOne(int pos) {
    BinaryString tmp = BinaryString(*this);
    for (int i = pos; i > -1; i--) {
        if (tmp.data[i] == '0') {
            tmp.data[i] = '1';
            return tmp;
        } else {
            tmp.data[i] = '0';
        }
    }
    return tmp;
}

BinaryString::operator int() {
    int sign = 1;
    int result = 0;
    BinaryString tmp = BinaryString(*this);
    int power = pow(2, length - 1);
    power /= 2;
    if (tmp[0] != '0') {
        sign = -1;
        for (int i = 0; i < tmp.length; i++) {
            tmp.data[i] = tmp.data[i] == '0' ? '1' : '0';
        }
        tmp = tmp.addOne(tmp.length - 1);
    }
    for (int i = 1; i < length; ++i) {
        result += (tmp[i] - '0') * power;
        power /= 2;
    }
    return result * sign;
}

BinaryString BinaryString::toNormal() {
    BinaryString tmp = BinaryString(*this);
    for (int i = 0; i < tmp.length; i++) {
        tmp.data[i] = tmp.data[i] == '0' ? '1' : '0';
    }
    return tmp.addOne(tmp.length - 1);
}

BinaryString BinaryString::toAdditional() {
    BinaryString tmp = BinaryString(*this);
    tmp.data[0] = '1';
    for (int i = 1; i < tmp.length; i++) {
        tmp.data[i] = tmp.data[i] == '0' ? '1' : '0';
    }
    return tmp.addOne(tmp.length - 1);
}

bool BinaryString::operator>(BinaryString other) {
    int a = int(*this);
    int b = int(other);
    return a > b;
}

BinaryString BinaryString::operator+(const BinaryString &rhs) {
    bool flag;
    int len;
    BinaryString l_tmp = BinaryString(*this);
    BinaryString r_tmp = BinaryString(rhs);

    if (length > rhs.length) {
        flag = true;
        len = rhs.length;
    } else {
        flag = false;
        len = length;
    }

    for (int i = 0; i < len; i++) {
        if (flag) {
            if (rhs[len - i - 1] == '1') {
                l_tmp = l_tmp.addOne(length - 1 - i);
            }
        } else {
            if (this->data[len - i - 1] == '1') {
                r_tmp = r_tmp.addOne(rhs.length - 1 - i);
            }
        }
    }
    if (flag) {
        return l_tmp;
    } else {
        return r_tmp;
    }
}

BinaryString BinaryString::operator-(const BinaryString &rhs) {
    bool flag;
    int len;
    std::string str;
    BinaryString l_tmp;
    BinaryString r_tmp;

    if (length > rhs.length) {
        flag = true;
        len = length;

        for (int i = 0; i < len; i++) {
            str += "0";
        }
        l_tmp = BinaryString(*this);
        r_tmp = BinaryString(str.c_str());
        for (int i = 0; i < rhs.length; i++) {
            r_tmp.data[len - 1 - i] = rhs.data[rhs.length - 1 - i];
        }
    } else {
        flag = false;
        len = rhs.length;
        for (int i = 0; i < len; i++) {
            str += "0";
        }
        l_tmp = BinaryString(str.c_str());
        r_tmp = BinaryString(rhs);
        for (int i = 0; i < length; i++) {
            l_tmp.data[len - 1 - i] = data[length - 1 - i];
        }
    }
    if (rhs.data[0] == '1') {
        r_tmp.data[len - rhs.length] = '0';
        r_tmp.data[0] = 1;
        r_tmp = r_tmp.toNormal();
    } else {
        r_tmp = r_tmp.toAdditional();
    }
    return l_tmp + r_tmp;
}