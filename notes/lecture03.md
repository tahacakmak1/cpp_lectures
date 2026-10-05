# LECTURE 03

## Basic Types

- `bool`    
- `char`
- `signed char`
- `unsigned char`    
- `short`
- `unsigned short`
- `int`
- `unsigned int`    
- `long`
- `unsigned long`    
- `long long`
- `unsigned long long`    

##### ###REMARK###6

> `sizeof(short)` <= `sizeof(int)` <= `sizeof(long)` <= `sizeof(long long)`

`float`        (4 bytes)  
`double`       (8 bytes)  
`long double`

4.5  means `double`
4.5F means `float`

|Types                   |Suffix                                                                   |
|------------------------|-------------------------------------------------------------------------|
|unsigned                |U                                                                        |
|long                    |L                                                                        |
|float                   |F    (has to contain . , e.g. 34F is a syntax error, correct way is 34.F)|
|unsigned long           |UL  or LU                                                                |
|unsigned long long      |ULL or LLU                                                               |

##### REMARK#7

> - When `signed` or `unsigned` used without any type keywords like `signed x` or `unsigned x`, it
>     automatically becomes `signed int x` and `unsigned int x` respectively.
> - Using scientific notation in real numbers eliminates the necessity of `.`.
>
>   ```c
>   10e2, 10e2F
>   ```
>
> - If you exceed the value limits of `int` or `float`, variable type automatically changes to the
>     respective bigger types, depending on which type can contain that value.
> - To make reading large numbers easier, `'` (digit separator) can be used.  
>     `int x = 784'123;` would mean `int x = 784123;` but it is much easier to read the number. This is not exclusive to
decimals.

|C                   |C++             |                  |
|--------------------|----------------|------------------|
|Decimal             |Decimal         |41 (default)      |
|Octal               |Octal           |041               |
|Hexadecimal         |Hexadecimal     |0x41              |
|                    |Binary          |0b1001            |

Default type of variables are int.

```c
ival * 1000  int operation
ival * 1000L long operation (typecasting)
```

##### REMARK#8

> Variable types are critically important for function overloading.

## Scope

- Names have scope.
- In C
  - Block Scope
  - File Scope
  - Function Prototype Scope
  - Function Scope
- In C++
  - Block Scope
  - Namespace Scope
  - Class Scope
  - Function Prototype Scope
  - Function Scope
- Name Lookup

## Expression

Most widely used statement form is expression statement.

### Expression Statement

If you put a ';' at the end of an expression it becomes an expression statement. e.g. `x = 5;`  
Every expression has a data type(int, double, ...) and a value category (PR, X, L (primary val cats) or R, GL (secondary val cats)).

##### REMARK#9
> Priority operator does not change the value category.  
>`x = 9;` and `(((((((((x))))))))) = 9;` are the same thing.

## constexpr

##### REMARK#10

> constant (`const`) and constant expression (`constexpr`) are different from each other.
>
> C definition: If the value of an expression is known by the compiler at the compile time then that expression is a
> constant expression (`constexpr`).
>
> In C there are some places that constexpr must be used;
>
> - `int a[constexpr]` because compiler has to know the size of the array (if compiler does
> not support variable length array).
> - Initializations of global variables.
> - Case label expressions in `switch`.
> - Bitfield member
>
> In C++ importance of constepxr is much greater than in C.

## Operators

- By Operand(s)
  - Unary
  - Binary
  - Ternary    (the ternary/conditional operator)
- By Position
  - Prefix     `*ptr` or `++x` or `--x` etc.
  - Postfix    `x++` or `x--` etc.
  - Infix      `a + b` or `a * b` etc.

### Operator Precedence in C

