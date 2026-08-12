#ifndef GUARD_ED45D3BD_EA8B_4BE2_912B_AF36A9C23A2F
#define GUARD_ED45D3BD_EA8B_4BE2_912B_AF36A9C23A2F

#include <iosfwd>

namespace car {

class ICar {
public:
    virtual void  start()                       = 0;
    virtual void  run()                         = 0;
    virtual void  stop()                        = 0;
    virtual void  lock()                        = 0;
    virtual ICar* clone()                       = 0;
    virtual void  print(std::ostream& os) const = 0;

    friend std::ostream& operator<<(std::ostream& os, ICar const& c) {
        c.print(os);
        return os;
    }

    friend std::ostream& operator<<(std::ostream& os, ICar const* cPtr) {
        cPtr->print(os);
        return os;
    }

}; // class ICar
} // namespace car
#endif // GUARD_ED45D3BD_EA8B_4BE2_912B_AF36A9C23A2F
