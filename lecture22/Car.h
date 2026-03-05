#ifndef GUARD_ED45D3BD_EA8B_4BE2_912B_AF36A9C23A2F
#define GUARD_ED45D3BD_EA8B_4BE2_912B_AF36A9C23A2F

#include <iosfwd>

namespace car {

class Car {
public:
    virtual void         start() = 0;
    virtual void         run()   = 0;
    virtual void         stop()  = 0;
    virtual void         lock()  = 0;
    virtual Car*         clone() = 0;
    friend std::ostream& operator<<(std::ostream& os, Car const& c);
    friend std::ostream& operator<<(std::ostream& os, Car const* cPtr);

private:
    virtual void print(std::ostream& os) const = 0;
}; // class Car

class Mercedes : public Car {
public:
    void      start() override;
    void      run() override;
    void      lock() override;
    void      stop() override;
    Mercedes* clone() override;
    void      print(std::ostream& os) const override;
}; // class Mercedes

class MercedesA180 : public Mercedes {
public:
    void          start() override;
    void          run() override;
    void          lock() override;
    void          stop() override;
    MercedesA180* clone() override;
    void          print(std::ostream& os) const override;
}; // class MercedesA180

class Audi : public Car {
public:
    void  start() override;
    void  run() override;
    void  lock() override;
    void  stop() override;
    Audi* clone() override;
    void  print(std::ostream& os) const override;
}; // class Audi

} // namespace car
#endif // GUARD_ED45D3BD_EA8B_4BE2_912B_AF36A9C23A2F
