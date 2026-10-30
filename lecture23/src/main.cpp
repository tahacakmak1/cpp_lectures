// Lecture 23
#include "Audi.h"
#include "Mercedes.h"

#include <cstdint>
#include <iostream>
#include <random>

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
}; // class Myclass

struct Shape {
    virtual double      get_area() const          = 0;
    virtual double      get_circumference() const = 0;
    virtual std::string get_name() const          = 0;
}; // struct Shape

struct Circle : public Shape {
    Circle(double const& radius) : _r{radius} {}

    double get_area() const override { return PI * _r * _r; }

    double get_circumference() const override { return 2 * PI * _r; }

    std::string get_name() const override { return "Circle"; }

    static constexpr double PI = 3.1415926535;
    double                  _r;
}; // struct Circle

struct Rectangle : public Shape {
    Rectangle(double const& a, double const& b) : _a{a}, _b{b}, _isSquare(a == b) {}

    double get_area() const final override { return _a * _b; }

    double get_circumference() const final override { return 2 * (_a + _b); }

    std::string get_name() const override { return _isSquare ? "Square" : "Rectangle"; }

    double _a, _b;
    bool   _isSquare;
}; // struct Rectangle

Shape* create_random_shape() {
    std::random_device                     rd;
    std::mt19937                           gen(rd());
    std::uniform_int_distribution<int>     dist_int(1, 2);
    std::uniform_real_distribution<double> dist_real(1, 20);

    int number = dist_int(gen);
    switch (number) {
        case 1: {
            double r = dist_real(gen);
            return new Circle{r};
        }
        case 2: {
            double a = dist_real(gen), b = dist_real(gen);
            return new Rectangle{a, b};
        }
        default: {
            return nullptr;
        }
    }
}

class A {
public:
    A() { std::cout << "A ctor\n"; }
}; // class A

class B {
public:
    B() { std::cout << "B ctor\n"; }
}; // class B

class C
: public A
, public B {}; // class C

int main() {
    // std::cout << sizeof(car::ICar) << '\n';
    // std::cout << sizeof(car::Audi) << '\n';
    // std::cout << sizeof(int*) << '\n';
    // std::cout << "sizeof(Base*) = " << sizeof(Base*) << '\n';
    // std::cout << "sizeof(Der*) = " << sizeof(Der*) << '\n';
    // std::cout << "sizeof(int) = " << sizeof(int) << '\n';
    // std::cout << "sizeof(int*) = " << sizeof(int*) << '\n';
    // std::cout << "sizeof(Base) = " << sizeof(Base) << '\n';
    // std::cout << "sizeof(Der) = " << sizeof(Der) << '\n';
    // std::cout << "sizeof(Myclass) = " << sizeof(Myclass) << '\n';

    std::vector<Shape*> shapes;
    for (int i = 0; i < 5; i++) {
        shapes.push_back(create_random_shape());
    }
    Rectangle sq{5, 5};
    shapes.push_back(&sq);
    for (auto s : shapes) {
        std::cout << "This is a " << s->get_name() << ", it's area is " << s->get_area()
                  << ", it's circumference is " << s->get_circumference() << '\n';
    }
    C cx;
}
