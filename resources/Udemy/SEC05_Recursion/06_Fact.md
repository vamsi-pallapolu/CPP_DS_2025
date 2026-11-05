# Factorial — Recursive and Iterative

Source: `SEC05_Recursion/6_Fact.cpp`

## Problem

Compute `n! = 1 × 2 × 3 × ... × n`, with `0! = 1` by convention.

## Recursive version

```cpp
int fact(int n)
{
    if (n == 0)             // base case — includes the 0! = 1 convention
        return 1;
    return fact(n - 1) * n;
}
```

- Recurrence: `fact(n) = fact(n-1) * n`.
- Depth: `n + 1` stack frames.
- Same head-vs-tail note as `sum`: the `* n` after the call means this is *not* tail recursion.

## Iterative version

```cpp
int loopFac(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}
```

- O(n) time, O(1) space — no stack growth.
- Prefer this in production for anything beyond very small `n`.

## Trace for `fact(3)`

```
fact(3) = fact(2) * 3
        = (fact(1) * 2) * 3
        = ((fact(0) * 1) * 2) * 3
        = ((1 * 1) * 2) * 3
        = 6
```

## Overflow ceiling

`int` is typically 32-bit, so:

| n | n! | fits in int32? |
|---|---|---|
| 12 | 479 001 600 | yes |
| 13 | 6 227 020 800 | **no** — overflows |

- Use `long long` (up to 20!) or arbitrary-precision libraries for larger values.
- The source code silently overflows for `n >= 13` — a common interview trap.

## Gotchas

- Never call `fact(-1)` — infinite recursion. If negative inputs are possible, guard: `if (n < 0) return -1;` or throw.
- The recursive version is elegant but 20× slower than the loop for large `n` due to function-call overhead.
