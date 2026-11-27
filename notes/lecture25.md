# Lecture 25

## Exception Handling

### Rethrow Statement

```cpp
#include <iostream>

void func() { throw std::out_of_range{"out of range error"}; }

void foo() {
    try {
        func();
    }
    catch (std::out_of_range const& ex) {
        std::cout << "Exception caught in foo: " << ex.what() << '\n';
        std::cout << "&ex = " << &ex << '\n';
        throw;
    }
}

int main() {
    try {
        foo();
    }
    catch (std::out_of_range const& ex) {
        std::cout << "Exception caught in main: " << ex.what() << '\n';
        std::cout << "&ex = " << &ex << '\n';
    }
}
```

The above code snippet will have the following output

> Exception caught in foo: out of range error  
> &ex = 0x62c29e1cd330  
> Exception caught in main: out of range error  
> &ex = 0x62c29e1cd330

#### Why `throw` Instead of `throw expr`?

1. As stated before, when an exception is thrown, an exception object is created by the compiler. By
   using `throw` that very same object is thrown again. Not a copy of it, directly itself. This
   saves a call to copy constructor.

2. Using `throw expr` might cause object slicing, which may result in loss of information about the
   exception.

#### Some Important Reminders for Rethrow Statements

- It does not have to be in a `catch` block, i.e

  ```cpp
  void bar() {
    throw 1;
  }

  void foo() {
    try {
        bar();
    }
    catch (int const&) {
        //.. code goes here
        throw;
    }
  }
  ```

  is a valid code snippet.

- If the rethrow statement does not have an exception object passed onto it, `std::abort()` will be
  called. e.g.

  ```cpp
  #include <iostream>

  void foo() { throw; }

  void myabort() { std::cout << "myabort() is called\n"; }

  int main() {
      std::set_terminate(&myabort);
      foo();
  }
  ```

  is a valid code snippet and will have the following output

  > myabort() is called  
  > Aborted

### Exception Dispatcher Idiom

```cpp
class Myexception1 {};1

class Myexception2 {};2

class Myexception3 {};3

void handle_exception() {
    try {
        throw;
    }
    catch (Myexception1& e) {
    }
    catch (Myexception2& e) {
    }
    catch (Myexception3& e) {
    }
}

void func() {
    try {
        // exception happens here
    }
    catch (...) {
        handle_exception();
    }
}

int main() { func(); }
```

What happens if the exception thrown in `func()` is not one of the types in `handle_exception()`
catch block? Assuming these are the only `catch` blocks this exception can be caught at, it will be
an uncaught exception. Depending on the `set_terminate()`, `std::abort()` may be called.

The advantage of this idiom is all the exception handling is done in the same place. It also reduces
repetition.

### Constructors and Exceptions

When a constructor fails to create an object it must return an exception. If it doesn't, the object
is created but not actually. These objects are called Zombie Objects.

```cpp
#include <iostream>
#include <stdexcept>

class Myclass {
public:
    Myclass() {
        if (true) {
            throw std::runtime_error{"Myclass exception"};
        }
    }

    ~Myclass() {
        std::cout << "~Myclass()\n";
    }
};

void foo() { Myclass x; }

int main() {
    try {
        foo();
    }
    catch (std::exception const& ex) {
        std::cout << "exception caught in main: " << ex.what() << '\n';
    }
}
```

##### ###QUESTION.2###

> In the above code snippet, will the destructor of the `Myclass` be called for `x`?
> No it won't, because in C++ for an object to exist, it's constructor must reach it's closign
> brace. Because of this, there isn't an object to call it's destructor. There is an important
> detail about this, resources acquired in the constructor before the exception will not be freed
> bescause the destructor won't be called due to the exception. This will create a resource leak.

```cpp
#include <iostream>

class Member {
public:
    Member() {
        std::cout << "Member ctor\n";
        throw std::out_of_range{"error"};
    }

    ~Member() { std::cout << "Member dtor\n"; }
};

class Myclass {
public:
    Myclass() { std::cout << "Myclass ctor\n"; }

    ~Myclass() { std::cout << "Myclass ctor\n"; }

private:
    Member _x;
};

void foo() { Myclass x; }

int main() {
    try {
        foo();
    }
    catch (std::exception const& ex) {
        std::cout << "exception caught in main: " << ex.what() << '\n';
    }
}
```

In the above code snippet due to the exception in `Member` constructor, `_x` of `Myclass` won't be
created, because of that `x` in `foo()` also won't be created. Since they are not created, their
destructors won't be called. Therefore, it will have the following output

> Member ctor  
> exception caught in main: error

If the exception were to be thrown in the constructor of `Myclass`, then the `Member`'s constructor
would have been successful therefore it's destructor would be called. But since the `Myclass`
constructor threw an exception, it's object won't be created and it's destructor won't be called.
The output of that scenario would be the following

