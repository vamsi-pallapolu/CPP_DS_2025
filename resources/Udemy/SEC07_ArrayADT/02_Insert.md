# Array ADT — Append & Insert

Source: `SEC07_ArrayADT/2_Insert.cpp`

## What changed vs. the dynamic version?

Same conceptual `Array` ADT, but the buffer is a **fixed-size C array member** (`int A[10]`) instead of a heap pointer. This trades flexibility (max 10 elements, ever) for simplicity (no `malloc`, no `free`, initialisable at declaration). On top of that base, this file adds two mutation operations — `append` and `insert` — that are the building blocks for every array-based ADT.

## The struct

```cpp
struct Array {
    int A[10];    // fixed capacity 10
    int _size;    // capacity as tracked by the ADT
    int _length;  // number of valid elements
};
```

- `_size` is redundant with the fixed capacity of 10, but keeping it lets algorithms written against the ADT stay identical regardless of storage.

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
    std::cout << std::endl;
}
```

- Use `_length` (valid elements), not `_size`, so you don't print the zero-initialised tail.
- The trailing `std::endl` makes each call print on its own line — handy when calling `displayElements` between mutations.

## Append — O(1)

Push an element onto the end of the array.

```cpp
void append(Array &array, int element) {
    if(array._length < array._size) {
        array.A[array._length] = element;
        array._length++;
    }
}
```

- **Guard**: `_length < _size` prevents writing past the buffer.
- **Post-increment position**: write at index `_length`, then bump `_length`.
- **Cost**: constant time — one write, no shifting.
- **Silently fails** if the array is full. A production ADT would return a status or throw.

## Insert at index — O(n)

Place an element at a specific index, shifting the tail right by one.

```cpp
void insert(Array &array, int index, int element){
    if(index >= 0 && index <= array._length){
        for(int i = array._length; i > index; i--){
            array.A[i] = array.A[i-1];
        }
        array.A[index] = element;
        array._length++;
    }
}
```

- **Valid range**: `0 <= index <= _length`. `index == _length` is legal — it's just an append. `index == _size` is not (that's past the last valid slot, and would also overflow the buffer).
- **Shift right-to-left**: copy `A[i-1] → A[i]` starting from the tail. Going left-to-right would overwrite values before you copy them.
- **Cost**: linear — up to `_length` writes.
- **No capacity check.** If the caller passes a valid index but `_length == _size`, the shift writes to `A[_size]`, which is out of bounds. A robust version would also require `_length < _size`.

### Walkthrough

Starting with `{2, 3, 4, 5, 6, 7}` (`_length = 6`):

| Call | Result | `_length` |
|---|---|---|
| `insert(array, 0, 10)` | `{10, 2, 3, 4, 5, 6, 7}` | 7 |
| `insert(array, 6, 20)` | `{10, 2, 3, 4, 5, 6, 20, 7}` | 8 |

The second call inserts `20` before the last element (index 6 was `7`), pushing `7` to index 7.

## Complexity summary

| Operation | Time | Space |
|---|---|---|
| `displayElements` | O(n) | O(1) |
| `append` | O(1) | O(1) |
| `insert(index, x)` | O(n) worst case (insert at 0), O(1) best case (insert at end) | O(1) |

## Static vs. dynamic buffer trade-off

| Aspect | `int A[10]` (this file) | `int *A = malloc(...)` (prev file) |
|---|---|---|
| Capacity fixed at | compile time | runtime |
| Storage location | stack (if local) / data segment | heap |
| Needs `free` | no | yes |
| Can grow | no | yes (reallocate) |
| Value-init possible | yes (aggregate list) | no (malloc gives garbage) |

## Gotchas

- The struct is **passed by reference** (`Array &`); pass-by-value would copy all 10 ints every call. `displayElements` uses `const Array &` because it doesn't mutate; `append` and `insert` drop the `const` because they do.
- **Shift direction matters** in `insert`. Iterating `i` from `index` up to `_length` would clobber every element with `A[index]`. Always shift from the tail inward when making room.
- **Silent failures**: both `append` (full buffer) and `insert` (bad index) do nothing when their guard fails. Callers can't tell success from no-op — consider returning `bool` or an error code.
- `insert` allows `index == _length` (append semantics) but the loop body simply doesn't run in that case — the single write to `A[index]` places the element at the end.
- Positional aggregate init `{{2,3,4,5,6}, 10, 5}` still works in C++20 — it is not deprecated. C++20 additionally allows **designated initialisers** (`{ .A = {...}, ._size = 10, ._length = 5 }`), which are clearer when the struct has many fields.
