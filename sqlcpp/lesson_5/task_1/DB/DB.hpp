#pragma once

#include <pqxx/pqxx>
#include <string>
#include <vector>

struct Client {
    std::string firstName;
    std::string lastName;
    std::string email;
    std::vector<std::string> phoneNumbers;
};

class DB {
public:
  DB(pqxx::connection &connection);

  void create_database_structure();
  void add_new_client(const Client& client);

private:
  pqxx::connection &m_connection;
};