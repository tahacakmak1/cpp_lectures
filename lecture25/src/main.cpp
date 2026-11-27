class Base {
public:
    virtual void foo() noexcept {}

    virtual void bar() noexcept {}

    virtual void baz() {}
};

class Der : public Base {
public:
    // void foo() override {} // INVALID

    void bar() noexcept override {} // VALID

    void baz() override {} // VALID
};

void func(Base& r) {
    r.foo();
    r.bar();
}

int main() {}
