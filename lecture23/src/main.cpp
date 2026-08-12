// Lecture 23
#include "Audi.h"
#include "Mercedes.h"

#include <cstdint>
#include <iostream>

class Base {
public:
    virtual void vf();
};

class Der : private Base {
    void vf() override;
    // int _x;
}; // class Der

class Myclass {
    Base _y;
    // uint64_t _x;
};

int main() {
    std::cout << sizeof(car::ICar) << '\n';
    std::cout << sizeof(car::Audi) << '\n';
    std::cout << sizeof(int*) << '\n';
    std::cout << "sizeof(Base*) = " << sizeof(Base*) << '\n';
    std::cout << "sizeof(Der*) = " << sizeof(Der*) << '\n';
    std::cout << "sizeof(int) = " << sizeof(int) << '\n';
    std::cout << "sizeof(int*) = " << sizeof(int*) << '\n';
    std::cout << "sizeof(Base) = " << sizeof(Base) << '\n';
    std::cout << "sizeof(Der) = " << sizeof(Der) << '\n';
    std::cout << "sizeof(Myclass) = " << sizeof(Myclass) << '\n';
}
