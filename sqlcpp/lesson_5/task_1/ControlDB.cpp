#include "ControlDB.hpp"
#include <iostream>
#include <pqxx/pqxx>
#include <format>

ControlDB::ControlDB(const std::string &conn) : m_connection{conn} {
  m_connection.prepare("insert_client",
                       "INSERT INTO clients (name, surname, email) VALUES($1, "
                       "$2, $3) RETURNING id");
  m_connection.prepare("insert_phone",
                       "INSERT INTO phones (client_id, phone) VALUES($1, $2)");

  m_connection.prepare(
      "update_client",
      "UPDATE clients SET name = $1, surname = $2, email = $3 WHERE id = $4");
  m_connection.prepare("update_phone",
                       "UPDATE phones SET phone = $1 WHERE client_id = $2");

  m_connection.prepare("delete_phone",
                       "DELETE FROM phones WHERE client_id = $1");
  m_connection.prepare("delete_client", "DELETE FROM clients WHERE id = $1");
};

void ControlDB::CreateStructureDB() {
  try {
    pqxx::work tx{m_connection};

    tx.exec(R"(
      CREATE TABLE IF NOT EXISTS clients (
        id SERIAL PRIMARY KEY,
        name VARCHAR(255) NOT NULL,
        surname VARCHAR(255) NOT NULL,
        email VARCHAR(255) NOT NULL UNIQUE
      );
      CREATE TABLE IF NOT EXISTS phones (
        id SERIAL PRIMARY KEY,
        client_id INTEGER NOT NULL REFERENCES clients(id),
        phone VARCHAR(255) UNIQUE
      );
    )");
    std::cout << "Tables created" << std::endl;

    tx.commit();
    std::cout << "Transaction committed" << std::endl;
  } catch (const pqxx::sql_error &e) {
    std::cerr << e.what() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown error" << std::endl;
  }
  std::cout << "Database created" << std::endl;
}

void ControlDB::AddClient(const std::string &name, const std::string &surname,
                          const std::string &email, const std::string &phone) {
  try {
    pqxx::work tx{m_connection};
    pqxx::result result =
        tx.exec_prepared("insert_client", name, surname, email);

    int id = result[0][0].as<int>();

    tx.exec_prepared("insert_phone", id, phone);
    tx.commit();
  } catch (pqxx::sql_error e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "Client " << name << " successfully added!" << std::endl;
}

void ControlDB::AddPhone(int id, const std::string &phone) {
  try {
    pqxx::work tx{m_connection};

    tx.exec_prepared("insert_phone", id, phone);
    tx.commit();
  } catch (pqxx::sql_error e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "The phone number for the client(" << id
            << ") has been successfully added!" << std::endl;
}
void ControlDB::EditClient(const std::string &name, const std::string &surname,
                           const std::string &email, const std::string &phone,
                           int id) {
  try {
    pqxx::work tx{m_connection};

    tx.exec_prepared("update_client", name, surname, email, id);
    tx.exec_prepared("update_phone", phone, id);
    tx.commit();
  } catch (pqxx::sql_error e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "The data for the client(" << id
            << ") has been successfully changed!" << std::endl;
}
void ControlDB::DeletePhone(int id) {
  try {
    pqxx::work tx{m_connection};

    tx.exec_prepared("delete_phone", id);
    tx.commit();
  } catch (pqxx::sql_error e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "The client's phone(" << id << ") has been successfully deleted!"
            << std::endl;
}
void ControlDB::DeleteClient(int id) {
  try {
    pqxx::work tx{m_connection};

    tx.exec_prepared("delete_phone", id);
    tx.exec_prepared("delete_client", id);
    tx.commit();
  } catch (pqxx::sql_error e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "Clients(" << id << ") successfully deleted!" << std::endl;
}

#include <format> // Для использования std::format

void ControlDB::FindClient(const int id, const std::string& name,
                           const std::string& surname, const std::string& email,
                           const std::string& phone) {
  try {
    pqxx::work tx{m_connection};

    std::string query = "SELECT name, surname, email FROM clients WHERE 1=1 ";

    // Если не указан id, выполняем поиск только по остальным параметрам
    if (id != 0) {
      query += std::format("AND id = {}", id);
    }
    if (!name.empty()) {
      query += std::format(" AND name = '{}'", tx.esc(name));
    }
    if (!surname.empty()) {
      query += std::format(" AND surname = '{}'", tx.esc(surname));
    }
    if (!email.empty()) {
      query += std::format(" AND email = '{}'", tx.esc(email));
    }

    query += ";";

    for (auto [name, surname, email] :
         tx.query<std::string, std::string, std::string>(query)) {
      std::cout << "Client by parameters(" << name << ", " << surname << ", "
                << email << ") found!" << std::endl;
    }

    // Теперь выполняем поиск по номеру телефона только если он указан
    if (!phone.empty()) {
      std::string phone_query =
          std::format("SELECT client_id, phone FROM phones WHERE phone = '{}'", tx.esc(phone));

      for (auto [id, phone] : tx.query<int, std::string>(phone_query)) {
        std::cout << "Client phone by parameters(" << id << ", " << phone
                  << ") found!" << std::endl;
      }
    }

  } catch (const pqxx::sql_error& e) {
    std::cout << "Error: " << e.what() << std::endl;
  }
}
