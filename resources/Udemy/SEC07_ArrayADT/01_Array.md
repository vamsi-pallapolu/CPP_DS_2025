# Array ADT — Struct with Dynamic Buffer

Source: `SEC07_ArrayADT/1_Array.cpp`

## What is an Array ADT?

An **Array ADT** wraps a raw contiguous buffer with metadata (capacity + current length) so higher-level operations (insert, delete, search) can be built on top. Separating `size` (capacity) from `length` (elements currently used) is the key idea — it lets you insert without reallocating until the buffer is full.

## The `Array` struct

```cpp
struct Array
{
    int *A;      // pointer to a heap-allocated buffer
    int size;    // capacity of the buffer
    int lenght;  // number of valid elements (typo preserved from source)
};
```

- `A` points to memory obtained from `malloc` — the buffer lives on the heap, so its size can be chosen at runtime.
- `size` is fixed once allocated; `lenght` grows/shrinks as elements are inserted or removed.

## Allocating the buffer

```cpp
struct Array array;
scanf("%d", &array.size);

array.A = (int *)malloc(array.size * sizeof(int));
array.lenght = 0;
```

- `malloc` returns `void*`; the C-style cast to `int*` is required in C++.
- Always multiply by `sizeof(int)` — `malloc` takes **bytes**, not element count.
- Initialise `lenght = 0` so the ADT knows it is empty.

## Displaying elements

```cpp
void displayElements(const struct Array &array){
    for(int i = 0; i < array.size; i++){
        printf("%d", array.A[i]);
    }
}
```

- Passed by `const &` — no copy, and the callee cannot mutate the wrapper.
- Bug to watch for: the loop uses `array.size` (capacity) instead of `array.lenght`, so it reads past the valid elements. **But** in this program `lenght` is never incremented on insert (stays at `0`) — so naively switching to `lenght` would print nothing. The real fix is to increment `array.lenght++` inside the input loop *and* iterate to `lenght` here.

## Reading elements from stdin

```cpp
for (int i = 0; i < n; i++)
{
    scanf("%d", &array.A[i]);
}
```

- `&array.A[i]` gives the address of the i-th element; equivalent to `array.A + i`.
- `n` here is user-supplied and must satisfy `n <= array.size`, else out-of-bounds writes occur.

## Gotchas

- `malloc` does **not** initialise memory — new cells contain garbage.
- Forgetting `free(array.A)` before program exit is a leak (small in a short program, catastrophic in a loop).
- In C++, prefer `new int[size]` / `delete[]` over `malloc` / `free` for consistency with RAII.
- The typo `lenght` propagates through the code — a lesson in why compilers can't save you from misspelled field names.
