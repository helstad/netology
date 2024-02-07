#pragma once

template<typename T>
UniquePtr<T>::UniquePtr(T* p) : ptr(p) {}

template<typename T>
UniquePtr<T>::UniquePtr(T value) : ptr(new T(std::move(value))) {}

template<typename T>
UniquePtr<T>::UniquePtr(UniquePtr&& other) noexcept : ptr(other.ptr) {
    other.ptr = nullptr;
}

template<typename T>
UniquePtr<T>::~UniquePtr() {
    delete ptr;
}

template<typename T>
T& UniquePtr<T>::operator*() const {
    return *ptr;
}

template<typename T>
T* UniquePtr<T>::release() {
    T* temp = ptr;
    ptr = nullptr;
    return temp;
}