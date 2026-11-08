// Lecture 24
#include <iostream>

void f3() {
    try {
        throw 10;
    }
    catch (double const&) {
        std::cout << "Exception caught in f3(), catch(double const&)\n";
    }
}

void f2() {
    try {
        f3();
    }
    catch (float const&) {
        std::cout << "Exception caught in f2(), catch(float const&)\n";
    }
}

void f1() {
    try {
        f2();
    }
    catch (...) {
        std::cout << "Exception caught in f1(), catch(...)\n";
    }
}

void myabort() {
    std::cout << "myabort() is called\n";
    std::exit(EXIT_FAILURE);
}

int main() {
    std::set_terminate(myabort);
    f1();
}
