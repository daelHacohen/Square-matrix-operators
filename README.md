# Square-matrix-operators

##  Overview

This project implements a robust `SquareMat` class in C++ that represents square matrices of real numbers. The class supports a wide variety of mathematical operations through operator overloading, including:

- Basic arithmetic: addition, subtraction, multiplication
- Scalar operations
- Modulo and division
- Matrix power and transpose
- Determinant calculation
- Logical comparisons
- Increment/decrement (prefix and postfix)
- Input/output (via `<<` operator)

It is implemented without use of the C++ STL for educational purposes and includes proper dynamic memory management and extensive input validation.

---

##  Project Structure

| File              | Description |
|-------------------|-------------|
| `SquareMat.hpp`   | Header file for the `SquareMat` class, including function declarations and documentation. |
| `SquareMat.cpp`   | Implementation file for the `SquareMat` class, with full operator overloads and logic. |
| `test_SquareMat.cpp` | Unit tests written using the [doctest](https://github.com/doctest/doctest) framework to validate all functionalities. |
| `Main.cpp`        | A demonstration file showing usage of the `SquareMat` class. |
| `Makefile`        | Includes the following build targets:
  - `make Main` – compile and run demo.
  - `make test` – run unit tests.
  - `make valgrind` – memory leak check.
  - `make clean` – remove compiled files. |

---

##  Features

-  Safe dynamic memory allocation
-  Full operator overloading for arithmetic and logical comparisons
-  Determinant via recursive expansion
-  Matrix power (`^`) and transpose (`~`)
-  Stream output (`<<`) formatting
-  Modular scalar/matrix operation
-  Unit-tested using `doctest`

---

##  Testing

Testing is done using the `doctest` library. The test suite includes:

- Constructor behavior
- All arithmetic operators
- Comparison operators
- Transpose and determinant logic
- Error handling (invalid operations, bounds checking)

All tests are located in `test_SquareMat.cpp`.

---

##  Author

Developed by [Dael](https://github.com/YOUR_GITHUB_USERNAME](https://github.com/daelHacohen?tab=repositories)) as part of a university assignment on Systems Programming course in C++.
