# Big Number Undo

A recovered C++17 data-structures exercise: store a number as a string, delete a digit by index and undo deletions in last-in-first-out order with a stack. Leading zeroes are preserved. It is not an arbitrary-precision arithmetic library.

## Build and run
With GCC: g++ -std=c++17 -Wall -Wextra main.cpp -o big_number_undo
On Windows use a Visual Studio Developer Command Prompt: cl /EHsc /std:c++17 main.cpp

Or use CMake: cmake -S . -B build, then cmake --build build and ctest --test-dir build --output-on-failure (add -C Debug for multi-configuration generators).

## Recovery
The original C++ code was saved as a C# Program.cs file. This edition puts it in main.cpp, fixes the restoreLastDelete spelling mismatch, corrects signed index checking, validates digit-only input and adds assertions for multiple undo operations, leading zeroes, invalid indexes, a single digit and invalid input.

Compile without NDEBUG to run the self-checks.

Validation limitation: the available Visual Studio installation lacks the C++ compiler headers/SDK, so compilation and the assertions could not be executed in this preparation environment.
