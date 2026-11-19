#include <iostream>

class Member {
public:
    Member() { std::cout << "Member ctor\n"; }

    ~Member() { std::cout << "Member dtor\n"; }
}; // class Member

class Myclass {
public:
    Myclass() {
        std::cout << "Myclass ctor\n";
        throw std::out_of_range{"error"};
    }

    ~Myclass() { std::cout << "Myclass ctor\n"; }

private:
    Member _x;
}; // class Myclass

void foo() { Myclass x; }

int main() {
    try {
        foo();
    }
    catch (std::exception const& ex) {
        std::cout << "exception caught in main: " << ex.what() << '\n';
    }
}
