#include <iostream>
#include "../static_lib/Greeter.h"

int main() {
    std::string name;

    std::cout << "Enter your name: ";
    std::cin >> name;

    std::cout << Greeter::greet(name);
    return 0;
}
