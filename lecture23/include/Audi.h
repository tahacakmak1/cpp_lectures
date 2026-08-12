#ifndef GUARD_B9E02025_B40D_4FF8_B69F_27DFAD9F8455
#define GUARD_B9E02025_B40D_4FF8_B69F_27DFAD9F8455

#include "ICar.h"

namespace car {

class Audi : public ICar {
public:
    void  start() override;
    void  run() override;
    void  stop() override;
    void  lock() override;
    Audi* clone() override;
    void  print(std::ostream& os) const override;
}; // class Audi
} // namespace car

#endif // GUARD_B9E02025_B40D_4FF8_B69F_27DFAD9F8455
