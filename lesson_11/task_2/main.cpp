#include <iostream>
#include "Leaver.h"

int main() {
    std::string name;

    std::cout << "Enter your name: ";
    std::cin >> name;

    std::cout << Leaver::leave(name);
    return 0;
}