#include <iostream>
#include <string>

struct bank_account_info {
    unsigned long long int bank_account{};
    std::string name;
    double balance{};
};

void change_balance(bank_account_info& account, double new_balance) {
    account.balance = new_balance;
}

int main() {
    bank_account_info info;

    std::cout << "Enter bank account: ";
    std::cin >> info.bank_account;
    std::cin.ignore();

    std::cout << "Enter name: ";
    std::getline(std::cin, info.name);

    std::cout << "Enter balance: ";
    std::cin >> info.balance;

    double new_balance;
    std::cout << "Enter new balance: ";
    std::cin >> new_balance;

    change_balance(info, new_balance);

    std::cout << "Your account: " << info.name << ", " << info.bank_account << ", " << info.balance << std::endl;

    return EXIT_SUCCESS;
}
