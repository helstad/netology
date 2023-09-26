#include <iostream>
#include <string>

struct address {
    std::string city;
    std::string street;
    int number_house{};
    int number_room{};
    int index_mail{};
};

void printAddress(address& addr) {
    std::cout << "City: " << addr.city << std::endl;
    std::cout << "Street: " << addr.street << std::endl;
    std::cout << "House number: " << addr.number_house << std::endl;
    std::cout << "Room number: " << addr.number_room << std::endl;
    std::cout << "Index: " << addr.index_mail << std::endl;
}

int main() {
    address addr_1 = {"Moscow", "Chistoprudny Blvd", 15, 4, 164447};
    printAddress(addr_1);

    std::cout << std::endl;

    address addr_2 = {"Moscow", "Varshavskoye Highway", 1, 105, 117105};
    printAddress(addr_2);

    return EXIT_SUCCESS;
}
