#pragma once

#include <string>
#include <string_view>
#include <fstream>
#include <filesystem>
#include <stdexcept>
#include <format>

namespace INIp {
    class Exception : public std::runtime_error {
        public:
            using std::runtime_error::runtime_error;
    };

    class Parser {
        public:
            void AddFile(const std::filesystem::path& path);
            void AddString(const std::string_view& str);

        private:
    };
}