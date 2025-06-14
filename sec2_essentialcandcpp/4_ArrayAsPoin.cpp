/*
    Array as a pointer example
*/
#include <iostream>

int* func(int n){
    // let's create memory to store 5 variables in heap memory
    int *p;
    p = (int *)malloc(n*sizeof(int));
    return (p);
}

int main(){
    int *a;
    a = func(3);
    return 0;
}