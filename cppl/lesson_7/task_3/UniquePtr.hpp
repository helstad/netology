#pragma once

template<typename T>
class UniquePtr {
public:
    explicit UniquePtr(T* p = nullptr);
    explicit UniquePtr(T value);
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;
    UniquePtr(UniquePtr&& other) noexcept;
    ~UniquePtr();

    T& operator*() const;
    T* release();
private:
    T* ptr;
};

#include "UniquePtr.tpp"