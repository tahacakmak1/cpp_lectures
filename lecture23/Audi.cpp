#include "Audi.h"

#include <iostream>

namespace car {

void Audi::start() { std::cout << "Audi::start()\n"; }

void Audi::run() { std::cout << "Audi::run()\n"; }

void Audi::lock() { std::cout << "Audi::lock()\n"; }

void Audi::stop() { std::cout << "Audi::stop()\n"; }

Audi* Audi::clone() {
    std::cout << "Audi::clone()\n";
    return new Audi(*this);
}

void Audi::print(std::ostream& os) const { os << "This is an Audi\n"; }
} // namespace car
