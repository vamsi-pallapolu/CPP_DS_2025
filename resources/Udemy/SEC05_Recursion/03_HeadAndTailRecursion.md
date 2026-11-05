# Head vs. Tail Recursion

Source: `SEC05_Recursion/3_HeadAndTailRecursion.cpp`

## Definitions

- **Tail recursion** — the recursive call is the **last** operation in the function. Nothing happens after it returns.
- **Head recursion** — the recursive call happens **first** (before any other work), so the "work" runs as the stack unwinds.

The difference matters because tail-recursive functions can often be transformed by the compiler into a plain loop (**tail-call optimisation**), reusing the current stack frame instead of pushing a new one.

## Tail recursion — print first, recurse last

```cpp
void tail(int n)
{
    if (n > 0)
    {
        std::cout << n << std::endl;   // work happens on the way down
        tail(n - 1);                   // recursive call is the LAST thing
    }
}
```

- `tail(3)` prints `3, 2, 1`.
- With `-O2` on Clang/GCC, this often becomes a simple loop — no stack growth.

## Head recursion — recurse first, print last

```cpp
void head(int n)
{
    if (n > 0)
    {
        head(n - 1);                   // recursive call is FIRST
        std::cout << n << std::endl;   // work happens on the way UP
    }
}
```

- `head(3)` prints `1, 2, 3` — the *reverse* order, because the deepest call prints first.
- Cannot be tail-call-optimised — every frame still has work pending when the recursive call returns.

## Side-by-side trace for `n = 3`

| Step | Tail (down) | Head (up) |
|---|---|---|
| enter `f(3)` | print 3 | (no print yet) |
| enter `f(2)` | print 2 | (no print yet) |
| enter `f(1)` | print 1 | (no print yet) |
| enter `f(0)` | return | return |
| unwind `f(1)` | — | print 1 |
| unwind `f(2)` | — | print 2 |
| unwind `f(3)` | — | print 3 |

## Rule of thumb

- Need output/work in **natural order**? Use **tail** recursion.
- Need output/work in **reverse order** (e.g. printing a linked list backwards)? Use **head** recursion.
- If performance matters and depth is large, prefer tail recursion (compiler-optimisable) or convert to a loop.

## Gotchas

- "There shouldn't be any statements after the function call" — that's the strict definition of tail. Even `return f(n-1) + 1;` is **not** tail recursion, because the `+ 1` runs after the call.
- C++ does **not** guarantee tail-call optimisation. Enable optimisations (`-O2`) and inspect assembly to confirm.
