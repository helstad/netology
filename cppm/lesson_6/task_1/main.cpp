#include <iostream>
#include "maths.h"

int main() {
    double num_1{}, num_2{};
    int command{};

    std::cout << "Enter number_1: " << std::endl;
    std::cin >> num_1;
    std::cout << "Enter number_2: " << std::endl;
    std::cin >> num_2;

    std::cout << "Choose command ( 1 - addition, 2 - subtraction, 3 - multiplication, 4 - division, 5 - exponentiation )" << std::endl;
    std::cin >> command;

    switch (command) {
        case 1:
            std::cout << num_1 << " + " << num_2 << " = " << addition(num_1, num_2) << std::endl;
            break;
        case 2:
            std::cout << num_1 << " - " << num_2 << " = " << subtraction(num_1, num_2) << std::endl;
            break;
        case 3:
            std::cout << num_1 << " * " << num_2 << " = " << multiplication(num_1, num_2) << std::endl;
            break;
        case 4:
            std::cout << num_1 << " / " << num_2 << " = " << division(num_1, num_2) << std::endl;
            break;
        case 5:
            std::cout << num_1 << " to the power of " << num_2 << " = " << exponentiation(num_1, static_cast<int>(num_2)) << std::endl;
            break;
        default:
            std::cout << "Unknown command" << std::endl;
            break;
    }

    return 0;
}
