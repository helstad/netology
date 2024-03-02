#pragma once

#include <pqxx/pqxx>

class ControlDB {
public:
  ControlDB(const std::string &conn);
  ControlDB() = delete;

  void CreateStructureDB();
  void AddClient(const std::string &name, const std::string &surname,
                 const std::string &email, const std::string &phone);
  void AddPhone(const int id, const std::string &phone);
  void EditClient(const std::string &name, const std::string &surname,
                  const std::string &email, const std::string &phone,
                  const int id);
  void DeletePhone(const int id);
  void DeleteClient(const int id);
  void FindClient(const int id, const std::string &name,
                  const std::string &surname, const std::string &email,
                  const std::string &phone);

private:
  pqxx::connection m_connection;
};