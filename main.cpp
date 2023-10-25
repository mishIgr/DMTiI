#include "lib/num.h"
#include <iostream>
#include <string>

int main() {
    Num a("1");
    Num b("-10000");
    // b = a;
    std::cout << a + b;
    return 0;
}