For more details check [CppReference C Operator Precedence](https://en.cppreference.com/w/c/language/operator_precedence)

|Precedence|Operator&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|Description|Associativity|
|:--------:|--------|-----------|-------------|
|1|`++` `--`[^1]  `()`  `[]`  `.`  `->`  `(type){list}`|Suffix/postfix incerement and decrement  Function call  Array subscripting  Structure and union member access  Structure and union member access through pointer  Compound literal|Left-to-right|
|2|`++` `--`[^1]  `+` `-`  `!` `~`  `(type)`  `*`  `&`  `sizeof` [^2]  `_Alignof`|Prefix increment and decrement  Unary plus and minus  Logical `NOT` and bitwise `NOT`  Cast  Indirection (dereference)  Address-of  Size-of  Alignment requirement|Right-to-left
|3|`*` `/` `%`|Multiplication, division, and remainder|Left-to-right|
|4|`+` `-`|Addition and subtraction|Left-to-right|
|5|`<<` `>>`[^3]|Bitwise left shift and right shift|Left-to-right|
|6|`<` `<=`  `>` `>=`    |Relational operators for less than and less than or equal to respectively  Relational operators for greater than and greater than or equal to respectively|Left-to-right|
|7|`==` `!=`|For relational equal and not equal|Left-to-right|
|8|`&`|Bitwise `AND`|Left-to-right|
|9|`^`|Bitwise `XOR`|Left-to-right|
|10| `\|`|Bitwise `OR`|Left-to-right|
|11|`&&`|Logical `AND`[^4]|Left-to-right|
|12|`\|\|`|Logical `OR`[^4]|Left-to-right|
|13|`?:`[^5]|Ternary conditional|Right-to-left|
|14|`=`  `+=` `-=`  `*=` `/=` `%=`  `<<=` `>>=`  `&=` `^=` `\|=`[^6]|Simple assignment  Assignment by sum and difference  Assignment by product, quotient and remainder  Assignment by bitwise left shift and bitwise right shift  Assignment by bitwise `AND`, `XOR`, and `OR`|Right-to-left|
|15|`,`[^7]|Comma|Left-to-right|

### Operator Precedence in C++

For more details check [CppReference C++ Operator Precedence](https://en.cppreference.com/w/cpp/language/operator_precedence)

|Precedence|Operator|Description|Associativity|
|----------|--------|-----------|-------------|
|1|`a::b`|Scope resolution|Left-to-right|
|2|`a++` `a--`[^1]  `type(a)` `type{a}`  `a()`  `a[]`  `a.b` `a->b`|Suffix/postfix increment and decrement  Functional cast  Function call  Subscript  Member access|Left-to-right|
|3|`++a` `--a`[^1]  `+a` `-a`  `!a` `~a`  `(type)a`  `*a`  `&a`  `sizeof`[^2]  `co_await`  `new` `new[]`  `delete` `delete[]`|Prefix increment and decrement  Unary plus and minus  Logical `NOT` and bitwise `NOT`  C-style cast  Indirection (dereference)  Address-of  Size-of  await-expression  Dynamic memory allocation  Dynamic memory deallocation|Right-to-left|
|4|`a.*b` `a->*b`|Pointer to member|Left-to-right|
|5|`a * b` `a / b` `a % b`|Multiplication, division, and remainder|Left-to-right|
|6|`a + b` ` a - b`|Addition and subtraction|Left-to-right|
|7|`a << b` `a >> b`[^3]|Bitwise left shift and right shift|Left-to-right|
|8|`a <=> b`|Three-way comparison operator (C++20)|Left-to-right|
|9|`a < b` `a <= b`  `a > b` `a >= b`|Relational operators|Left-to-right|
|10|`==` `!=`| Equality operators|Left-to-right|
|11|`a & b`|Bitwise `AND`|Left-to-right|
|12|`a ^ b`|Bitwise `XOR`|Left-to-right|
|13|`a \| b`|Bitwise `OR`|Left-to-right|
|14|`a && b`[^4]|Logical `AND`|Left-to-right|
|15|`a \|\| b`[^4]|Logical `OR`|Left-to-right|
|16|`a ? b : c`[^5]  `throw`  `co_yield`  `a = b`[^6]  `a += b` `a -= b`  `a *= b` `a /= b` `a %= b`  `a <<= b` `a >>= b`  `a &= b` `a ^= b` `a \|= b`|Ternary conditional  `throw operator`  `yield expression`(C++20)  Direct assignment  Compound assignment by sum and difference  Compound assignment by product, quotient, and remainder  Compound assignment by bitwise left shift and right shift  Compound assignment by bitwise `AND`, `XOR`, and `OR`|Right-to-left|
|17|`,`[^7]|Comma operator|Left-to-right|

##### REMARK#11

> Yielded value, generated value, return value are the same thing.

## Sequence Point(also called sequencing in C++)

Expressions causing a side effect before this point, must be completed after this point
```c
x = 10;
x++;
//-------------sequence point
x;                              // x is 11 from here

int x = 5, y = ++x, z = y + x;  // Comma separator creates a sequence point, therefore
                                // at the end of this line x is 6, y is 6, z is 12.
                                // Expression in if, switch, while, do-while and
                                // semicolons in for are sequence points. Left hand
                                // operand of && operator is a sequence point.
```

## Order of Evaluation

```c
f1() + f2() * 5;    // f1 will be evaluated first, then f2, then multiplication and finally addition
```

##### REMARK#12

> Token
>
> - Identifier
> - Operator
> - String Literal (e.g. "mike")
> - Keywords

##### REMARK#13

> Do not compare two real numbers.

##### QUESTION#1

```c
#include <stdio.h>

int main(void) {
    int x = 10, y = 20;
    int z;

    z = x, y;
    printf("z = %zu\n", z);                // This will output         z = 10

    z = (x, y);
    printf("z = %zu\n", z);                // This will output         z = 20
        
    return 0;
}
```

[^1]:
    `++` `--`  
    Postfix and prefix operators have side effects, they change the value of their operand.

    ```c
    int x = 10;
    int y = x++;    // In this, y will be 10, and x will be increased to 11.
    int x = 10;
    int y = ++x;    // In this, y will be 11, and x will be increased to 11.         
                    // In both examples x has the value 11 because of the side effect but, in the first example
                    // it happens after y is initialized.
    ```

[^2]:

    1. `sizeof`
    2. `sizeof` is a keyword and is an operator, not a function.
    3. `sizeof` is a compile time operator, which means expressions generated by `sizeof` are `constexpr`, so they can be used in
    array declarations.
    4. Value generated by `sizeof` has the value type `size_t` (it can be `unsigned int`, `unsigned long`, `unsigned long long`).
    5. Operand of `sizeof` operator is unevaluated context.
    6. `()` used in `sizeof` are not part of the operator, they are only necessary when the operand is a typename.

        ```c
        sizeof 5;
        sizeof(int);
        sizeof(double);
        ```

[^3]:
    Bitshift Operators  

    1. Value of the right operand of bitshift operators must be smaller than the number of bits of the left operand.
    2. Value of the right operand must be non-negative.
    3. Left operand will be promoted.
    4. Left operand must be positive (in C).
    5. Whether it's an arithmetic bitshift or logic bitshift, is implementation defined (meaning it depends on the compiler).

[^4]:
    Short Circuit Behavior;  
    for `&&` if the left operand is false, right operand is not calculated.  
    for `||` if the left operand is true,  right operand is not calculated.

[^5]:
    Ternary Operators

    ```c
    // assignments
    z = x > y ? a : b;
    // function calls
    function(a > b ? a : b)
    // return statements
    return x > 10 ? x : b;
    ```

[^6]: Return value of every assignment operator is the value that is assigned to the variable.

[^7]:
    Comma Operator  
    Is a binary operator that evaluates its first operand and discards the result, it then evaluates the
    second operand and returns this value and type.
    Separator comma and operator comma are different from each other.

    ```c
    int num1 = (5, 10);         // 10 is assigned to num
    int num2 = (f1(), f2());    // f1() is called(evaluated) first followed by f2(). The returned value of f2() is
                                // assigned to num2.
    ```
