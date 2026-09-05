# Test Report - Math Foundations C++ Toolkit

## Run details

- Date: 2026-09-04.
- Source: local working tree based on commit `a921bd8`, including the explanatory-comment changes from Milestones 2-4.
- Environment: Windows, PowerShell, MSYS2 UCRT64 GCC 14.2.0.
- Build: all seven `src/*.cpp` files with `-std=c++17 -Wall -Wextra -Wpedantic`.
- Build result: success, exit status zero.
- Warnings: 13 signed/unsigned comparison warnings in `FunctionAnalyzer.cpp` and `MatrixTool.cpp`.
- Method: a fresh executable in a separate temporary directory, scripted console input, and manual comparison of output and report contents.
- Runtime result: normal exit, status zero.

I am recording only the checks exercised in this run. These results do not imply that every feature or error path has been tested.

## Results

- T1 - Passed. AND produced `0, 0, 0, 1` for `00, 01, 10, 11`.
- T2 - Passed. Implication produced `1, 1, 0, 1` for those same pairs.
- T3 - Blocked. The interface cannot supply the populated bijective example.
- T4 - Blocked. The interface cannot supply the populated non-bijective example.
- T5 - Passed. Sum `(5, 7, 9)`, difference `(-3, -3, -3)`, scalar multiple `(2, 4, 6)`, dot product `32`, magnitude `3.74166`, same dimension `Yes`, perpendicular `No`.
- T6 - Passed. Sum `[[6, 8], [10, 12]]`, difference `[[-4, -4], [-4, -4]]`, scalar multiple `[[2, 4], [6, 8]]`, transpose `[[1, 3], [2, 4]]`, product `[[19, 22], [43, 50]]`.
- T7 - Passed. The derivative estimate was `6`, within the stated tolerance.
- T8 - Passed. The integral estimate was `0.33335`, within `0.00002` of `1/3`.
- T9 - Passed for fixed-text export. The program reported success, and the created file contained the three expected introductory lines.
- T10 - Passed. Choice `99` printed an error and returned to the menu; choice `0` exited normally.

Total: eight passed cases and two blocked cases. Passes apply only to the inputs and expectations defined in the [test plan](TEST_PLAN.md).

## Observations and remaining gaps

Option 2 printed no range values and reported injective, surjective, and bijective as `Yes`. This reflects empty stored data; it does not pass T3 or T4.

Report export is not listed in the printed menu and does not include calculation results. Its successful fixed-text check does not complete the session-export requirement.

The compiler warnings remain. Other logical operations, limit tables, other calculus formulas, malformed input, data-shape errors, and file-output failures were not covered by this run. There is no complete automated regression suite.

This milestone changed documentation only. No claim of a new published release is being made.
