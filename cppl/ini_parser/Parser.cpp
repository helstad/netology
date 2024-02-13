#include "Parser.hpp"

void INIp::Parser::AddFile(const std::filesystem::path& path) {
    std::ifstream fileIn(path, std::ios::binary | std::ios::in);
    if(!fileIn.is_open())
        throw Exception(std::format("Can't open file \"{}\"", path.string()));
    
    std::string fileData;
    fileIn.seekg(0, std::ios::end);
    fileData.resize((size_t)fileIn.tellg() + 1, '\0');
}