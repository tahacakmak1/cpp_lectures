#include <iostream>

template<typename T, typename U>
void func(T (*)(U)) {}

double foo(int) {
    return 5.;
}

void bar(double) {}

int main() {
    func(foo); // T will be deduced to double (*)(int). U will be deduced to int
    func(bar); // T will be deduced to void (*)(double). U will be deduced to double
}
