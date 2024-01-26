#include <iostream>
#include <vector>

template<typename T>
class Table {
public:
    Table(int rows, int cols)
            : rows_(rows), cols_(cols), data_(new T*[rows]) {
        for (int i = 0; i < rows; ++i) {
            data_[i] = new T[cols];
        }
    }

    ~Table() {
        for (int i = 0; i < rows_; ++i) {
            delete[] data_[i];
        }
        delete[] data_;
    }

    T* operator[](int row) {
        return data_[row];
    }

    const T* operator[](int row) const {
        return data_[row];
    }

    [[nodiscard]] std::pair<int, int> Size() const {
        return {rows_, cols_};
    }

private:
    int rows_{};
    int cols_{};
    T** data_ = nullptr;
};

int main() {
    Table<int> table_1(2, 3);
    table_1[0][0] = 4;
    std::cout << table_1[0][0] << std::endl;

    auto size = table_1.Size();
    std::cout << "Rows: " << size.first << ", Columns: " << size.second << std::endl;
    return 0;
}
