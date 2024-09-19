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
    // Default constructor: Creates an empty array
    Array() : array(NULL), _size(0) {}

    // Constructor with size n: Creates an array of n elements initialized by default
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

    // Destructor
    ~Array() {
        delete[] array;
    }

    // Subscript operator to access elements with bounds checking
    T& operator[](unsigned int index) {
        if (index >= _size) {
            throw std::out_of_range("Array index out of bounds");
        }
        return array[index];
    }

    // Const version of subscript operator
    const T& operator[](unsigned int index) const {
        if (index >= _size) {
            throw std::out_of_range("Array index out of bounds");
        }
        return array[index];
    }

    // Size function to return the number of elements in the array
    unsigned int size() const {
        return _size;
    }
};

#endif
