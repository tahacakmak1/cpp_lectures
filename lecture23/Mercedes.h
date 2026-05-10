#ifndef GUARD_BDF28EF0_812D_44D8_9A76_759F03993998
#define GUARD_BDF28EF0_812D_44D8_9A76_759F03993998

#include "ICar.h"

namespace car {

class Mercedes : public ICar {
public:
    void      start() override;
    void      run() override;
    void      lock() override;
    void      stop() override;
    Mercedes* clone() override;
    void      print(std::ostream& os) const override;
}; // class Mercedes
} // namespace car

#endif // GUARD_BDF28EF0_812D_44D8_9A76_759F03993998
