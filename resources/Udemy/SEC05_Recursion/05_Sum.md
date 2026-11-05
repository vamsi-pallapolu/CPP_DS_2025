# Recursive Sum — 1 to N

Source: `SEC05_Recursion/5_Sum.cpp`

## Problem

Compute `1 + 2 + ... + n` for `n >= 0`. This is a classic first-recursion problem because the recurrence is trivial: `sum(n) = sum(n-1) + n`.

## Recursive solution

```cpp
int sum(int n)
{
    if (n == 0)          // base case
        return 0;
    return sum(n - 1) + n;   // recursive case
}
```

- Base: `sum(0) = 0`.
- Recurrence: `sum(n) = sum(n-1) + n`.

## Trace for `n = 3`

```
sum(3) = sum(2) + 3
       = (sum(1) + 2) + 3
       = ((sum(0) + 1) + 2) + 3
       = ((0 + 1) + 2) + 3
       = 6
```

## Head vs. tail form

The expression `sum(n - 1) + n` is **not** tail recursion — the `+ n` runs after the recursive call returns. It's technically head recursion.

You can rewrite it in tail form with an accumulator:

```cpp
int sumTail(int n, int acc = 0)
{
    if (n == 0) return acc;
    return sumTail(n - 1, acc + n);   // pure tail call
}
```

The accumulator carries the partial sum down, so nothing remains to be done after the recursive call.

## Closed form

Recursion is a nice **exercise** here, but for real code use Gauss's formula:

```cpp
int sumClosed(int n) { return n * (n + 1) / 2; }
```

O(1) time, no stack growth.

## Gotchas

- For `n` above ~10⁵, recursion overflows the default stack. Use iteration or the closed form.
- `int` overflows around `n ≈ 65535` for the closed form and much sooner if `n * (n+1)` is computed with `int`. Use `long long` for large inputs.
