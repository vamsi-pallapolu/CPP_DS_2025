# Pointer to a Struct

Source: `SEC02_essentialcandcpp/3_PointToStruct.cpp`

## What is a struct pointer?

A **pointer to a struct** stores the address of a struct instance. It's how you refer to heap-allocated aggregates or pass structs efficiently without copying. Member access uses either `(*p).field` (dereference then dot) or the shorthand `p->field`.

## Heap-allocated struct

```cpp
struct Rectangle
{
    int length;
    int breadth;
};

struct Rectangle *r;
r = (struct Rectangle *)malloc(sizeof(struct Rectangle));
(*r).length = 10;  // dereference-and-access
r->breadth  = 20;  // arrow shorthand — same thing
free(r);
```

- `(*r).length` and `r->length` are equivalent; `->` exists because `.` has higher precedence than `*`, so `*r.length` would try to dereference the field first.
- Always pair `malloc` with `free`.

## Stack-allocated struct + pointer

```cpp
Rectangle r3 = {10, 20};
Rectangle *p = &r3;
std::cout << p->length << std::endl;   // 10
std::cout << p->breadth << std::endl;  // 20
```

- `&r3` gives the address of a stack object — valid only while `r3` is in scope.
- No `free` needed — the compiler cleans up when the scope ends.

## Array of structs + range-for

```cpp
Rectangle r2[] = {{10, 20}};
for (const Rectangle &r : r2)  // const & avoids copy + prevents mutation
    std::cout << r.length << std::endl;
```

- `{{10, 20}}` is nested braces: outer for the array, inner for one `Rectangle`.
- `const Rectangle &` is the idiomatic loop variable for large or non-trivial types.

## `.` vs `->` — precedence

`.` binds tighter than `*`. So:

- `*r.length` means `*(r.length)` — tries to dereference an `int`, compile error.
- `(*r).length` is the correct dereference-then-access.
- `r->length` is sugar for the same thing.

## Gotchas

- In C++, the `struct` keyword before the type name is optional (`Rectangle *r`); in C it is mandatory unless you `typedef`.
- `malloc` does **not** call constructors — fine for POD types like `Rectangle`, but never use it for classes with non-trivial constructors.
- The source prints `r` itself (`std::cout << r`) which prints the **address**, not the fields. To see field values use `r->length`, etc.
