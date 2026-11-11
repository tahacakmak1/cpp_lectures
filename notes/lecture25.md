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
        std::cout << &ex << '\n';
        throw;
    }
}

int main() {
    try {
        foo();
    }
    catch (std::out_of_range const& ex) {
        std::cout << "Exception caught in main: " << ex.what() << '\n';
        std::cout << &ex << '\n';
    }
}

```

The above code snippet will have the following output

> Exception caught in foo: out of range error  
> 0x62c29e1cd330  
> Exception caught in main: out of range error  
> 0x62c29e1cd330

#### Why `throw` Instead of `throw ex`?

1. As stated before, when an exception is thrown, an exception object is created by the compiler. By
   using `throw` that very same object is thrown again. Not a copy of it, directly itself. This
   saves a call to copy constructor.

2. Using `throw ex` might cause object slicing, which may result in loss of information about the
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
  > Aborted (core dumped)
