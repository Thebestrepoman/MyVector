#include <cstdint>
#include <iostream>

template <typename T>
class MyVector {
private:
    T *vector_ = nullptr;
    std::size_t size_ = 0;
    std::size_t mem_cap_ = 0;

public:
    MyVector() = default;

    ~MyVector() {
        delete[] vector_;
    }

    std::size_t Size() {
        return size_;
    }

    std::size_t Capacity() {
        return mem_cap_;
    }

    MyVector(const MyVector<T> &other) {
        size_ = other.size_;
        mem_cap_ = other.mem_cap_;
        vector_ = new T[mem_cap_];
        for (std::size_t i = 0; i < size_; ++i) {
            vector_[i] = other.vector_[i];
        }
    }

    MyVector &operator=(const MyVector &other) {
        delete[] vector_;
        size_ = other.size_;
        mem_cap_ = other.mem_cap_;
        vector_ = new T[mem_cap_];
        for (std::size_t i = 0; i < size_; ++i) {
            vector_[i] = other.vector_[i];
        }
        return *this;
    }

    T &operator[](const size_t i) {
        return vector_[i];
    }

    void reserve(int new_mem) {
        if (new_mem > mem_cap_) {
            mem_cap_ = new_mem;
            T *new_vector = new T[new_mem];
            for (size_t i = 0; i < size_; ++i) {
                new_vector[i] = vector_[i];
            }
            delete vector_;
            vector_ = new_vector;
        }
    }

    void pop_back() {
        size_--;
    }

    void push_back(T el) {
        if (size_ == mem_cap_) {
            if (mem_cap_ == 0) {
                this->reserve(1);
            } else {
                this->reserve(mem_cap_ * 2);
            }
        }
        vector_[size_] = el;
        size_++;
    }
};