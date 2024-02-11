#include <iostream>
#include "BigInteger.hpp"

int main() {
    auto number1 = BigInteger("114575");
    auto number2 = BigInteger("78524");

    auto result = number1 + number2;
    std::cout << result; // 193099

    return 0;
}
