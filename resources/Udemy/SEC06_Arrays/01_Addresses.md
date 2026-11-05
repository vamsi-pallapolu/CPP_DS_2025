# Array Addresses

Source: `SEC06_Arrays/1_Addresses.cpp`

## Why array elements have contiguous addresses

A C/C++ array is a **contiguous block of memory**. Element `i` sits exactly `i * sizeof(T)` bytes after element `0`. This is what makes `A[i]` and `*(A + i)` equivalent — the compiler multiplies the index by the element size and adds to the base pointer.

## Example

```cpp
int A[3];
int size = sizeof(A) / sizeof(A[0]);   // 3 — works only in scope, before decay
for (int i = 0; i < size; i++)
{
    printf("%u\n", &A[i]);   // address of element i
    printf("%u\n", (A + i)); // same address, via pointer arithmetic
}
```

Typical output (addresses will differ per run):

```
3221221828
3221221828
3221221832
3221221832
3221221836
3221221836
```

Each pair of lines is identical because `&A[i]` **is** `A + i` — they compile to the same instruction. Consecutive addresses differ by `sizeof(int)` = 4 bytes.

## `sizeof(A) / sizeof(A[0])` trick

The classic C idiom for **compile-time array length**:

- `sizeof(A)` — total bytes of the array (only works while `A` is still an array type, not after decay to a pointer).
- `sizeof(A[0])` — bytes per element.
- Ratio → number of elements.

```cpp
int A[10];
size_t n = sizeof(A) / sizeof(A[0]);  // 10
```

- Fails silently if you pass `A` to a function — inside the function it's a pointer, and `sizeof` returns the pointer size (usually 8), giving a wrong answer.
- In C++, prefer `std::size(A)` (C++17) or `std::array<int, N>::size()` for clarity.

## Pointer arithmetic — units are elements, not bytes

`A + 1` advances by `sizeof(int)` bytes automatically. You never multiply by `sizeof` manually when doing pointer arithmetic — the compiler scales for you.

```cpp
int *p = A;
p += 2;    // now points to A[2], moved by 2 * sizeof(int) = 8 bytes
```

## Gotchas

- `%u` is the format specifier for `unsigned int`, but addresses on 64-bit systems are 8 bytes — use `%p` (and cast to `void*`) for portable, warning-free output.
- Never rely on printed addresses across runs — ASLR randomises them.
- Once the array decays to a pointer (e.g. inside a function parameter), you lose `sizeof`-based length info. Pass the length as a separate parameter.
