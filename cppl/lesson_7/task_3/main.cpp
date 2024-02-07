#include <iostream>
#include "UniquePtr.hpp"

int main() {
    UniquePtr<int> u_ptr(100);
    std::cout << *u_ptr << " " << &u_ptr << std::endl;

    UniquePtr<int> u_ptr_2(50);
    std::cout << *u_ptr_2 << " " << &u_ptr_2 << std::endl;

    int* u_ptr_raw = u_ptr.release();
    std::cout << *u_ptr_raw << " " << &u_ptr_raw << std::endl;

    delete u_ptr_raw;

    return 0;
}