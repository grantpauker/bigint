#include <iostream>
#include "bigint.hpp"
#define pln(n) std::cout << n << std::endl
#define p(n) std::cout << n

int main()
{
    BigInt dog("910273410237412309471230909712340912734091273490000001234012340");
    BigInt cat("7701820492735041208473592683742834295789273094128390257");
    dog += cat;
    pln(dog);
}