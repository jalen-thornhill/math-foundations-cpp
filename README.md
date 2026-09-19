# Math Foundations C++ 

This is a small C++ program covering foundational math topics (truth tables, function properties, vectors, matrices, and  calculus).

## What it does
Each of the following components is a separate class in its own `.cpp`/`.hpp` pair:

- **Logic module**
  - Truth tables for the basic unary/binary connectives: NOT, AND, OR, implication (cond), and equivalence.
- **Function analyzer**
  - Analyzes a function for its range and for the properties of being injective, surjective, and bijective.
- **Vector toolkit**
  - Vector addition, subtraction, scalar multiplication.
  - Dot product and angle-related operations: perpendicularity tests.
  - Vector magnitude and dimension comparison between vectors.
- **Matrix toolkit**
  - Matrix addition, subtraction, scalar multiplication.
  - Matrix multiplication and transpose.
- **Calculus toolkit**
  - Numerical evaluation of sample functions such as x^2, x^3, 2x + 1, sin(x), and cos(x) (radians for trigonometric functions).
  - Numerical derivative using a central difference approximation (h = 0.1).
  - Table of function values near a point for intuitive limit exploration.
  - Numerical definite integration using the trapezoidal rule, with user-specified number of subdivisions.
- **Report generation**
  - Writes a fixed introductory text to a plain-text file .
  - This is a placeholder for more substantial generated reports.
## Building and running

Prerequisites:

- A C++17 compiler (tested with MSYS2 UCRT64 GCC 14.2.0).

Build and run from the repository root using:

```
 g++ src\*.cpp -o math-foundations.exe
```

## Using the program

After starting `./math-foundations.exe`, you see a numbered menu:

- `1` Logic module: truth tables for basic logical connectives.
- `2` Function analyzer: check range, injectivity, surjectivity, bijectivity.
- `3` Vector toolkit: vector operations (addition, subtraction, scalar multiplication, dot product, angle).
- `4` Matrix toolkit: matrix operations (addition, subtraction, scalar multiplication, multiplication, transpose).
- `5` Calculus toolkit: function evaluation, derivative (central difference), limit exploration table, definite integral (trapezoidal rule).
- `6` Writes a report to `report.txt`.
- `0` Exit the program.




## License

This project is licensed under the [MIT License](LICENSE).

Copyright (c) 2026 Jalen Thornhill.
