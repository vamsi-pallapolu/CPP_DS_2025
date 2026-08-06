#include <stdio.h>

struct Array {
    int A[10];
    int _size;
    int _length;
};

void displayElements(const struct Array &array){
    for(int i=0;i<array._length;i++){
        printf("%d", array.A[i]);
    }
}

int main(){
    struct Array array = {{2, 3, 4, 5, 6}, 10, 5};

    // display
    displayElements(array);
    return 0;
}