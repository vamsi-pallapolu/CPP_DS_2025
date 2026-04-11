#include <iostream>

int loopFac(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}

int fact(int n)
{
    if (n == 0)
        return 1;
    return fact(n - 1) * n;
}

int main()
{
    int result;
    result = fact(3);
    std::cout << "Result:" << result << std::endl;
    std::cout << "Result:" << loopFac(3) << std::endl;

    return 0;
}