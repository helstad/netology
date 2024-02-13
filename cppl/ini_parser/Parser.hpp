#pragma once

#include <string>
#include <string_view>
#include <fstream>
#include <filesystem>
#include <stdexcept>
#include <format>
#include <cctype>

namespace INIp {
    class Exception : public std::runtime_error {
        public:
            using std::runtime_error::runtime_error;
    };

    class Parser {
        public:
            void AddFile(const std::filesystem::path& path);
            void AddString(const std::string_view& str);
            void Reset();

            virtual void ParseKVPair(const std::string& section, const std::string& key, const std::string& value) = 0;

        private:
            void ProcessChar(char c);

        private:
            enum class State {
                ReadForData,
                Comment,
                Section,
                KVKey,
                KVKeyDone,
                KVEqual,
                KVValue,
            };

        private:
            State m_state = State::ReadForData;
            std::string m_currentSection, m_currentKey, m_currentValue;
    };
}