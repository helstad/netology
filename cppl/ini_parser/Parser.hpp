#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <stdexcept>

class Parser {
public:
    explicit Parser(const std::string &filename);

    template<typename T>
    T get_value(const std::string &variable_name) const;

private:
    struct variable {
        std::string name;
        std::string value;
    };

    struct section {
        std::string name;
        std::unordered_map<std::string, variable> variables;
    };

    std::unordered_map<std::string, section> sections;
    std::string current_section;

    void parse_file(const std::string &filename);

    void parse_line(const std::string &line, int line_number);
};

#include "Parser.tpp"