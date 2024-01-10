#include <stdexcept>
#include <iostream>
#include "SmartArray.hpp"

SmartArray::SmartArray(size_t init_capacity)
    : data(new int[init_capacity]), size(0), capacity(init_capacity) {}

void SmartArray::add_element(int element) {
    if (size < capacity) {
        data[size++] = element;
    } else {
        throw std::out_of_range("The capacity of the array has been exceeded");
    }
}

int SmartArray::get_element(size_t index) const {
    if (index < size) {
        return data[index];
    } else {
        throw std::out_of_range("Index out of range");
    }
}

void SmartArray::copy_data(const SmartArray& other) {
    capacity = other.capacity;
    size = other.size;
    data = new int[capacity];
    std::copy(other.data, other.data + size, data);
}

SmartArray& SmartArray::operator=(const SmartArray& other) {
    if (this != &other) {
        delete[] data;
        copy_data(other);
    }
    return *this;
}

SmartArray::~SmartArray() {
    delete[] data;
}
