#include "String.h"
#include <algorithm>
#include <cstring>
#include <cstdlib>

String::String(): str(nullptr), size(0){}

String::String(String& other){
    size = other.size;
    str = new char[size];
    for(int i = 0; i < size; ++i){
        str[i] = other.str[i];
    }
}

String::String(const char* str_) {
    int j = 0;
    while(true){
        if(str_[j]=='\0'){
            break;
        }
        ++j;
    }
    size = j;
    str = new char[j];
    for(int i = 0; i < j; ++i){
        str[i] = str_[i];
    }
}

String::~String(){
    delete[]str;
}

bool String::operator==(String& other){
    return std::strcmp(this->str, other.str)==0;
}

int String::search(String& other){
    int j = 0;
    for(int i = 0; i < size; ++i){
        str[i]==other.str[j]?++j:j=0;
        if(j == other.size){
            return i - other.size + 1;
        }

    }
    return -1;
}

char String::operator[](int a){
    return str[a];
}

String& String::operator+(String& other){
    char* stra = new char[size+other.size];
    for(int i = 0; i < size; ++i){
        stra[i] = str[i];
    }
    for(int i = 0; i < other.size; ++i){
        stra[i + size] = str[i];
    }
    String a(stra);
    return a;
}

std::ostream& String::operator<<(std::ostream& os){
    os << str;
    return os;
}

std::istream& String::operator>>(std::istream& is){
    size = 0;
    str = (char*)malloc(128);
    int cap = 128;
    int c = EOF;
    int i =0;
    while (( c = getchar() ) != '\n' && c != EOF) {
        str[i++] = (char) c;
        ++size;
        if (i == cap) {
            cap = i + 128;
            str = (char*)realloc(str, cap);
        }
    }
    str[i] = '\0';
    return is;
}
