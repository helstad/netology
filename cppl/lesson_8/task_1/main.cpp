#include <iostream>
#include <vector>

template<typename T>
void move_vectors(std::vector<T> &lhs, std::vector<T> &rhs) {
    std::vector<T> tmp = std::move(lhs);
    lhs = std::move(rhs);
    rhs = std::move(tmp);
}

int main() {
    std::vector<std::string> one = {"test_string1", "test_string2"};
    std::vector<std::string> two;

    move_vectors(one, two);

    return 0;
}