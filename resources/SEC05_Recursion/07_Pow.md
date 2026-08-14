# Power — Naïve vs. Fast Exponentiation

Source: `SEC05_Recursion/7_Pow.cpp`

## Problem

Compute `m^n` for integer `m` and non-negative integer `n`.

## Naïve recursion — O(n)

```cpp
int pow(int m, int n)
{
    if (n == 0)
        return 1;
    return pow(m, n - 1) * m;
}
```

- Recurrence: `m^n = m^(n-1) * m`.
- One multiplication per level; `n` levels → **O(n) multiplications**.
- Stack depth = `n + 1`.

## Fast exponentiation — O(log n)

Key idea:

```
If n is even:  m^n = (m^2)^(n/2)
If n is odd:   m^n = m × (m^2)^((n-1)/2)
```

Each squaring halves the exponent, so only ~log₂(n) multiplications are needed.

```cpp
int pow2(int m, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return pow(m * m, n / 2);
    return m * pow(m * m, (n - 1) / 2);
}
```

- **Note on the source**: `pow2` recurses into the O(n) `pow`, so the code-as-written is still O(n) overall. A true fast-power recurses into `pow2` itself:

```cpp
int fastPow(int m, int n)
{
    if (n == 0) return 1;
    if (n % 2 == 0) return fastPow(m * m, n / 2);
    return m * fastPow(m * m, (n - 1) / 2);
}
```

Only this "pure" version achieves O(log n). The table and trace below describe `fastPow`, i.e. what `pow2` *would* be if the inner call recursed correctly.

- Stack depth ≈ log₂(n) — for `n = 10^9` that's ~30 frames instead of a billion.

## Trace for `fastPow(2, 8)`

```
fastPow(2, 8)  = fastPow(4, 4)       (8 is even)
               = fastPow(16, 2)      (4 is even)
               = fastPow(256, 1)     (2 is even)
               = 256 * fastPow(65536, 0)   (1 is odd)
               = 256 * 1 = 256
```

Only 4 recursive calls to reach `2^8 = 256`.

## Complexity comparison

| Version | Multiplications | Stack depth |
|---|---|---|
| `pow` (naïve)        | n         | n + 1     |
| `pow2` (as written)  | O(n)      | ~log₂ n outer + O(n) inner |
| `fastPow` (pure)     | ~log₂ n   | ~log₂ n   |

## Gotchas

- The exponentiated base grows fast — `m*m` overflows `int` quickly. Use `long long` or modular arithmetic if working on interview problems.
- Handle `n < 0` explicitly (return `1 / pow(m, -n)` in double, or throw for `int`).
- For non-integer bases and exponents, use the standard `std::pow` from `<cmath>` — don't reinvent floating-point pow.
