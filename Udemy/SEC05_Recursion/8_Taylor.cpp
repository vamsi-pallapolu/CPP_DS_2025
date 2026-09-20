#include <iostream>

// Taylor series iterative approach
double taylor(int x, int n)
{
    double numer = 1, denom = 1, sum = 1;
    for (int i = 1; i <= n; i++)
    {
        numer = numer * x;
        denom = denom * i;
        sum += numer / denom;
    }
    return sum;
}

// Using Horner's rule
// Below code is not working
double eH(int x, int n)
{
    double static s = 1;
    if (n == 0)
        return 1;
    s = 1 + (double)x / n * s;
    return eH(x, n - 1);
}

double e(int x, int n)
{
    static double p = 1; // power of x
    static double f = 1; // factorial
    double r;
    if (n == 0)
        return 1;
    r = e(x, n - 1);
    p = p * x;
    f = f * n;
    return r + p / f;
}
int main()
{
    double result = e(1, 10);
    std::cout << "Result:" << result << std::endl;
    std::cout << "Result:" << eH(1, 10) << std::endl;
    std::cout << "Result:" << taylor(1, 10) << std::endl;
    return 0;
}