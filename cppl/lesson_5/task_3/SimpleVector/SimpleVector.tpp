template <typename T>
SimpleVector<T>::SimpleVector() : size_(0), capacity_(0), data_(nullptr) {}

template <typename T>
SimpleVector<T>::~SimpleVector() {
    delete[] data_;
}

template<typename T>
T& SimpleVector<T>::at(int index) {
    if (index < 0 || index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

template<typename T>
void SimpleVector<T>::push_back(const T &value) {
    if (size_ == capacity_) {
        capacity_ = (capacity_ == 0) ? 1 : capacity_ * 2;

        T* newData = new T[capacity_];

        for(int i = 0; i < size_; ++i) {
            newData[i] = data_[i];
        }

        delete[] data_;
        data_ = newData;
    }

    data_[size_] = value;
    ++size_;
}

template<typename T>
int SimpleVector<T>::size() const {
    return size_;
}

template<typename T>
int SimpleVector<T>::capacity() const {
    return capacity_;
}