#pragma once

#include <stdexcept>

template <typename T>
class SimpleVector {
public:
    SimpleVector();
    ~SimpleVector();

    T& at(int index);
    void push_back(const T& value);
    [[nodiscard]] int size() const;
    [[nodiscard]] int capacity() const;

private:
    int size_{};
    int capacity_{};
    T* data_{};
};

#include "SimpleVector.tpp"