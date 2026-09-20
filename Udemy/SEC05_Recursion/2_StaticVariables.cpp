#include <iostream>

int fun(int n)
{
    static int x = 0;
    if (n > 0)
    {
        x++;
        return fun(n - 1) + x;
    }
}

int main()
{
    int n = 3;
    int result;
    result = fun(3);
    std::cout << "Result:" << result << std::endl;
    return 0;
}