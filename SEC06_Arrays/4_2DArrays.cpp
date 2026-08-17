#include <iostream>
#include <stdio.h>

int main()
{

    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};

    int rows = sizeof(A) / sizeof(A[0]);       // total bytes / bytes-per-row = 2
    int cols = sizeof(A[0]) / sizeof(A[0][0]); // bytes-per-row / bytes-per-int = 3

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", A[i][j]);
        }
        std::cout << std::endl;
    }
    
    int *B[2]; // Array of 2 integer pointers
    B[0] = new int[3];
    B[1] = new int[3];

    // double pointer
    int **C = new int *[2];
    C[0] = new int[3];
    C[1] = new int[3];

    std::cout << std::endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", C[i][j]);
        };
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return 0;
}