#include <stdio.h>
#include <iostream>

struct Array {
    int A[10];
    int _size;
    int _length;
};

void displayElements(const struct Array &array){
    for(int i=0;i<array._length;i++){
        printf("%d", array.A[i]);
    }
    std::cout << std::endl;
}

void append(Array &array, int element) {
    if(array._length < array._size) {
        array.A[array._length] = element;
        array._length++;
    }
}

void insert(Array &array, int index, int element){
    if(index >= 0 && index <= array._length){
        for(int i = array._length; i > index; i--){
            array.A[i] = array.A[i-1];
        }
        array.A[index] = element;
        array._length++;
    }
}

int main(){
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

    return 0;
}