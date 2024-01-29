#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main() {
    int quantity{};
    std::cout << "Enter the number of elements: ";
    std::cin >> quantity;

    std::set<int> numbersSet;
    int num{};

    std::cout << "Enter a numbers" << std::endl;

    for (int i = 0; i < quantity; ++i) {
        std::cin >> num;
        numbersSet.insert(num);
    }

    std::vector<int> uniqueNumbers(numbersSet.begin(), numbersSet.end());

    std::sort(uniqueNumbers.rbegin(), uniqueNumbers.rend());

    std::cout << "Unique sorted numbers" << std::endl;

    for (int unique : uniqueNumbers) {
        std::cout << unique << std::endl;
    }

    return 0;
}
