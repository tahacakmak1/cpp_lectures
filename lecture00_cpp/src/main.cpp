#include <iostream>
#include <cstddef>
#include <new>
#include <type_traits>

class Base {
public:
    Base(char const* c) { std::cout << "Base(char const* c), c = " << c << '\n'; }
}; // class Base

class Der1 : virtual public Base {
public:
    Der1() : Base("Der1") {}
}; // class Der1

class Der2 : virtual public Base {
public:
    Der2() : Base("Der2") {}
}; // class Der2

class MDer
: public Der1
, public Der2 {
public:
    MDer() : Base("MDer") {}
}; // class MDer

class MDez : public MDer {
public:
    MDez() : Base("MDez") {}
}; // class MDez

// int main() {
//     MDer myder;
//     MDez mydez;
// }

template<class T, std::size_t N>
struct vec
{
    vec() : _size(0U) {}

    std::size_t size() const
    {
        return _size;
    }

    void push_back(T value)
    {
        _storage[sizeof(T) * _size] = value;
        // new (&_storage[sizeof(T) * _size]) T(value);
        ++_size;
    }

    T& operator [] (std::size_t index)
    {
        return *reinterpret_cast<T*>(&_storage[index * sizeof(T)]);
    }

    alignas(T) std::byte _storage[sizeof(T) * N];
    std::size_t _size;
};

struct A {
    A(int8_t val) : _x{val} {}

    operator std::byte() const {
        return static_cast<std::byte>(_x);
    }

    friend std::ostream& operator<<(std::ostream& out, A const& val) {
        out << static_cast<int16_t>(val._x);
        return out;
    }
private:
    int8_t _x;
}; // struct A

int main() {
    vec<A, 5> vector;
    for(int8_t i = 0; i < 5; i++)
    {
        vector.push_back(i);
    }
    for(int i = 0; i < 5; i++)
    {
        std::cout << vector[i] << '\n';
    }
}
