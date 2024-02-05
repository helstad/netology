#include <iostream>
#include <set>
#include <vector>
#include <list>

template<typename Container>
void print_container(const Container& container) {
    for (const auto& item : container) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::set<std::string> test_set = {"one", "two", "three", "four"};
    print_container(test_set);

    std::list<std::string> test_list = {"one", "two", "three", "four"};
    print_container(test_list);

    std::vector<std::string> test_vector = {"one", "two", "three", "four"};
    print_container(test_vector);
    return 0;
}
