#include <iostream>
#include "BigInteger.hpp"

int main() {
    auto number1 = BigInteger("114575");
    auto number2 = BigInteger("78524");

    auto result = number1 + number2;
    std::cout << result << std::endl; // 193099

    result = number1 * number2;
    std::cout << result << std::endl; // 8996887300

    return 0;
}
