#include "BigInteger.hpp"

#include <algorithm>

BigInteger::BigInteger(std::string &&str) : value(std::move(str)) {}

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

BigInteger BigInteger::operator*(const BigInteger &other) const {
    std::string result(value.size() + other.value.size(), '0');
    for (int i = value.size() - 1; i >= 0; --i) {
        int carry = 0;
        for (int j = other.value.size() - 1; j >= 0; --j) {
            int mul = (value[i] - '0') * (other.value[j] - '0') + carry + (result[i + j + 1] - '0');
            result[i + j + 1] = mul % 10 + '0';
            carry = mul / 10;
        }
        result[i] += carry;
    }
    auto pos = result.find_first_not_of('0');
    if (pos != std::string::npos) {
        return BigInteger(result.substr(pos));
    }
    return BigInteger("0");
}

std::ostream &operator<<(std::ostream &os, const BigInteger &bigint) {
    os << bigint.value;
    return os;
}
