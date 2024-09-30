#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>

template <typename T>
class Array {
private:
    T* array;
    unsigned int _size;

public:
    Array() : array(NULL), _size(0) {}

    Array(unsigned int n) : array(new T[n]()), _size(n) {}

    // Copy constructor
    Array(const Array& other) : array(NULL), _size(0) {
        *this = other;
    }

    // Assignment operator
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] array;
            _size = other._size;
            array = new T[_size];
            for (unsigned int i = 0; i < _size; i++) {
                array[i] = other.array[i];
            }
        }
        return *this;
    }

    ~Array() {
        delete[] array;
    }

    T& operator[](unsigned int index) {
        if (index >= _size) {
            throw std::out_of_range("Array index out of bounds");
        }
        return array[index];
    }

    const T& operator[](unsigned int index) const {
        if (index >= _size) {
            throw std::out_of_range("Array index out of bounds");
        }
        return array[index];
    }

    unsigned int size() const {
        return _size;
    }
};

#endif
