#include <vector>
#pragma once

template <class T>
class Allocator {
    public:
        using value_type = T;
        using pointer = T*;
        using const_pointer = const T*;
        using size_type = std::size_t;

        Allocator() noexcept {}

        T* allocate(size_t n) {
            T* new_pointer = new T[n];

            if (new_pointer) {
                used_blocks.push_back(new_pointer);
                return new_pointer;
            }

            throw std::bad_alloc();
        }

        void deallocate(T* block, size_type n) {
            std::remove(used_blocks.begin(), used_blocks.end(), block);
            delete[] block;
        }

        ~Allocator() {
            for (T* block : used_blocks) {
                delete[] block;
            }
        }

    private:    
        std::vector<T*> used_blocks;
};


