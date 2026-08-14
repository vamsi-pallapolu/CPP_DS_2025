#include <iostream>
void funB(int);
void funA(int n)
{
    if (n > 0)
    {
        std::cout << n << " ";
        funB(n - 1);
    }
}

void funB(int n)
{
    if (n > 1)
    {
        std::cout << n << " ";
        funA(n/2);
    }
}

int main()
{
    funA(20);
    return 0;
}