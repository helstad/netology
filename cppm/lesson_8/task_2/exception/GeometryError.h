#ifndef TASK_2_GEOMETRYERROR_H
#define TASK_2_GEOMETRYERROR_H

#include <stdexcept>
#include <string>

class GeometryError : public std::domain_error {
public:
    GeometryError(const std::string& name, const std::string& message);
};

#endif //TASK_2_GEOMETRYERROR_H
