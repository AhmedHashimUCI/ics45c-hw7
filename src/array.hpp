#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <utility>

template <typename T>
class Array {
public:
    Array() : len{0}, buf{nullptr} {
    }

    explicit Array(int len) : len{len}, buf{new T[len]} {
    }

    int length() const {
        return len;
    }

private:
    int len;
    T* buf;
};

#endif

