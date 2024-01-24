#include <iostream>
#include <vector>
#include <algorithm>

std::ostream &operator<<(std::ostream &out, const std::vector<int> &values) {
    std::for_each(values.begin(), values.end(), [&out](const int &value) { out << value << ' '; });
    return out;
}

template<typename T>
T square(const T &value) {
    return value * value;
}

template<typename T>
std::vector<T> square(const std::vector<T> &values) {
    std::vector<T> result;
    result.reserve(values.size());

    for (const T &value: values) {
        result.push_back(value * value);
    }
    return result;
}

int main() {
    int value{4};
    std::vector<int> values{-1, 4, 8};

    std::cout << "[IN]: " << value << std::endl;
    std::cout << "[OUT]: " << square(value) << std::endl;

    std::cout << "[IN]: " << values << std::endl;
    std::cout << "[OUT]: " << square(values) << std::endl;

    return 0;
}
