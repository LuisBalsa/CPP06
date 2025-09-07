# CPP06 - C++ Casts

This module covers the different types of casts in C++ and type identification in polymorphic hierarchies. Each exercise focuses on a fundamental concept for understanding type conversion, pointer serialization, and dynamic type identification in C++.

## Structure

- `ex00/` - Scalar type conversion (char, int, float, double)
- `ex01/` - Pointer serialization and deserialization
- `ex02/` - Identification of the real type of a polymorphic object

---

## Exercise 00: Scalar Conversion

**Files:** `Makefile`, `main.cpp`, `ScalarConverter.cpp`, `ScalarConverter.hpp`

### What is required?

Implement a class `ScalarConverter` with a static method `convert` that receives a string literal and converts it to char, int, float, and double, displaying the result of each conversion. It must handle pseudo-literals (nan, inf, etc.) and inform when conversion is not possible.

### Lesson to learn

You learn to use `static_cast` for explicit and safe conversions between scalar types, to validate input, and to handle special cases. This is fundamental to understanding how C++ handles conversions and to avoid subtle bugs in real programs.

---

## Exercise 01: Serialization

**Files:** `Makefile`, `includes/Data.hpp`, `includes/Serializer.hpp`, `sources/main.cpp`, `sources/Serializer.cpp`

### What is required?

Implement a class `Serializer` with static methods to convert a pointer to an integer (`uintptr_t`) and vice versa. Test the serialization and deserialization of a `Data` object.

### Lesson to learn

You learn to use `reinterpret_cast` for conversion between pointers and integers, and the importance of ensuring the conversion is safe. This is useful to understand how pointer serialization and address manipulation work in C++.

---

## Exercise 02: Identify Real Type

**Files:** `Makefile`, `includes/Base.hpp`, `includes/Identify.hpp`, `sources/Base.cpp`, `sources/Identify.cpp`, `sources/main.cpp`

### What is required?

Implement a hierarchy of polymorphic classes (`Base`, `A`, `B`, `C`) and functions to identify the real type of an object at runtime using `dynamic_cast`, without using `<typeinfo>`. Test with both pointers and references.

### Lesson to learn

You learn to use `dynamic_cast` for type identification in polymorphic hierarchies, the difference between casting pointers and references, and the importance of RTTI (Run-Time Type Information) in C++.

---

## How to compile and test

For each exercise:

```sh
cd ex0X
make
./<executable_name>
```

---

## Notes

- The code follows the C++98 standard, as required by the project.
- STL containers and `<typeinfo>` are not allowed.
- Usage examples and comments are included in the test files (`main.cpp`).
- Each exercise has its own Makefile and modular organization.

---

**This module is essential for understanding conversions, casting, and dynamic type identification in C++.**
