#include <iostream>
#include "String.h"
using namespace std;

int main() {
    String a;
    String b;
    a >> cin;
    b >> cin;
    cout<< a.search(b);
    return 0;

}