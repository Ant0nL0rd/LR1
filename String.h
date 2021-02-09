#ifndef ABV_STRING_H
#define ABV_STRING_H
#include <iostream>

class String{
public:
    char* str;
    int size;
    String();
    String(String& other);
    String(const char* str_);
    ~String();
    void change(int n, char ch);
    int get_size();
    bool operator==(String& other);
    String operator=(String& other);
    int search(String& other);
    char operator[](int a);
    String& operator+(String& other);

};

std::ostream& operator<<(std::ostream& os, String& st);
std::istream& operator>>(std::istream& is, String& st);




#endif //ABV_STRING_H
