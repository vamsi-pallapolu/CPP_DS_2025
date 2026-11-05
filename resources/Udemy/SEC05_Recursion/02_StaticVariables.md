# Static Variables in Recursive Functions

Source: `SEC05_Recursion/2_StaticVariables.cpp`

## What is a `static` local variable?

A `static` local variable is stored in the program's data segment, **not** on the stack. Its value **persists across function calls** — including recursive calls. There is exactly one copy of it, shared by every invocation.

## The example

```cpp
int fun(int n)
{
    static int x = 0;   // initialised once, at program start
    if (n > 0)
    {
        x++;            // shared across every call
        return fun(n - 1) + x;
    }
}
```

Trace `fun(3)`:

| Call | `n` | `x` after `x++` | returns |
|---|---|---|---|
| `fun(3)` | 3 | 1 | `fun(2) + 1` |
| `fun(2)` | 2 | 2 | `fun(1) + 2` |
| `fun(1)` | 1 | 3 | `fun(0) + 3` |
| `fun(0)` | 0 | — | ? (no return statement — UB!) |

- Because `x` is `static`, every increment is visible to every unwinding call.
- Compare with `int x = 0;` (non-static): each call would start over with `x = 0`.

## Bug in the source

`fun(0)` falls off the end without executing a `return`. C++ says: **falling off a non-void function without returning is undefined behaviour**. On most compilers the return register happens to hold `0`, so the answer looks like `1 + 2 + 3 = 6` — but this is luck, not correctness.

Fix:

```cpp
int fun(int n)
{
    static int x = 0;
    if (n <= 0) return 0;   // explicit base case
    x++;
    return fun(n - 1) + x;
}
```

## When to use `static` in recursion

- **Memoisation caches** — global state persists across calls (see `9_1_Fib.cpp`'s `mfib`).
- **Accumulators** — pass state via a static instead of an extra parameter.
- **Only in single-threaded, single-instance code** — a `static` inside a function is a global, and globals are dangerous when the function is called from multiple threads or reset by an outer driver.

## Gotchas

- The initialiser (`= 0`) runs **once**, at first entry — subsequent calls skip it.
- `static` breaks referential transparency: `fun(3)` returns different values on successive top-level calls.
- Every C++ compiler enables warnings for missing returns — always compile with `-Wall -Wreturn-type`.
