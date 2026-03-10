#include <cstdint>
#include <iostream>

// class Myclass {
// public:
//     static int foo() { return 777; }

//     static int _x;
// }; // class Myclass

int foo() { return 5; }

class Myclass {
public:
    static inline int _x = foo(); // INVALID, it would be VALID if foo were to be defined before _x.

    static int foo() { return 5; }
}; // class Myclass

int main(){}
