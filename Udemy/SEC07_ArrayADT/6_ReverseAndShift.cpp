#include <iostream>

struct Array{
    int A[5];
    int length;
    int size;
};


void reverse(struct Array & array){
    int i =0;
    int j = array.length-1;
    
    while(i<j){
        int temp = array.A[i];
        array.A[i] = array.A[j];
        array.A[j] = temp;
        i++;
        j--;
    }
}

void display(const struct Array &array){
    for(int i=0;i<array.length;i++){
        std::cout << array.A[i] << " ";
    }
    std::cout << std::endl;
}

int main(){

    struct Array array = {{1,2,3,4, 5}, 5, 5};

    reverse(array);
    display(array);

    return 0;
}