#include <iostream>

int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return sum(n - 1) + n;
}

int main()
{
    std::cout << sum(3) << std::endl;
    return 0;
}