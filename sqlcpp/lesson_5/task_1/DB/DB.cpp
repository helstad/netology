#include "DB.hpp"
#include <iostream>

DB::DB(pqxx::connection &connection) : m_connection(connection) {
  create_database_structure();
};

void DB::create_database_structure() {
  pqxx::work txn(m_connection);

  txn.exec(R"(
        CREATE TABLE IF NOT EXISTS Clients (
            client_id SERIAL PRIMARY KEY,
            first_name VARCHAR(50),
            last_name VARCHAR(50),
            email VARCHAR(100)
        );
    )");

  txn.exec(R"(
        CREATE TABLE IF NOT EXISTS Phones (
            phone_id SERIAL PRIMARY KEY,
            client_id INT,
            phone_number VARCHAR(20),
            FOREIGN KEY (client_id) REFERENCES Clients(client_id)
        );
    )");

  txn.commit();
}

void DB::add_new_client(const Client &client) {
  pqxx::work txn(m_connection);

  pqxx::result result =
      txn.exec_params("INSERT INTO Clients (first_name, last_name, email) "
                      "VALUES ($1, $2, $3) RETURNING client_id",
                      client.firstName, client.lastName, client.email);

  int clinet_id = result[0][0].as<int>();

  for (const std::string &phoneNumber : client.phoneNumbers) {
    txn.exec_params(
        "INSERT INTO Phones (client_id, phone_number) VALUES ($1, $2)",
        clinet_id, phoneNumber);
  }

  txn.commit();
}