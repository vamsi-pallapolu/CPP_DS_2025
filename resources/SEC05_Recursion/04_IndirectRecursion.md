# Indirect (Mutual) Recursion

Source: `SEC05_Recursion/4_IndirectRecursion.cpp`

## What is indirect recursion?

**Indirect recursion** happens when function A calls function B, and B (eventually) calls A. Neither function calls itself directly, but together they form a recursive cycle. Also called **mutual recursion**.

## Example

```cpp
void funB(int);          // forward declaration — needed because funA uses funB before it is defined

void funA(int n)
{
    if (n > 0)
    {
        std::cout << n << " ";
        funB(n - 1);      // A calls B
    }
}

void funB(int n)
{
    if (n > 1)
    {
        std::cout << n << " ";
        funA(n / 2);      // B calls A
    }
}

int main()
{
    funA(20);
    return 0;
}
```

Trace `funA(20)`:

| Step | Call | Prints | Next |
|---|---|---|---|
| 1 | `funA(20)` | 20 | `funB(19)` |
| 2 | `funB(19)` | 19 | `funA(9)`  (19/2 = 9) |
| 3 | `funA(9)`  | 9  | `funB(8)` |
| 4 | `funB(8)`  | 8  | `funA(4)` |
| 5 | `funA(4)`  | 4  | `funB(3)` |
| 6 | `funB(3)`  | 3  | `funA(1)` |
| 7 | `funA(1)`  | 1  | `funB(0)` |
| 8 | `funB(0)`  | —  | base case (`n > 1` false), return |

Output: `20 19 9 8 4 3 1`

## Why the forward declaration?

C++ resolves names top-down through a file. `funA` references `funB` before the compiler has seen its definition, so a **prototype** (`void funB(int);`) must appear first — otherwise the compile fails with "use of undeclared identifier".

## Common use cases

- **Parsing** — e.g. `parseExpression` calls `parseTerm`, which calls `parseFactor`, which may call back to `parseExpression` for parenthesised sub-expressions.
- **State machines** — one function per state, each transitioning by calling the next.
- **Even/odd** as a teaching example: `isEven(n)` calls `isOdd(n-1)` and vice versa.

## Gotchas

- Termination is subtler than direct recursion — you must show that some measure (here, `n`) decreases across the *cycle*, not just one function.
- Forward declarations must match the definition exactly (return type, parameter types, `const`).
- Indirect recursion cannot be tail-call-optimised across compilation units unless both functions are visible at optimisation time.
