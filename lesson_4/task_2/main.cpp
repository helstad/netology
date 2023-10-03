#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

class Address {
private:
    std::string city, street;
    int house{}, room{};
public:
    std::string get_output_address() const {
        return city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(room);
    }

    Address() {
        city = "";
        street = "";
        house = 0;
        room = 0;
    }

    Address(const std::string &city, const std::string &street, int house, int room) {
        this->city = city;
        this->street = street;
        this->house = house;
        this->room = room;
    }

    const std::string& getCity() const {
        return city;
    }

    const std::string& getStreet() const {
        return street;
    }
};

void sortAddress(Address *&pAddress, int i);

bool openInputFile(std::ifstream &fin) {
    fin.open("in.txt");
    if (!fin.is_open()) {
        std::cerr << "File in.txt not found!\n";
        return false;
    }
    return true;
}

bool openOutputFile(std::ofstream &fout) {
    fout.open("out.txt");

    if (!fout.is_open()) {
        std::cerr << "File out.txt not found!\n";
        return false;
    }
    return true;
}

int readAddress(Address *&addresses, int &size, std::ifstream &fin) {
    fin >> size;
    fin.ignore();
    addresses = new Address[size];

    for (int i = 0; i < size; ++i) {
        std::string city, street;
        int house, room;

        std::getline(fin, city);
        std::getline(fin, street);
        fin >> house >> room;
        fin.ignore();

        addresses[i] = Address(city, street, house, room);
    }
    return size;
}

void writeAddresses(const Address *addresses, int size, std::ofstream &fout) {
    fout << size << std::endl;
    for (int i = size - 1; i >= 0; --i) {
        fout << addresses[i].get_output_address() << std::endl;
    }
}

void closeFiles(std::ifstream &fin, std::ofstream &fout) {
    fin.close();
    fout.close();
}

bool compareAddresses(const Address& a, const Address& b) {
    if (a.getCity() != b.getCity()) {
        return a.getCity() > b.getCity();
    } else {
        return a.getStreet() > b.getStreet();
    }
}

int main() {
    std::ifstream fin;
    std::ofstream fout;

    if (!openInputFile(fin) || !openOutputFile(fout)) {
        return EXIT_FAILURE;
    }

    int size{};
    Address *addresses;

    size = readAddress(addresses, size, fin);

    std::sort(addresses, addresses + size, compareAddresses);

    writeAddresses(addresses, size, fout);

    std::cout << "Data write in to out.txt\n";

    delete[] addresses;
    closeFiles(fin, fout);

    return EXIT_SUCCESS;
}
