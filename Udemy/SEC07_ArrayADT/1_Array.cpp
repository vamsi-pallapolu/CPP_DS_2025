#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int _size;
    int _length;
};

void displayElements(const struct Array &array){
    for(int i=0;i<array._length;i++){
        printf("%d", array.A[i]);
    }
}

int main()
{
    struct Array array;
    int n;

    printf("Enter Array _size:");
    scanf("%d", &array._size);

    array.A = (int *)malloc(array._size * sizeof(int));
    array._length = 0;

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