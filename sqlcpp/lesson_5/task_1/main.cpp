#include <iostream>
#include <pqxx/pqxx>

#include "DB/DB.hpp"

int main() {
  setlocale(LC_ALL, "Russian");

  pqxx::connection c;

  try {
    c = pqxx::connection("host=127.0.0.1 "
                       "port=5432 "
                       "dbname=pdb "
                       "user=postgres "
                       "password=pdb");

    if (!c.is_open()) {
      std::cerr << "Failed to connect to database" << std::endl;
      return 1;
    }

    DB db(c);

    std::cout << "Structure created successfully if not exist!" << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
    return 1;
  }

 

  return 0;
}
