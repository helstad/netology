#pragma once

#ifndef LEAVER_EXPORTS
#define LEAVER_API __declspec(dllexport)
#else
#define LEAVER_API __declspec(dllimport)
#endif

#include <string>

class Leaver {
public:
    LEAVER_API static std::string leave(const std::string &name);
};