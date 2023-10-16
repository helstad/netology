#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>

int function(const std::string& str, int forbidden_length) {
    int length = static_cast<int>(str.length());

    if (length == forbidden_length) {
        throw std::runtime_error("bad_length");
    }
    return length;
}

int main() {
    int forbidden_length{};

    std::cout << "Enter forbidden length: ";
    if (!(std::cin >> forbidden_length) || forbidden_length <= 0) {
        std::cout << "Invalid input." << std::endl;
        return EXIT_FAILURE;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (true) {
        std::string str;

        std::cout << "Enter word: ";
        std::getline(std::cin, str);

        try {
            int length = function(str, forbidden_length);
            std::cout << "String length \"" << str << "\" equal " << length << std::endl;
        } catch (const std::runtime_error& e) {
            if (e.what() == std::string("bad_length")) {
                std::cout << "You entered forbidden length string. Goodbye." << std::endl;
                break;
            }
        }
    }

    return EXIT_SUCCESS;
}
