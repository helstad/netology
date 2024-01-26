#include <iostream>
#include <vector>
#include <algorithm>

class Counter {
public:
    Counter() : sum_(0), count_(0) {}

    void operator()(int number) {
        sum_ += number;
        if (number % 3 == 0) {
            ++count_;
        }
    }

    [[nodiscard]] int get_sum() const { return sum_; }

    [[nodiscard]] int get_count() const { return count_; }

private:
    int sum_{};
    int count_{};
};

int main() {
    std::vector<int> numbers = {4, 1, 3, 6, 25, 54};

    Counter counter = std::for_each(numbers.begin(), numbers.end(), Counter());

    std::cout << "get_sum() = " << counter.get_sum() << std::endl;
    std::cout << "get_count() = " << counter.get_count() << std::endl;

    return 0;
}
