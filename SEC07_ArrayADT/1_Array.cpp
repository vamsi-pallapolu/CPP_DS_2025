#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int lenght;
};

void displayElements(const struct Array &array){
    for(int i=0;i<array.size;i++){
        printf("%d", array.A[i]);
    }
}

int main()
{
    struct Array array;
    int n;

    printf("Enter Array Size:");
    scanf("%d", &array.size);

    array.A = (int *)malloc(array.size * sizeof(int));
    array.lenght = 0;

    printf("Enter number of elements:");
    scanf("%d", &n);

    printf("Enter all elements\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter element:");
        scanf("%d", &array.A[i]);
    }

    displayElements(array);

    return 0;
}