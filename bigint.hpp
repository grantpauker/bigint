#ifndef H_BIGINT
#define H_BIGINT
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
class BigInt
{

  public:
    std::vector<int> number;
    BigInt() {}
    BigInt(std::string value)
    {
        for (auto curchar = value.rbegin(); curchar != value.rend(); curchar++)
        {
            number.push_back((*curchar - '0'));
        }
    }
    BigInt(long long value) : BigInt(std::to_string(value)) {}
    BigInt operator+(const BigInt &val)
    {
        BigInt ret;
        auto this_it = number.begin();
        auto val_it = val.number.begin();
        int carry = 0;
        int sum;
        while (this_it != number.end() || val_it != val.number.end())
        {
            sum = 0;
            if (this_it != number.end())
            {
                sum += *this_it;
                ++this_it;
            }
            if (val_it != val.number.end())
            {
                sum += *val_it;
                ++val_it;
            }
            sum += carry;
            carry = (sum >= 10);
            sum %= 10;
            ret.number.push_back(sum);
        }
        return ret;
    }
    BigInt operator+=(const BigInt &val)
    {
        *this = *this + val;
        return *this;
    }
};

std::ostream &operator<<(std::ostream &out, const BigInt &b)
{
    for (auto it = b.number.rbegin(); it != b.number.rend(); it++)
    {
        out << *it;
    }
    return out;
}
#endif

