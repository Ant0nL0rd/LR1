#ifndef ABV_STRING_H
#define ABV_STRING_H
#include <iostream>

class String{
    char* str;
    int size;
public:
    String();
    String(String& other);
    String(const char* str_);
    ~String();
    bool operator==(String& other);
    int search(String& other);
    char operator[](int a);
    String& operator+(String& other);
    std::ostream& operator<<(std::ostream& os);
    std::istream& operator>>(std::istream& is);

};





#endif //ABV_STRING_H
