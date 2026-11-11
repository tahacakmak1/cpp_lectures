#include <iostream>

class Resource {
public:
    Resource(int val) : _x{val} { std::cout << "Resource acquired, _x = " << _x << '\n'; }

    ~Resource() { std::cout << "Resource released, _x = " << _x << '\n'; }

private:
    int _x;
}; // class Resource

void f4() {
    Resource r{4};
    throw 1;
}

void f3() {
    Resource r{3};
    f4();
}

void f2() {
    Resource r{2};
    f3();
}

void f1() {
    Resource r{1};
    f2();
}

int main() {
    Resource* ptr = new Resource{5};
    try {
        f1();
    }
    catch (int const&) {
        std::cout << "Exception caught\n";
    }
    delete ptr;
    std::cout << "Main continues\n";
}
