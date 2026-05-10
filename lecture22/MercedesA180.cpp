#include "MercedesA180.h"

#include <iostream>

namespace car {

void MercedesA180::start() { std::cout << "MercedesA180::start()\n"; }

void MercedesA180::run() { std::cout << "MercedesA180::run()\n"; }

void MercedesA180::stop() { std::cout << "MercedesA180::stop()\n"; }

void MercedesA180::lock() { std::cout << "MercedesA180::lock()\n"; }

MercedesA180* MercedesA180::clone() { return new MercedesA180(*this); }

void MercedesA180::print(std::ostream& os) const { os << "This is a MercedesA180\n"; }
} // namespace car
