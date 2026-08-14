# Static vs. Dynamic Arrays

Source: `SEC06_Arrays/2_StaticAndDynamic.cpp`

## Static array — size known at compile time

```cpp
int A[] = {2, 4, 6, 8, 10};
```

- **Storage**: stack (if local) or data segment (if global/static).
- **Lifetime**: tied to enclosing scope.
- **Size**: fixed by initialiser, cannot be changed.
- **Access**: `A[i]` — direct.

## Dynamic array — size known at runtime

```cpp
int *p = (int *)malloc(5 * sizeof(int));
p[0] = 3;
p[1] = 5;
p[2] = 7;
p[3] = 9;
p[4] = 11;
```

- **Storage**: heap.
- **Lifetime**: from `malloc` until `free(p)` (must be released explicitly).
- **Size**: chosen at allocation time; can be replaced via `realloc` or a fresh `malloc`.
- **Access**: `p[i]` — the compiler translates to `*(p + i)`, same as arrays.

## Side-by-side

| Aspect | Static (`int A[5]`) | Dynamic (`int *p = malloc(...)`) |
|---|---|---|
| Size determined at | compile time | runtime |
| Where it lives | stack / data | heap |
| Lifetime | scope | until explicitly freed |
| Resizeable | no | via `realloc` |
| Needs manual cleanup | no | yes (`free`) |
| `sizeof` gives | total array bytes | pointer size |
| Fastest allocation | yes (stack bump) | slower (heap metadata) |

## When to pick each

- **Static** when the size is a small compile-time constant and the array lives for a well-defined scope.
- **Dynamic** when the size is unknown at compile time, or when the array must outlive the function that allocates it.
- In modern C++, prefer `std::vector<int>` — it wraps dynamic allocation with automatic cleanup and resizing.

## Gotchas

- Very large static local arrays (`int A[10'000'000]`) overflow the stack — use heap allocation or `std::vector`.
- `p[i]` and `A[i]` look identical but the underlying storage is completely different — be conscious of ownership.
- `malloc(5 * sizeof(int))` **doesn't zero-initialise** — the values you read before writing are garbage.
- Never `free` a pointer to a static array — undefined behaviour.
