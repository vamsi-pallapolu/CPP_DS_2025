#include <stdio.h>
#include <iostream>

struct Array
{
    int A[10];
    int _size;
    int _length;
};

void displayElements(const struct Array &array)
{
    for (int i = 0; i < array._length; i++)
    {
        printf("%d ", array.A[i]);
    }
    std::cout << std::endl;
}

void append(Array &array, int element)
{
    if (array._length < array._size)
    {
        array.A[array._length] = element;
        array._length++;
    }
}

void insert(Array &array, int index, int element)
{
    if (array._length < array._size && index >= 0 && index <= array._length)
    {
        for (int i = array._length; i > index; i--)
        {
            array.A[i] = array.A[i - 1];
        }
        array.A[index] = element;
        array._length++;
    }
}

void deleteArray(Array &array, int index)
{
    // check if index is within the length
    if (index >= 0 && index < array._length)
    {
        // Shift all elemnets after index to left
        for (int i = index; i < array._length - 1; i++)
        {
            array.A[i] = array.A[i + 1];
        }
        array._length--;
    }
    else
    {
        std::cout << "No element at index:" << index << std::endl;
    }
}

int main()
{
    struct Array array = {{2, 3, 4, 5, 6}, 10, 5};

    // display
    displayElements(array);

    // append element
    append(array, 7);
    displayElements(array);

    // insert element at specific index
    insert(array, 0, 10);
    displayElements(array);

    insert(array, 6, 20);
    displayElements(array);

    // Deletion of elements in an Array
    deleteArray(array, 0);
    displayElements(array); // 2 3 4 5 6 20 7

    deleteArray(array, 7); // No element at index: 7

    deleteArray(array, 6);
    displayElements(array); // 2 3 4 5 6 20

    deleteArray(array, 1);
    displayElements(array); // 2 4 5 6 20
    return 0;
}