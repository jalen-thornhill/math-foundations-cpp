# Requirements

I am separating the intended features from the current implementation so that unfinished work remains visible.

## Functional requirements

- FR1: Generate truth tables for basic logical operations. Implemented; AND and implication are covered by the recorded checks.
- FR2: Analyse populated finite functions for range, injectivity, surjectivity, and bijectivity. Partial: the methods exist, but the current interface does not populate their data.
- FR3: Perform vector calculations. Implemented as a fixed-data console demonstration and reusable methods; user-entered vectors are not available through the menu.
- FR4: Perform matrix calculations. Implemented as a fixed-data console demonstration and reusable methods; user-entered matrices are not available through the menu.
- FR5: Evaluate formulas and approximate derivatives and integrals, with tables for exploring limits. Implemented for five formulas; testing is currently limited to selected examples.
- FR6: Export session results to a text file. Not complete: option 6 writes fixed introductory text, not the session's calculations, and is missing from the printed menu.

## Non-functional requirements

- NFR1: Build as a modular C++17 console application. The recorded Windows build succeeds with warnings.
- NFR2: Handle invalid input clearly. Partial: some numeric choices and operation preconditions are checked, but failed numeric input and all data-shape errors are not handled.
- NFR3: Keep mathematical operations in separate classes for testing and reuse. Classes are present; a complete automated test suite is not.
- NFR4: Explain important sections with clear first-person present-continuous comments. Comments describe what I am doing and why without explaining every line.

## Scope of this documentation refresh

This refresh adds explanatory comments, build instructions, and accurate test documentation. It does not complete the unfinished features or change calculation behaviour.

The [test plan](TEST_PLAN.md) defines checks, and the [test report](TEST_REPORT.md) records what has actually been run.
