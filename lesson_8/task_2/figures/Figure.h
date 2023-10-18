#ifndef TASK_3_FIGURE_H
#define TASK_3_FIGURE_H

#include <string>
#include <iostream>

class Figure {
protected:
    std::string name;

public:
    Figure(const std::string& figureName);
    virtual void print_info() const;
};

#endif