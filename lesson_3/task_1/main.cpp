#include <iostream>

class Calculator {
private:
    double num1 = 1, num2 = 1;
public:
    double add() { return num1 + num2; }

    double multiply() { return num1 * num2; }

    double subtract_1_2() { return num1 - num2; }

    double subtract_2_1() { return num2 - num1; }

    double divide_1_2() { return num1 / num2; }

    double divide_2_1() { return num2 / num1; }

    bool set_num1(double num) {
        if (num != 0) {
            num1 = num;
            return true;
        }
        return false;
    }

    bool set_num2(double num) {
        if (num != 0) {
            num2 = num;
            return true;
        }
        return false;
    }
};


int main() {
    double input_number{};
    Calculator calc;

    // Endless loop
    while (true) {
        do {
            std::cout << "Enter num_1: ";
            std::cin >> input_number;
            if (!calc.set_num1(input_number)) {
                std::cout << "Wrong num_1!\n";
            }
        } while (!calc.set_num1(input_number));

        do {
            std::cout << "Enter num_2: ";
            std::cin >> input_number;
            if (!calc.set_num2(input_number)) {
                std::cout << "Wrong num_2!\n";
            }
        } while (!calc.set_num2(input_number));

        std::cout << "num_1 + num_2 = " << calc.add() << std::endl;
        std::cout << "num_1 - num_2 = " << calc.subtract_1_2() << std::endl;
        std::cout << "num_2 - num_1 = " << calc.subtract_2_1() << std::endl;
        std::cout << "num_1 * num_2 = " << calc.multiply() << std::endl;
        std::cout << "num_1 / num_2 = " << calc.divide_1_2() << std::endl;
        std::cout << "num_2 / num_1 = " << calc.divide_2_1() << std::endl;
    }

    return EXIT_SUCCESS;
}
