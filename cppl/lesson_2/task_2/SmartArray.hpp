#pragma once


class SmartArray {
public:
    explicit SmartArray(size_t init_capacity);

    void add_element(int element);
    [[nodiscard]] int get_element(size_t index) const;

    SmartArray& operator=(const SmartArray& other);

    ~SmartArray();

private:
    int* data;
    size_t size;
    size_t capacity;

    void copy_data(const SmartArray& other);
};
