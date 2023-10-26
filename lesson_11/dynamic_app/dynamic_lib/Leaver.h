#pragma once

#ifndef DYNAMICLIB_EXPORTS
#define DYNAMICLIB_API __declspec(dllexport)
#else
#define DYNAMICLIB_API __declspec(dllimport)
#endif

#include <string>

class Leaver {
public:
	DYNAMICLIB_API static std::string leave(const std::string& name);
};

