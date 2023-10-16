#include "GeometryError.h"

GeometryError::GeometryError(const std::string &message)
        : std::domain_error("Error creating figure. Reason: " + message) {}