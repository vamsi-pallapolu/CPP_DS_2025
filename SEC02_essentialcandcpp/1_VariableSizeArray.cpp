#include <iostream>

int main()
{
    int n;
    std::cout << "Enter n:";
    std::cin >> n;
    int A[n]; // Varibale sized Array
    A[0] = 2;
    for (int x : A)
        std::cout << x << std::endl;

    return 0;
}

/*
    Variable sized array may or may not be supported by compilers

*/