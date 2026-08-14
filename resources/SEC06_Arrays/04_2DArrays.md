# 2D Arrays — Three Representations

Source: `SEC06_Arrays/4_2DArrays.cpp`

## What is a 2D array?

A **2D array** is a grid of elements addressed by two indices — a row and a column. In memory, C/C++ stores them in **row-major order** (all of row 0, then all of row 1, ...). There are three common ways to build one, differing in *where* each row lives and *how* the rows are found.

## 1. Contiguous 2D array (stack)

```cpp
int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
```

- **Layout**: one contiguous chunk of `2 * 3 = 6` ints on the stack.
- **Row `i` start**: computed by the compiler as `A + i * 3`.
- **Fast**: single allocation, cache-friendly, indices resolve to pointer arithmetic.
- **Fixed shape**: dimensions must be compile-time constants.

## 2. Array of row pointers (semi-dynamic)

```cpp
int *B[2];               // stack: two pointers
B[0] = new int[3];       // heap: row 0 (3 ints)
B[1] = new int[3];       // heap: row 1 (3 ints)
```

- **Layout**: `B` is a small stack array of pointers; each row is a separately-allocated heap block.
- **Row lookup**: `B[i]` gives a pointer to row `i`; then `B[i][j]` indexes the element.
- **Rows may have different lengths** — useful for jagged arrays (e.g. rows of a triangular matrix).
- Cleanup: `delete[] B[0]; delete[] B[1];` — one `delete[]` per row.

## 3. Double-pointer (fully dynamic)

```cpp
int **C = new int*[2];   // heap: array of 2 pointers
C[0]    = new int[3];    // heap: row 0
C[1]    = new int[3];    // heap: row 1
```

- **Layout**: `C` itself is a heap pointer, pointing to a heap array of `int*`, each pointing to a heap `int[3]`.
- **Number of rows can be chosen at runtime** — `new int*[rows]`.
- Cleanup: `delete[] C[0]; delete[] C[1]; delete[] C;` — outside-in.

## Side-by-side

| Representation | Row count fixed at | Rows contiguous? | Memory blocks |
|---|---|---|---|
| `int A[2][3]` | compile time | yes (one block) | 1 |
| `int *B[2]` | compile time | no (rows are heap) | 1 stack + 2 heap = 3 |
| `int **C` | runtime | no | 1 (outer) + 2 (rows) = 3 |

## Access pattern is uniform

Once built, all three respond to the same syntax:

```cpp
A[i][j]   // 2D array
B[i][j]   // array of pointers
C[i][j]   // double pointer
```

- For `A`, this compiles to `*(A + i * 3 + j)`.
- For `B` and `C`, it compiles to `*(*(X + i) + j)` — one extra indirection.

## Uninitialised memory warning

The source prints `C[i][j]` immediately after `new int[3]`. With `new int[3]` (no parentheses), primitive types are **not initialised** — you'll print garbage. To zero-initialise:

```cpp
C[0] = new int[3]();   // note the parentheses — value-initialisation
```

## In modern C++

Prefer standard containers:

- `std::array<std::array<int, 3>, 2>` — compile-time fixed 2D array, on the stack.
- `std::vector<std::vector<int>>` — runtime dimensions, jagged rows allowed.
- `std::vector<int>` with manual `row * cols + col` indexing — one heap allocation, best cache behaviour.

## Gotchas

- Never mix `new` / `delete` forms — `new[]` requires `delete[]`.
- `int **C` is **not** the same type as `int C[2][3]` even though `C[i][j]` compiles for both — you cannot pass one where the other is expected.
- `sizeof(C)` for the double-pointer version is 8 bytes (pointer size); you must track dimensions manually.
- Row-major storage means iterating with the row index in the outer loop is cache-friendly; column-major iteration thrashes the cache.
