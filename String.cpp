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
    while(str_[j]!='\0'){
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

void String::change(int n, char ch){
    str[n] = ch;
}

int String::get_size(){
    return size;
}

bool String::operator==(String& other){
    if(size == other.size){
        for(int i = 0; i < size; ++i){
            if(str[i]!=other.str[i]){
                return false;
            }
        }
        return true;
    } else{
        return false;
    }
}


String String::operator=(String& other){
    size = other.size;
    str = new char[size];
    for(int i = 0; i < size; ++i){
        str[i] = other.str[i];
    }
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

String String::operator+(String& other){
    char* stra = new char[size+other.size];
    for(int i = 0; i < size; ++i){
        stra[i] = str[i];
    }
    for(int i = 0; i < other.size; ++i){
        stra[i + size] = str[i];
    }
    String a(stra);
    delete[]stra;
    return a;
}

std::ostream& operator<<(std::ostream& os, String& st){
    int i = 0;
    while(st[i] != '/n'){

        os << st.str[i++];
    }
    return os;
}

std::istream& operator>>(std::istream& is, String& st){
    st.size = 0;
    st.str = (char*)malloc(128);
    int cap = 128;
    int c = EOF;
    while (( c = getchar() ) != '\n' && c != EOF) {
        st.str[st.size++] = (char) c;
        if (st.size == cap) {
            cap = st.size + 128;
            st.str = (char*)realloc(st.str, cap);
        }
    }
    st.str[st.size] = '\0';
    return is;
}
