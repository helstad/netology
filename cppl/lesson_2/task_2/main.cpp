#include <iostream>
#include <stdexcept>
#include "SmartArray.hpp"

int main() {
    try {
        SmartArray arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);

        SmartArray new_array(2);
        new_array.add_element(44);
        new_array.add_element(34);

        arr = new_array;
    } catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