> Member ctor  
> Myclass ctor  
> Member dtor  
> exception caught in main: error

##### ###REMARK.134###

> In a scenario where the constructor threw an exception during the creation of a dynamic object,
> when the `delete` is used on it's pointer the destructor won't be called but the
> `operator delete()` will be called.

### Destructors and Exceptions

Under no circumstances destructors shall send exceptions.

There is a difference between the terms

- Throw an exception
- Send an exception

```cpp
void func() {
    try {
        throw expr;
    }
    catch (...) {
        //.. code goes here
    }
}
```

In the above code snippet, does the `func()` throw an exception, yes it does. Does the exception
leave the scope of `func()`, no it does not. This is the difference between throwing and sending an
exception. Sending an exception is also called emitting an exception or propagating an exception.

If a destructor called during the stack unwinding throws an exception, `std::terminate()` is called.
This is the reason why destructors should never emit (propagate) exceptions.  
Destructors can throw an exception, but the exception must be handled locally in the destructor.

### `noexcept` Keyword

This is one of the most confused parts in modernd C++. It can be used both as a specifier and an
operator. The confusement arises due to both having diffrent rules.

#### `noexcept` Specifier

It guarantees that the function it specifies won't throw exceptions.

```cpp
// no-throw guarantee
void func() noexcept;

void foo();
```

There is another way to use this specifier.

```cpp
void func() noexcept(expr);
```

`expr` in the above code snippet must a constant expression.

```cpp
void foo1() noexcept(true); // VALID and also identical to next line
void foo2() noexcept;       // VALID

void foo3() noexcept(false); // VALID and also identical to next line
void foo4();                 // VALID and also identical to next line

void foo5() noexcept(sizeof(int) > 4U); // VALID
```

#### operator `noexcept`

Is an operator that returns a `boolean`. If the operand is an expression that cannot throw an
exception, then it returns `true`, else it returns `false`.

```cpp
int main() {
    int x = 10;
    int y = 20;

    constexpr bool b = noexcept(x + y); // VALID
}
```

```cpp
void foo();

void bar() noexcept;

int main() {
    bool a = noexcept(foo()); // VALID. foo is not a no-throw function, noexcept() will return false

    bool b = noexcept(bar()); // VALID. bar is a no-thow function, noexcept() will return true
}
```

An example using both `noexcept` specifier and operator `noexcept`

```cpp
void foo() noexcept;

void bar() noexcept(noexcept(foo())); // Basically means "if foo is a no-throw function then bar
                                      // is also a no-throw function"
```

##### ###REMARK.135###

> Operand of operator `noexcept` is unevaluated context.  
> In C++ there are two more unevaluated contexts
>
> - operand of `sizeof`
> - operand of `decltype`
>
> In C there is only one, operand of `sizeof`.

##### ###REMARK.136###

> Destructor of a class always has the implicit `noexcept` specifier.

##### ###REMARK.137###

> If a no-throw function throws an exception `std::terminate()` is called in runtime.

```cpp
#include <iostream>
#include <stdexcept>

void foo() { throw std::bad_alloc{}; }

void func() noexcept { foo(); }

int main() {
    try {
        func();
    }
    catch (std::exception const& ex) {
        std::cout << "exception caught, in main: " << ex.what() << '\n';
    }
}
```

The above code snippet will have the following output

> terminate called after throwing an instance of 'std::bad_alloc'  
> &nbsp;&nbsp;&nbsp;&nbsp;what(): std::bad_alloc  
> Aborted (core dumped)

There are other impacts of the `noexcept` specifier, function pointers and inheritance.

- Function Pointers

  ```cpp
  int foo(int) { return 5; }

  int bar(int) noexcept { return 6; }

  int main() {
      int (*pfoo1)(int)          = foo; // VALID
      int (*pbar1)(int)          = bar; // VALID
      int (*pfoo2)(int) noexcept = foo; // INVALID
      int (*pbar2)(int) noexcept = bar; // VALID
  }
  ```

  So, a function pointer with a `noexcept` specifier can only point to a no-throw function.

- Inheritance  
  There is a famous rule for inheritance, "promise no less, require no more". This is about the
  functions of the base class and the derived class overriding those functions.

  ```cpp
  class Base {
  public:
      virtual void foo() noexcept {}

      virtual void bar() noexcept {}

      virtual void baz() {}
  };

  class Der : public Base {
  public:
      // void foo() override{}    // INVALID

      void bar() noexcept override {} // VALID

      void baz() override {} // VALID
  };

  void func(Base& r) {
      r.foo();
      r.bar();
  }
  ```

  In the above code snippet, if `Der::foo()` is not a no-throw function but `Base::foo()` is. This
  violates the "promise no less, require no more" rule and is ill-formed. But promising more is
  allowed, see `Base::baz()` and `Der::baz()`.
