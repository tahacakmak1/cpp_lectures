#include <iostream>

void func() { throw std::out_of_range{"out of range error"}; }

void foo() {
    try {
        func();
    }
    catch (std::out_of_range const& ex) {
        std::cout << "Exception caught in foo: " << ex.what() << '\n';
        std::cout << &ex << '\n';
        throw;
    }
}

int main() {
    try {
        foo();
    }
    catch (std::out_of_range const& ex) {
        std::cout << "Exception caught in main: " << ex.what() << '\n';
        std::cout << &ex << '\n';
    }
}
