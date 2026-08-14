# Fibonacci — Iterative Series Print

Source: `SEC05_Recursion/9_0_Fibonacci.cpp`

## What is a Fibonacci series?

`F(0) = 0`, `F(1) = 1`, and `F(n) = F(n-1) + F(n-2)` for `n >= 2`. First 10 terms: `0, 1, 1, 2, 3, 5, 8, 13, 21, 34`.

## Iterative printer

```cpp
void fibonacci(int n)
{
    if (n > 0)
    {
        int first  = 0;
        int second = 1;
        int current;
        for (int i = 1; i <= n; i++)
        {
            if (i == 1)               // print F(0)
            {
                std::cout << first << " ";
                continue;
            }
            if (i == 2)               // print F(1)
            {
                std::cout << second << " ";
                continue;
            }
            current = second + first; // F(i-1)
            std::cout << current << " ";
            first  = second;
            second = current;
        }
    }
    else
    {
        std::cout << "Enter input > 0" << std::endl;
    }
    std::cout << std::endl;
}
```

- Maintains only two variables (`first`, `second`) plus the running sum — O(1) space, O(n) time.
- Special-cases `i == 1` and `i == 2` to print the first two seed values without computing them.

## Simpler idiomatic version

The special cases can be avoided by seeding `first`/`second` and printing them before the loop:

```cpp
void fib(int n) {
    long long a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        std::cout << a << " ";
        long long next = a + b;
        a = b;
        b = next;
    }
    std::cout << '\n';
}
```

- Cleaner loop body, same asymptotic behaviour.
- `long long` since `F(93) = 12200160415121876738` already exceeds `int64` if you cross 93.

## Input handling

```cpp
std::cout << "Enter no of series>";
std::cin >> input;
fibonacci(input);
```

- Reads how many terms to print from `stdin`.
- No validation beyond the `n > 0` guard — non-integer input will leave `input` in an unspecified state (see `std::cin.fail()` for robust handling).

## Gotchas

- The source prints `n` terms (starting from `F(0)`), so `fibonacci(5)` prints `0 1 1 2 3` — five values.
- `int` overflows around `F(47)`. Use `long long` (safe until `F(92)`) or arbitrary precision beyond that.
- Recursive `F(n) = F(n-1) + F(n-2)` without memoisation is O(φⁿ) — exponential. Always iterate or memoise.
