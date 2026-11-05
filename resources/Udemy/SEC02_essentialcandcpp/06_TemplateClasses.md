# Template Classes

Source: `SEC02_essentialcandcpp/6_TemplateClasses.cpp`

## What is a class template?

A **class template** is a blueprint parameterised by one or more types. The compiler generates a concrete class for each type you instantiate with — `Arithmetic<int>` and `Arithmetic<float>` are distinct types built from the same template source. It's how the STL provides `vector<T>`, `map<K,V>`, etc. without duplicating code.

## Declaration

```cpp
template <class T>
class Arithmetic
{
public:
    T _a;
    T _b;

    Arithmetic(T a, T b);
    T area();
};
```

- `template <class T>` (or the equivalent `template <typename T>`) precedes the class.
- `T` is a placeholder — replaced at instantiation time with the concrete type.
- Members can be any type expression involving `T`.

## Out-of-line definitions

```cpp
template <class T>
Arithmetic<T>::Arithmetic(T a, T b) : _a{a}, _b{b}
{
}

template <class T>
T Arithmetic<T>::area()
{
    return _a * _b;
}
```

- Every out-of-line definition must repeat `template <class T>`.
- The class name becomes `Arithmetic<T>` — the `<T>` is required.
- `: _a{a}, _b{b}` is a **member initialiser list** using brace-init syntax — preferred over assigning inside the body.

## Instantiation

```cpp
Arithmetic<int>   a(10, 20);      // T = int
std::cout << a.area() << '\n';    // 200

Arithmetic<float> f(10.2f, 11.3f); // T = float
std::cout << f.area() << '\n';     // 115.26
```

- The `<int>` / `<float>` picks the concrete type.
- Each instantiation produces a fresh class the compiler compiles independently.

## Why templates live in headers

Because the compiler needs the **full template body** at every instantiation site to generate the code, template definitions almost always live in `.h` files (or `.hpp` / `.ipp`) rather than in a separate `.cpp`. Splitting them like non-template code causes linker errors.

## Gotchas

- The requirement `T * T -> T` in `area()` is implicit — try `Arithmetic<std::string>` and it fails to compile because `std::string * std::string` is not defined.
- `class` and `typename` are interchangeable in a template parameter list — `template <typename T>` is more modern and preferred.
- Compile times grow with heavy template use; each unique instantiation is a fresh compilation of the template body.
