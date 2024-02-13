#include "Parser.hpp"

#include <iostream>

class MyParser : public INIp::Parser {
    void ParseKVPair(const std::string& section, const std::string& key, const std::string& value) {
        std::cout << "Section: " << section << " Key: " << key << " Value: " << value << std::endl;
    }
};

int main() {
    MyParser parser;
    parser.AddFile("./config.ini");
}