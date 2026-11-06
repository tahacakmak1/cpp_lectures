# LECTURE 24

## Exception Handling

Traditional way of handling errors rely on one of the following;

1. Return value of a function, e.g. `malloc()`, `fopen()`
2. Value of the out parameter of a function
3. Setting a global variable (see errno.h for further explanation on this)

Each of these methods have their own issues as well as one big common issue, they lack enforcement.
Meaning, if you were to use `malloc()` or `fopen()` you can skip checking the validity of the return
value. Same goes for checking the validity of the out parameter and checking the global error
variable.

### `throw` Statement

Creates and throws an exception object. This object is not just a return value, it represents the
exception.  
Can exist in two different ways;

- ```cpp
  throw; // Also called rethrow statement
  ```

- ```cpp
  throw expr;
  ```

### `try` Block

- After every `try` block, there must be at least one `catch` block.

### `catch` Block
