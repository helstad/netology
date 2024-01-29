#include <iostream>
#include "SimpleVector/SimpleVector.hpp"

int main() {
    SimpleVector<int> mySimpleVector;

    for (int i = 0; i < 12; ++i) {
        mySimpleVector.push_back(i);
    }

    std::cout << "Size: " << mySimpleVector.size() << std::endl;
    std::cout << "Capacity: " << mySimpleVector.capacity() << std::endl;

    std::cout << "Elements:";
    for (int i = 0; i < mySimpleVector.size(); ++i) {
        std::cout << " " << mySimpleVector.at(i);
    }
    std::cout << std::endl;

    return 0;
}
