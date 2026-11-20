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
	
	friend void swap(Array& lhs, Array& rhs) noexcept {
    	std::swap(lhs.len, rhs.len);
    	std::swap(lhs.buf, rhs.buf);
	}

	Array& operator=(const Array& other){
		Array temp{other};
		swap(*this, temp);
		return *this;

	}

	Array& operator=(Array&& other) noexcept{
		Array temp{std::move(other)};
		swap(*this, temp);
		returm *this;
	

	}

private:
    int len;
    T* buf;
};

#endif

