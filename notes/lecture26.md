# Lecture 26

## Exception Handling

### Function `try` Block

```cpp
#include <iostream>

void func(int x) try {
    std::cout << "func has started\n";
    if (x == 0)
        throw 1;
    else if (x == 1)
        throw 5.;
}

catch (int) {
    std::cout << "Exception caught, catch (int)\n";
}
catch (double) {
    std::cout << "Exception caught, catch (double)\n";
}

int main() {
    func(5);
    func(0);
    func(1);
}
```

- Parameter(s) of the function is accessible from `catch` block(s).
- Local variable(s) of the fucntion is not accessible from `catch` block(s).
- `catch` block(s) can contain `return` statements matching the return type of the function.

Function `try` blocks can be used on all functions, but it is used almost exclusively with
constructors.  
There is a special feature of function `try` blocks when used with constructors,
`catch` block(s) have hidden rethrow statements. User can rethrow explicitly, can even throw other
types of exceptions. Compiler rethrows by default. In the `catch` block of a constructor, member(s)
of the class are accessible.

```cpp
#include <iostream>
#include <stdexcept>

class Myclass {
public:
    Myclass() try {
        //.. code goes here
        //.. code goes here
        //.. code goes here
        throw std::bad_alloc{};
    }

    catch (std::exception const& ex) {
        std::cout << "Exception caught, in Myclass::Myclass(): " << ex.what() << '\n';
    }
};

int main() {
    try {
        Myclass x;
    }
    catch (std::exception const& ex) {
        std::cout << "Exception caught, in main(): " << ex.what() << '\n';
    }
}
```

In the above code snippet, even though there isn't a rethrow statement in `Myclass` constructor, the
exception will be rethrown. It will have the following output

> Exception caught, in Myclass::Myclass(): std::bad_alloc  
> Exception caught, in main(): std::bad_alloc

##### ###REMARK.138###

> Function `try` blocks do not affect the initilization of it's parameters, e.g.
>
> ```cpp
> #include <iostream>
> #include <stdexcept>
>
> class Myclass {
> public:
>    Myclass() = default;
>
>    Myclass(Myclass const&) { throw std::runtime_error("Myclass error\n"); }
> };
>
> void func(Myclass x) try { std::cout << "func()\n"; }
>
> catch (std::exception const& ex) {
>    std::cout << "Exception caught in func: " << ex.what() << '\n';
> }
>
> int main() {
>    Myclass x;
>
>    func(x);
> }
> ```
>
> The exception thrown in the copy constructor of `Myclass` will not be caught in the `catch` block
> of `func` and it will have the following output
>
> > terminate called after throwing an instance of 'std::runtime_error'  
> > &nbsp;&nbsp;&nbsp;&nbsp;what(): Myclass error
> >
> > Aborted (core dumped)

### Functions Generally Suitable for `noexcept`

- Destructors are implicitly `noexcept`
- Move constructor (if there isn't a reason against it)
- Swap functions (if there isn't a reason against it)
- Memory deallocating functions

<!-- ### Levels of Guarantee -->
<!-- repeat this lecture from 44:14 to  1:12:17-->

## Templates

A template in C++ is a feature that allows you to write generic code that works with different data
types without having to rewrite the same code multiple times. Think of a template as a blueprint:
you write the code once, and C++ can use it with different data types.

1. Function Template
2. Class Template
3. Variable Template
4. Alias Template

Templates can have 3 different types of parameters;

1. Type Parameter
2. Non-Type Parameter
3. Template Parameter (a topic for later)

These three types can be used in any combination.

```cpp
template<typename T>                // VALID
template<typename T, std::size_t N> // VALID
template<std::size_t N>             // VALID
```

In the above code snippet `T` is the type parameter and `N` is the non-type parameter.  
Instead of the `typename` keyword, `class` keyword can also be used. In this context they mean the
same. The reason for both of these to work is when templates were introduced, `typename` keyword did
not exist.

##### ###REMARK.139###

> Before C++20, the non-type parameter has to be an integral or a pointer or a reference type but,
> with C++20 it can be a real number type as well.

#### How Does the Compiler Determine the Type Parameter?

There are three different ways for it;

1. Template Argument Deduction
   Similar to `auto`, compiler deduces the type parameter. The same deduction rules apply to both
   `auto` type deduction and template argument deduction with one additional rule for template
   argument deduction.

   ```cpp
   template<typename T>
   void func(T x) {}

   int main() {
     func(4);
   }
   ```

2. Explicit Template Argument
   Client code explicitly declares the type parameter.

   ```cpp
   template<typename T>
   void func(T* x, T y) {}

   int main() {
       int a = 4;
       func<int>(&a, 5);
   }
   ```

3. Default Template Argument

### Some Examples of Template Functions

```cpp
template<typename T>
void foo(T x);
```

```cpp
template<typename T>
void foo();
```

```cpp
template<typename T>
T foo();
```

```cpp
template<typename T>
T foo(T x);
```

```cpp
template<typename T, typename U>
void foo(T x, U y);
```

```cpp
template<typename T, typename U>
void foo(T* x, U& y);
```

```cpp
template<typename T, typename U>
void foo(T x);
```

```cpp
template<typename T>
void func(T x);

template<typename T>
void func(T x, T y);

void func(int x);
```

```cpp
class Myclass {
public:
    template<typename T>
    T foo(T x);
};
```

```cpp
#include <iostream>

template<typename T>
T foo(T x, T y) {
    return x + y;
}

int foo(int x, int y) { return x + y; }

int main() {
    std::cout << foo<int>(3, 5) << '\n';
    std::cout << foo(3, 5) << '\n';
}
```

```cpp
template<typename T>
void func(T&& x) {}

int main() {
    func(12); // with this, func will have specilization of R-Value Reference
    int x = 5;
    func(x); // with this, func will have a specilization of L-Value Reference
}
```

If you have questions about why this happens, check Universal (Forwarding) Reference and Reference
Collapsing under `auto` Type Deduction in this repository.

All of the code snippets above are valid.

Defining a template function in a header file without using `inline` keyword does not violate ODR.
This is also the reason for template codes _almost_ exclusively being in header files.

##### ###REMARK.140###

> The only difference between Template Type Deduction and `auto` Type deduction is shown in the code
> snippet below
>
> ```cpp
> template<typename T>
> void func(T x) {}
>
> int main() {
>     int x = {3, 4, 5, 6}; // will deduce to std::initializer_list<int>
>
>     func({3, 4, 5, 6}); // compiler cannot deduce this
> }
> ```

Template argument deduction does not have to be successful.

```cpp
template<typename T>
void func(T x, T y) {}

int main() {
    func(12, 3.4); // will cause ambiguity because T is deduce to int for 12 and double for 3.4
}
```
