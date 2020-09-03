#ifndef C_WORK_IDENTIFIER_H
#define C_WORK_IDENTIFIER_H

#include "String.h"

class Identifier : public String {
public:
    Identifier();

    Identifier(const Identifier &other);

    ~Identifier();

    int findLast(char c, const char* str);

protected:
    explicit Identifier(const char *str);
};


#endif //C_WORK_IDENTIFIER_H
