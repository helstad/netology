#include <iostream>
#include "../dynamic_lib/Leaver.h"

int main() {
	std::string name;

	std::cout << "Enter you name: ";
	std::cin >> name;

	std::cout << Leaver::leave(name);
	return 0;
}