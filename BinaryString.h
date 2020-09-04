#ifndef C_WORK_BINARYSTRING_H
#define C_WORK_BINARYSTRING_H

#include "string.h"

class BinaryString : public String {
public:
    BinaryString();

    BinaryString(const char *str);

    BinaryString(const BinaryString &other);

    BinaryString(int num);

    ~BinaryString();

    BinaryString &operator=(const BinaryString &other);

    BinaryString addOne(int pos);

    BinaryString substractOne(int pos);

    BinaryString toNormal();

    BinaryString toAdditional();

    bool operator>(BinaryString other);

    BinaryString operator+(const BinaryString &rhs);

    BinaryString operator-(const BinaryString &rhs);

    operator int();

    int getSign();

};


#endif //C_WORK_BINARYSTRING_H
