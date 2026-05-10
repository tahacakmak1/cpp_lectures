#ifndef GUARD_F2FE6C04_04F8_48D9_80B0_2BB158AEE178
#define GUARD_F2FE6C04_04F8_48D9_80B0_2BB158AEE178

#include "Mercedes.h"

namespace car {

class MercedesA180 : public Mercedes {
public:
    void          start() override;
    void          run() override;
    void          lock() override;
    void          stop() override;
    MercedesA180* clone() override;
    void          print(std::ostream& os) const override;
}; // class MercedesA180
} // namespace car
#endif // GUARD_F2FE6C04_04F8_48D9_80B0_2BB158AEE178
