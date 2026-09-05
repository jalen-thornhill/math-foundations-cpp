# Test Plan - Math Foundations C++ Toolkit

## Purpose and method

I am checking selected console results against known mathematical answers and recording untested or blocked cases separately.

Build the current source using the [README instructions](../README.md). Run from a disposable directory such as `build/`: report export replaces `report.txt` in the current working directory.

Enter each listed value at the next prompt. Return to the main menu between cases, and enter `0` when finished. Inspect the output; an exit status of zero alone does not prove a calculation is correct.

## Test cases

### T1 - AND truth table

Enter `1, 2`. For input pairs `00, 01, 10, 11`, expect results `0, 0, 0, 1`.

### T2 - Implication truth table

Enter `1, 4`. For input pairs `00, 01, 10, 11`, expect results `1, 1, 0, 1`.

### T3 - Bijective populated function

Planned data: domain `{1, 2, 3}`, codomain `{a, b, c}`, outputs `{a, b, c}`. Expect range `{a, b, c}` and all three properties to be true.

Blocked: the current interface cannot populate the private data. Option 2's empty-data output is not a substitute for this test.

### T4 - Non-bijective populated function

Planned data: domain `{1, 2, 3}`, codomain `{a, b, c}`, outputs `{a, a, b}`. Expect range `{a, b}` and all three properties to be false.

Blocked for the same reason as T3. A supported way to supply data is needed before running these cases.

### T5 - Vector demonstration

Enter `3`. Expect:

- Sum: `(5, 7, 9)`.
- Difference: `(-3, -3, -3)`.
- Twice the first vector: `(2, 4, 6)`.
- Dot product: `32`.
- Magnitude of the first vector: approximately `3.74166`, within `0.00001` of `sqrt(14)`.
- Same dimension: `Yes`; perpendicular: `No`.

### T6 - Matrix demonstration

Enter `4`. Expect:

- Sum: `[[6, 8], [10, 12]]`.
- Difference: `[[-4, -4], [-4, -4]]`.
- Twice A: `[[2, 4], [6, 8]]`.
- Transpose of A: `[[1, 3], [2, 4]]`.
- Product: `[[19, 22], [43, 50]]`.

### T7 - Numerical derivative

Enter `5, 2, 1, 3`. Expect the derivative estimate for `x^2` at `3` to be within `0.00001` of `6`.

### T8 - Trapezoidal integral

Enter `5, 4, 1, 0, 1, 100`. Expect approximately `0.33335`, within `0.00002` of the exact integral `1/3`. The trapezoidal approximation need not equal the exact integral.

### T9 - Introductory report export

Enter `6`, even though it is missing from the displayed menu. Expect a success message and a readable `report.txt` containing:

```text
My Math Foundations Report
==========================
This report was exported from the program.
```

This checks fixed-text export only, not session-result export.

### T10 - Invalid numeric menu choice and exit

Enter `99`. Expect `Invalid choice. Try again.` and another main menu. Enter `0`; expect a normal exit with process status zero.

## Repeating the selected checks in PowerShell

After building, use a working directory without a report you need to keep. From the repository root:

```powershell
Push-Location build
try {
    $testInput = @(1,2,1,4,2,3,4,5,2,1,3,5,4,1,0,1,100,6,99,0) -join "`n"
    $testInput | & .\math-foundations.exe
    "Runtime status: $LASTEXITCODE"
    Get-Content report.txt
} finally {
    Pop-Location
}
```

This repeats T1, T2, T5-T10 and observes the empty function analyzer. It is a scripted input sequence with manual output comparison, not an assertion-based automated test suite.

## Further coverage needed

NOT, OR, equivalence, direct formula evaluation, limit tables, other calculus formulas, invalid subdivisions, incompatible or empty vectors and matrices, nonnumeric input, and export failures need dedicated checks. Do not label these as passed without running them.
