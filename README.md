# Math Foundations C++ Toolkit

This is a small pedagogical C++ program covering foundational math topics (truth tables, function properties, vectors, matrices, and elementary calculus).

## What it does

The program is structured as a modular toolkit. Each of the following components is a separate class in its own `.cpp`/`.hpp` pair:

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
- PowerShell/ Command Prompt on Windows.

Build and run from the repository root using:

```
powershell g++ -std=c++17 -Wall -Wextra -Wpedantic src\*.cpp -o build\math-foundations.exe
```

This compiles all `.cpp` files in `src/` into `build/math-foundations.exe`.
The code should compile with `-Wall -Wextra -Wpedantic` with no errors, but 13 warnings, of all signed/unsigned int comparisons. See limitations for more details.

## Using the program

After starting `build/math-foundations.exe`, you see a numbered menu:

- `1` Logic module: truth tables for basic logical connectives.
- `2` Function analyzer: check range, injectivity, surjectivity, bijectivity.
- `3` Vector toolkit: vector operations (addition, subtraction, scalar multiplication, dot product, angle).
- `4` Matrix toolkit: matrix operations (addition, subtraction, scalar multiplication, multiplication, transpose).
- `5` Calculus toolkit: function evaluation, derivative (central difference), limit exploration table, definite integral (trapezoidal rule).
- `6` Writes a report to `report.txt`.
- `0` Exit the program.


Enter the number of the option and press Enter. The toolkit currently uses hardcoded sample data (for example, vectors {1, 2, 3} and {4, 5, 6}; matrices {{1, 2}, {3, 4}} and {{5, 6}, {7, 8}}) and prints the results to the console.
The report writing function can be used by typing `6` and pressing enter. This function will write to a new report.txt file in your current directory. Be careful, this overwrites any existing report.txt file.
## Code structure

- `src/main.cpp` represents the interactive menu, connects modules.
- `src/Logic.cpp` represents the class for finding truth tables of the unary/binary operators Not, And, Or, Equiv, and Cond.
- `src/FunctionAnalyzer.cpp` represents the class for determining injectivity, surjectivity, bijectivity, and range of functions.
- `src/VectorTool.cpp` represents the class for basic vector operations and angle/dot product calculations.
- `src/MatrixTool.cpp` represents the class for common matrix operations and the transpose function.
- `src/CalculusTool.cpp` represents the class for functions that take a function input, and return an associated function (derivative, limit, definite integral).
- `src/ReportWriter.cpp` represents the placeholder class for generating reports (currently outputs a fixed introductory text).
- Corresponding `.hpp` headers in `src/` declare the interfaces of each class.

## Limitations

The program does not have a currently implemented method for getting data input for the functions. The mappings are empty and there is currently no public function to set the data.
It also has no implemented method for recovering from nonnumeric inputs.
Matrix functions assume rectangular data.

## License

This project is licensed under the [MIT License](LICENSE).

Copyright (c) 2026 Jalen Thornhill.
