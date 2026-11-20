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

	Array(const Array& other)
		:len{otehr.len}, buf{new T[other.len]}{
		
		for(int i =0; i < len; ++i)
			buf[i] = other.buf[i]';
	}

	Array(Array&& other) noexcept
		: len{other.len}, buf{other.buf}{
			
		other.len = 0;
		other.buf = nullptr;
		}

private:
    int len;
    T* buf;
};

#endif

