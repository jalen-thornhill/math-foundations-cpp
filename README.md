# Math Foundations C++ Toolkit

I am using this C++ console project to practise Boolean logic, finite functions, vectors, matrices, and numerical calculus. I am organising the code into separate classes so that I can revisit each mathematical operation and understand how it works.

This is a learning project with working demonstrations and some unfinished features.

## Features

- Truth tables for NOT, AND, OR, implication, and equivalence.
- Vector addition, subtraction, scalar multiplication, dot product, magnitude, dimension checks, and perpendicularity checks using fixed examples.
- Matrix addition, subtraction, scalar multiplication, transpose, and multiplication using fixed examples.
- Evaluation of five formulas: `x^2`, `x^3`, `2x + 1`, `sin(x)`, and `cos(x)`. Trigonometric inputs are in radians.
- Numerical derivatives using a central difference with a step of `0.1`.
- Tables of nearby values for exploring limits.
- Definite-integral estimates using the trapezoidal rule.
- Fixed introductory text exported to `report.txt`.

The function analyzer contains methods for range, injectivity, surjectivity, and bijectivity, but the current interface does not supply a populated mapping.

## Build and run on Windows

You need a C++17 compiler. The current source was checked with MSYS2 UCRT64 GCC 14.2.0 and PowerShell.

Open PowerShell in the repository folder. If MSYS2 is installed at the path below, run:

```powershell
$env:PATH = 'C:\msys64\ucrt64\bin;' + $env:PATH
New-Item -ItemType Directory -Force -Path build | Out-Null
$sourceFiles = @(Get-ChildItem -LiteralPath src -Filter '*.cpp' | ForEach-Object { $_.FullName })
g++ -std=c++17 -Wall -Wextra -Wpedantic @sourceFiles -o build/math-foundations.exe
```

Adjust the compiler path if your installation is elsewhere. Only continue if compilation succeeds. Run the new executable from the build folder:

```powershell
Push-Location build
try {
    .\math-foundations.exe
} finally {
    Pop-Location
}
```

Running here keeps exported reports inside `build/`, which Git ignores. Build from source when checking changes; the existing executables in the repository root are not evidence of a current build.

## Using the menu

Enter one answer at each prompt:

- `1`: choose a logical operation and display its truth table.
- `2`: display the function analyzer state. Its data is empty; this is not a populated-mapping demonstration.
- `3`: run the vector demonstration with `{1, 2, 3}` and `{4, 5, 6}`.
- `4`: run the matrix demonstration with `{{1, 2}, {3, 4}}` and `{{5, 6}, {7, 8}}`.
- `5`: choose a calculus operation, a formula, and the requested numeric values.
- `6`: export the introductory report. This option works but is not currently listed in the printed menu.
- `0`: exit.

For example, enter `5`, `2`, `1`, and `3` at successive prompts to estimate the derivative of `x^2` at `x = 3`. The expected result is approximately `6`.

Report export writes to the current working directory and replaces an existing `report.txt`. It does not save your calculation history.

## Code guide

I am explaining the main sections in first-person present continuous, such as “I am checking whether both vectors have the same number of elements.” The comments describe the purpose of the work rather than narrating every line.

- [main.cpp](src/main.cpp): menus, user input, and calls to the mathematical tools.
- [Logic.cpp](src/Logic.cpp): logical operations and truth tables.
- [FunctionAnalyzer.cpp](src/FunctionAnalyzer.cpp): methods for finite-function properties.
- [VectorTool.cpp](src/VectorTool.cpp): vector calculations and checks.
- [MatrixTool.cpp](src/MatrixTool.cpp): matrix calculations and checks.
- [CalculusTool.cpp](src/CalculusTool.cpp): formula evaluation and numerical approximations.
- [ReportWriter.cpp](src/ReportWriter.cpp): writing text to a file.

Each tool has a matching `.hpp` header in `src/` that declares its class and methods.

## Testing and limitations

The latest recorded build succeeded with 13 signed/unsigned comparison warnings in the function analyzer and matrix code. Selected console checks passed; this is not a complete automated test suite.

- The function analyzer has empty data and no public way to populate it. Its three “Yes” results do not verify the sample mappings in the test plan.
- Vector and matrix menu options use fixed examples, not user-entered data.
- Numeric input is expected. Recovery from letters or other failed input is not implemented.
- Matrix operations assume rectangular data in places; uneven row lengths are not fully validated.
- Calculus results are numerical approximations, not symbolic answers or proofs of limits.
- Report export checks whether the file opens but does not check for later write failures.
- The repository's `LICENSE` file is empty; no licence terms are supplied there.

See the [requirements](docs/REQUIREMENTS.md), [test plan](docs/TEST_PLAN.md), and [recorded test results](docs/TEST_REPORT.md) for scope and evidence.
