# Array ADT — Static Buffer + Aggregate Initialisation

Source: `SEC07_ArrayADT/2_Insert.cpp`

## What changed vs. the dynamic version?

Same conceptual `Array` ADT, but the buffer is a **fixed-size C array member** (`int A[10]`) instead of a heap pointer. This trades flexibility (max 10 elements, ever) for simplicity (no `malloc`, no `free`, initialisable at declaration).

## The struct

```cpp
struct Array {
    int A[10];    // fixed capacity 10
    int _size;    // capacity as tracked by the ADT
    int _length;  // number of valid elements
};
```

- `_size` is a bit redundant here — the buffer is already sized 10 — but keeping it lets algorithms written against the ADT stay identical regardless of storage.

## Aggregate initialisation

```cpp
struct Array array = {{2, 3, 4, 5, 6}, 10, 5};
```

- Field order matters: `{A[]}, _size, _length`.
- Only the first 5 slots of `A` are given; the remaining 5 are value-initialised to `0`.
- This shorthand only works because the members are all "plain" (POD types, aggregate rules).

## Iterating with `_length`, not capacity

```cpp
void displayElements(const struct Array &array){
    for(int i = 0; i < array._length; i++){
        printf("%d", array.A[i]);
    }
}
```

- Correct choice this time: use `_length` (valid elements) so you don't print the zero-initialised tail.
- Compare with `1_Array.cpp` where the loop mistakenly used `size` — a good side-by-side of the ADT invariant.

## Static vs. dynamic buffer trade-off

| Aspect | `int A[10]` (this file) | `int *A = malloc(...)` (prev file) |
|---|---|---|
| Capacity fixed at | compile time | runtime |
| Storage location | stack (if local) / data segment | heap |
| Needs `free` | no | yes |
| Can grow | no | yes (reallocate) |
| Value-init possible | yes (aggregate list) | no (malloc gives garbage) |

## Gotchas

- The struct is **passed by reference** (`const Array &`); pass-by-value would copy all 10 ints every call.
- Positional aggregate init `{{2,3,4,5,6}, 10, 5}` still works in C++20 — it is not deprecated. C++20 additionally allows **designated initialisers** (`{ .A = {...}, ._size = 10, ._length = 5 }`), which are clearer when the struct has many fields.
