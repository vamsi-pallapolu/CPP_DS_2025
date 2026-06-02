#include <iostream>
/*
    Fibonacci series: 0 1 1 2 3 5 8 13 ...
    Added three variants of fibnacci series

*/

int F[10];

int mfib(int n)
{
    if (n <= 1)
        return n;
    else
    {
        if (F[n - 2] == -1)
            F[n - 2] = mfib(n - 2);
        if (F[n - 1] == -1)
            F[n - 1] = mfib(n - 1);
        return F[n - 2] + F[n - 1];
    }
}

int rfib(int n)
{
    if (n <= 1)
        return n;
    return rfib(n - 2) + rfib(n - 1);
}

int fib(int n)
{

    int t0 = 0, t1 = 1, s = 0;
    if (n <= 1)
        return n;
    for (int i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int main()
{
    std::cout << fib(5) << std::endl;  // 5
    std::cout << rfib(2) << std::endl; // 1

    // Initiaize global array with -1
    for (int i = 0; i < 10; i++)
        F[i] = -1;
    std::cout << mfib(2) << std::endl;
    return 0;
}