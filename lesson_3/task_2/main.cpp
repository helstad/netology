#include <iostream>

class Counter {
private:
    int value;
public:
    Counter(int initialValue) {
        value = initialValue;
    }

    void increment() {
        value++;
    }

    void decrement() {
        value--;
    }

    int getValue() const {
        return value;
    }
};

int getInputValue() {
    int initialValue;
    while (true) {
        std::cout << "Enter initial value: ";
        if (std::cin >> initialValue) {
            break;
        } else {
            std::cout << "Invalid input." << std::endl;
        }
    }

    return initialValue;
}

void handleCommands(Counter &counter) {
    char command;

    while (true) {
        std::cout << "Enter command ( + , - , = , x ): ";
        std::cin >> command;

        switch (command) {
            case '+':
                counter.increment();
                std::cout << "Counter increased. Value is " << counter.getValue() << std::endl;
                break;
            case '-':
                counter.decrement();
                std::cout << "Counter decreased. Value is " << counter.getValue() << std::endl;
                break;
            case '=':
                std::cout << "Current counter value: " << counter.getValue() << std::endl;
                break;
            case 'x':
                std::cout << "Bye!" << std::endl;
                return;
            default:
                std::cout << "Wrong command. Enter again." << std::endl;
        }
    }
}

int main() {
    char command;

    std::cout << "Do you want init counter value? Enter 'y' or 'n': " << std::endl;
    std::cin >> command;

    int initialValue;
    if (command == 'y' || command == 'Y') {
        initialValue = getInputValue();
    } else if (command == 'n' || command == 'N') {
        initialValue = 1;
    } else {
        std::cout << "Invalid input." << std::endl;
        return EXIT_FAILURE;
    }

    Counter counter(initialValue);

    std::cout << "Counter initial value is " << counter.getValue() << std::endl;

    handleCommands(counter);

    return EXIT_SUCCESS;
}
