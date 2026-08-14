#include <iostream>

template <class T>
class Arithmetic
{
public:
    T _a;
    T _b;

    Arithmetic(T a, T b);

    T area();
};

template <class T>
Arithmetic<T>::Arithmetic(T a, T b) : _a{a}, _b{b}
{
}

template <class T>
T Arithmetic<T>::area()
{
    return _a * _b;
}

int main()
{
    Arithmetic<int> a(10, 20);
    std::cout << a.area() << std::endl;

    Arithmetic<float> f(10.2f, 11.3f);
    std::cout << f.area() << std::endl;

    return 0;
}