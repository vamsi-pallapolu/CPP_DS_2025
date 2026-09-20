#include <iostream>

struct Array
{
    int A[10];
    int length;
    int size;
};

// Binary search iterative approach
int BinarySearch(const Array &array, int key)
{

    int b = 0;
    int end = array.length - 1;
    int mid;

    while (b <= end)
    {
        mid = (b + end) / 2;
        if (array.A[mid] == key)
        {
            return mid;
        }
        else if (key < array.A[mid])
        {
            end = mid - 1;
        }
        else
        {
            b = mid + 1;
        }
    }
    return -1;
}

void display(const Array &array)
{
    for (int i = 0; i < array.length; i++)
    {
        std::cout << array.A[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // In Binary search array elements must be sorted
    Array array = {{1, 2, 3, 4, 5}, 5, 10};
    display(array);

    int index = BinarySearch(array, 1);
    if (index == -1)
        std::cout << "Element not found" << std::endl;
    else
        std::cout << "Element found at index:" << index << std::endl;
    return 0;
}