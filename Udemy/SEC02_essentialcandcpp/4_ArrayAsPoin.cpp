/*
    Array as a pointer example
*/
#include <iostream>

void printArray(const int *A, int size)
{
    // A[1] = 10;
    for (int i = 0; i < size; i++)
    {
        // std::cout << A[i];
        std::cout << *(A + i);
    }
    const int *B = A;
    for (int i = 0; i < size; i++)
    {
        // std::cout << A[i];
        std::cout << *(B + i);
    }
}

int *func(int n)
{
    // let's create memory to store 5 variables in heap memory
    int *p;
    p = (int *)malloc(n * sizeof(int));
    return (p);
}

int main()
{
    int *a;
    a = func(3);

    int A[3] = {1, 2, 3};
    printArray(A, 3);
    return 0;
}