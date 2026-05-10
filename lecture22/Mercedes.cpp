#include "Mercedes.h"

#include <iostream>

namespace car {

void Mercedes::start() { std::cout << "Mercedes::start()\n"; }

void Mercedes::run() { std::cout << "Mercedes::run()\n"; }

void Mercedes::stop() { std::cout << "Mercedes::stop()\n"; }

void Mercedes::lock() { std::cout << "Mercedes::lock()\n"; }

void Mercedes::print(std::ostream& os) const { os << "This is a Mercedes\n"; }

Mercedes* Mercedes::clone() { return new Mercedes(*this); }
} // namespace car
