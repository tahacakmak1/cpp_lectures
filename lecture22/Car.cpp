#include "Car.h"

#include <iostream>

namespace car {

std::ostream& operator<<(std::ostream& os, Car const& c) {
    c.print(os);
    return os;
}

std::ostream& operator<<(std::ostream& os, Car const* cPtr) {
    cPtr->print(os);
    return os;
}

void Mercedes::start() { std::cout << "Mercedes::start()\n"; }

void Mercedes::run() { std::cout << "Mercedes::run()\n"; }

void Mercedes::stop() { std::cout << "Mercedes::stop()\n"; }

void Mercedes::lock() { std::cout << "Mercedes::lock()\n"; }

void Mercedes::print(std::ostream& os) const { os << "This is a Mercedes\n"; }

Mercedes* Mercedes::clone() { return new Mercedes(*this); }

void MercedesA180::start() { std::cout << "MercedesA180::start()\n"; }

void MercedesA180::run() { std::cout << "MercedesA180::run()\n"; }

void MercedesA180::stop() { std::cout << "MercedesA180::stop()\n"; }

void MercedesA180::lock() { std::cout << "MercedesA180::lock()\n"; }

MercedesA180* MercedesA180::clone() { return new MercedesA180(*this); }

void MercedesA180::print(std::ostream& os) const { os << "This is a MercedesA180\n"; }

void Audi::start() { std::cout << "Audi::start()\n"; }

void Audi::run() { std::cout << "Audi::run()\n"; }

void Audi::lock() { std::cout << "Audi::lock()\n"; }

void Audi::stop() { std::cout << "Audi::stop()\n"; }

Audi* Audi::clone() { return new Audi(*this); }

void Audi::print(std::ostream& os) const { os << "This is a Audi\n"; }

} // namespace car
