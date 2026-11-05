# Passing Structs as Parameters

Source: `SEC02_essentialcandcpp/5_StructAsParam.cpp`

## Three ways to pass a struct

1. **By value** — the callee gets a copy; mutations don't propagate. Cost: a full struct copy.
2. **By reference** (`T &`) — no copy, mutations propagate to the caller.
3. **By const reference** (`const T &`) — no copy, callee cannot mutate. Idiomatic default for read-only parameters.

## Pass by reference

```cpp
void area(struct Rectangle &r)
{
    r.length = 20;   // mutates the caller's Rectangle
    std::cout << r.length * r.breadth << std::endl;
}

int main() {
    struct Rectangle r = {10, 20};
    area(r);
    std::cout << r.length << std::endl;  // prints 20 — mutation visible
}
```

- `&` in a parameter declaration means reference, not "address of".
- No pointer syntax needed at the call site — just `area(r)`.

## Pass by value (commented alternative)

```cpp
// void area(struct Rectangle r)
// {
//     std::cout << r.length * r.breadth << std::endl;
// }
```

- The `r` inside is a **copy** — mutating it would not affect the caller.
- For structs with only two `int`s this is cheap; for larger structs it costs a real copy per call.

## Structs holding arrays

```cpp
struct Rect
{
    int A[3] = {1, 2, 3};   // default member initialiser
};

void print(struct Rect r)   // pass by value here
{
    for (int i = 0; i < 3; i++)
        std::cout << *(r.A + i) << std::endl;
}
```

- **Arrays wrapped in a struct DO get copied on pass-by-value** — unlike bare arrays, which decay to pointers.
- That's one motivation for structs: they restore value semantics to arrays.

## When to pick which

| Situation | Best choice |
|---|---|
| Read-only, small struct | value or `const &` |
| Read-only, large struct | `const &` |
| Callee must mutate | `&` |
| Optional / may be null | `T *` |

## Gotchas

- `&` in a parameter position is a reference; `&r` in an expression is address-of. Same symbol, different roles.
- Default member initialisers (`int A[3] = {1, 2, 3};`) require C++11 or later.
- Pass-by-reference lets the callee silently mutate — use `const &` unless mutation is the intended behaviour.
