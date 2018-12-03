#include <iostream>
#include <string>
#include "bigint.hpp"

#define pln(n) std::cout << (n) << std::endl
#define p(n) std::cout << n

int main()
{
     BigInt num0("199");
    BigInt num1("99");
    num0 -= num1; 
    pln(num0);
}
