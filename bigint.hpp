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
    bool positive;

    BigInt() {}

    BigInt(std::string value)
    {
        auto end_it = value.rend();
        if (value[0] != '-')
        {
            positive = true;
        }
        else
        {
            positive = false;
            --end_it;
        }
        positive = (value[0] != '-');

        for (auto curchar = value.rbegin(); curchar != end_it; curchar++)
        {
            number.push_back((*curchar - '0'));
        }
    }

    BigInt(long long value) : BigInt(std::to_string(value)) {}

    BigInt operator+(const BigInt &val) const
    {
        if (positive && !val.positive)
        {
            return *this - val;
        }
        if (!positive && val.positive)
        {
            return val - *this;
        }
        BigInt ret;
        ret.positive = (positive && val.positive);
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

    BigInt operator-(const BigInt &val) const
    {
        if (*this < val)
        {
            return -(val - *this);
        }
        BigInt ret;
        ret.positive = true;
        auto this_it = number.begin();
        auto val_it = val.number.begin();
        int borrow = 0;
        int dif;
        while (this_it != number.end())
        {
            dif = 0;
            dif += *this_it;
            ++this_it;
            if (val_it != val.number.end())
            {
                dif -= *val_it;
                ++val_it;
            }
            dif -= borrow;
            borrow = (dif < 0);
            dif = (dif + 10) % 10;
            ret.number.push_back(dif);
        }
        if (number.size() > 1)
        {
            auto ret_it = ret.number.begin();
            do
            {
                ret_it = ret.number.end() -1;
                if (*ret_it == 0){
                    ret.number.pop_back();
                } else{
                    break;
                }
            } while(number.size() > 1);
        }
        return ret;
    }

    BigInt operator-=(const BigInt &val)
    {
        *this = *this - val;
        return *this;
    }

    BigInt operator-()
    {
        positive = !(this->positive);
        return *this;
    }
    bool operator==(const BigInt &val) const
    {
        return number == val.number;
    }

    bool operator!=(const BigInt &val) const
    {
        return number != val.number;
    }

    bool operator>(const BigInt &val) const
    {
        return compare(val) == 1;
    }

    bool operator<(const BigInt &val) const
    {
        return compare(val) == -1;
    }

    bool operator>=(const BigInt &val) const
    {
        return compare(val) == 1 || compare(val) == 0;
    }

    bool operator<=(const BigInt &val) const
    {
        return compare(val) == -1 || compare(val) == 0;
    }

    int compare(const BigInt &b) const
    {
        if (number.size() > b.number.size())
        {
            return 1;
        }
        else if (number.size() < b.number.size())
        {
            return -1;
        }
        else
        {
            auto this_it = number.rbegin();
            auto val_it = b.number.rbegin();
            while (this_it != number.rend() && val_it != b.number.rend())
            {
                if (*this_it > *val_it)
                {
                    return 1;
                }
                else if (*this_it < *val_it)
                {
                    return -1;
                }
                ++this_it;
                ++val_it;
            }
        }
        return 0;
    }
};

std::ostream &operator<<(std::ostream &out, const BigInt &b)
{
    if (!b.positive)
    {
        out << '-';
    }
    for (auto it = b.number.rbegin(); it != b.number.rend(); it++)
    {
        out << *it;
    }
    return out;
}
#endif