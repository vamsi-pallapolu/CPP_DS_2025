# Array ADT

An **Array ADT (Abstract Data Type)** is a collection that stores elements in contiguous memory locations and lets you access each element using an index.

For example:

```cpp
int arr[5] = {10, 20, 30, 40, 50};
```

Here, `arr[0]` is `10` and `arr[4]` is `50`.

## Key operations

- Access by index: `arr[i]` — **O(1)** time
- Update an element — **O(1)**
- Traverse all elements — **O(n)**
- Insert or delete at the end — often **O(1)** if capacity remains
- Insert or delete in the middle or beginning — **O(n)** because elements must shift
- Search an unsorted array — **O(n)**; a sorted array can use binary search in **O(log n)**

## Typical representation

An array ADT typically maintains:

```cpp
struct Array {
    int A[100];   // storage
    int size;     // maximum capacity
    int length;   // currently used elements
};
```

`size` is the capacity, while `length` is the number of actual stored values.

## Advantages and limitations

The main advantage of an array is very fast indexed access.

The main limitation is that fixed-size arrays cannot grow beyond their allocated capacity. Dynamic arrays can grow, but resizing may require copying elements.
