#include <iostream>
#include <stdio.h>
int main()
{

    int A[3];
    int size = sizeof(A)/sizeof(A[0]);
    for (int i = 0; i < size; i++)
    {
        printf("%u\n", &A[i]);
        printf("%u\n", (A+i));
    }

    return 0;
}