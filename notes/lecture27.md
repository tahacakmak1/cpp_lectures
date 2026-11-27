# Lecture 27

## Templates

### Calculating the Size of an Array

- The old way

  ```cpp
  #include <iostream>

  #define asize(a)  (sizeof(a) / sizeof(*a))

  int main() {
      double a[] = {2., 3., 5., 8., 9.};

      std::cout << asize(a) << '\n';
  }
  ```

- New way

  ```cpp
  #include <iostream>

  template<typename T, std::size_t SIZE>
  constexpr std::size_t asize(T const (&)[SIZE]) {
      return SIZE;
  }

  int main() {
      double a[] = {2., 3., 5., 8., 9.};

      std::cout << asize(a) << '\n';
  }
  ```

### More Examples of Template Functions

```cpp
#include <iostream>

template<typename T, typename U>
void func(T (*)(U)) {}

double foo(int) {
    return 5.;
}

void bar(double) {}

int main() {
    func(foo); // T will be deduced to double (*)(int). U will be deduced to int
    func(bar); // T will be deduced to void (*)(double). U will be deduced to double
}
```

##### ###REMARK.141###

> ```cpp
> #include <iostream>
>
> int foo(int x) {
>     std::cout << "foo(int x), x = " << x << '\n';
>     return {};
> }
>
> int main() {
>     int x = foo({});    // VALID
>     int y = foo(int{}); // VALID
>     std::cout << "x in main is " << x << '\n';
>     std::cout << "y in main is " << y << '\n';
> }
> ```
>
> The above code snippet will have the following output
>
> > foo(int x), x = 0  
> > foo(int x), x = 0  
> > x in main is 0  
> > y in main is 0

```cpp
#include <iostream>

template<typename T>
void func(T x, T y) {}

class Myclass {};

int main() {
    func(12, {});   // VALID
    Myclass m1;
    func(m1, {});   // VALID
}
```

## Runtime Type Information (Identification) (RTTI)
