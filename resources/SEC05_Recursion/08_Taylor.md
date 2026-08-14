# Taylor Series — `e^x` Three Ways

Source: `SEC05_Recursion/8_Taylor.cpp`

## The series

The Taylor expansion of `e^x` around 0:

```
e^x = 1 + x + x²/2! + x³/3! + ... + x^n/n!
```

Truncating at `n` terms gives an approximation. The three implementations below all compute the same thing but differ in structure.

## Version 1 — Iterative

```cpp
double taylor(int x, int n)
{
    double numer = 1, denom = 1, sum = 1;
    for (int i = 1; i <= n; i++)
    {
        numer = numer * x;    // xⁱ built incrementally
        denom = denom * i;    // i! built incrementally
        sum  += numer / denom;
    }
    return sum;
}
```

- Straightforward loop, O(n) time, O(1) space.
- Building `numer` and `denom` incrementally avoids recomputing powers/factorials from scratch.

## Version 2 — Recursion with static accumulators

```cpp
double e(int x, int n)
{
    static double p = 1;   // xⁿ across calls
    static double f = 1;   // n! across calls
    double r;
    if (n == 0)
        return 1;
    r = e(x, n - 1);       // recurse into deeper terms first
    p = p * x;             // update on the way up
    f = f * n;
    return r + p / f;
}
```

- Uses `static` locals so `p` and `f` accumulate as the stack unwinds.
- **Broken for repeated calls** — `p` and `f` persist across top-level calls, so `e(1, 5)` followed by `e(1, 5)` yields different answers. See `[[02_StaticVariables]]` for why `static` inside a function is dangerous.

## Version 3 — Horner's rule (recursive form)

Horner rewrites the series so each step needs only one multiplication and one addition:

```
e^x ≈ 1 + (x/1)(1 + (x/2)(1 + (x/3)(...(1 + x/n)...)))
```

```cpp
double eH(int x, int n)
{
    static double s = 1;
    if (n == 0)
        return 1;
    s = 1 + (double)x / n * s;
    return eH(x, n - 1);
}
```

- Fewer multiplications than the naïve form; each level contributes `1 + (x/i)*s`.
- Same static-state pitfall as Version 2.
- Source comments note "Below code is not working" — likely because the return should be `s`, not the recursive call's return. As written, `eH` returns whatever the deepest call returns (always `1`), ignoring `s`. Fix:

```cpp
double eH(int x, int n)
{
    static double s = 1;
    if (n == 0) return s;      // <- return the accumulator
    s = 1 + (double)x / n * s;
    return eH(x, n - 1);
}
```

## Which to use in an interview

- **Iterative** — safest, clearest, no hidden state.
- **Horner's rule** — best if the interviewer asks about numerical efficiency.
- **Static-based recursion** — clever but fragile; only mention if the interviewer explicitly wants a recursive version.

## Gotchas

- `static` variables retain values across top-level calls — reset them if you invoke the function multiple times.
- Integer `x` in `numer * x` can overflow long before the series converges; prefer `double x` for real inputs.
- The series only converges quickly for small `|x|`. For large `|x|`, use range reduction (e.g. `e^x = (e^(x/k))^k`).
