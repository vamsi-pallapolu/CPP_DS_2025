# Recursion — First Example

Source: `SEC05_Recursion/1_Example.cpp`

## What is recursion?

A **recursive function** calls itself, either directly or indirectly, with a smaller sub-problem each time. Two ingredients are always present: a **base case** that stops the recursion, and a **recursive case** that makes progress toward the base. Missing either one → infinite recursion → stack overflow.

## Minimal example

```cpp
void fun(int n)
{
    if (n > 0)          // recursive case: keep going while n > 0
    {
        std::cout << n << std::endl;
        fun(n - 1);     // shrink toward the base case
    }
    // implicit base case: n <= 0 → do nothing, return
}

int main()
{
    fun(3);   // prints 3, 2, 1
    return 0;
}
```

- The condition `n > 0` guarantees termination — `n` decreases by 1 each call.
- Printing **before** the recursive call means output appears in descending order (3, 2, 1). If you moved the print **after** the call, the order would flip (1, 2, 3) — this is the head-vs-tail distinction covered in `3_HeadAndTailRecursion.cpp`.

## Call-stack picture

Every recursive call gets its own stack frame. For `fun(3)`:

```
main -> fun(3) -> fun(2) -> fun(1) -> fun(0) [returns]
                                     [fun(1) resumes, returns]
                             [fun(2) resumes, returns]
                     [fun(3) resumes, returns]
```

- Each frame holds its own `n` — they don't share state.
- Depth = 4 frames for input 3.

## Gotchas

- Deep recursion (e.g. `fun(1_000_000)`) overflows the stack; iteration is safer for very large `n`.
- Every recursive function must have a base case; check it first when debugging.
