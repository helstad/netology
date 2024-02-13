#include <fstream>
#include <sstream>
#include <algorithm>

Parser::Parser(const std::string& filename) {
    parse_file(filename);
}

void Parser::parse_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    std::string line;
    int line_number = 0;
    while (std::getline(file, line)) {
        ++line_number;
        parse_line(line, line_number);
    }
}

void Parser::parse_line(const std::string& line, int line_number) {
    std::string trimmed_line = line.substr(0, line.find(';'));
    trimmed_line.erase(std::remove_if(trimmed_line.begin(), trimmed_line.end(), ::isspace), trimmed_line.end());
    if (trimmed_line.empty()) return;

    if (trimmed_line.front() == '[' && trimmed_line.back() == ']') {
        current_section = trimmed_line.substr(1, trimmed_line.size() - 2);
        sections[current_section];
    } else if (trimmed_line.find('=') != std::string::npos) {
        if (current_section.empty()) {
            throw std::runtime_error("Variable found outside of a section at line: " + std::to_string(line_number));
        }
        std::istringstream iss(trimmed_line);
        std::string var_name, var_value;
        std::getline(iss, var_name, '=');
        std::getline(iss, var_value);
        sections[current_section].variables[var_name].name = var_name;
        sections[current_section].variables[var_name].value = var_value;
    } else {
        throw std::runtime_error("Invalid syntax at line: " + std::to_string(line_number));
    }
}

template<typename T>
T Parser::get_value(const std::string& variable_name) const {
    std::size_t dot_pos = variable_name.find('.');
    if (dot_pos == std::string::npos) {
        throw std::invalid_argument("Invalid variable name format");
    }

    std::string section_name = variable_name.substr(0, dot_pos);
    std::string var_name = variable_name.substr(dot_pos + 1);

    auto section_it = sections.find(section_name);
    if (section_it == sections.end()) {
        throw std::invalid_argument("Section not found: " + section_name);
    }

    const auto& variables = section_it->second.variables;
    auto var_it = variables.find(var_name);
    if (var_it == variables.end()) {
        std::string available_vars;
        for (const auto& [name, _] : variables) {
            available_vars += name + ", ";
        }
        if (!available_vars.empty()) {
            available_vars.pop_back();
            available_vars.pop_back();
        }
        throw std::invalid_argument("Variable not found: " + var_name + ". Available variables: " + available_vars);
    }

    T value;
    std::istringstream(var_it->second.value) >> value;
    return value;
}