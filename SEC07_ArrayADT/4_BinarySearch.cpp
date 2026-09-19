#include <iostream>

struct Array{
    int A[10];
    int length;
    int size;
};



int BinarySearch(const Array &array, int element){

    int b = 0;
    int end = array.length-1;
    int mid = (b+end)/2;

    while(b<=end){
        b++;
        end--;
    }


}

void display(const Array &array){
    for(int i=0;i<array.length;i++){
        std::cout << array.A[i] << " ";
    }
}

int main()
{
    // In Binary search array elements must be sorted
    Array array = {{1,2,3,4,5}, 5, 10};
    display(array);

    return 0;
}