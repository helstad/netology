#include <iostream>

#define MODE 1

int add(int a, int b) {
    return a + b;
}

int main() {
#ifndef MODE
    std::cout << "A constant MODE is required." << std::endl;
    return EXIT_FAILURE;
#endif

#if MODE == 0
    std::cout << "Training mode" << std::endl;
#elif MODE == 1
    std::cout << "Combat mode" << std::endl;

    int number_1{}, number_2{};
    std::cout << "Enter number_1: ";
    std::cin >> number_1;
    std::cout << "Enter number_2: ";
    std::cin >> number_2;

    std::cout << "Sum: " << add(number_1, number_2) << std::endl;
#else
    std::cout << "Unknown mode. Exit" << std::endl;
#endif

    return EXIT_SUCCESS;
}
