#include <iostream>

void fun(int n)
{
    if (n > 0)
    {
        std::cout << n << std::endl;
        fun(n - 1);
    }
}

int main()
{
    fun(3);
    return 0;
} 