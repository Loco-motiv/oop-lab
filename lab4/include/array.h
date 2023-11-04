#pragma once

#include "figure.h"
#include <memory>

template <class T>
class Array {
public:

    Array() : _size(0), _array{nullptr} {}

    Array(const std::initializer_list<T> &t)
    {
        _array = std::shared_ptr<T[]>(new T[t.size()]);
        int i = 0;
        for (auto &c : t)
            _array[i++] = c;
        _size = t.size();
    }

    double totalArea() const {
        double total = 0.0;
        for (int i = 0; i < _size; ++i){
            total += _array[i]->operator double();
        }
        return total;
    }

    void remove(int index) {
        if (index < _size) {
            std::shared_ptr<T[]> newArray(new T[_size - 1]);
            for (int i = 0; i < index; ++i) {
                newArray[i] = _array[i];
            }
            for (int i = index + 1; i < _size; ++i) {
                newArray[i - 1] = _array[i];
            }
            _array = newArray;
            _size--;
        }
    }

    T& operator[](size_t index){
        return _array[index];
    }

    int size() const{
        return _size;
    }

private:
    int _size;
    std::shared_ptr<T[]> _array;
};