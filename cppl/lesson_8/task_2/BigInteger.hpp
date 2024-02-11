#pragma once

#include <iostream>
#include <string>

class BigInteger {
public:
    BigInteger() = default;
    explicit BigInteger(std::string &&str);
    BigInteger &operator=(std::string &&str);
    BigInteger operator+(const BigInteger& other) const;
    friend std::ostream &operator<<(std::ostream &os, const BigInteger &bigint);
private:
    std::string value;
};
