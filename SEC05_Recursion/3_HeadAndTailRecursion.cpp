#include <iostream>

// Head Recursion
void head(int n)
{
    if (n > 0)
    {
        head(n - 1);
        std::cout << n << std::endl;
    }
}

// Tail recursion
void tail(int n)
{
    if (n > 0)
    {
        std::cout << n << std::endl;
        tail(n - 1); // There shouldn't be any statements after function call
    }
}

int main()
{

    int result = 0;
    tail(3);
    head(3);
    return 0;
}