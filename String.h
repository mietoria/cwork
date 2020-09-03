//
// Created by nefed on 31.08.2020.
//

#ifndef C_WORK_STRING_H
#define C_WORK_STRING_H

class String {
protected:
    char *data;
    
public:
    int length;

    String();

    explicit String(const char *str);

    explicit String(char a);

    String(const String &other);

    ~String();

    char operator[](int index) const;
};


#endif //C_WORK_STRING_H