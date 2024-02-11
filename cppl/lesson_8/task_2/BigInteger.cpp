#include "BigInteger.hpp"

#include <algorithm>

BigInteger::BigInteger(std::string&& str) : value(std::move(str)) {}

BigInteger &BigInteger::operator=(std::string &&str) {
    value = std::move(str);
    return *this;
}

BigInteger BigInteger::operator+(const BigInteger &other) const {
    std::string result;
    int carry = 0;
    int i = value.size() - 1;
    int j = other.value.size() - 1;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += value[i--] - '0';
        if (j >= 0) sum += other.value[j--] - '0';
        carry = sum / 10;
        sum %= 10;
        result.push_back(sum + '0');
    }
    std::reverse(result.begin(), result.end());
    return BigInteger(std::move(result));
}

std::ostream &operator<<(std::ostream &os, const BigInteger &bigint) {
    os << bigint.value;
    return os;
}
