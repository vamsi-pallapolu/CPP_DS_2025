#include <iostream>

double e(int x, int n)
{
    static double f = 1, p = 1;
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
    double result = e(2, 1);
    std::cout << "Result:" << result << std::endl;
    return 0;
}