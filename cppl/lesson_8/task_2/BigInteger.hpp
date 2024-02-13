#pragma once

#include <iostream>
#include <string>

class BigInteger {
public:
    BigInteger() = default;
    explicit BigInteger(std::string &&str) noexcept;
    BigInteger(const BigInteger& other) = default;
    BigInteger(BigInteger&& other) noexcept;

    BigInteger& operator=(std::string &&str) noexcept;
    BigInteger& operator=(const BigInteger& other) = default;
    BigInteger& operator=(BigInteger&& other) noexcept;
    BigInteger operator+(const BigInteger& other) const;
    BigInteger operator*(const BigInteger& other) const;

    friend std::ostream &operator<<(std::ostream &os, const BigInteger &bigint);
private:
    std::string value;
};
