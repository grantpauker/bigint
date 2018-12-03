#include <iostream>
#include "bigint.hpp"

#define pln(n) std::cout << (n) << std::endl
#define p(n) std::cout << n

int main()
{
    BigInt num0("123456789987654321");
    BigInt num1("314159265358979323846");
    BigInt num2("314282722148966978167");
    num0 += num1;
    pln(num0);
    pln(num0 == num2);
}