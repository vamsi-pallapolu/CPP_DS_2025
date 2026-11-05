# Heap Allocation — `malloc` vs `new`

Source: `SEC02_essentialcandcpp/2_Pointers.cpp`

## What is heap allocation?

The **heap** is a region of memory whose lifetime is not tied to the enclosing scope — objects allocated there persist until explicitly freed. Both C and C++ let you get a pointer into the heap, but the two APIs are subtly different.

## C-style: `malloc`

```cpp
int *p = (int *)malloc(5 * sizeof(int));
```

- `malloc` takes a byte count — `5 * sizeof(int)`, not `5`.
- Returns `void*`; C++ requires an explicit cast (C does not).
- Memory is **uninitialised** — contents are garbage.
- Must be released with `free(p);`.

## C++-style: `new`

```cpp
int *p = new int[5];
```

- Takes an element count, not bytes — the compiler multiplies by `sizeof(int)`.
- Returns the correctly-typed pointer directly — no cast.
- For scalar types like `int` this leaves values uninitialised; `new int[5]()` value-initialises to zero.
- Must be released with `delete[] p;` (matching form — `delete p;` for a scalar `new`).

## `malloc` vs `new`

| Aspect | `malloc` | `new` |
|---|---|---|
| Argument | bytes | element count |
| Return type | `void*` | typed `T*` |
| Failure mode | returns `NULL` | throws `std::bad_alloc` |
| Constructor call | no | yes (for class types) |
| Pair with | `free` | `delete` / `delete[]` |

## Gotchas

- The source file declares `int *p` twice in the same scope — that is a compile error. Treat this file as demonstrating **two alternative styles**, not a working program.
- Never mix: `malloc` + `delete`, or `new` + `free`. Behaviour is undefined.
- Prefer `std::vector<int>` or `std::unique_ptr<int[]>` in real C++ code — RAII removes the need to remember to free.
