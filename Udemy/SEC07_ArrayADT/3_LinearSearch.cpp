#include <iostream>

struct Array
{
    int A[10];
    int size;
    int length;
};
 
void swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int LinearSearch(struct Array &array, int element){
    for(int i=0;i<array.length; i++){
        if(array.A[i] == element){
            // swap(array.A[i], array.A[i-1]); // Transposition
            swap(array.A[i], array.A[0]); // Move to first
            return i;
        }
    }
    return -1;
}

void display(const struct Array &array){
    for(int i=0;i<array.length;i++){
        std::cout << array.A[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{

    Array arr = {{2, 1, 4, 0, 5}, 7, 5};
    display(arr);
    std::cout << LinearSearch(arr, 4) << std::endl;
    display(arr);



    return 0;
}