#include <iostream>

struct Array{
    int A[10];
    int length;
    int size;
};

int Sum(struct Array &array){
    int sum = 0;
    for(int i=0;i< array.length;i++){
        sum += array.A[i];
    }
    return sum;
}

float Average(struct Array &array){
    return (float)Sum(array)/array.length;
}

int Min(struct Array &array){
    int MIN = array.A[0];
    for(int i = 1; i< array.length;i++){
        if(array.A[i]<MIN)
            MIN = array.A[i];
    }
    return MIN;
}

int Max(struct Array &array){
    int MAX = array.A[0];
    for(int i=1;i<array.length;i++){
        if(array.A[i]>MAX){
            MAX = array.A[i];
        }
    }
    return MAX;
}

void Set(struct Array &array, int index, int element){
    if(index >=0 && index < array.length){
        array.A[index] = element;
    }
}

int Get(const struct Array &array, int index){
    if(index>=0 && index < array.length){
        return array.A[index];
    }else{
        return -1;
    }
}

int main(){
    Array arr ={{1,4,1,3,2},5, 10};

    // Get element from an array
    std::cout << Get(arr, 0) << std::endl;
    
    // Set element
    Set(arr, 2, 20);
    std::cout << Get(arr, 2) << std::endl;

    // MAX element
    std::cout << "Max:" << Max(arr) << std::endl;

    // MIN element in an array
    std::cout << "Min:" << Min(arr) << std::endl;

    // Sum of an array
    std::cout << "Sum:" << Sum(arr) << std::endl;

    // Average of an array
    std::cout << "Average:" << Average(arr) << std::endl;

    return 0;
}