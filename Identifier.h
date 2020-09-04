#ifndef C_WORK_IDENTIFIER_H
#define C_WORK_IDENTIFIER_H

#include "String.h"

class Identifier : public String {
public:
    Identifier();

    Identifier(const Identifier &other);

    ~Identifier();

    int findLast(char c) const;

    Identifier &operator=(const Identifier &other);

    bool operator>(const Identifier other);

protected:
    explicit Identifier(const char *str);
};


#endif //C_WORK_IDENTIFIER_H
