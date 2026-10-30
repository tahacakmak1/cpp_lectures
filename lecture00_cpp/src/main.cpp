#include <iostream>

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

int main() {
    MDer myder;
    MDez mydez;
}
