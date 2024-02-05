#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void remove_duplicates(std::vector<T>& vec) {
    std::sort(vec.begin(), vec.end());

    auto last = std::unique(vec.begin(), vec.end());

    vec.erase(last, vec.end());
}

int main() {
    std::vector<int> vec = {1, 1, 2, 5, 6, 1, 2, 4};

    std::cout << "[IN]: ";
    for (const auto& item : vec) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;

    remove_duplicates(vec);

    std::cout << "[OUT]: ";
    for (const auto& item : vec) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;

    return 0;
}
