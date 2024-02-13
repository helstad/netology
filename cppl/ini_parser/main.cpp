#include <iostream>
#include "Parser.hpp"

int main() {
    try {
        Parser parser("../config.ini");

        auto var1_value = parser.get_value<std::string>("owner.name");
        auto var2_value = parser.get_value<std::string>("data.theme");
        auto var3_value = parser.get_value<std::string>("Section4.Vid");
        auto var4_value = parser.get_value<double>("owner.variable");

        std::cout << "Value: " << var1_value << std::endl;
        std::cout << "Value: " << var2_value << std::endl;
        std::cout << "Value: " << var3_value << std::endl;
        std::cout << "Value: " << var4_value << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
