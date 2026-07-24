#include <iostream>
#include <stdio.h>

int main(){

    int A[2][3] = {{1, 2, 3},{4, 5, 6}};
    std::cout << std::endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            printf("%d", A[i][j]);
        };
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return 0;
}