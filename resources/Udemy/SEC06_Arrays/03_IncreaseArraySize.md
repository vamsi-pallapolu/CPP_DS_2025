# Growing a Dynamic Array

Source: `SEC06_Arrays/3_IncreaseArraySize.cpp`

## The problem

Once a heap array is allocated with `malloc(5 * sizeof(int))`, its size is **fixed**. To "grow" it you must:

1. Allocate a larger new block.
2. Copy old elements into the new block.
3. Free the old block.
4. Update your pointer to point to the new block.

This is exactly what `std::vector::push_back` does behind the scenes when capacity is exceeded.

## Manual grow — step by step

```cpp
int *p, *q;
p = (int *)malloc(5 * sizeof(int));
p[0]=3; p[1]=4; p[2]=5; p[3]=6; p[4]=7;

q = (int *)malloc(10 * sizeof(int));   // 1. bigger block

for (int i = 0; i < 5; i++)
    q[i] = p[i];                        // 2. copy old elements

free(p);                                // 3. free old block
p = q;                                  // 4. point p at new block
p = NULL;                               // clear the redundant handle
```

- After `free(p)`, the memory `p` used to reference is invalid — using it is a **use-after-free** bug.
- Reassigning `p = q;` makes both `p` and `q` point to the same new block.
- Setting `p = NULL;` is defensive: if code accidentally uses `p` again, dereferencing NULL crashes fast rather than corrupting memory silently.

## Why not just use `realloc`?

The standard library provides `realloc`, which does the same job in one call and *may* extend in place if adjacent memory is free:

```cpp
p = (int *)realloc(p, 10 * sizeof(int));   // resize p to hold 10 ints
```

- If `realloc` moves the block, it copies the old contents automatically.
- Returns `NULL` on failure **without freeing the old block** — always assign to a temporary first: `void *tmp = realloc(p, n); if (!tmp) { /* handle */ } p = tmp;`.

## In C++: use `std::vector`

```cpp
std::vector<int> v = {3, 4, 5, 6, 7};
v.resize(10);       // grows; new slots are zero-initialised
v.push_back(11);    // grows automatically if capacity exhausted
```

- Handles allocation, copy, and free for you.
- Amortised O(1) `push_back` — capacity typically doubles, so growth is rare.

## Growth-factor rule of thumb

To keep insertions amortised O(1), grow by a **multiplicative** factor (e.g. 1.5× or 2×), never a fixed increment. Growing by "+10 each time" gives O(n²) total work when appending n elements.

## Gotchas

- Order matters: `free(p)` *before* `p = q` is required. If you did `p = q; free(p);` you'd free the new block and leak the old one.
- The `p = NULL;` line in the source runs **immediately after** `p = q;` — so `p` never actually points at `q`. If you wanted `p` to be the surviving handle to the new block, remove `p = NULL;` or move it later.
- Always match `malloc`/`free`, `new`/`delete`, `new[]`/`delete[]`. Never cross the streams.
