#include "Parser.hpp"

#include <iostream>

int main() {
    INIp::Parser parser;
    parser.AddFile("./config.ini");
    
    std::cout << "Hello world!" << std::endl;
}