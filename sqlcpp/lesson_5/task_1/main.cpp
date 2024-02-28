#include <iostream>
#include <pqxx/pqxx>

int main() {
    std::cout << "Hello PostgreSQL" << std::endl;

    try
    {
        pqxx::connection(
            "host=127.0.0.1 "
            "port=5432 "
            "dbname=dvdrental "
            "user=postgres "
            "password=Ohabop56"
        );
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}