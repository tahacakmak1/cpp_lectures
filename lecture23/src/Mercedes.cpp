#include "Mercedes.h"

#include <iostream>

namespace car {

void Mercedes::start() { std::cout << "Mercedes::start()\n"; }

void Mercedes::run() { std::cout << "Mercedes::run()\n"; }

void Mercedes::stop() { std::cout << "Mercedes::stop()\n"; }

void Mercedes::lock() { std::cout << "Mercedes::lock()\n"; }

Mercedes* Mercedes::clone() {
    std::cout << "Mercedes::clone()\n";
    return new Mercedes(*this);
}

void Mercedes::print(std::ostream& os) const { os << "This is a Mercedes\n"; }
} // namespace car
