#include <iostream>

int main()
{

    // To create memory in heap in C
    int *p = (int *)malloc(5 * sizeof(int));

    // In CPP
    int *p = new int[5];

    return 0;
}