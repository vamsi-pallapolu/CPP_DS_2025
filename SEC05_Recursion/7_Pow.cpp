#include <iostream>

// Optimized approach
/*
    If power is even:
    m⁸ = (m²)⁴
    If power is odd:
    m⁹ = m × (m²)⁴
    So:
    •	Squaring reduces the exponent by half.
    •	This significantly reduces computations.

*/
int pow2(int m, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return pow(m * m, n / 2);
    return m * pow(m * m, (n-1) / 2);
}

int pow(int m, int n)
{
    if (n == 0)
        return 1;
    return pow(m, n - 1) * m;
}
int main()
{
    int result = pow(2, 3);
    std::cout << "Result:" << result << std::endl;
    std::cout << "Result:" << pow2(2, 8) << std::endl;
    return 0;
}