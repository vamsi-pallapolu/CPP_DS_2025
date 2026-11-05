# Variable-Length Arrays (VLAs)

Source: `SEC02_essentialcandcpp/1_VariableSizeArray.cpp`

## What is a VLA?

A **variable-length array** is a stack-allocated array whose size is determined by a runtime expression, e.g. `int A[n];` where `n` is read from input. Standard C (C99+) supports VLAs; standard C++ **does not** — GCC/Clang allow them as an extension.

## Example

```cpp
int n;
std::cin >> n;
int A[n];      // Variable-sized array — non-standard in C++
A[0] = 2;
for (int x : A)
    std::cout << x << std::endl;
```

- The compiler defers computing the array's stack size until `int A[n];` is reached.
- Range-based `for (int x : A)` on a VLA is **also non-standard C++** — it compiles under the same GCC/Clang extension that permits the VLA itself, and won't work on MSVC.
- Elements other than `A[0]` are **uninitialised** — printing them is undefined behaviour.

## Why avoid in C++?

- Not portable — MSVC rejects it entirely.
- Stack allocation with an unbounded `n` risks stack overflow.
- Prefer `std::vector<int> A(n);` — heap-allocated, portable, zero-initialised by default.

## Gotchas

- `sizeof(A)` for a VLA is a **runtime** expression, unlike a normal fixed-size array where it is a compile-time constant.
- Range-based `for` iterates all `n` slots, including uninitialised ones.
