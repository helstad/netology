#include "ControlDB.hpp"
#include <iostream>
#include <string>

int main() {
  setlocale(LC_ALL, "Russian");
  std::string name, surname, email, phone;
  int id, command;

  std::string query{R"(
      host=localhost
      port=5432
      dbname=pdb
      user=postgres
      password=pdb
  )"};

  ControlDB db(query);

  while (true) {
    std::cout << "Welcome" << std::endl;
    std::cout << "Choose one of the options: " << std::endl;
    std::cout << "1. Create a database" << std::endl;
    std::cout << "2. Add a client to the database" << std::endl;
    std::cout << "3. Add a phone to an existing client" << std::endl;
    std::cout << "4. Change client data" << std::endl;
    std::cout << "5. Delete a phone for an existing client" << std::endl;
    std::cout << "6. Remove a client from the database" << std::endl;
    std::cout << "7. Find a client by parameters" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cin >> command;
    std::cin.ignore();

    switch (command) {
    case 1:
      db.CreateStructureDB();
      break;

    case 2:
      std::cout << "Enter the client's name: ";
      std::cin >> name;
      std::cout << "Enter the client's surname: ";
      std::cin >> surname;
      std::cout << "Enter the client's email: ";
      std::cin >> email;
      std::cout << "Enter the client's phone: ";
      std::cin >> phone;
      std::cin.ignore();

      db.AddClient(name, surname, email, phone);
      break;

    case 3:
      std::cout << "Enter the client's client_id: ";
      std::cin >> id;
      std::cout << "Enter the client's phone: ";
      std::cin >> phone;
      std::cin.ignore();

      db.AddPhone(id, phone);
      break;

    case 4:
      std::cout << "Enter the client's name: ";
      std::cin >> name;
      std::cout << "Enter the client's surname: ";
      std::cin >> surname;
      std::cout << "Enter the client's email: ";
      std::cin >> email;
      std::cout << "Enter the client's client_id: ";
      std::cin >> id;
      std::cout << "Enter the client's phone: ";
      std::cin >> phone;
      std::cin.ignore();

      db.EditClient(name, surname, email, phone, id);
      break;

    case 5:
      std::cout << "Enter the client's client_id: ";
      std::cin >> id;
      std::cin.ignore();

      db.DeletePhone(id);
      break;

    case 6:
      std::cout << "Enter the client's client_id: ";
      std::cin >> id;
      std::cin.ignore();

      db.DeleteClient(id);
      break;

    case 7:
      std::cout << "Enter the client's client_id (if dont know enter 0): ";
      std::cin >> id;
      std::cin.ignore();

      std::cout << "Enter the client's name (or press enter): ";
      std::getline(std::cin, name);

      std::cout << "Enter the client's surname (or press enter): ";
      std::getline(std::cin, surname);

      std::cout << "Enter the client's email (or press enter): ";
      std::getline(std::cin, email);

      std::cout << "Enter the client's phone (or press enter): ";
      std::getline(std::cin, phone);

      db.FindClient(id, name, surname, email, phone);
      break;
    case 0:
      std::cout << "Exiting..." << std::endl;
      return 0;
    default:
      std::cout << "Invalid command. Please try again." << std::endl;
      break;
    }
    std::cout << std::endl;
  }

  return 0;
}
