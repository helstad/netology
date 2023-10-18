#include "Figure.h"

Figure::Figure(const std::string &figureName) : name(figureName) {}

void Figure::print_info() const {
    std::cout << name << ":" << std::endl;
}