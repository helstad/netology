#include "GeometryError.h"

GeometryError::GeometryError(const std::string &name, const std::string &message)
        : std::domain_error("Error creating figure " + name + ". Reason: " + message) {}