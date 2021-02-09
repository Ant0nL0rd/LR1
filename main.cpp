#include <iostream>
#include "String.h"
using namespace std;

int main() {
    String a;
    String b;
    cin >> a;
    cin >> b;
    cout << a.search(b);
    return 0;

}