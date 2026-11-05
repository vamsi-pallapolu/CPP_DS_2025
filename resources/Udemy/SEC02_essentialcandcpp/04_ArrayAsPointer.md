# Array as a Pointer

Source: `SEC02_essentialcandcpp/4_ArrayAsPoin.cpp`

## What does "array decays to a pointer" mean?

When an array is **passed to a function** (or used in most expressions), it *decays* into a pointer to its first element. The function no longer knows the array's length — you must pass it separately. Indexing (`A[i]`) and pointer arithmetic (`*(A + i)`) then become interchangeable.

## Passing an array to a function

```cpp
void printArray(const int *A, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << *(A + i);   // equivalent to A[i]
    }
    const int *B = A;            // copy the pointer, not the data
    for (int i = 0; i < size; i++)
    {
        std::cout << *(B + i);
    }
}
```

- The parameter `const int *A` and `const int A[]` are **the same declaration** — the array form is a stylistic hint only.
- `size` must be passed separately; `sizeof(A)` inside the function gives `sizeof(int*)`, not the array size.
- `const` prevents the callee from mutating the underlying elements (`A[1] = 10;` would fail to compile).

## `A[i]` vs `*(A + i)`

The compiler translates `A[i]` into `*(A + i)` — they are *literally* the same operation. As a curiosity, `i[A]` is also legal C/C++ and produces the same result, because `+` is commutative.

## Returning a heap pointer

```cpp
int *func(int n)
{
    int *p = (int *)malloc(n * sizeof(int));
    return p;   // caller now owns this memory
}

int *a = func(3);   // remember to free(a) later
```

- Safe because `p` refers to **heap** memory, which outlives the function.
- Contrast with returning `&localArray` — that pointer would dangle immediately.

## Gotchas

- `sizeof(array)` inside a function gives pointer size (typically 8 bytes on 64-bit), not the array's byte size.
- Arrays cannot be passed by value in C/C++ — you always get the decayed pointer.
- Prefer `std::span<const int>` (C++20) or `std::vector<int> const &` for safer, size-carrying array parameters.
